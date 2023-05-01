/************************************************************************************
      
 *                 Copyright (C) 2021 - 2023, Barca, Inc. 
 
 *    Email: <opensource@barca.com>  GitHub: @BarcaWebCloud. 
 *    Project: Speed Run To Clean Your System And Gain More Performance
 
 * This software is licensed as described in the file COPYING, which                    
 * you should have received as part of this distribution. The terms                     
 * are also available at https://BarcaCorporation.github.io/docs/copyright.html.           
 *
 * You may opt to use, copy, modify, merge, publish, distribute and/or sell             
 * copies of the Software, and permit persons to whom the Software is                   
 * furnished to do so, under the terms of the COPYING file.                             
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY            
 * KIND, either express or implied.                                                      
 *
 **************************************************************************************/
#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)

#pragma once

#include <WbemIdl.h>
#include <Windows.h>
#include <comdef.h>
#include <ntddscsi.h>

#include <string>
#include <type_traits>
#include <vector>
#pragma comment(lib, "wbemuuid.lib")

namespace bscan::wmi {

template <typename T>
inline bool queryWMI(const std::string& WMIClass, std::string field, std::vector<T>& value,
                     const std::string& serverName = "ROOT\\CIMV2") {
  std::string query("SELECT " + field + " FROM " + WMIClass);

  HRESULT hres;
  hres = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
  if (FAILED(hres)) {
    return false;
  }
  hres = CoInitializeSecurity(nullptr, -1, nullptr, nullptr, RPC_C_AUTHN_LEVEL_DEFAULT, RPC_C_IMP_LEVEL_IMPERSONATE,
                              nullptr, EOAC_NONE, nullptr);
  if (FAILED(hres)) {
    CoUninitialize();
    return false;
  }
  IWbemLocator* pLoc = nullptr;
  hres = CoCreateInstance(CLSID_WbemLocator, nullptr, CLSCTX_INPROC_SERVER, IID_IWbemLocator, (LPVOID*)&pLoc);
  if (FAILED(hres)) {
    CoUninitialize();
    return false;
  }
  IWbemServices* pSvc = nullptr;
  hres = pLoc->ConnectServer(_bstr_t(L"ROOT\\CIMV2"), nullptr, nullptr, nullptr, 0, nullptr, nullptr, &pSvc);
  if (FAILED(hres)) {
    pLoc->Release();
    CoUninitialize();
    return false;
  }
  hres = CoSetProxyBlanket(pSvc, RPC_C_AUTHN_WINNT, RPC_C_AUTHZ_NONE, nullptr, RPC_C_AUTHN_LEVEL_CALL,
                           RPC_C_IMP_LEVEL_IMPERSONATE, nullptr, EOAC_NONE);
  if (FAILED(hres)) {
    pSvc->Release();
    pLoc->Release();
    CoUninitialize();
    return false;
  }
  IEnumWbemClassObject* pEnumerator = nullptr;
  hres = pSvc->ExecQuery(bstr_t(L"WQL"), bstr_t(std::wstring(query.begin(), query.end()).c_str()),
                         WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY, nullptr, &pEnumerator);
  if (FAILED(hres)) {
    pSvc->Release();
    pLoc->Release();
    CoUninitialize();
    return false;
  }
  IWbemClassObject* pclsObj = nullptr;
  ULONG uReturn = 0;
  while (pEnumerator) {
    pEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);

    if (!uReturn) {
      break;
    }

    VARIANT vtProp;
    pclsObj->Get(std::wstring(field.begin(), field.end()).c_str(), 0, &vtProp, nullptr, nullptr);

    if (std::is_same<T, long>::value || std::is_same<T, int>::value) {
      value.push_back((T)vtProp.intVal);
    } else if (std::is_same<T, bool>::value) {
      value.push_back((T)vtProp.boolVal);
    } else if (std::is_same<T, unsigned>::value) {
      value.push_back((T)vtProp.uintVal);
    } else if (std::is_same<T, unsigned short>::value) {
      value.push_back((T)vtProp.uiVal);
    } else if (std::is_same<T, long long>::value) {
      value.push_back((T)vtProp.llVal);
    } else if (std::is_same<T, unsigned long long>::value) {
      value.push_back((T)vtProp.ullVal);
    } else {
      value.push_back((T)((bstr_t)vtProp.bstrVal).copy());
    }

    VariantClear(&vtProp);
    pclsObj->Release();
  }

  if (value.empty()) {
    value.resize(1);
  }

  pSvc->Release();
  pLoc->Release();
  if (pEnumerator) pEnumerator->Release();
  CoUninitialize();
  return true;
}

};

#endif

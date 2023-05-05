/************************************************************************************
      
 *                 Copyright (C) 2021 - 2023, Barca, Inc. 
 
 *    Email: <opensource@barca.com>  GitHub: @BarcaCorporation. 
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
#ifndef PYHELPER_HPP
#define PYHELPER_HPP
#pragma once

#include <py39/Python.h>

class InitPy {
  public:
    InitPy() {
      Py_Initialize();
    }

    ~InitPy() {
      Py_Finalize();
    }
};

class CPyObject {
  private:
    PyObject *p;
  public:
    CPyObject() : p(NULL)
    {}

    CPyObject(PyObject* _p) : p(_p)
    {}
    
    ~CPyObject() {
      Release();
    }

    PyObject* getObject() {
      return p;
    }

    PyObject* setObject(PyObject* _p) {
      return (p=_p);
    }

    PyObject* AddRef() {
      if(p) {
        Py_INCREF(p);
      }
      return p;
    }

    void Release() {
      if(p) {
        Py_DECREF(p);
      }
      p= NULL;
    }

    PyObject* operator ->() {
      return p;
    }

    bool is() {
      return p ? true : false;
    }

    operator PyObject*() {
      return p;
    }

    PyObject* operator = (PyObject* pp) {
      p = pp;
      return p;
    }

    operator bool() {
      return p ? true : false;
    }
};

#endif
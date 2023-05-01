## Speed Run v0.1.0-beta

<br>

<p align="center">
 <img width="100px" src="https://raw.githubusercontent.com/BarcaCorporation/community/main/static/cloud/speedrun/logos/2023/barca-speedrun-logo.png" align="center" alt="GitHub Readme Stats" />
 <h2 align="center">Speed Run </h2>
 <p align="center">
    Speed Up Your System Using Cleanup Features For Cache, Temp Data, Memory Dumps and More</p>
 </p>
  <p align="center">
    <a href="https://github.com/BarcaWebCloud/github-readme-stats/actions">
      <img alt="GitHub issues" src="https://img.shields.io/github/issues/BarcaWebCloud/speedrun">
    </a>
    <a href="https://codecov.io/gh/BarcaWebCloud/github-readme-stats">
      <img alt="GitHub pull requests" src="https://img.shields.io/github/issues-pr/BarcaWebCloud/speedrun">
    </a>
    <a href="https://a.paddle.com/v2/click/16413/119403?link=1227">
      <img alt="GitHub Release Date" src="https://img.shields.io/github/release-date/BarcaWebCloud/speedrun">
    </a>
    <a href="https://a.paddle.com/v2/click/16413/119403?link=2345">
      <img alt="GitHub repo size" src="https://img.shields.io/github/repo-size/BarcaWebCloud/speedrun">
    </a>
  </p>

</p>

<br>



**Speed Run** is a Program To Clean Your System And Gain More Performance.

We can install **Speed Run** desktop version on *Windows, Linux & MacOS* systems.

<br>

1. [Cache](/docs/cache/intro.md) - delete all data cache on system.

2. [Temporary](/docs/temp/intro.md) - delete all files temporary on system.


<br>

## Requirements

It is necessary that you have installed the programs below to use **Speed Run** in developer mode.

### To Linux

<br>

- [Python](https://www.python.org/) **v3.1** or greater
- [Compilers C/C++](https://school.barca.com/edu/ti/overview/c++/compiler/intro.html) 
  - [MinGW/GCC](https://www.mingw-w64.org)
  - [Digital Mars](https://www.digitalmars.com/d/2.0/dmd-linux.html)
  - [Clang](https://clang.llvm.org)
  - [Intel](https://www.intel.com/content/www/us/en/developer/tools/oneapi/dpc-compiler.html)
  - [GNU GCC](http://gcc.gnu.org)
  - [Code Block](https://wiki.codeblocks.org/index.php/Installing_a_supported_compiler)
  - [Cygwin](http://www.cygwin.org)
  - [Small Device](https://sdcc.sourceforge.net)
- [Node.js](https://nodejs.org/) **v8** or greater

<br>

### To Windows

<br>

- [Python](https://www.python.org/) **v3.1** or greater
- [Compilers C/C++](https://school.barca.com/edu/ti/overview/c++/compiler/intro.html) 
  - [MinGW/GCC](https://www.mingw-w64.org)
  - [Clang](https://clang.llvm.org)
  - [Intel](https://www.intel.com/content/www/us/en/developer/tools/oneapi/dpc-compiler.html)
  - [Visual (suggested)](https://visualstudio.microsoft.com/vs/features/cplusplus)
  - [Code Block](https://wiki.codeblocks.org/index.php/Installing_a_supported_compiler)
  - [Cygwin](http://www.cygwin.org)
  - [Small Device](https://sdcc.sourceforge.net)
- [Node.js](https://nodejs.org/) **v8** or greater
  
<br>

### To Apple

<br>

- [Python](https://www.python.org/) **v3.1** or greater
- [Compilers C/C++](https://school.barca.com/edu/ti/overview/c++/compiler/intro.html) 
  - [MinGW/GCC](https://www.mingw-w64.org)
  - [Clang](https://clang.llvm.org)
  - [XCode](https://wiki.xcode.org/index.php/Installing_a_supported_compiler)
  - [Cygwin](http://www.cygwin.org)
- [Node.js](https://nodejs.org/) **v8** or greater

<br>
<br>

## Obtaining Speed Run

<br>

View the [changelog](/CHANGELOG.md) for the latest updates and changes by version.

<br>

### Binary Downloads

Binary downloads are available from the [BWC downloads](https://cloud.barca.com/downloads)
page or from each [GitHub Releases](https://github.com/BarcaWebCloud/speedrun/releases) page.


<br>
<br>

## Build From Source

<br>

**Speed Run** requires C++ version 17 or newer, the CMakelists requires GNU cmake.

  1. [Install Node.js](https://nodejs.org/) >=8.0.0 (16.11 recommended)
  2. [Install Python](https://www.python.org/downloads/) >=2.6.0 (3.9.0 recommended)
  3. Clone the Speed Run repository:
    
      ```sh
      git clone https://github.com/BarcaWebCloud/speedrun.git
      ```

<br>

## Build Executable Speed Run in Your Environment

### To Linux

<br>

  1. Run `cmake CMakeLists.txt` from the source directory

      ```shell
      cd speedrun
      cmake CMakeLists.txt
      ```
  2. Now run `make all` or `make speedrun` to compile the main program

<br>

### To Windows

<br>

Check the **gcc** version of your System. Speed Run requires version greater than **17**.
We can view a list of *Makefile* generators with the command: `cmake -G`.
Here shows an example to use the **MinGW** *Makefile* generator:

<br>

  1. Run `cmake -G "MinGW Makefiles" <file-cmake>` from the source directory

      ```shell
      cd speedrun
      cmake -G "MinGW Makefiles" CMakeLists.txt
      ```
  
  <br>

  2. Now run `make all` or `make speedrun` to compile the main program

<br>


<br>

## Documentation

[Latest Release Documentation](https://cloud.barca.com/docs/speedrun/latest/)

For documentation on the latest development code see the [documentation index](/docs).

<br>

## Contributing

There are many ways to contribute:

- Fix and [report bugs](https://github.com//BarcaWebCloud/speedrun/issues/new)
- [Review code and feature proposals](https://github.com/BarcaWebCloud/speedrun/pulls)
- Answer questions and discuss here on github and on the [Community Site](https://opensource.barca.com/)
- [Contribute plugins](CONTRIBUTING.md)

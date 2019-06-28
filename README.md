LibroDeConocimiento

## PURPOSE
This program aims to try out different concepts within the C++ software development that is often overlooked when working on already established projects.

## REQUIREMENTS
1. GNU/Linux environment
    * Either:
        1. Full operating system
        2. Virtual machine (as a guest OS)
        3. Cygwin
        4. etc.
2. Git (optional if you just prefer to do a download and extract from GitHub)
    ~~~
    sudo apt install git
    ~~~
3. GNU Toolchain
    ~~~
    sudo apt install build-essential
    ~~~
4. CMake
    ~~~
    sudo apt install cmake
    ~~~

## BUILDING
~~~
git clone https://github.com/nponcian/LibroDeConocimiento.git
cd LibroDeConocimiento
mkdir -p build && cd build
cmake ..
~~~

## RUNNING
~~~
cd LibroDeConocimiento/build
cmake ..
make
src/libro_src --help
~~~

Feliz aprendizaje mis AMIGOS!

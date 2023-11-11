# How to organize a big C++ project
(11/05/2023 )

This is a tutorial example of how to organize a c++ project.

## Top level folder explanation
> doc/  the doumentation \
> ref/  references \
> pkg/  the thirdparty packages w/ or w/o source code \
> src/  our own source code is this project \
> build/ building folder in general \
> build-vs2019/ specific building folder vy vs2019 \
> build-jetson/ specific building folder for jetson

## Top level cmake build philosophy 
We support both top-down and bottom-up buiding 

### Top-down

Go to project root folder: howToOrgCppProj/ 

> howToOrgCppProj$ mkdir build && cd build \
> howToOrgCppProj/build$ cmake -DAPPLOG_TESTS=1 ../ 

The building results will be located at:
> howToOrgCppProj/build/pkg/lib \
> howToOrgCppProj/build/pkg/bin \
> howToOrgCppProj/build/lib \
> howToOrgCppProj/build/bin

### bottom-up
For debug and development purpose, we also can build a individual lib and its tests. General speaking
whenever there is a CMakeLists.txt in folder X/ you can do:
> X$ mkdir build && cd build \
> X/build$ cmake ../

The building results will be located at:
> X/build/lib \
> X/build/bin \

But the building results will be located at:\
> build/  -- (**buid_dir** varaiable in CMakeLists.txt) \
> build/pkg/lib/ \
> build/pkg/bin/ \
> build/app/lib/ \
> build/app/bin/

## Document Slides
> doc/How-to-organize-A-large-cpp-proj.pptx \
--------- eof-----------

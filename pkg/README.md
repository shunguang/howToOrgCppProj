# PKG

pkgs are third party packages used to build our application. We use git submodules to control them.

## build
### Each pkg can be built individually by pkg/xxx/CMakeLists.txt
   $cd pkg\xxx \
   $mkdir build && cd build \
   $cmake .. && make -j4
   
### All pkgs can also be built once by pkg/CMakeLists.txt
   $cd pkg \
   $mkdir build && cd build \
   $cmake .. && make -j4

### location of build resulsts
   $build/pkg \
   $build/pkg/lib \
   $build/pkg/bin \
(eof)

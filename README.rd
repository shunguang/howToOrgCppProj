# How to organize a large C++ project
(12/22/2023 )

This tutorial shows how to organize a large c++ project and build it by cmake with static libraries without installation folders.  Based on the current CMakeLists.txt files,  extend to dynamical libraries and add an install folder is trivial.   see ***doc/How-to-organize-A-large-cpp-proj.pdf*** for more details.

## Top level folder structure
```
howToOrgCppProj/
              cmake/      			#the cmake scripts folder
              data/      			#the test data folder
              doc/      			#the doumentation 
              pkg/    			   	#the third party packages
                  pkgA/			   	#package A (we cannot control its folder strcture)
                  ...
                  pkgX/            	#package X (we cannot control its folder strcture)
              src/                 	#our developed source code
                    libA/          	#library A
                       src/        	#cpp files
                       include/    	#headers
                       test/       	#unit test stuff
                    ...
                    libX/          	#library X
                         (same folder structure as that in libA)
                    appA/          	#executable application A
                       src/        	#source code
                       cfg/        	#configuration files
                      ...
                    appX/          	#executable application X
                         (same folder structure as that in appA)
              build/			#building folder in general
					lib/		#the libs: libpkgA.a, ..., libpkgX.a
					bin/		#the binaries: test_pkgA, ...
					...         #cmake related intermediate files/folders 					                       
              build-jetson/   		#specific building folder for jetson
                          (same folder structure as that in build/)
              build-vs2019/   	    #specific building folder for vs2019 in windows
                          /int          //intermediate building results
                          /Debug        //lib and exe for debug
                          /Release      //lib and exe for release
```
## CMake build philosophy 
We support both top-down and bottom-up build approaches, and ***do not copy*** any headers into our output building folders.   In another words, there is ***one and only one copy of a header file ***  in howToOrgCppProj/ folder.
### Top-down
Go to project root folder: howToOrgCppProj/ 
```
    howToOrgCppProj$ mkdir build && cd build \
    howToOrgCppProj/build$ cmake -DBUILD_LOG_TESTS=1 ../ 
```
The building results will be located at:
```
    howToOrgCppProj/build/lib          #hold the static/dynamic libs
    howToOrgCppProj/build/bin          #the hold the binaries
```
### bottom-up
For debug and development purpose, we also support build an individual lib and its tests. General speaking whenever there is a CMakeLists.txt in folder X/ you can do:
```
> X$ mkdir build && cd build \
> X/build$ cmake ../
```
The building results will be located at:
```
> X/build/lib \
> X/build/bin \
```
Moreover, in the bottom-up building approach, the building order matters.  We assume you build the packages in howToOrgCppProj/pkg/ first,  then either automatically or manually  copy them into 
```
howToOrgCppProj/build/
		 		     lib/   #libpkgA.a, ..., libpkgX.a
				     bin/   #some test bininaries from pkgs
```
In the process of building our own modules in ***howToOrgCppProj/src***, we may link them from ***howToOrgCppProj/build/lib***.

For modules in howToOrgCppProj/src/,   when you build libX, we assume that all its dependences  were built and the building results are located at: 
```
howToOrgCppProj/build/
			lib/   #libA.a, ..., libY.a
			bin/   #some test bininaries

```
If the dependence of  libX is not available,  an error  message will be prompted.
--------- eof-----------
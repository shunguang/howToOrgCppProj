# libLog

libLog is a wrapper from pkg/spdlog. To build it you need to have submodule pkg/spdlog ready. 

## build
```
	$mkdir build && cd build
	build$ cmake ../ -DAPPLOG_TESTS=1
```
	
## usage  
see test/main.cpp for more details 

## test
```   
   build$ bin/appLogTest
```

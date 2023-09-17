cmake_minimum_required(VERSION 3.10)


set(CgiCc_DIR "/home/matvey-l/data/site-forge/src/cgicc")
set(CMAKE_VERBOSE_MAKEFILE TRUE)
#CMAKE_VERBOSE_MAKEFILE=TRUE make

project(KrapSite)

set(CMAKE_BUILD_TYPE Release) #Debug / Release
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


set(MADDY_SRC "/home/matvey-l/data/site-forge/src/Maddy_src")
set(MD4C_LIB_DIR "/home/matvey-l/data/site-forge/src/md4c-build/src")
set(MD4C_INC_DIR "/home/matvey-l/data/site-forge/src/md4c-release-0.4.8/src")
#CMAKE -DBUILD_SHARED_LIBS=OFF

add_subdirectory(classes)
add_subdirectory(executables)
add_subdirectory(pages)


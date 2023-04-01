cmake_minimum_required(VERSION 3.10)

set(CgiCc_DIR "/var/www/kraposhin/cgicc")
set(CMAKE_VERBOSE_MAKEFILE TRUE)
#CMAKE_VERBOSE_MAKEFILE=TRUE make

project(KrapSite)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set (MADDY_SRC "/home/matvey/data/site-forge/Maddy_src")

add_subdirectory(classes)
add_subdirectory(executables)


cmake_minimum_required(VERSION 3.10)

set(CgiCc_DIR "/var/www/kraposhin/cgicc")

project(KrapSite)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(classes)
add_subdirectory(executables)


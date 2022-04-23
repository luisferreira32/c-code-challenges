cmake_minimum_required(VERSION 3.2)
project(aux-libs)

set(SOURCE_FILES quicksort.c util.c)

add_library(quicksort STATIC ${SOURCE_FILES})

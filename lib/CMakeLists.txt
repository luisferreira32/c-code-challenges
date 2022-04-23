cmake_minimum_required(VERSION 3.2)
project(lib)

add_library(lib STATIC 
    quicksort.c
    iohelper.c
	util.c
)

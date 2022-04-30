cmake_minimum_required(VERSION 3.2)
project(anagram-challenge)

add_library(wordinversion STATIC 
    wordinversion.c
    solver1.c
    solver2.c
)

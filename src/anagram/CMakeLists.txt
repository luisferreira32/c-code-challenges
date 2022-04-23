cmake_minimum_required(VERSION 3.2)
project(anagram-challenge)

add_library(anagram STATIC 
    anagram.c
    solver1.c
)

# link whatever libraries your anagram solver needs
target_link_libraries(anagram lib)
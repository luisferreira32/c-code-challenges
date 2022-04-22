cmake_minimum_required(VERSION 3.2)
project(anagram-challenge)

set(SOURCE_FILES anagram.c)

add_library(anagram STATIC ${SOURCE_FILES})

# link whatever libraries your anagram solver needs
target_link_libraries(anagram lib)
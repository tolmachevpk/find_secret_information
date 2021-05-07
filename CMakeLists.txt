cmake_minimum_required(VERSION 3.19)
project(find_secret_information)

set(CMAKE_CXX_STANDARD 20)

add_executable(find_secret_information main.cpp Headers/trie.h Sources/trie.cpp Headers/aho_corasick.h Sources/aho_corasick.cpp Headers/read_files.h Sources/read_files.cpp)
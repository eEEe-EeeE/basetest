cmake_minimum_required(VERSION 3.14)
project(basetest C)

include_directories(include)

set(CMAKE_C_STANDARD 99)

add_executable(basetest
        main.c
        include/tree.h
        lib/tree.c
        include/binary_tree.h
        lib/binary_tree.c
        include/utils.h
        lib/utils.c
        include/main.h
        include/queue.h
        lib/queue.c
        include/stack.h
        lib/stack.c
        include/mydef.h
        include/thread_binary_tree.h
        lib/thread_binary_tree.c
        include/balanced_binary_tree.h
        lib/balanced_binary_tree.c
        include/huffman_tree.h
        lib/huffman_tree.c include/hash.h lib/hash.c include/splay_tree.h lib/splay_tree.c include/binary_search_tree.h lib/binary_search_tree.c)
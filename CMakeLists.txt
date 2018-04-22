cmake_minimum_required(VERSION 3.9)
project(cachelab_handout)

set(CMAKE_CXX_STANDARD 11)

add_executable(cachelab_handout
        traces/dave.trace
        traces/long.trace
        traces/trans.trace
        traces/yi.trace
        traces/yi2.trace
        cachelab.c
        cachelab.h
        csim-ref
        csim.c
        driver.py
        Makefile
        README
        test-csim
        test-trans.c
        tracegen.c
        trans.c)

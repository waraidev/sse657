cmake_minimum_required(VERSION 3.17)
project(sse657)

set(CMAKE_CXX_STANDARD 14)

add_executable(sse657
        RozemicBanking/main.cpp RozemicBanking/Payment.cpp RozemicBanking/Payment.h)

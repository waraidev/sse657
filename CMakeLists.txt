cmake_minimum_required(VERSION 3.17)
project(sse657)

set(CMAKE_CXX_STANDARD 14)

add_executable(sse657
        RozemicBanking/RozemicBanking/main.cpp RozemicBanking/RozemicBanking/Payment.cpp RozemicBanking/RozemicBanking/Payment.h RozemicBanking/RozemicBanking/UserAccount.cpp RozemicBanking/RozemicBanking/UserAccount.h)

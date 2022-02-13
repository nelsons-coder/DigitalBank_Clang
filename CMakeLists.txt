cmake_minimum_required(VERSION 3.21)
project(DigitalBank_Clang)

set(CMAKE_C_STANDARD 99)

add_executable(DigitalBank_Clang main.c Manager.c Manager.h Client.c Client.h Wallet.c Wallet.h Crypto.c Crypto.h CleanBuffer.c CleanBuffer.h Menus.c Menus.h Random.c Random.h)

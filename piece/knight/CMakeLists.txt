cmake_minimum_required(VERSION 3.22)

set (CMAKE_CXX_STANDARD 20)


project(TEST_KNIGHT_PIECE)


add_executable(knight_test knight_test.cpp ../piece.cpp knight.cpp)
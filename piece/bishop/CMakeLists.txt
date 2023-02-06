

cmake_minimum_required(VERSION 3.22)

set (CMAKE_CXX_STANDARD 20)


project(TEST_BISHOP_PIECE)


add_executable(bishop_test bishop_test.cpp ../piece.cpp bishop.cpp)
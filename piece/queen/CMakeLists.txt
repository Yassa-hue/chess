

cmake_minimum_required(VERSION 3.22)

set (CMAKE_CXX_STANDARD 20)


project(TEST_QUEEN_PIECE)


add_executable(queen_test queen_test.cpp ../piece.cpp queen.cpp)

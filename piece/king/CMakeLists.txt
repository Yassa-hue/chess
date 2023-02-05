

cmake_minimum_required(VERSION 3.22)

set (CMAKE_CXX_STANDARD 20)


project(TEST_KING_PIECE)


add_executable(king_test king_test.cpp ../piece.cpp king_piece.cpp)

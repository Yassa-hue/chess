cmake_minimum_required(VERSION 3.22)

set (CMAKE_CXX_STANDARD 20)


project(TEST_PAWN_PIECE)


add_executable(pawn_test pawn_test.cpp ../piece.cpp pawn.cpp)
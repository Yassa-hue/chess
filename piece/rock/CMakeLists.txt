cmake_minimum_required(VERSION 3.22)

set (CMAKE_CXX_STANDARD 20)


project(TEST_ROCK_PIECE)


add_executable(rock_test rock_test.cpp ../piece.cpp rock.cpp)
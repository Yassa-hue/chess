

cmake_minimum_required(VERSION 3.22)

set (CMAKE_CXX_STANDARD 20)


project(CHESS_GAME)


add_executable(chess_game main.cpp ./board/board.cpp ./game/game.cpp ./piece/piece.cpp ./piece/bishop/bishop.cpp ./piece/king/king_piece.cpp ./piece/knight/knight.cpp ./piece/pawn/pawn.cpp ./piece/queen/queen.cpp ./piece/rock/rock.cpp ./square/square.cpp)
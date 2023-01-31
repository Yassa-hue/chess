
# Compile the piece class
g++ -std=c++20 -c ../piece.cpp -o piece.o

# Compile the king class
g++ -std=c++20 -c ./king_piece.cpp -o king_piece.o



# the main test script
g++ -std=c++20 -c ./king_test.cpp -o king_test.o



# link the files
g++ -std=c++20 king_test.o king_piece.o piece.o


# clear the folder
rm *.o





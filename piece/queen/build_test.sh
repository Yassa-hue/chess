
# Compile the piece class
g++ -std=c++20 -c ../piece.cpp -o piece.o

# Compile the queen class
g++ -std=c++20 -c ./queen.cpp -o queen.o



# the main test script
g++ -std=c++20 -c ./queen_test.cpp -o queen_test.o



# link the files
g++ -std=c++20 queen_test.o queen.o piece.o


# clear the folder
rm *.o

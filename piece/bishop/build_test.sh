
# Compile the piece class
g++ -std=c++2a -c ../piece.cpp -o piece.o

# Compile the bishop class
g++ -std=c++2a -c ./bishop.cpp -o bishop.o



# the main test script
g++ -std=c++2a -c ./bishop_test.cpp -o bishop_test.o



# link the files
g++ -std=c++2a bishop_test.o bishop.o piece.o


# clear the folder
rm *.o




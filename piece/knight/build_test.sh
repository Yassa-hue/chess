
# Compile the piece class
g++ -std=c++2a -c ../piece.cpp -o piece.o

# Compile the king class
g++ -std=c++2a -c ./knight.cpp -o knight.o



# the main test script
g++ -std=c++2a -c ./knight_test.cpp -o knight_test.o



# link the files
g++ -std=c++2a knight_test.o knight.o piece.o


# clear the folder
rm *.o





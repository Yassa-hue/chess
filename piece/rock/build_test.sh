
# Compile the piece class
g++ -std=c++2a -c ../piece.cpp -o piece.o

# Compile the queen class
g++ -std=c++2a -c ./rock.cpp -o rock.o



# the main test script
g++ -std=c++2a -c ./rock_test.cpp -o rock_test.o



# link the files
g++ -std=c++2a rock_test.o rock.o piece.o


# clear the folder
rm *.o

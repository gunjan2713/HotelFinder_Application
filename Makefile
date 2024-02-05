# Specifies the dependencies for the final executable
hotelFinder: main.o HashTable.o BST.o Hotel.o
    # Compilation command that links these object files together into an executable
    # Ensure to include -g flag for debugging information
    # Added -std=c++11 to enable C++11 features
	g++ -std=c++11 -g main.o HashTable.o BST.o Hotel.o -o hotelFinder

# Specifies target main.o that depends on source file main.cpp
main.o: main.cpp HashTable.hpp BST.hpp Hotel.hpp
    # Compilation command for main.o with -g flag
    # Added -std=c++11 to enable C++11 features
	g++ -c -std=c++11 -g main.cpp

# Specifies target HashTable.o that depends on HashTable.cpp and HashTable.hpp
HashTable.o: HashTable.cpp HashTable.hpp
    # Compilation command for HashTable.o
    # Added -std=c++11 to enable C++11 features
	g++ -c -std=c++11 -g HashTable.cpp

# Specifies target BST.o that depends on BST.cpp and BST.hpp
BST.o: BST.cpp BST.hpp
    # Compilation command for BST.o
    # Added -std=c++11 to enable C++11 features
	g++ -c -std=c++11 -g BST.cpp

# Specifies target Hotel.o that depends on Hotel.cpp and Hotel.hpp
Hotel.o: Hotel.cpp Hotel.hpp
    # Compilation command for Hotel.o
    # Added -std=c++11 to enable C++11 features
	g++ -c -std=c++11 -g Hotel.cpp

# Clean target to remove compiled files
clean:
	rm -f hotelFinder main.o HashTable.o BST.o Hotel.o

# Specifiy the compiler and flags to be used


# Specifiy the target
all: Find.exe

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
Find.exe: Find.o Driver.o
	g++ Find.o  Driver.o -o Find.exe

# Specify how the object files should be created from source files
Find.o: Find.cpp
	g++ -c  Find.cpp

Driver.o: Driver.cpp
	g++  -c  Driver.cpp

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing

clean:
	rm -f *.o Find.exe


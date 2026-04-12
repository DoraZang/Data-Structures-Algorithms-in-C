CXX=clang
CXXFLAGS=-std=c99 -Wall -O -g -MMD -Werror=vla # use -MMD to generate dependencies
SOURCES=$(wildcard *.c)    # list of all .c files in the current directory
OBJECTS=${SOURCES:.c=.o}   # .o files depend upon .cc files with same names
DEPENDS=${OBJECTS:.o=.d}   # .d file is list of dependencies for corresponding .cc file
EXEC=deque

# First target in the makefile is the default target.
# Note that the LIBFLAGS must come last in the command
$(EXEC): $(OBJECTS)
		$(CXX) $(CXXFLAGS) $(OBJECTS) -fsanitize=address -o $(EXEC)

%.o: %.c
		$(CXX) -c -o $@ $< $(CXXFLAGS) 

-include ${DEPENDS}

.PHONY: clean
clean:
		rm  -f $(OBJECTS) $(DEPENDS) $(EXEC)

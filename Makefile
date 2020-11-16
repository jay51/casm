EXEC=casm
CXX=gcc
SOURCES=$(wildcard src/*.c)
OBJECTS=$(SOURCES:.c=.o)
FLAGS=-g -Wall -lm -ldl


$(EXEC): $(OBJECTS)
	$(CXX) $(OBJECTS) $(FLAGS) -o $(EXEC)

%.o: %.c %.h
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	-rm *.out
	-rm *.o
	-rm *.a
	-rm src/*.o

lint:
	clang-tidy src/*.c src/include/*.h


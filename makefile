COMPILER=g++

FLAGS=-Wall -Wextra -pedantic -std=c++11 -lsimlib -lm

.PHONY: run clean

main: main.cpp
	$(COMPILER) -o $@ $< $(FLAGS)

run:
	./main

clean:
	rm -f main
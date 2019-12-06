COMPILER=g++

FLAGS=-Wall -Wextra -pedantic -std=c++11 -lsimlib -lm

all: coal wind

coal: coal.cpp
	$(COMPILER) -o $@ $< $(FLAGS)

wind: wind.cpp
	$(COMPILER) -o $@ $< $(FLAGS)
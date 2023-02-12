all:
	g++ -Wall -Wextra -Wpedantic -o sf18 -std=c++17 *.cpp
install:
	install ./sf18 dirProg/
unistall:
	rm -rvf ./dirProg/*
clean:
	rm sf18

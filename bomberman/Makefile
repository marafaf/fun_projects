all: bomberman

bomberman: main.o #other .o
	g++ main.o -o bomberman #other .o

main.o: src/*.cpp includes/*.h
	g++ -c src/*.cpp
clean:
	rm -rf *.o bomberman
fclean: clean
	rm -f *~
re: clean fclean bomberman

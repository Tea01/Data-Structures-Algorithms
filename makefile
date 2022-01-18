all:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/DDugum.cpp -o ./lib/DDugum.o
	g++ -c -I "./include" ./src/Liste.cpp -o ./lib/Liste.o
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
bagla:
	g++ ./lib/DDugum.o ./lib/Liste.o ./lib/main.o -o ./bin/program
calistir:
	./bin/program
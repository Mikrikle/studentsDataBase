all:
	g++ -std=c++17 -pthread -I/usr/include/gtest -L/usr/lib/x86_64-linux-gnu database_tests.cpp database.h -o program.out -lgtest -lpthread

clean:
	rm program.out
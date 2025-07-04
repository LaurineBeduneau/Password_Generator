CXX = g++
CXXFLAGS = -I../shared -std=c++17 -Wall -Wextra
SRC = src/main.cpp ../shared/password_generator.cpp
OUT = build/password_console

all:
	mkdir -p build
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

clean:
	rm -rf build
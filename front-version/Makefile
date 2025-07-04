CXX = g++
CXXFLAGS = -I../shared -std=c++17 -Wall
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
SRC = src/main.cpp ../shared/password_generator.cpp
OUT = build/password_front

all:
	mkdir -p build
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT) $(LDFLAGS)

clean:
	rm -rf build
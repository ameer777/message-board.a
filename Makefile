#!make -f

CXX=clang++-9 
CXXFLAGS=-std=c++2a -Werror -Wsign-conversion

SOURCES=NumberWithUnits.cpp
OBJECTS=$(subst .cpp,.o,$(SOURCES))

run: demo
	./$^

demo: Demo.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o demo

test: TestCounter.o Test.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o test

tidy:
	clang-tidy $(SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

main: main.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o main

%.o: %.cpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@


clean:
	rm -f *.o new_unit.txt object.txt unit.txt demo test main
CXX := g++
CPPFLAGS := -g

out : main.o csp.o
	$(CXX) -o $@ $^ $(CPPFLAGS)

main.o: main.cpp csp.h

csp.o: csp.cpp csp.h

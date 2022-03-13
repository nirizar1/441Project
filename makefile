CXX = g++
CXXFLAGS = -Wall

driver:  main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o driver
	
clean:
	rm *.o*
	rm *~ 

run:
	./driver

val:
	valgrind ./driver

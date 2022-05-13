CXX = g++
CXXFLAGS = -Wall

driver: insertionSort.o quickSort.o bucketSort.o cudiSort.o main.cpp
	$(CXX) $(CXXFLAGS) insertionSort.o quickSort.o bucketSort.o cudiSort.o main.cpp -o driver

insertionSort.o: insertionSort.cpp insertionSort.h
	$(CXX) $(CXXFLAGS) -c insertionSort.cpp

quickSort.o: quickSort.cpp quickSort.h
	$(CXX) $(CXXFLAGS) -c quickSort.cpp

bucketSort.o: bucketSort.cpp bucketSort.h
	$(CXX) $(CXXFLAGS) -c bucketSort.cpp

cudiSort.o: cudiSort.cpp cudiSort.h
	$(CXX) $(CXXFLAGS) -c cudiSort.cpp

clean:
	rm *.o*
	rm *~ 

run:
	./driver

val:
	valgrind ./driver

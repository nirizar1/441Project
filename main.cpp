#include <iostream>
#include <bits/stdc++.h>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>
#include <stdlib.h>
#include <filesystem>
#include <vector>
#include <fstream>
#include <algorithm>
#include "insertionSort.h"
#include "quickSort.h"
#include "bucketSort.h"
#include "cudiSort.h"
using namespace std; //namespace

// Test Parameters
int N_DEGREE = 0; // N degree of sortedness for the array 
int NUM_TEST_CASES = 10000; // number of desired test cases 
int ARRAY_TEST_RANGE = 999;
int ARRAY_RANGE_FLOOR = 10;

// hybridSort, modifiedBucketSort, and cudiSort fulcrum parameters
int FULCRUM_HS = 125;
int FULCRUM_CS = 380;
int FULCRUM = degree_finder(N_DEGREE);

void generateTestArray(int *array, int size, int percent);

float generateFloat();

void generateFloatArray(float *array, int size, int percent);

void write_csv(std::string filename, std::vector<std::pair<std::string, std::vector<double>>> dataset);

bool test(string file);

void logFile(string file, bool exists, int arraySize, double clockTicks, double seconds, double memorySize, int algoCategory);

void test_cases_insertion_sort(int size);

void test_cases_quick_sort(int size);

void test_cases_3_way_quick_sort(int size);

void test_cases_hybrid_sort(int size);

void test_cases_bucket_sort(int size);

void test_cases_modified_bucket_sort(int size);

void test_cases_cudi_sort(int size);


int main(){

    srand (time(NULL)); //random seed

    int test_size = NUM_TEST_CASES; // number of test cases to be compeleted

    while(N_DEGREE <= 100)
      {
        
        cout << "Degree of Sortedness = " << N_DEGREE << "%" << endl;
        /*
        // *****************TESTS FOR BASE SORTING ALGORITHMS***************************
        cout << "Loading test cases for insertion sort. Please wait." << endl;
        for(int i = 0; i < test_size; i++){
            int randomArrSize = rand() % ARRAY_TEST_RANGE + ARRAY_RANGE_FLOOR;
            test_cases_insertion_sort(randomArrSize);
            
        }
        cout << "Insertion sort tests completed." << endl;
        
        cout << "Loading test cases for quick sort. Please wait." << endl;
        for(int i = 0; i < test_size; i++){
            int randomArrSize = rand() % ARRAY_TEST_RANGE + ARRAY_RANGE_FLOOR;
            test_cases_quick_sort(randomArrSize);
        }

        cout << "Quick Sort tests completed."<< endl;

        cout << "Loading test cases for bucket sort. Please wait." << endl;
        for(int i = 0; i < test_size; i++){
            int randomArrSize = rand() % ARRAY_TEST_RANGE + ARRAY_RANGE_FLOOR;
            test_cases_bucket_sort(randomArrSize);
        }
        cout << "Bucket Sort tests completed. "<< endl;

        // *****************TESTS FOR BASE iMRPOVED VARIATIONS OF BASE ALGORITHMS***************************
        cout << "Loading test cases for 3-way quick sort. Please wait." << endl;
        for(int i = 0; i < test_size; i++){
            int randomArrSize = rand() % ARRAY_TEST_RANGE + ARRAY_RANGE_FLOOR;
            test_cases_3_way_quick_sort(randomArrSize);
        }
        cout << "3-way Quick Sort tests completed."<< endl;
*/
        FULCRUM = degree_finder(N_DEGREE);
         cout << "Loading test cases for Hybrid sort. Please wait." << endl;
        for(int i = 0; i < test_size; i++){
            int randomArrSize = rand() % ARRAY_TEST_RANGE + ARRAY_RANGE_FLOOR;
            test_cases_hybrid_sort(randomArrSize);
        }
        cout << "Hybrid Sort tests completed."<< endl;
        
        cout << "Loading test cases for modified bucket sort. Please wait." << endl;
        for(int i = 0; i < test_size; i++){
            int randomArrSize = rand() % ARRAY_TEST_RANGE + ARRAY_RANGE_FLOOR;
            test_cases_modified_bucket_sort(randomArrSize);
        }
        cout << "Modified bucket Sort tests completed. "<< endl;
        /*
        // *****************TESTS FOR CUDI SORT***************************
        cout << "Loading test cases for cudi sort. Please wait." << endl;
        for(int i = 0; i < test_size; i++){
          int randomArrSize = rand() % ARRAY_TEST_RANGE + ARRAY_RANGE_FLOOR;
          test_cases_cudi_sort(randomArrSize);
        }
        cout << "Cudi Sort tests completed."<< endl;
        cout << endl;
        */
        N_DEGREE += 25;
      }
      cout <<  "\n PROGRAM END" << endl;
      

    return 0;
}


void generateTestArray(int *array, int size, int percent){
   int swaps = 0;
  if(percent == 0)
  {
    swaps = size;
    swaps = swaps/2;
  }
  else
  {
    swaps = (1-(percent/100)) * size;   //number of swaps desired based on the percent of sortedness
    swaps = swaps/2;                        //we make two swaps during each iterations such that swaps needs to be halfed
  }       
  
  for(int i  = 0; i < size; i ++){        //filling array with sorted values
    array[i] = i;
  }

  for(int i = 0; i < swaps; i++){
    //two random array elements
    int first = rand() % size;
    int second = rand() % size;
    
    int arrOne = array[first];
    int arrTwo = array[second];

    //swapping the values of the two values
    array[first] = arrTwo;
    array[second] = arrOne;
  }

}

float generateFloat(){
  return (float(rand())/float((RAND_MAX)));
}

float forceLess(float previous){
  float newFloat =  generateFloat();

  while(previous > newFloat){
    newFloat = generateFloat();
  }
  return newFloat;
}

void generateFloatArray(float *array, int size, int percent){
  int swaps = 0;
  if(percent == 0)
  {
    swaps = size;
    swaps = swaps/2;
  }
  else
  {
    swaps = (1-(percent/100)) * size;   //number of swaps desired based on the percent of sortedness
    swaps = swaps/2;                        //we make two swaps during each iterations such that swaps needs to be halfed
  }                      
  
  
    for(int i = 0; i < size; i++){
        array[i] = float(i * pow(10,-5));
    }
    
  
  for(int i = 0; i < swaps; i++){
    //two random array elements
    int first = rand() % (size -1);
    int second = rand() % (size - 1);

    float x,y;
    x = array[first];
    y = array[second];

    array[first] = y;
    array[second] = x;
  }
}

void write_csv(std::string filename, std::vector<std::pair<std::string, std::vector<double>>> dataset){
  // Make a CSV file with one or more columns of integer values
  // Each column of data is represented by the pair <column name, column data>
  //   as std::pair<std::string, std::vector<int>>
  // The dataset is represented as a vector of these columns
  // Note that all columns should be the same size
  
  // Create an output filestream object
  std::ofstream myFile(filename, ios::app);
  
  // Send column names to the stream
  for(int j = 0; j < int(dataset.size()); ++j)
    {
      myFile << dataset.at(j).first;
      if(j != int(dataset.size()) - 1) myFile << ","; // No comma at end of line
    }
  myFile << "\n";
  
  // Send data to the stream
  for(int i = 0; i < int(dataset.at(0).second.size()); ++i)
    {
      for(int j = 0; j < int(dataset.size()); ++j)
        {
          myFile << dataset.at(j).second.at(i);
          if(j != int(dataset.size()) - 1) myFile << ","; // No comma at end of line
        }
      myFile << "\n";
    }
  
  // Close the file
  myFile.close();
}

bool test(string file){
  string fileName  = file; // target csv where outputs will be logged
  
  if (FILE *file = fopen(fileName.c_str(), "r")) {
    fclose(file);
    return true;
  }
  else {
    return false;
  }
}

/**Size 	Ticks 	Seconds 	Memory 	Percent_Sort
*** writes to csv with the following columns of data
*** 1 - Size
*** 2 - Ticks
*** 3 - Seconds
*** 4 - Memory
*** 5 - Percent_Sort
*** 6 - Algorithm: (1 = quick, 2 = insertion, 3 = bucket, 4 = cudi, 5 = 3way quick
6 = hyrbid, 7 = modifbucketsort, 8 = fixed quicksort)
***/
void logFile(string file, bool exists, int arraySize, double clockTicks, double seconds, double memorySize, int algoCategory){

  vector<int> size;
  vector<double> ticks;
  vector<double> secondsVector;
  vector<double> size_double;
  vector<double> memoryVector;
  vector<double> array_degree_sort;
  vector<double> algorithm;


  size.push_back(arraySize);
  size_double.push_back(double(arraySize));
  ticks.push_back(clockTicks);
  secondsVector.push_back(seconds);
  memoryVector.push_back(memorySize);
  array_degree_sort.push_back(N_DEGREE);
  algorithm.push_back(double(algoCategory));

  if(!exists){
    ofstream myFile(file);
    //cout << "File creation successful" << endl;
  }

  std::vector<std::pair<std::string, std::vector<double>>> vals = {{"", size_double}, {"", ticks}, {"", secondsVector}, {"", memoryVector}, {"",array_degree_sort}, {"",algorithm}};
  write_csv(file, vals);

}

/**
* TEST CASE FUNCTION FOR INSERTION SORT
**/
void test_cases_insertion_sort(int size){

  int arrSize = size;         //size of array
  float randArray[arrSize];     //creating empty array
  int category = 2;  //number for algorithm category that will be mapped into the master csv
  
  generateFloatArray(randArray, arrSize, N_DEGREE);
  
  clock_t start, stop;    //stores the clock ticks while running the program
  double T = 0.0;         // number of total ticks
  
  start = clock();        //clock start
  
  insertionSort(randArray, arrSize);   //algorithm function callS
  
  stop = clock();
  T = stop - start;           //number of clock ticks the algorithm took
  
  bool exists = test("master.csv");                 //check if the output file exists

  logFile("master.csv",exists, arrSize, T, T/CLOCKS_PER_SEC, sizeof(randArray),category); //writing to the log file
}



/**
* TEST CASE FUNCTION FOR QUICK SORT
**/
void test_cases_quick_sort(int size){
  int arrSize = size;
  int startIndex = 0;
  int endIndex = arrSize - 1;
  int category = 8;

  float randArray[arrSize]; //creating empty array
  
  generateFloatArray(randArray, arrSize, N_DEGREE);
  
  
  clock_t start, stop;    //stores the clock ticks while running the program
  double T = 0.0;         // number of total ticks
  
  start = clock();        //clock start
  
  quickSort(randArray,startIndex, endIndex);  //algorithm function callS
  
  stop = clock();
  T = stop - start;           //number of clock ticks the algorithm took
  
  
  bool exists = test("master.csv");                 //check if the output file exists
  
  logFile("master.csv",exists, arrSize, T, T/CLOCKS_PER_SEC, sizeof(randArray),category); //writing to the log file
}

/**
* TEST CASE FUNCTION FOR 3WAY QUICK SORT
**/
void test_cases_3_way_quick_sort(int size){
  int arrSize = size;
  int startIndex = 0;
  int endIndex = arrSize - 1;
  int category = 5;

  float randArray[arrSize]; //creating empty array
  
  generateFloatArray(randArray, arrSize, N_DEGREE);
  
  
  clock_t start, stop;    //stores the clock ticks while running the program
  double T = 0.0;         // number of total ticks
  
  start = clock();        //clock start
  
  threeWayQuicksort(randArray,startIndex, endIndex);  //algorithm function callS
  
  stop = clock();
  T = stop - start;           //number of clock ticks the algorithm took
  
  
  bool exists = test("master.csv");                 //check if the output file exists
  
  logFile("master.csv",exists, arrSize, T, T/CLOCKS_PER_SEC, sizeof(randArray),category); //writing to the log file
}

/**
* TEST CASE FUNCTION FOR HYBRID QUICK SORT
**/
void test_cases_hybrid_sort(int size){
  int arrSize = size;
  int startIndex = 0;
  int endIndex = arrSize - 1;
  int category = 6;

  float randArray[arrSize]; //creating empty array
  
  generateFloatArray(randArray, arrSize, N_DEGREE);
  
  
  clock_t start, stop;    //stores the clock ticks while running the program
  double T = 0.0;         // number of total ticks

  start = clock();        //clock start
  
  
  hybridSort(randArray,startIndex, endIndex, FULCRUM);  //algorithm function callS
  
  stop = clock();
  T = stop - start;           //number of clock ticks the algorithm took
  
  
  bool exists = test("master.csv");                 //check if the output file exists
  
  logFile("master.csv",exists, arrSize, T, T/CLOCKS_PER_SEC, sizeof(randArray),category); //writing to the log file
}
/**
* TEST CASE FUNCTION FOR BUCKET SORT
**/
void test_cases_bucket_sort(int size){
  int arrSize = size;      //size of array
  float randArray[arrSize]; //creating empty array
  int category = 3;
  
  generateFloatArray(randArray, arrSize, N_DEGREE);
  //cout << "GENERATED TEST ARRAY" << endl;
  
  clock_t start, stop;    //stores the clock ticks while running the program
  double T = 0.0;         // number of total ticks
  
  start = clock();
  //cout << "CALLING BUCKET SORT FROM TEST CASE FUNCTION" << endl;
  bucketSort(randArray, arrSize); //algorithm function callS
  
  stop = clock();
  T = stop - start;           //number of clock ticks the algorithm took
  //cout << "BUCKET SORT SUCCESSFUL" <<endl;
  
  bool exists = test("master.csv");                 //check if the output file exists
  
  logFile("master.csv",exists, arrSize, T, T/CLOCKS_PER_SEC, sizeof(randArray), category); //writing to the log file
}

/**
* TEST CASE FUNCTION FOR MODIFIED BUCKET SORT
**/
void test_cases_modified_bucket_sort(int size){
  int arrSize = size;      //size of array
  float randArray[arrSize]; //creating empty array
  int category = 7;
  
  generateFloatArray(randArray, arrSize, N_DEGREE);
  //cout << "GENERATED TEST ARRAY" << endl;
  
  clock_t start, stop;    //stores the clock ticks while running the program
  double T = 0.0;         // number of total ticks
  start = clock();
  //cout << "CALLING BUCKET SORT FROM TEST CASE FUNCTION" << endl;
  modifiedBucketSort(randArray, arrSize, FULCRUM); //algorithm function callS
  
  stop = clock();
  T = stop - start;           //number of clock ticks the algorithm took
  //cout << "BUCKET SORT SUCCESSFUL" <<endl;
  
  bool exists = test("master.csv");                 //check if the output file exists
  
  logFile("master.csv",exists, arrSize, T, T/CLOCKS_PER_SEC, sizeof(randArray), category); //writing to the log file
}

void test_cases_cudi_sort(int size){
  int category = 4;           //algorithm category value that will be written into csv

  float randArray[size]; //creating empty array


  generateFloatArray(randArray, size, N_DEGREE);
  
  
  clock_t start, stop;    //stores the clock ticks while running the program
  double T = 0.0;         // number of total ticks
  
  start = clock();        //clock start
  
  cudiSort(randArray, size, FULCRUM_HS, FULCRUM_CS);  //algorithm function callS
  
  stop = clock();
  T = stop - start;           //number of clock ticks the algorithm took 
  
  
  bool exists = test("master.csv");                 //check if the output file exists
  
  logFile("master.csv",exists, size, T, T/CLOCKS_PER_SEC, sizeof(randArray),category); //writing to the log file
}
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
using namespace std; //namespace

int N_DEGREE = 95; // N degree of sortedness for the array 
int NUM_TEST_CASES = 6000; // number of desired test cases 
int ARRAY_TEST_RANGE = 6000;
int ARRAY_RANGE_FLOOR = 1000;

void generateTestArray(int *array, int size, int percent);

float generateFloat();

void generateFloatArray(float *array, int size, int percent);

void write_csv(std::string filename, std::vector<std::pair<std::string, std::vector<double>>> dataset);

bool test(string file);

void logFile(string file, bool exists, int arraySize, double clockTicks, double seconds, double memorySize);

void test_cases_insertion_sort(int size);

void test_cases_quick_sort(int size);

void test_cases_bucket_sort(int size);

int main(){

    srand (time(NULL)); //random seed

    int test_size = NUM_TEST_CASES; // number of test cases to be compeleted

    cout << "Loading test cases for insertion sort. Please wait." << endl;
    for(int i = 0; i < test_size; i++){
        int randomArrSize = rand() % ARRAY_TEST_RANGE + ARRAY_RANGE_FLOOR;
        test_cases_insertion_sort(randomArrSize);
        
    }
    cout << "Insertion sort tests completed." << endl;
    cout << endl;
     
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
    cout << "Bucket Sort tests completed. \n PROGRAM END"<< endl;
    
    return 0;
}


void generateTestArray(int *array, int size, int percent){
  int swaps = (1-(percent/100)) * size;   //number of swaps desired based on the percent of sortedness
  swaps = swaps/2;                        //we make two swaps during each iterations such that swaps needs to be halfed
  
  
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
  int swaps = (1-(percent/100)) * size;   //number of swaps desired based on the percent of sortedness
  swaps =swaps/2;                        //we make two swaps during each iterations such that swaps needs to be halfed
  
  
  for(int i  = 0; i < size; i ++){        //filling array with sorted values
    /*if(i == 0){
      array[i] = generateFloat();
      }
      else{
      //array[i] = forceLess(array[i-1]);
      }*/
    array[i] = generateFloat();
  }
  
  for(int i = 0; i < swaps; i++){
    //two random array elements
    int first = rand() % size;
    int second = rand() % size;
    
    swap(array[first], array[second]);
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
  for(int j = 0; j < dataset.size(); ++j)
    {
      myFile << dataset.at(j).first;
      if(j != dataset.size() - 1) myFile << ","; // No comma at end of line
    }
  myFile << "\n";
  
  // Send data to the stream
  for(int i = 0; i < dataset.at(0).second.size(); ++i)
    {
      for(int j = 0; j < dataset.size(); ++j)
        {
          myFile << dataset.at(j).second.at(i);
          if(j != dataset.size() - 1) myFile << ","; // No comma at end of line
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

void logFile(string file, bool exists, int arraySize, double clockTicks, double seconds, double memorySize){

  vector<int> size;
  vector<double> ticks;
  vector<double> secondsVector;
  vector<double> size_double;
  vector<double> memoryVector;
  vector<double> array_degree_sort;


  size.push_back(arraySize);
  size_double.push_back(double(arraySize));
  ticks.push_back(clockTicks);
  secondsVector.push_back(seconds);
  memoryVector.push_back(memorySize);
  array_degree_sort.push_back(N_DEGREE);

  if(!exists){
    ofstream myFile(file);
    //cout << "File creation successful" << endl;
  }

  std::vector<std::pair<std::string, std::vector<double>>> vals = {{"", size_double}, {"", ticks}, {"", secondsVector}, {"", memoryVector}, {"",array_degree_sort}};
  write_csv(file, vals);

}
void test_cases_insertion_sort(int size){

  int arrSize = size;      //size of array
  int randArray[arrSize]; //creating empty array
  
  generateTestArray(randArray, arrSize, N_DEGREE);
  
  clock_t start, stop;    //stores the clock ticks while running the program
  double T = 0.0;         // number of total ticks
  
  start = clock();        //clock start
  
  insertionSort(randArray, arrSize);   //algorithm function callS
  
  stop = clock();
  T = stop - start;           //number of clock ticks the algorithm took
  
  bool exists = test("insertion_sort_results.csv");                 //check if the output file exists

  logFile("insertion_sort_results.csv",exists, arrSize, T, T/CLOCKS_PER_SEC, sizeof(randArray)); //writing to the log file
}

void test_cases_quick_sort(int size){
  int arrSize = size;
  int startIndex = 0;
  int endIndex = arrSize - 1;

  int randArray[arrSize]; //creating empty array
  
  generateTestArray(randArray, arrSize, N_DEGREE);
  
  
  clock_t start, stop;    //stores the clock ticks while running the program
  double T = 0.0;         // number of total ticks
  
  start = clock();        //clock start
  
  quickSort(randArray,startIndex, endIndex);  //algorithm function callS
  
  stop = clock();
  T = stop - start;           //number of clock ticks the algorithm took
  
  
  bool exists = test("quick_sort_results.csv");                 //check if the output file exists
  
  logFile("quick_sort_results.csv",exists, arrSize, T, T/CLOCKS_PER_SEC, sizeof(randArray)); //writing to the log file
}

void test_cases_bucket_sort(int size){
  int arrSize = size;      //size of array
  float randArray[arrSize]; //creating empty array
  
  generateFloatArray(randArray, arrSize, N_DEGREE);
  //cout << "GENERATED TEST ARRAY" << endl;
  
  clock_t start, stop;    //stores the clock ticks while running the program
  double T = 0.0;         // number of total ticks
  
  //cout << "CALLING BUCKET SORT FROM TEST CASE FUNCTION" << endl;
  bucketSort(randArray, arrSize); //algorithm function callS
  
  stop = clock();
  T = stop - start;           //number of clock ticks the algorithm took
  //cout << "BUCKET SORT SUCCESSFUL" <<endl;
  
  bool exists = test("bucket_sort_results.csv");                 //check if the output file exists
  
  logFile("bucket_sort_results.csv",exists, arrSize, T, T/CLOCKS_PER_SEC, sizeof(randArray)); //writing to the log file
}

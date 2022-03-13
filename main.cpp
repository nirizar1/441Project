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

using namespace std; //namespace


/* Column output formart for results.csv
** Column1: Array Size
** Column2: Clock Ticks
** Column3: Seconds for execution
*/

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





bool test(){
    string fileName  = "results.csv"; // target csv where outputs will be logged

    if (FILE *file = fopen(fileName.c_str(), "r")) {
        fclose(file);
        return true;
    }
    else {
        return false;
    } 
}

void logFile(bool exists, int arraySize, double clockTicks, double seconds){

    vector<int> size;
    vector<double> ticks;
    vector<double> secondsVector;
    vector<double> size_double;


    size.push_back(arraySize);
    size_double.push_back(double(arraySize));
    ticks.push_back(clockTicks);
    secondsVector.push_back(seconds);

    if(!exists){
        ofstream myFile("results.csv");
        //cout << "File creation successful" << endl;
    }
        
    std::vector<std::pair<std::string, std::vector<double>>> vals = {{"", size_double}, {"", ticks}, {"", secondsVector}};
    write_csv("results.csv", vals);
    //cout << "Write successful" << endl;
}

void insertionSort(int array[], int arrSize){
    for (int i = 1; i < arrSize; i++){
        int key = array[i];
        int j = i - 1;
        while ((j >= 0) && (array[j] < key)){
            array[j + 1]  = array[j];
            j -= 1;
        }
        array[j+1] = key;
    }
}


void test_cases(int size){

    int arrSize = size;      //size of array
    int randArray[arrSize]; //creating empty array

    for(int i = 0; i < arrSize; i++){           //assigning random values in array
        randArray[i] = rand()% arrSize;
    }

    clock_t start, stop;    //stores the clock ticks while running the program
    double T = 0.0;         // number of total ticks

    start = clock();        //clock start

    insertionSort(randArray, arrSize);   //algorithm function callS

    stop = clock();
    T = stop - start;           //number of clock ticks the algorithm took

    //cout << "Sorting " << arrSize << " array elements in random array" << " took " << T<< " clock ticks ("<< T/CLOCKS_PER_SEC << " seconds)!" << endl;

    bool exists = test();                 //check if the output file exists

    logFile(exists, arrSize, T, T/CLOCKS_PER_SEC); //writing to the log file
}

int main(){

    srand (time(NULL)); //random seed

    for(int i = 0; i < 1000; i++){
        int randomArrSize = rand() % 100000 + 4000;
        test_cases(randomArrSize);
    }

    cout << "Program end." << endl;
    return 0;
}
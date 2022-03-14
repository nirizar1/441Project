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

void logFile(string file, bool exists, int arraySize, double clockTicks, double seconds){

    vector<int> size;
    vector<double> ticks;
    vector<double> secondsVector;
    vector<double> size_double;


    size.push_back(arraySize);
    size_double.push_back(double(arraySize));
    ticks.push_back(clockTicks);
    secondsVector.push_back(seconds);

    if(!exists){
        ofstream myFile(file);
        //cout << "File creation successful" << endl;
    }
        
    std::vector<std::pair<std::string, std::vector<double>>> vals = {{"", size_double}, {"", ticks}, {"", secondsVector}};
    write_csv(file, vals);
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

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
 
    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void test_cases_insertion_sort(int size){

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

    bool exists = test("insertion_sort_results.csv");                 //check if the output file exists

    logFile("insertion_sort_results.csv",exists, arrSize, T, T/CLOCKS_PER_SEC); //writing to the log file
}

void test_cases_quick_sort(int size){
    int arrSize = size;
    int startIndex = 0;
    int endIndex = arrSize - 1;

    int randArray[arrSize]; //creating empty array

    for(int i = 0; i < arrSize; i++){           //assigning random values in array
        randArray[i] = rand()% arrSize;
    }

    clock_t start, stop;    //stores the clock ticks while running the program
    double T = 0.0;         // number of total ticks

    start = clock();        //clock start

    quickSort(randArray,startIndex, endIndex);  //algorithm function callS

    stop = clock();
    T = stop - start;           //number of clock ticks the algorithm took

    //cout << "Sorting " << arrSize << " array elements in random array" << " took " << T<< " clock ticks ("<< T/CLOCKS_PER_SEC << " seconds)!" << endl;

    bool exists = test("quick_sort_results.csv");                 //check if the output file exists

    logFile("quick_sort_results.csv",exists, arrSize, T, T/CLOCKS_PER_SEC); //writing to the log file
}

int main(){

    srand (time(NULL)); //random seed

    cout << "Loading test cases for insertion sort. Please wait." << endl;
    for(int i = 0; i < 1000; i++){
        int randomArrSize = rand() % 10000 + 3000;
        test_cases_insertion_sort(randomArrSize);
    }
    cout << "Insertion sort tests completed." << endl;
    cout << endl;
    cout << "Loading test cases for quick sort. Please wait." << endl;
    for(int i = 0; i < 1000; i++){
        int randomArrSize = rand() % 10000 + 3000;
        test_cases_quick_sort(randomArrSize);
    }
    cout << "Quick Sort tests completed \n Program end."<< endl;
    return 0;
}
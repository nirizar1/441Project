#include "cudiSort.h"
#include "insertionSort.h"
#include "quickSort.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int FULCRUM_BS = 100;
int FULCRUM_QS = 100;

void cudiSort(float arr[], int n){
    //int score = scoreData(arr,size);


    // Insertion sort for small inputs 
    if(n < FULCRUM_BS){
        insertionSort(arr, n);
    }
    // Modified Bucket Sort for large inputs
    else
    {
      vector<float> b[n];
      for (int i = 0; i < n; i++) {
        int bi = n * arr[i];
        b[bi].push_back(arr[i]);
      }

      for (int i = 0; i < n; i++)
      {
        // Insertion Sort for small buckets
        if(b[i].size() < FULCRUM_QS)
        {
          insertionSort(&b[i][0], b[i].size());
        }
        // 3Way Quick Sort for large buckets
        else
        {
          quickSort(&b[i][0], 0, b[i].size() - 1);
        }
      }
    int index = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < int(b[i].size()); j++)
        arr[index++] = b[i][j];
    }
}


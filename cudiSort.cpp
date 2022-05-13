#include "cudiSort.h"
#include "insertionSort.h"
#include "quickSort.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


void cudiSort(float arr[], int n, int fulcrum_hs, int fulcrum_cs){
    //int score = scoreData(arr,size);


    // Insertion sort for small inputs 
    if(n < fulcrum_cs){
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
          hybridSort(&b[i][0], 0, b[i].size() - 1, fulcrum_hs);
      }
    int index = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < int(b[i].size()); j++)
        arr[index++] = b[i][j];
    }
}


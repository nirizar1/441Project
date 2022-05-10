#include "cudiSort.h"
#include "insertionSort.h"
#include "quickSort.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
/*
int FULCRUM = 100;

void cudiSort(float arr[], int n){
  // 1) Create n empty buckets
  vector<float> b[n];
  
  // 2) Put array elements
  // in different buckets
  for (int i = 0; i < n; i++) {
    int bi = n * arr[i]; // Index in bucket
    b[bi].push_back(arr[i]);
  }
  
  // 3) Sort individual buckets
  for (int i = 0; i < n; i++)
  {
    float *bucket = &b[i][0];
    int bucket_size = b[i].size();
    if(bucket_size <= FULCRUM)
    {
        insertionSort(bucket, bucket_size);
    }
    else
    {
        threeWayQuicksort(bucket, 0, bucket_size);
    }

  }
  // 4) Concatenate all buckets into arr[]
  int index = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < int(b[i].size()); j++)
      arr[index++] = b[i][j];
}
*/

void cudiSort(float arr[], int n){
    //int score = scoreData(arr,size);


    //insertion sort for small inputs 
    if(n < 100){
        insertionSort(arr, n);
    }
    //threeway partition for intermidate size and high sort
    else{
      threeWayQuicksort(arr, 0, n-1);
      /*
        vector<float> b[n];
  
  // 2) Put array elements
  // in different buckets
  for (int i = 0; i < n; i++) {
    int bi = n * arr[i]; // Index in bucket
    b[bi].push_back(arr[i]);
  }
  
  // 3) Sort individual buckets
  for (int i = 0; i < n; i++)
  {
    float *bucket = &b[i][0];
    int bucket_size = b[i].size();
    threeWayQuicksort(bucket, 0, bucket_size - 1);

  }
  // 4) Concatenate all buckets into arr[]
  int index = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < int(b[i].size()); j++)
      arr[index++] = b[i][j];
      */
    }
}


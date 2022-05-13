#include "bucketSort.h"
#include "insertionSort.h"
#include "quickSort.h"
#include <vector>
#include <algorithm>
using namespace std;

void bucketSort(float arr[], int n){
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
    insertionSort(&b[i][0], b[i].size());
 
  // 4) Concatenate all buckets into arr[]
  int index = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < int(b[i].size()); j++)
      arr[index++] = b[i][j];
}

void modifiedBucketSort(float arr[], int n, int fulcrum){
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
    hybridSort(&b[i][0], 0, b[i].size() - 1, fulcrum);
 
  // 4) Concatenate all buckets into arr[]
  int index = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < int(b[i].size()); j++)
      arr[index++] = b[i][j];
}
#include "insertionSort.h"

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



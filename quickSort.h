#ifndef QUICKSORT_H
#define QUICKSORT_H


/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high);

int partition (int arr[], int low, int high);

void swap(int* a, int* b);

#endif

#ifndef QUICKSORT_H
#define QUICKSORT_H



void swap(float* a, float* b);
int partition (float arr[], int low, int high);
void quickSort(float arr[], int low, int high);
int c_partition (float arr[], int low, int high, int cutoff);
void hybridSort(float arr[], int low, int high, int cutoff);
int degree_finder(int degree);

#endif

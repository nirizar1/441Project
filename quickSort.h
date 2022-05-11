#ifndef QUICKSORT_H
#define QUICKSORT_H


void partition(float a[], int l, int r, int& i, int& j);
void threeWayQuicksort(float a[], int l, int r);
void swap(float* a, float* b);
int partition (float arr[], int low, int high);
void quickSort(float arr[], int low, int high);
void hybridSort(float a[], int l, int r, int fulcrum);
#endif

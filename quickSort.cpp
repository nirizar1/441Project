#include "quickSort.h"
#include "insertionSort.h"
#include <iostream>
#include <stdio.h>
using namespace std;
#include <bits/stdc++.h>
 int CUTOFF[4] = {126,117,117,127};
 int CUTOFF_V = 121;
// A utility function to swap two elements
void swap(float* a, float* b)
{
    float t = *a;
    *a = *b;
    *b = t;
}

int c_partition (float arr[], int low, int high, int cutoff)
{
    float pivot = arr[high];// pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
    if((high - low + 1) <= cutoff)
    {
        insertionSort(arr, high - low + 1);
        return -1;
    }
    else
    {
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
    }
    return (i + 1);
}
int partition (float arr[], int low, int high)
{
    float pivot = arr[high];// pivot
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
void quickSort(float arr[], int low, int high)
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



void hybridSort(float arr[], int low, int high, int cutoff)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = c_partition(arr, low, high, cutoff);
        if(pi == -1)
        {
            return;
        }
 
        // Separately sort elements before
        // partition and after partition
        hybridSort(arr, low, pi - 1, cutoff);
        hybridSort(arr, pi + 1, high, cutoff);
    }
}

int degree_finder(int degree)
{
    for(int i = 0; i < 4; i++)
    {
        if(degree == i*25)
        {
            return CUTOFF[i];
        }
    }
    return 122;
}


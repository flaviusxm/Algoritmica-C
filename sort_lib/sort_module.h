#ifndef SORT_MODULE_H
#define SORT_MODULE_H

#ifdef _WIN32
    #define DLL_EXPORT __declspec(dllexport)
#else 
    #define DLL_EXPORT
#endif

// Helpers 
DLL_EXPORT int *generate_random_array(int size, int min, int max);
DLL_EXPORT void print_array(int arr[], int size);

// Sortări
DLL_EXPORT void bubbleSort(void);
DLL_EXPORT void quickSort(void);
DLL_EXPORT void insertionSort(void);
DLL_EXPORT void selectionSort(void);
DLL_EXPORT void mergeSort(void);
DLL_EXPORT void heapSort(void);
DLL_EXPORT void shellSort(void);
DLL_EXPORT void countSort(void);
DLL_EXPORT void radixSort(void);
DLL_EXPORT void bucketSort(void);

#endif
#include "sort_module.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
// general helpers
static int *generate_random_array(int size, int min, int max) {
    if (size <= 0) return NULL;
    int *arr = (int*)malloc(size * sizeof(int));
    if (!arr) return NULL;
    
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (max - min + 1) + min;
    }
    return arr;
}

static void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// general helpers

// sort algos helpers
static void quick_sort_RecursiveCall(int arr[], int low_index, int high_index) {
    if (low_index < high_index) {
        int pivot_value = arr[high_index];
        int partition_index = low_index - 1;
        
        for (int current_index = low_index; current_index < high_index; current_index++) {
            if (arr[current_index] < pivot_value) {
                partition_index++;
                int temp = arr[partition_index];
                arr[partition_index] = arr[current_index];
                arr[current_index] = temp;
            }
        }
        
        int temp = arr[partition_index + 1];
        arr[partition_index + 1] = arr[high_index];
        arr[high_index] = temp;
        
        int final_partition_index = partition_index + 1;
        
        quick_sort_RecursiveCall(arr, low_index, final_partition_index - 1);
        quick_sort_RecursiveCall(arr, final_partition_index + 1, high_index);
    }
}

static void mergeSortRecursive(int arr[], int left_index, int right_index) {
    if (left_index < right_index) {
        int middle_index = left_index + (right_index - left_index) / 2;
        
        mergeSortRecursive(arr, left_index, middle_index);
        mergeSortRecursive(arr, middle_index + 1, right_index);
        
     
        int left_size = middle_index - left_index + 1;
        int right_size = right_index - middle_index;
        
        int *left_array = (int*)malloc(left_size * sizeof(int));
        int *right_array = (int*)malloc(right_size * sizeof(int));
        
        for (int i = 0; i < left_size; i++)
            left_array[i] = arr[left_index + i];
        for (int j = 0; j < right_size; j++)
            right_array[j] = arr[middle_index + 1 + j];
        
        int left_pointer = 0, right_pointer = 0, merge_pointer = left_index;
        
        while (left_pointer < left_size && right_pointer < right_size) {
            if (left_array[left_pointer] <= right_array[right_pointer]) {
                arr[merge_pointer++] = left_array[left_pointer++];
            } else {
                arr[merge_pointer++] = right_array[right_pointer++];
            }
        }
        
        while (left_pointer < left_size) {
            arr[merge_pointer++] = left_array[left_pointer++];
        }
        
        while (right_pointer < right_size) {
            arr[merge_pointer++] = right_array[right_pointer++];
        }
        
        free(left_array);
        free(right_array);
    }
}

static void heapify(int arr[], int heap_size, int root_index) {
    int largest_index = root_index;
    int left_child = 2 * root_index + 1;
    int right_child = 2 * root_index + 2;
    
    if (left_child < heap_size && arr[left_child] > arr[largest_index]) {
        largest_index = left_child;
    }
    
    if (right_child < heap_size && arr[right_child] > arr[largest_index]) {
        largest_index = right_child;
    }
    
    if (largest_index != root_index) {
        int temp_value = arr[root_index];
        arr[root_index] = arr[largest_index];
        arr[largest_index] = temp_value;
        heapify(arr, heap_size, largest_index);
    }
}

static void custom_count_sort_RadixSort(int arr[], int size, int exponent) {
    int *output = (int*)malloc(size * sizeof(int));
    int count[10] = {0};
    
    for (int i = 0; i < size; i++) {
        count[(arr[i] / exponent) % 10]++;
    }
    
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    
    for (int i = size - 1; i >= 0; i--) {
        output[count[(arr[i] / exponent) % 10] - 1] = arr[i];
        count[(arr[i] / exponent) % 10]--;
    }
    
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
    
    free(output);
}
// sort algos helpers


DLL_EXPORT void bubbleSort(void) {
    srand(time(NULL));
    int num_elements, min_val, max_val;
    printf("=== BUBBLE SORT ===\n");
    printf("Introduceti nr. de elemente: ");
    if (scanf("%d", &num_elements) != 1) return;
    printf("Introduceti valoarea minima si maxima: ");
    if (scanf("%d %d", &min_val, &max_val) != 2) return;
    
    int *array = generate_random_array(num_elements, min_val, max_val);
    if (!array) {
        printf("Eroare!\n");
        return;
    }
    
    printf("Vector initial: ");
    print_array(array, num_elements);

    bool was_swapped;
    int current_size = num_elements;
    do {
        was_swapped = false;
        for (int current_index = 0; current_index < current_size - 1; current_index++) {
            if (array[current_index] > array[current_index + 1]) {
                int temporary_value = array[current_index];
                array[current_index] = array[current_index + 1];
                array[current_index + 1] = temporary_value;
                was_swapped = true;
            }
        }
        current_size--;
    } while (was_swapped);
    
    printf("Vector sortat: ");
    print_array(array, num_elements);
    free(array);
}


DLL_EXPORT void quickSort(void) {
    srand(time(NULL));
    int num_elements, min_val, max_val;
    printf("=== QUICK SORT ===\n");
    printf("Introduceti nr. de elemente: ");
    if (scanf("%d", &num_elements) != 1) return;
    printf("Introduceti valoarea minima si maxima: ");
    if (scanf("%d %d", &min_val, &max_val) != 2) return;

    int *array = generate_random_array(num_elements, min_val, max_val);
    if (!array) {
        printf("Eroare!\n");
        return;
    }

    printf("Vector initial: ");
    print_array(array, num_elements);
    
    quick_sort_RecursiveCall(array, 0, num_elements - 1);

    printf("Vector sortat: ");
    print_array(array, num_elements);
    free(array);
}

DLL_EXPORT void insertionSort(void) {
    srand(time(NULL));
    int num_elements, min_val, max_val;
    printf("=== INSERTION SORT ===\n");
    printf("Introduceti nr. de elemente: ");
    if (scanf("%d", &num_elements) != 1) return;
    printf("Introduceti valoarea minima si maxima: ");
    if (scanf("%d %d", &min_val, &max_val) != 2) return;
    
    int *array = generate_random_array(num_elements, min_val, max_val);
    if (!array) {
        printf("Eroare!\n");
        return;
    }
    
    printf("Vector initial: ");
    print_array(array, num_elements);

    for (int current_position = 1; current_position < num_elements; current_position++) {
        int key_element = array[current_position];
        int previous_position = current_position - 1;
        
        while (previous_position >= 0 && array[previous_position] > key_element) {
            array[previous_position + 1] = array[previous_position];
            previous_position--;
        }
        array[previous_position + 1] = key_element;
    }

    printf("Vector sortat: ");
    print_array(array, num_elements);
    free(array);
}


DLL_EXPORT void selectionSort(void) {
    srand(time(NULL));
    int num_elements, min_val, max_val;
    printf("=== SELECTION SORT ===\n");
    printf("Introduceti nr. de elemente: ");
    if (scanf("%d", &num_elements) != 1) return;
    printf("Introduceti valoarea minima si maxima: ");
    if (scanf("%d %d", &min_val, &max_val) != 2) return;

    int *array = generate_random_array(num_elements, min_val, max_val);
    if (!array) {
        printf("Eroare!\n");
        return;
    }
    
    printf("Vector initial: ");
    print_array(array, num_elements);

    for (int current_index = 0; current_index < num_elements - 1; current_index++) {
        int min_index = current_index;
        
        for (int search_index = current_index + 1; search_index < num_elements; search_index++) {
            if (array[search_index] < array[min_index]) {
                min_index = search_index;
            }
        }
        
        int temporary = array[current_index];
        array[current_index] = array[min_index];
        array[min_index] = temporary;
    }
    
    printf("Vector sortat: ");
    print_array(array, num_elements);
    free(array);
}

DLL_EXPORT void mergeSort(void) {
    srand(time(NULL));
    int num_elements, min_val, max_val;
    printf("=== MERGE SORT ===\n");
    printf("Introduceti nr. de elemente: ");
    if (scanf("%d", &num_elements) != 1) return;
    printf("Introduceti valoarea minima si maxima: ");
    if (scanf("%d %d", &min_val, &max_val) != 2) return;

    int *array = generate_random_array(num_elements, min_val, max_val);
    if (!array) {
        printf("Eroare!\n");
        return;
    }
    
    printf("Vector initial: ");
    print_array(array, num_elements);
    
    mergeSortRecursive(array, 0, num_elements - 1);
    
    printf("Vector sortat: ");
    print_array(array, num_elements);
    free(array);
}


DLL_EXPORT void countSort(void) {
    srand(time(NULL));
    int num_elements, min_val, max_val;
    printf("=== COUNTING SORT ===\n");
    printf("Introduceti nr. de elemente: ");
    if (scanf("%d", &num_elements) != 1) return;
    printf("Introduceti valoarea minima si maxima: ");
    if (scanf("%d %d", &min_val, &max_val) != 2) return;

    int *array = generate_random_array(num_elements, min_val, max_val);
    if (!array) {
        printf("Eroare!\n");
        return;
    }
    
    printf("Vector initial: ");
    print_array(array, num_elements);

    int max_value = array[0];
    for (int i = 1; i < num_elements; i++) {
        if (array[i] > max_value) {
            max_value = array[i];
        }
    }
    
    int *count_array = (int*)calloc(max_value + 1, sizeof(int));
    int *output_array = (int*)malloc(num_elements * sizeof(int));
    
    for (int i = 0; i < num_elements; i++) {
        count_array[array[i]]++;
    }
    
    for (int i = 1; i <= max_value; i++) {
        count_array[i] += count_array[i - 1];
    }
    
    for (int i = num_elements - 1; i >= 0; i--) {
        output_array[count_array[array[i]] - 1] = array[i];
        count_array[array[i]]--;
    }
    
    for (int i = 0; i < num_elements; i++) {
        array[i] = output_array[i];
    }
    
    printf("Vector sortat: ");
    print_array(array, num_elements);
    
    free(array);
    free(count_array);
    free(output_array);
}

DLL_EXPORT void heapSort(void) {
    srand(time(NULL));
    int num_elements, min_val, max_val;
    printf("=== HEAP SORT ===\n");
    printf("Introduceti nr. de elemente: ");
    if (scanf("%d", &num_elements) != 1) return;
    printf("Introduceti valoarea minima si maxima: ");
    if (scanf("%d %d", &min_val, &max_val) != 2) return;

    int *array = generate_random_array(num_elements, min_val, max_val);
    if (!array) {
        printf("Eroare!\n");
        return;
    }

    printf("Vector initial: ");
    print_array(array, num_elements);
    
    for (int i = num_elements / 2 - 1; i >= 0; i--) {
        heapify(array, num_elements, i);
    }
    
    for (int i = num_elements - 1; i > 0; i--) {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        heapify(array, i, 0);
    }
    
    printf("Vector sortat: ");
    print_array(array, num_elements);
    free(array);
}


DLL_EXPORT void radixSort(void) {
    srand(time(NULL));
    int num_elements, min_val, max_val;
    printf("=== RADIX SORT ===\n");
    printf("Introduceti nr. de elemente: ");
    if (scanf("%d", &num_elements) != 1) return;
    printf("Introduceti valoarea minima si maxima: ");
    if (scanf("%d %d", &min_val, &max_val) != 2) return;

    int *array = generate_random_array(num_elements, min_val, max_val);
    if (!array) {
        printf("Eroare!\n");
        free(array);
        return;
    }

    printf("Vector initial: ");
    print_array(array, num_elements);

    int max_value = array[0];
    for (int i = 1; i < num_elements; i++) {
        if (array[i] > max_value) {
            max_value = array[i];
        }
    }
    
    for (int exponent = 1; max_value / exponent > 0; exponent *= 10) {
        custom_count_sort_RadixSort(array, num_elements, exponent);
    }

    printf("Vector sortat: ");
    print_array(array, num_elements);
    free(array);
}


DLL_EXPORT void bucketSort(void) {
    srand(time(NULL));
    int num_elements, min_val, max_val;
    printf("=== BUCKET SORT ===\n");
    printf("Introduceti nr. de elemente: ");
    if (scanf("%d", &num_elements) != 1) return;
    printf("Introduceti valoarea minima si maxima: ");
    if (scanf("%d %d", &min_val, &max_val) != 2) return;
    
    int *array = generate_random_array(num_elements, min_val, max_val);
    if (!array) {
        printf("Eroare!\n");
        free(array);
        return;
    }
    
    printf("Vector initial: ");
    print_array(array, num_elements);

    int max_value = array[0];
    for (int i = 1; i < num_elements; i++) {
        if (array[i] > max_value) {
            max_value = array[i];
        }
    }

    int num_buckets = 10;
    int **buckets = (int**)malloc(num_buckets * sizeof(int*));
    int *bucket_sizes = (int*)calloc(num_buckets, sizeof(int));
    int *bucket_capacities = (int*)malloc(num_buckets * sizeof(int));
    
    for (int i = 0; i < num_buckets; i++) {
        bucket_capacities[i] = 10;
        buckets[i] = (int*)malloc(bucket_capacities[i] * sizeof(int));
    }
    
    for (int i = 0; i < num_elements; i++) {
        int bucket_index = (array[i] * num_buckets) / (max_value + 1);
        
        if (bucket_sizes[bucket_index] >= bucket_capacities[bucket_index]) {
            bucket_capacities[bucket_index] *= 2;
            buckets[bucket_index] = (int*)realloc(buckets[bucket_index], 
                                                bucket_capacities[bucket_index] * sizeof(int));
        }
        
        buckets[bucket_index][bucket_sizes[bucket_index]++] = array[i];
    }
    
    for (int i = 0; i < num_buckets; i++) {
        for (int j = 1; j < bucket_sizes[i]; j++) {
            int key = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = key;
        }
    }
    
    int index = 0;
    for (int i = 0; i < num_buckets; i++) {
        for (int j = 0; j < bucket_sizes[i]; j++) {
            array[index++] = buckets[i][j];
        }
        free(buckets[i]);
    }
    
    free(buckets);
    free(bucket_sizes);
    free(bucket_capacities);

    printf("Vector sortat: ");
    print_array(array, num_elements);
    free(array);
}


DLL_EXPORT void shellSort(void) {
    srand(time(NULL));
    int num_elements, min_val, max_val;
    printf("=== SHELL SORT ===\n");
    printf("Introduceti nr. de elemente: ");
    if (scanf("%d", &num_elements) != 1) return;
    printf("Introduceti valoarea minima si maxima: ");
    if (scanf("%d %d", &min_val, &max_val) != 2) return;
    
    int *array = generate_random_array(num_elements, min_val, max_val);
    if (!array) {
        printf("Eroare!\n");
        free(array);
        return;
    }

    printf("Vector initial: ");
    print_array(array, num_elements);

    for (int gap = num_elements / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < num_elements; i++) {
            int temp = array[i];
            int j;
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
    }

    printf("Vector sortat: ");
    print_array(array, num_elements);
    free(array);
}
DLL_EXPORT void gnomeSort(void) {
    srand(time(NULL));
    int num_elements, min_val, max_val;
    printf("=== GNOME SORT ===\n");
    printf("Introduceti nr. de elemente: ");
    if (scanf("%d", &num_elements) != 1) return;
    printf("Introduceti valoarea minima si maxima: ");
    if (scanf("%d %d", &min_val, &max_val) != 2) return;
    int *array = generate_random_array(num_elements, min_val, max_val);
    if (!array) {printf("Eroare!\n");free(array);return;}
    printf("Vector initial: ");
    print_array(array, num_elements);

    int index=0;
    while (index < num_elements) {
        if ( index==0 || array[index] >= array[index-1]) {
            index++;
        }else {
            int temp=array[index];
            array[index] = array[index-1];
            array[index-1] = temp;
            index--;
        }
    }
    printf("Vector sortat: ");
    print_array(array, num_elements);
    free(array);
}

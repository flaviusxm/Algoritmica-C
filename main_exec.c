#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>
#include <windows.h>
#include <psapi.h>

//dynamic libs
static HMODULE hSortDLL;
static HMODULE hInfoDLL;

typedef void (*proc_void)(void);

// sort function pointers (from sort_module.dll)
static proc_void bubbleSort_ptr = NULL;
static proc_void quickSort_ptr = NULL;
static proc_void insertionSort_ptr = NULL;
static proc_void selectionSort_ptr = NULL;
static proc_void mergeSort_ptr = NULL;
static proc_void heapSort_ptr = NULL;
static proc_void shellSort_ptr = NULL;
static proc_void countSort_ptr = NULL;
static proc_void radixSort_ptr = NULL;
static proc_void bucketSort_ptr = NULL;

// search function pointers (from search_module.dll)
static proc_void dfs_ptr = NULL;
static proc_void bfs_ptr = NULL;

// info function pointers (from info_module.dll)
static proc_void info_bubble_sort_ptr = NULL;
static proc_void info_insertion_sort_ptr = NULL;
static proc_void info_quick_sort_ptr = NULL;
static proc_void info_bucket_sort_ptr = NULL;
static proc_void info_selection_sort_ptr = NULL;
static proc_void info_merge_sort_ptr = NULL;
static proc_void info_heap_sort_ptr = NULL;
static proc_void info_radix_sort_ptr = NULL;
static proc_void info_shell_sort_ptr = NULL;
static proc_void info_count_sort_ptr = NULL;

// Forward declarations for menus
static void sort_algo_menu(void);
static void search_algo_menu(void);
static void more_info_menu(void);
static void more_info_sort_algorithms(void);
static void more_info_search_algorithms(void);

// Benchmark result
typedef struct {
    double execution_time;  // seconds
    size_t memory_used;     // KB
} BenchmarkResult;

static BenchmarkResult run_benchmarks(void (*f)(void)){
    BenchmarkResult result;
    result.execution_time = 0.0;
    result.memory_used = 0;

    clock_t start_time = clock();
    f();
    clock_t end_time = clock();

    result.execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    PROCESS_MEMORY_COUNTERS pmc;
    if (GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc))) {
        result.memory_used = pmc.WorkingSetSize / 1024; // KB
    } else {
        result.memory_used = 0;
    }
    return result;
}

// Menus and helpers
enum SortType {
    SORT_BUBBLE = 1,
    SORT_QUICK,
    SORT_INSERTION,
    SORT_SELECTION,
    SORT_MERGE,
    SORT_HEAP,
    SORT_SHELL,
    SORT_COUNT,
    SORT_RADIX,
    SORT_BUCKET
};

enum SearchType {
    SEARCH_DFS = 1,
    SEARCH_BFS,
    SEARCH_DIJKSTRA,
    SEARCH_ASTAR,
    SEARCH_JUMP
};

static void sort_algo_menu(void){
    int int_input;
    printf("\n Sortari \n");
    printf("1. Bubble Sort\n");
    printf("2. Quick Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Selection Sort\n");
    printf("5. Merge Sort\n");
    printf("6. Heap Sort\n");
    printf("7. Shell Sort\n");
    printf("8. Counting Sort\n");
    printf("9. Radix Sort\n");
    printf("10. Bucket Sort\n");
    printf("Alege :");

    if (scanf("%d", &int_input) != 1) {
        printf("Input invalid\n");
        return;
    }

    bool executed = false;
    BenchmarkResult results = {0};

    switch(int_input){
        case SORT_BUBBLE:{  
            if (!bubbleSort_ptr) { printf("Functia bubbleSort indisponibila.\n"); return; }
            results = run_benchmarks(bubbleSort_ptr);
            executed = true;
            break;
        }
        case SORT_QUICK:{
            if (!quickSort_ptr) { printf("Functia quickSort indisponibila.\n"); return; }
            results = run_benchmarks(quickSort_ptr);
            executed = true;
            break;
        }
        case SORT_INSERTION: {
            if (!insertionSort_ptr) { printf("Functia insertionSort indisponibila.\n"); return; }
            results = run_benchmarks(insertionSort_ptr);
            executed = true;
            break;
        }
        case SORT_SELECTION: {
            if (!selectionSort_ptr) { printf("Functia selectionSort indisponibila.\n"); return; }
            results = run_benchmarks(selectionSort_ptr);
            executed = true;
            break;
        }
        case SORT_MERGE: {
            if (!mergeSort_ptr) { printf("Functia mergeSort indisponibila.\n"); return; }
            results = run_benchmarks(mergeSort_ptr);
            executed = true;
            break;
        }
        case SORT_HEAP:{ 
            if (!heapSort_ptr) { printf("Functia heapSort indisponibila.\n"); return; }
            results = run_benchmarks(heapSort_ptr);
            executed = true;
            break;
        }
        case SORT_SHELL:{ 
            if (!shellSort_ptr) { printf("Functia shellSort indisponibila.\n"); return; }
            results = run_benchmarks(shellSort_ptr);
            executed = true;
            break;
        }
        case SORT_COUNT: {
            if (!countSort_ptr) { printf("Functia countSort indisponibila.\n"); return; }
            results = run_benchmarks(countSort_ptr);
            executed = true;
            break;
        }
        case SORT_RADIX: {
            if (!radixSort_ptr) { printf("Functia radixSort indisponibila.\n"); return; }
            results = run_benchmarks(radixSort_ptr);
            executed = true;
            break;
        }
        case SORT_BUCKET:{
            if (!bucketSort_ptr) { printf("Functia bucketSort indisponibila.\n"); return; }
            results = run_benchmarks(bucketSort_ptr);
            executed = true;
            break;
        }
        default:
            printf("Optiune invalida\n\n");
            break;
    }

    if (executed) {
        printf("Timpul de executie -> %.7f secunde\n", results.execution_time);
        printf("Memorie folosita -> %lu KB\n", (unsigned long)results.memory_used);
    }
}

static void to_lowercase_transform(char* string){
    for (int i = 0; string[i]; i++){
        string[i] = (char)tolower((unsigned char)string[i]);
    }
}

static void search_algo_menu(void){
    int int_input;
    printf("\n Cautari \n");
    printf("1. DFS\n");
    printf("2. BFS\n");
    printf("3. Dijkstra\n");
    printf("4. A* search\n");
    printf("5. Jump search\n");
    printf("Alege :");

    if (scanf("%d", &int_input) != 1) {
        printf("Input invalid\n");
        return;
    }

    bool executed = false;
    BenchmarkResult results = {0};

    switch(int_input){
        case SEARCH_DFS:{
            if (!dfs_ptr) { printf("Functia dfs indisponibila.\n"); return; }
            results = run_benchmarks(dfs_ptr);
            executed = true;
            break;
        }
        case SEARCH_BFS:{
            if (!bfs_ptr) { printf("Functia bfs indisponibila.\n"); return; }
            results = run_benchmarks(bfs_ptr);
            executed = true;
            break;
        }
        case SEARCH_DIJKSTRA:{
            printf("Dijkstra nu este implementat.\n");
            break;
        }
        case SEARCH_ASTAR:{
            printf("A* search nu este implementat.\n");
            break;
        }
        case SEARCH_JUMP:{  
            printf("Jump search nu este implementat.\n");
            break;
        }
        default: 
            printf("Optiune invalida\n");
            break;
    }

    if (executed) {
        printf("Timpul de executie -> %.7f secunde\n", results.execution_time);
        printf("Memorie folosita -> %lu KB\n",(unsigned long) results.memory_used);
    }
}

static void more_info_menu(void){
    char *input = (char*)malloc(15 * sizeof(char));
    if (!input) return;

    do {
        printf("Explicatii mecanisme sortari/cautari :\n1. Algoritmi Sortari\n2. Algoritmi Cautari\nIesire (q/Q)\n\n");
        if (scanf("%14s", input) != 1) break;

        if (strcmp(input, "1") == 0) {
            more_info_sort_algorithms();
        } else if (strcmp(input, "2") == 0) {
            more_info_search_algorithms();
        } else if (strcmp(input, "q") == 0 || strcmp(input, "Q") == 0) {
            printf("Ai iesit din meniul de informatii!\n");
        } else {
            printf("Optiune invalida\n");
        }
    } while (strcmp(input, "q") != 0 && strcmp(input, "Q") != 0);

    free(input);
    return;
}

static void more_info_sort_algorithms(void){
    int int_input;
    do {
        printf("\n Explicatii mecanisme sortare in detaliu\n");
        printf("1. Bubble Sort\n");
        printf("2. Quick Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Selection Sort\n");
        printf("5. Merge Sort\n");
        printf("6. Heap Sort\n");
        printf("7. Shell Sort\n");
        printf("8. Counting Sort\n");
        printf("9. Radix Sort\n");
        printf("10. Bucket Sort\n");
        printf("Alege :");
        if (scanf("%d", &int_input) != 1) break;

        switch(int_input){
            case SORT_BUBBLE: if (info_bubble_sort_ptr) info_bubble_sort_ptr(); else printf("Functia info_bubble_sort indisponibila.\n"); break;
            case SORT_QUICK: if (info_quick_sort_ptr) info_quick_sort_ptr(); else printf("Functia info_quick_sort indisponibila.\n"); break;
            case SORT_INSERTION: if (info_insertion_sort_ptr) info_insertion_sort_ptr(); else printf("Functia info_insertion_sort indisponibila.\n"); break;
            case SORT_SELECTION: if (info_selection_sort_ptr) info_selection_sort_ptr(); else printf("Functia info_selection_sort indisponibila.\n"); break;
            case SORT_MERGE: if (info_merge_sort_ptr) info_merge_sort_ptr(); else printf("Functia info_merge_sort indisponibila.\n"); break;
            case SORT_HEAP: if (info_heap_sort_ptr) info_heap_sort_ptr(); else printf("Functia info_heap_sort indisponibila.\n"); break;
            case SORT_SHELL: if (info_shell_sort_ptr) info_shell_sort_ptr(); else printf("Functia info_shell_sort indisponibila.\n"); break;
            case SORT_COUNT: if (info_count_sort_ptr) info_count_sort_ptr(); else printf("Functia info_count_sort indisponibila.\n"); break;
            case SORT_RADIX: if (info_radix_sort_ptr) info_radix_sort_ptr(); else printf("Functia info_radix_sort indisponibila.\n"); break;
            case SORT_BUCKET: if (info_bucket_sort_ptr) info_bucket_sort_ptr(); else printf("Functia info_bucket_sort indisponibila.\n"); break;
            default: printf("Optiune invalida\n\n"); break;
        }
    } while (int_input >= 1 && int_input <= 10);
}

static void more_info_search_algorithms(void){
    printf("Functia de informatii pentru cautari nu este implementata inca.\n");
}

int main(void){
    // Load DLLs available in current directory
    hSortDLL = LoadLibrary("sort_module.dll");
    if (!hSortDLL) {
        printf("Eroare la incarcare sort_module.dll\n");
        // We can still run other parts if needed
    }
   
    hInfoDLL = LoadLibrary("info_module.dll");
    if (!hInfoDLL) {
        printf("Eroare la incarcare info_module.dll (optional)\n");
    }

    // Resolve sort functions
    if (hSortDLL) {
        bubbleSort_ptr     = (proc_void)GetProcAddress(hSortDLL, "bubbleSort");
        quickSort_ptr      = (proc_void)GetProcAddress(hSortDLL, "quickSort");
        insertionSort_ptr  = (proc_void)GetProcAddress(hSortDLL, "insertionSort");
        selectionSort_ptr  = (proc_void)GetProcAddress(hSortDLL, "selectionSort");
        mergeSort_ptr      = (proc_void)GetProcAddress(hSortDLL, "mergeSort");
        heapSort_ptr       = (proc_void)GetProcAddress(hSortDLL, "heapSort");
        shellSort_ptr      = (proc_void)GetProcAddress(hSortDLL, "shellSort");
        countSort_ptr      = (proc_void)GetProcAddress(hSortDLL, "countSort");
        radixSort_ptr      = (proc_void)GetProcAddress(hSortDLL, "radixSort");
        bucketSort_ptr     = (proc_void)GetProcAddress(hSortDLL, "bucketSort");
    }

    

    // Resolve info functions (optional)
    if (hInfoDLL) {
        info_bubble_sort_ptr    = (proc_void)GetProcAddress(hInfoDLL, "info_bubble_sort");
        info_insertion_sort_ptr = (proc_void)GetProcAddress(hInfoDLL, "info_insertion_sort");
        info_quick_sort_ptr     = (proc_void)GetProcAddress(hInfoDLL, "info_quick_sort");
        info_bucket_sort_ptr    = (proc_void)GetProcAddress(hInfoDLL, "info_bucket_sort");
        info_selection_sort_ptr = (proc_void)GetProcAddress(hInfoDLL, "info_selection_sort");
        info_merge_sort_ptr     = (proc_void)GetProcAddress(hInfoDLL, "info_merge_sort");
        info_heap_sort_ptr      = (proc_void)GetProcAddress(hInfoDLL, "info_heap_sort");
        info_radix_sort_ptr     = (proc_void)GetProcAddress(hInfoDLL, "info_radix_sort");
        info_shell_sort_ptr     = (proc_void)GetProcAddress(hInfoDLL, "info_shell_sort");
        info_count_sort_ptr     = (proc_void)GetProcAddress(hInfoDLL, "info_count_sort");
    }

    char *input = (char*)malloc(15 * sizeof(char));
    if (!input) return 1;

    do {
        printf("Alege :\n1. Algoritmi Sortari\n2. Algoritmi Cautari\n3. Informatii algoritmi\nIesire (q/Q)\n\n");
        if (scanf("%14s", input) != 1) break;

        if (strcmp(input, "1") == 0) {
            sort_algo_menu();
        } else if (strcmp(input, "2") == 0) {
            search_algo_menu();
        } else if (strcmp(input, "3") == 0) {
            more_info_menu();
        } else if (strcmp(input, "q") == 0 || strcmp(input, "Q") == 0) {
            printf("Ai iesit din program!\n");
        } else {
            printf("Optiune invalida\n");
        }
    } while (strcmp(input, "q") != 0 && strcmp(input, "Q") != 0);

    free(input);

    if (hSortDLL) FreeLibrary(hSortDLL);
   
    if (hInfoDLL) FreeLibrary(hInfoDLL);

    return 0;
}

#include "search_module.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

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


static int compare_ints(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}


static void dfs_search_utility(int node, bool visited[], int **matrix, int n) {
    visited[node] = true;
    printf("%d ", node); 
    for (int i = 0; i < n; i++) {
        if (matrix[node][i] != 0 && !visited[i]) {
            dfs_search_utility(i, visited, matrix, n);
        }
    }
}

static void bfs_search_utility(int start, int **matrix, int n) {
    bool *visited = (bool*)calloc(n, sizeof(bool));
    int *queue = (int*)calloc(n, sizeof(int));
    if (!visited || !queue) {
        free(visited);
        free(queue);
        return;
    }
    
    int front = 0, back = 0;
    
    visited[start] = true;
    queue[back++] = start;

    while (front < back) {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 0; i < n; i++) {
            if (matrix[node][i] != 0 && !visited[i]) {
                visited[i] = true;
                queue[back++] = i;
            }
        }
    }
    free(queue);
    free(visited);
}


static int linear_search_logic(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

static int binary_search_logic(int arr[], int size, int target) {
    int l = 0;
    int r = size - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

static int jump_search_logic(int arr[], int size, int target) {
    int step = (int)sqrt(size);
    int prev = 0;
    while (arr[(step < size ? step : size) - 1] < target) {
        prev = step;
        step += (int)sqrt(size);
        if (prev >= size) return -1;
    }
    for (int i = prev; i < step && i < size; i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

static int interpolation_search_logic(int arr[], int size, int target) {
    int l = 0;
    int r = size - 1;
    while (l <= r && target >= arr[l] && target <= arr[r]) {
        if (l == r) {
            return (arr[l] == target) ? l : -1;
        }

        int pos = l + (int)(((double)(r - l) / (arr[r] - arr[l])) * (target - arr[l]));
        
        if (arr[pos] == target) return pos;
        if (arr[pos] < target) l = pos + 1;
        else r = pos - 1;
    }
    return -1;
}


static int binary_search_utility_range(int arr[], int l, int r, int target) {
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

static int exponential_search_logic(int arr[], int size, int target) {
    if (size == 0) return -1;
    if (arr[0] == target) return 0;

    int i = 1;
    while (i < size && arr[i] <= target) {
        i = i * 2;
    }
    
    int l = i / 2;
    int r = (i < size) ? i : size - 1;
    return binary_search_utility_range(arr, l, r, target);
}


DLL_EXPORT void dfs_search(void) {
    srand((unsigned int)time(NULL));
    int n, start_node;
    printf("=== DFS SEARCH ===\n");
    printf("Introduceti nr. de noduri (max 20 recomandat pt demo): ");
    if (scanf("%d", &n) != 1 || n <= 0) return;

    int **matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)calloc(n, sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (rand() % 100 < 30) {
                matrix[i][j] = matrix[j][i] = 1;
            }
        }
    }
    
    printf("Matrice de adiacenta generata:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%d ", matrix[i][j]);
        printf("\n");
    }

    printf("Nod de start (0 - %d): ", n - 1);
    if (scanf("%d", &start_node) != 1 || start_node < 0 || start_node >= n) {
        printf("Nod invalid.\n");
        for(int i=0; i<n; i++) free(matrix[i]);
        free(matrix);
        return;
    }

    printf("Parcurgere DFS: ");
    bool *visited = (bool*)calloc(n, sizeof(bool));
    if (visited) {
        dfs_search_utility(start_node, visited, matrix, n);
        free(visited);
    }
    printf("\n");

    for(int i=0; i<n; i++) free(matrix[i]);
    free(matrix);
}


DLL_EXPORT void bfs_search(void) {
    srand((unsigned int)time(NULL));
    int n, start_node;
    printf("=== BFS SEARCH ===\n");
    printf("Introduceti nr. de noduri: ");
    if (scanf("%d", &n) != 1 || n <= 0) return;
    
    int **matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) matrix[i] = (int*)calloc(n, sizeof(int));
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (rand() % 100 < 30) matrix[i][j] = matrix[j][i] = 1;
        }
    }
    
    printf("Matrice de adiacenta:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%d ", matrix[i][j]);
        printf("\n");
    }

    printf("Nod de start: ");
    if (scanf("%d", &start_node) != 1 || start_node < 0 || start_node >= n) {
        printf("Nod invalid.\n");
        for(int i=0; i<n; i++) free(matrix[i]);
        free(matrix);
        return;
    }

    printf("Parcurgere BFS: ");
    bfs_search_utility(start_node, matrix, n);
    printf("\n");

    for(int i=0; i<n; i++) free(matrix[i]);
    free(matrix);
}



static void run_search_algo(const char* name, int (*algo)(int[], int, int), bool requires_sorted) {
    srand((unsigned int)time(NULL));
    int num_elements, min_val, max_val, target;
    
    printf("=== %s ===\n", name);
    printf("Introduceti nr. de elemente: ");
    if (scanf("%d", &num_elements) != 1 || num_elements <= 0) return;
    
    printf("Introduceti valoarea minima si maxima: ");
    if (scanf("%d %d", &min_val, &max_val) != 2) return;
    
    int *array = generate_random_array(num_elements, min_val, max_val);
    if (!array) {
        printf("Eroare alocare memorie.\n");
        return;
    }

    if (requires_sorted) {
        qsort(array, num_elements, sizeof(int), compare_ints);
        printf("Vector generat si SORTAT: ");
    } else {
        printf("Vector generat: ");
    }
    print_array(array, num_elements);

    printf("Introduceti valoarea cautata: ");
    if (scanf("%d", &target) != 1) {
        free(array);
        return;
    }

    int result = algo(array, num_elements, target);
    if (result != -1) {
        printf("Elementul %d gasit la indexul %d.\n", target, result);
    } else {
        printf("Elementul %d NU a fost gasit.\n", target);
    }

    free(array);
}

DLL_EXPORT void linear_search(void) {
    run_search_algo("LINEAR SEARCH", linear_search_logic, false);
}

DLL_EXPORT void binary_search(void) {
    run_search_algo("BINARY SEARCH", binary_search_logic, true);
}

DLL_EXPORT void jump_search(void) {
    run_search_algo("JUMP SEARCH", jump_search_logic, true);
}

DLL_EXPORT void interpolation_search(void) {
    run_search_algo("INTERPOLATION SEARCH", interpolation_search_logic, true);
}

DLL_EXPORT void exponential_search(void) {
    run_search_algo("EXPONENTIAL SEARCH", exponential_search_logic, true);
}

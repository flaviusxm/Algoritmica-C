#include<stdio.h>
#include<malloc.h>
const void bubbleSort(){
    int nr_elem;
    int *arr=(int*)malloc(nr_elem*sizeof(int));
    printf("Introduceti nr. de elemente: \n\n");
    scanf("%d",&nr_elem);
    if( nr_elem<0 || !arr){
        printf("Eroare!");
        return;
    }
    for(int i=0;i<nr_elem;i++){
        printf("array[%d]= ",i);
        scanf("%d",arr[i]);
    }

    do {
bool_checker=false;
for(int i=0;i<nr_elem-1;i++){
    if(arr[i]>arr[i+1]){
        int temp=arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=temp;
        bool_checker=true;
    }
}
}while(bool_checker);

printf("Vector sortat: ");
for(int i=0;i<nr_elem;i++)printf("%d ",arr[i]);
printf("\n");
    free(arr);
    arr=NULL;
}
const void insertionSort(){
    int nr_elem;
    printf("Introduceti nr. de elemente: \n\n");
    scanf("%d",&nr_elem);
    if(nr_elem<0||!arr){
        printf("Eroare!");
        return;
    }
    for(int i=0;i<nr_elem;i++){
        printf("array[%d]= ",i);
        scanf("%d",&arr[i]);
    }
    for(int i=1;i<nr_elem;i++){
        int element_cheie=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>element_cheie){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=element_cheie;
    }

    printf("Vector sortat: ");
    for(int i=0;i<nr_elem;i++)printf("%d ",arr[i]);
    printf("\n");
    free(arr);
    arr=NULL;
}
void sort_algo_menu(){
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
    switch(int_input){
        case 1:bubbleSort();break;
        case 2:quickSort();break;
        case 3: insertionSort();break;
        case 4: selectionSort();break;
        case 5: mergeSort();break;
        case 6: heapSort();break;
        case 7: shellSort();break;
        case 8: countSort();break;
        case 9: RadixSort();break;
        case 10:bucketSort();break;
        default:printf("Optiune invalida\n\n");
    }
}

int main(){
char *input=(char*)malloc(2*sizeof(char));
    do {
printf("1. Alg Sortari\n");
printf("2. Alg Cautari\n");
printf("3. Alg Grafuri\n");
printf(" Iesire \n");
printf("\n");
printf("Alege : \n");
scanf("%s",input);

int int_input=atoi(input);
switch (int_input){
    case 1: sort_algo_menu();break;
    case 2: search_algo_menu();break;
    case 3: graph_algo_menu();break;
    default: printf("Optiune invalida\n");break;
}
    }while((strcmp(input,"q")==0 )||(strcmp(input,"Q")));
    return 0;
}
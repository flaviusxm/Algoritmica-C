#include<stdio.h>
#include<malloc.h>
#include<time.h>
#include<sys/resource.h>

const void timSort(){
     srand(time(NULL));
    int nr_elem;
    printf("Introduceti nr. de elemente: ");
    scanf("%d",&nr_elem);
    int a,b;
    int*arr=(int*)malloc(nr_elem*sizeof(int));
    printf("Introduceti valoarea minima < - > maxima pentru valorile vectorului: ");
    scanf("%d %d",&a,&b);
    for(int i=0;i<nr_elem;i++){
        arr[i]=rand()%a+b;
        printf("array[%d]= %d",i,arr[i]);
    }

    for (int i=0;i<nr_elem;i+=32){
        insertionSort(arr,i,(i+32-1<n-1)?(i+32-1):(n-1));
    }
    for(int array_size=32;array_size<nr_elem;array_size*=2){
        for (int left_part=0;left_part<n;left_part+=2*array_size){
            int mid_part=left_part+array_size-1;
            int right_part;
            if(mid_part<right_part){
                mergeSort(arr,left_part,mid_part,right_part);
            }
        }
    }

}
const void countingSort(){
    srand(time(NULL));
    int nr_elem;
    int a;
    int b;
    printf("Introduceti nr. de elemente: ");
    scanf("%d",&nr_elem);
    printf("Introduceti valoarea minima < - > maxima pentru valorile vectorului: ");
    scanf("%d %d",&a,&b);
    if (nr_elem || !arr){
        printf("Eroare!");
        return;
    }
    int max_valoare=0;
    for(int i=0;i<nr_elem;i++){
        arr[i]=rand()%a+b;
        printf("array[%d]= ",i);
        if(arr[i]>max_valoare){
            max_valoare=arr[i];
        }
    }
    int *counts_array=(int*)malloc((max_valoare+1)*sizeof(int));
    for(int i=0;i<nr_elem;i++){
        counts_array[arr[i]]++;
    }
    int index=0;
    for(int i=0;i<max_valoare;i++){
while(counts_array[i]>0){
    arr[index++]=i;
    counts_array[i]--;
}
    }

    printf("Elemente sortate");
    for(int i=0;i<nr_elem;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
free(arr);
free(counts_array);
}
const void selectionSort()
{
    srand(time(NULL));
    int nr_elem;
    int *arr=(int*)malloc(nr_elem*sizeof(int));
    int a;
    int b;
    printf("Introduceti nr. de elemente: ");
    scanf("%d",&nr_elem);
    printf("Introduceti valoarea minima < - > maxima pentru valorile vectorului: ");
    scanf("%d %d",&a,&b);
     if (nr_elem<0|| !arr){
        printf("Eroare!");
        return;
    }
    for(int i=0;i<nr_elem;i++){
        arr[i]=rand()%a+b;
        printf("arr[%d]= %d",i,arr[i]);
    }
    for(int i=0;i<nr_elem-1;i++){
        int index_minim=i;
        for(int j=i+1;j<nr_elem;j++){
            if(arr[j]<arr[index_minim]){
                index_minim=j;
            }
        }
        int temporar=arr[i];
        arr[i]=arr[index_minim];
        arr[index_minim]=temporar;
    }
    printf("Elemente sortate: \n\n");
    for(int i=0;i<nr_elem;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    free(arr);
}
const void quickSortLogic(){
    if (l<r){
        int element_pivot=arr[r];
        int i=l-1;
        for(int j=l;j<r;j++){
            if(arr[j]<element_pivot){
                i++;
                int temporar=arr[i];
                arr[i]=arr[j];
                arr[j]=temporar;
            }
        }
        int temporar=arr[i+1];
        arr[i+1]=arr[j];
        arr[j]=temporar;
        quickSortLogic(arr,l,i);
        quickSortLogic(arr,i+i,r);
    }
}
const void quickSort(){
    int nr_elem;
    int a,b;
    int *arr=(int*)malloc(nr_elem*sizeof(int));
    printf("Introduceti nr. de elemente: \n\n");
    scanf("%d",&nr_elem);
    printf("Introduceti valoarea minima < - > maxima pentru valorile vectorului: ");
    scanf("%d %d",&a,&b);
    if(nr_elem<0 || !arr){
        printf("Eroare!");
        return;
    }

    for(int i=0;i<nr_elem;i++){
        arr[i]=rand()%a+b;
        printf("array[%d]= %d",i,arr[i]);
    }
    quickSortLogic(arr,o,nr_elem-1);
    
}
const void mergeSort(){
    int nr_elem;
    int a,b;
    printf("Introduceti nr. de elemente: \n\n");
    scanf("%d",&nr_elem);
     int *arr=(int*)malloc(nr_elem*sizeof(int));
    printf("Introduceti valoarea minima < - > maxima pentru valorile vectorului: ");
    scanf("%d %d",&a,&b);
    if(nr_elem<0||!arr){
        printf("Eroare!");
        return;
    }
    
    for(int i=0;i<nr_elem;i++){
        arr[i]=rand()%a+b;
        printf("array[%d]= %d",i,arr[i]);
    }
    int n1=mid_pos-left_pos+1;
    int n2=right_pos-mid_pos;
    int *l_array=(int*)malloc(n1*sizeof(int));
    int *r_array=(int*)malloc(n2*sizeof(int));
    for(int i=0;i<n1;i++)l_array[i]=arr[left+i];
    for(int i=0;i<n2;i++)r_array[i]=arr[mid+j+1];

    int i=0,j=0;
    k_index=left_pos;
    while(i<n1 && j<n2){
        if(l_array[i]<=r_array[j]){
            arr[k_index++]=l_array[i++];
        }else{
            arr[k_index++]=r_array[j++];
        }
    }
    while(i<n1)arr[k_index++]=l_array[i++];
    while(j<n2)arr[k_index++]=r_array[j++];
    free(l_array);
    free(r_array);   
}

const void bubbleSort(){
    int nr_elem;
    int a,b;
    int *arr=(int*)malloc(nr_elem*sizeof(int));
    printf("Introduceti nr. de elemente: \n\n");
    scanf("%d",&nr_elem);
    printf("Introduceti valoarea minima < - > maxima pentru valorile vectorului: ");
    scanf("%d %d",&a,&b);
    if( nr_elem<0 || !arr){
        printf("Eroare!");
        return;
    }
    for(int i=0;i<nr_elem;i++){
        arr[i]=rand()%a+b;
        printf("array[%d]= %d",i,arr[i]);        
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
    srand(time(NULL));
    int nr_elem;
    printf("Introduceti nr. de elemente: \n\n");
    scanf("%d",&nr_elem);
    printf("Introduceti valoarea minima < - > maxima pentru valorile vectorului: ");
    scanf("%d %d",&a,&b);
    if(nr_elem<0||!arr){
        printf("Eroare!");
        return;
    }
    for(int i=0;i<nr_elem;i++){
        arr[i]=rand()%a+b;
        printf("array[%d]= %d",i,arr[i]);
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
    printf("Alege :");
    scanf("%d",int_input);
    switch(int_input){
        case 1:{
            struct rusage usage_before,usage_after;
            getrusage(RUSAGE_SELF,&usage_before);
            clock_t f_time; // time to exec function
            f_time=clock();
        bubbleSort();
        f_time=clock()-f_time;
        double exec_time=((double)f_time)/CLOCKS_PER_SEC;
        long exec_memory_used=usage_after.ru_maxrss-usage_before.ru_maxrss;
        printf("Execution time - > %.7f seconds \n",exec_time);
        printf("Memory used - > %ld KB\n".exec_memory_used);
        break;
        }
        case 2:{
              struct rusage usage_before,usage_after;
            getrusage(RUSAGE_SELF,&usage_before);
            clock_t f_time; 
            f_time=clock();
            quickSort();
        f_time=clock()-f_time;
        double exec_time=((double)f_time)/CLOCKS_PER_SEC;
        long exec_memory_used=usage_after.ru_maxrss-usage_before.ru_maxrss;
        printf("Execution time - > %.7f seconds \n",exec_time);
        printf("Memory used - > %ld KB\n".exec_memory_used);
        break;}
        case 3: {
              struct rusage usage_before,usage_after;
            getrusage(RUSAGE_SELF,&usage_before);
            clock_t f_time;
            f_time=clock();
            insertionSort();
        f_time=clock()-f_time;
        double exec_time=((double)f_time)/CLOCKS_PER_SEC;
        long exec_memory_used=usage_after.ru_maxrss-usage_before.ru_maxrss;
        printf("Execution time - > %.7f seconds \n",exec_time);
        printf("Memory used - > %ld KB\n".exec_memory_used);
        break;
        }
        case 4: {
              struct rusage usage_before,usage_after;
            getrusage(RUSAGE_SELF,&usage_before);
            clock_t f_time;
            f_time=clock();
            selectionSort();
        f_time=clock()-f_time;
        double exec_time=((double)f_time)/CLOCKS_PER_SEC;
        long exec_memory_used=usage_after.ru_maxrss-usage_before.ru_maxrss;
        printf("Execution time - > %.7f seconds \n",exec_time);
        printf("Memory used - > %ld KB\n".exec_memory_used);
        break;
        }
        case 5: {
              struct rusage usage_before,usage_after;
            getrusage(RUSAGE_SELF,&usage_before);
            clock_t f_time;
            f_time=clock();
            mergeSort();f_time=clock()-f_time;
        double exec_time=((double)f_time)/CLOCKS_PER_SEC;
        long exec_memory_used=usage_after.ru_maxrss-usage_before.ru_maxrss;
        printf("Execution time - > %.7f seconds \n",exec_time);
        printf("Memory used - > %ld KB\n".exec_memory_used);
        break;}
        case 6:{ 
              struct rusage usage_before,usage_after;
            getrusage(RUSAGE_SELF,&usage_before);
            clock_t f_time;
            f_time=clock();
            heapSort();
        f_time=clock()-f_time;
        double exec_time=((double)f_time)/CLOCKS_PER_SEC;
        long exec_memory_used=usage_after.ru_maxrss-usage_before.ru_maxrss;
        printf("Execution time - > %.7f seconds \n",exec_time);
        printf("Memory used - > %ld KB\n".exec_memory_used);
        break;}
        case 7:{ 
              struct rusage usage_before,usage_after;
            getrusage(RUSAGE_SELF,&usage_before);
            clock_t f_time;
            f_time=clock();
            shellSort();
        f_time=clock()-f_time;
        double exec_time=((double)f_time)/CLOCKS_PER_SEC;
        long exec_memory_used=usage_after.ru_maxrss-usage_before.ru_maxrss;
        printf("Execution time - > %.7f seconds \n",exec_time);
        printf("Memory used - > %ld KB\n".exec_memory_used);
        break;}
        case 8: {
              struct rusage usage_before,usage_after;
            getrusage(RUSAGE_SELF,&usage_before);
            clock_t f_time;
            f_time=clock();
            countSort();
        f_time=clock()-f_time;
        double exec_time=((double)f_time)/CLOCKS_PER_SEC;
        long exec_memory_used=usage_after.ru_maxrss-usage_before.ru_maxrss;
        printf("Execution time - > %.7f seconds \n",exec_time);
        printf("Memory used - > %ld KB\n".exec_memory_used);
        break;
}
        case 9:{
              struct rusage usage_before,usage_after;
            getrusage(RUSAGE_SELF,&usage_before);
            clock_t f_time;
            f_time=clock();
            radixSort();
        f_time=clock()-f_time;
        double exec_time=((double)f_time)/CLOCKS_PER_SEC;
        long exec_memory_used=usage_after.ru_maxrss-usage_before.ru_maxrss;
        printf("Execution time - > %.7f seconds \n",exec_time);
        printf("Memory used - > %ld KB\n".exec_memory_used);
        break;}
        case 10:{
              struct rusage usage_before,usage_after;
            getrusage(RUSAGE_SELF,&usage_before);
            clock_t f_time; 
            f_time=clock();
            bucketSort();
        f_time=clock()-f_time;
        double exec_time=((double)f_time)/CLOCKS_PER_SEC;
        long exec_memory_used=usage_after.ru_maxrss-usage_before.ru_maxrss;
        printf("Execution time - > %.7f seconds \n",exec_time);
        printf("Memory used - > %ld KB\n".exec_memory_used);
        break;}
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
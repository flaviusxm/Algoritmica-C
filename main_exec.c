<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

void bubbleSort();
void quickSort();
void insertionSort();
void selectionSort();
void mergeSort();
void heapSort();
void shellSort();
void countSort();
void radixSort();
void bucketSort();

 void timSort(){
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

void countingSort(){
    srand(time(NULL));
    int nr_elem,a,b;
    printf("Introduceti nr. de elemente: ");
    scanf("%d",&nr_elem);
    printf("Introduceti valoarea minima < - > maxima pentru valorile vectorului: ");
    scanf("%d %d",&a,&b);
int *arr=(int*)malloc(nr_elem*sizeof(int));
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
        printf("array[%d]= %d\n",arr[i]);
    }
    printf("\n");
free(arr);
free(counts_array);
}
void selectionSort()
{
    int nr_elem,a,b;
    printf("Introduceti nr. de elemente: ");
    scanf("%d",&nr_elem);
    printf("Introduceti valoarea minima < - > maxima pentru valorile vectorului: ");
    scanf("%d %d",&a,&b);

    int *arr=(*int)malloc(nr_elem*sizeof(int));
     if (nr_elem<0|| !arr){
        printf("Eroare!\n");
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
void quickSortLogic(){
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
 void quickSort(){
    int nr_elem,a,b;
    printf("Introduceti nr. de elemente: \n\n");
    scanf("%d",&nr_elem);
    printf("Introduceti valoarea minima < - > maxima pentru valorile vectorului: ");
    scanf("%d %d",&a,&b);
    if(nr_elem<0 || !arr){
        printf("Eroare!");
        return;
    }
    int *arr=(int*)malloc(nr_elem*sizeof(int));
    for(int i=0;i<nr_elem;i++){
        arr[i]=(rand()%(b-a+1))+a;
        printf("array[%d]= %d\n",i,arr[i]);
    }
    quickSortLogic(arr,0,nr_elem-1);
    free(arr);
}
 void mergeSort(){
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

void bubbleSort(){
    int nr_elem,a,b;
    printf("Introduceti nr. de elemente: \n\n");
    scanf("%d",&nr_elem);
    printf("Introduceti valoarea minima < - > maxima pentru valorile vectorului: ");
    scanf("%d %d",&a,&b);
    int *arr=(int*)malloc(nr_elem*sizeof(int));
    if( nr_elem < 0 || !arr){
        printf("Eroare!");
        return;
    }
    for(int i=0;i<nr_elem;i++){
        arr[i]=(rand()%(b-a+1))+a;
        printf("array[%d]= %d\n",i,arr[i]);        
    }
bool bool_checker;
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
 void insertionSort(){
    int nr_elem,a,b;
    printf("Introduceti nr. de elemente: \n\n");
    scanf("%d",&nr_elem);
    printf("Introduceti valoarea minima < - > maxima pentru valorile vectorului: ");
    scanf("%d %d",&a,&b);
    int *arr=(int*)malloc(nr_elem*sizeof(int));
    if(nr_elem<0||!arr){
        printf("Eroare!");
        return;
    }
    for(int i=0;i<nr_elem;i++){
        arr[i]=(rand()%(b-a+1))+a;
        printf("array[%d]= %d\n",i,arr[i]);
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
    scanf("%d",&int_input);
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
        printf("Memory used - > %ld KB\n",exec_memory_used);
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
        printf("Memory used - > %ld KB\n",exec_memory_used);
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
        printf("Memory used - > %ld KB\n",exec_memory_used);
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
        printf("Memory used - > %ld KB\n",exec_memory_used);
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
        printf("Memory used - > %ld KB\n",,exec_memory_used);
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
        printf("Memory used - > %ld KB\n",exec_memory_used);
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
        printf("Memory used - > %ld KB\n",exec_memory_used);
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
        printf("Memory used - > %ld KB\n",exec_memory_used);
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
        printf("Memory used - > %ld KB\n",exec_memory_used);
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
        printf("Memory used - > %ld KB\n",exec_memory_used);
        break;}
        default:printf("Optiune invalida\n\n");
    }
}

int main(){
char *input=(char*)malloc(3*sizeof(char));
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
} while(strcmp(input,"q")!=0 && strcmp(input,"Q")!=0);
    return 0;
}
=======
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>
void info_bubble_sort(){ 
    printf("\n=== BUBBLE SORT ===\n\n");
    printf("Bubble Sort este un algoritm simplu de sortare.\n");
    printf("Compara elemente adiacente si le interschimba daca sunt in ordine gresita.\n");
    printf("La fiecare trecere prin lista, cel mai mare element 'urca' spre final, ca o bula.\n\n");

    printf("Luam urmatorul exemplu: [6, 3, 8, 5, 2]\n\n");

    printf("Trecerea 1:\n");
    printf("Comparam 6 si 3 => swap   => [3, 6, 8, 5, 2]\n");
    printf("Comparam 6 si 8 => ok     => [3, 6, 8, 5, 2]\n");
    printf("Comparam 8 si 5 => swap   => [3, 6, 5, 8, 2]\n");
    printf("Comparam 8 si 2 => swap   => [3, 6, 5, 2, 8]\n");
    printf("=> 8 este acum in pozitia finala (index 4)\n\n");

    printf("Trecerea 2:\n");
    printf("Comparam 3 si 6 => ok     => [3, 6, 5, 2, 8]\n");
    printf("Comparam 6 si 5 => swap   => [3, 5, 6, 2, 8]\n");
    printf("Comparam 6 si 2 => swap   => [3, 5, 2, 6, 8]\n");
    printf("=> 6 este acum pe pozitia corecta (index 3)\n\n");

    printf("Trecerea 3:\n");
    printf("Comparam 3 si 5 => ok     => [3, 5, 2, 6, 8]\n");
    printf("Comparam 5 si 2 => swap   => [3, 2, 5, 6, 8]\n");
    printf("=> 5 este acum pe pozitia corecta (index 2)\n\n");

    printf("Trecerea 4:\n");
    printf("Comparam 3 si 2 => swap   => [2, 3, 5, 6, 8]\n");
    printf("=> 3 este acum pe pozitia corecta (index 1)\n\n");

    printf("Trecerea 5:\n");
    printf("Lista deja sortata => [2, 3, 5, 6, 8]\n\n");

    // Rezultatul
    printf("Lista sortata final: [2, 3, 5, 6, 8]\n\n");

    printf("Complexitate timp:\n");
    printf("- Caz favorabil (lista sortata): O(n)\n");
    printf("- Caz mediu: O(n^2)\n");
    printf("- Caz defavorabil (lista invers sortata): O(n^2)\n\n");

    printf("Caracteristici:\n");
    printf("- In-place: Da (nu foloseste memorie suplimentara semnificativa)\n");
    printf("- Stabil: Da (mentine ordinea elementelor egale)\n");
    printf("- Simplu, dar ineficient pentru liste mari\n\n");

    printf("Cand e util Bubble Sort:\n");
    printf("- In scopuri educationale\n");
    printf("- Pentru colectii foarte mici\n");
    printf("- Cand performanta nu este critica\n");

    printf("\n=====================\n\n");

}
void info_insertion_sort(){
    printf("\n=== INSERTION SORT ===\n\n");

    printf("Insertion Sort este un algoritm simplu si intuitiv de sortare.\n");
    printf("Functioneaza asemanator cu modul in care un om si-ar sorta cartile in mana.\n");
    printf("Porneste de la al doilea element si il compara cu cele din stanga sa.\n");
    printf("Daca elementul este mai mic decat cel din stanga, il muta spre stanga\n");
    printf("pana gaseste pozitia corecta unde sa fie inserat.\n\n");
    printf("Practic, construieste treptat o lista sortata la stanga,\n");
    printf("inserand fiecare element din lista initiala la locul potrivit.\n\n");
 printf("Luam urmatorul exemplu: [6, 3, 8, 5, 2]\n\n");

    printf("Trecerea 1 (i = 1):\n");
    printf("Key = 3, comparam cu 6 => 3 < 6 => mutam 6 la dreapta\n");
    printf("Inseram 3 => [3, 6, 8, 5, 2]\n\n");

    printf("Trecerea 2 (i = 2):\n");
    printf("Key = 8, comparam cu 6 => 8 > 6 => nu facem nimic\n");
    printf("8 ramane pe loc => [3, 6, 8, 5, 2]\n\n");

    printf("Trecerea 3 (i = 3):\n");
    printf("Key = 5, comparam cu 8 => 5 < 8 => mutam 8 la dreapta\n");
    printf("Comparam cu 6 => 5 < 6 => mutam 6\n");
    printf("Comparam cu 3 => 5 > 3 => stop\n");
    printf("Inseram 5 => [3, 5, 6, 8, 2]\n\n");

    printf("Trecerea 4 (i = 4):\n");
    printf("Key = 2, comparam cu 8 => mutam 8\n");
    printf("Comparam cu 6 => mutam 6\n");
    printf("Comparam cu 5 => mutam 5\n");
    printf("Comparam cu 3 => mutam 3\n");
    printf("Nu mai avem ce compara, inseram 2 la inceput => [2, 3, 5, 6, 8]\n\n");

    // Rezultatul
    printf("Lista sortata final: [2, 3, 5, 6, 8]\n\n");

    printf("Complexitate timp:\n");
    printf("- Caz favorabil (lista sortata): O(n)\n");
    printf("- Caz mediu: O(n^2)\n");
    printf("- Caz defavorabil (lista invers sortata): O(n^2)\n\n");

    printf("Caracteristici:\n");
    printf("- In-place: Da (nu foloseste memorie suplimentara)\n");
    printf("- Stabil: Da (mentine ordinea elementelor egale)\n");
    printf("- Foarte eficient pentru liste mici sau aproape sortate\n");
    printf("- Usor de implementat\n\n");

    printf("Cand e util Insertion Sort:\n");
    printf("- Pentru liste mici\n");
    printf("- Cand datele sunt aproape sortate\n");
    printf("- In algoritmi mai complecsi (ex: hibrizi precum TimSort)\n");

    printf("\n=======================\n\n");

}
void info_quick_sort(){
        printf("\n=== QUICK SORT ===\n\n");

    printf("Quick Sort este un algoritm eficient de sortare, bazat pe principiul divide et impera.\n");
    printf("Ideea de baza este:\n");
    printf("- Alegem un element numit pivot\n");
    printf("- Reordonam lista astfel incat:\n");
    printf("   -> toate elementele mai mici decat pivotul sa fie in stanga\n");
    printf("   -> toate cele mai mari sa fie in dreapta\n");
    printf("- Aplicam aceeasi strategie recursiv pentru sublistele din stanga si dreapta\n\n");

    printf("Quick Sort NU este stabil (poate schimba ordinea elementelor egale).\n");
    printf("Este un algoritm in-place: nu necesita memorie suplimentara semnificativa.\n");
    printf("In practica, este unul dintre cei mai rapizi algoritmi de sortare.\n\n");

    printf("Luam urmatorul exemplu: [6, 3, 8, 5, 2]\n\n");

    // Pas 1
    printf("Trecerea 1:\n");
    printf("Lista: [6, 3, 8, 5, 2]\n");
    printf("Alegem pivotul = 2 (ultimul element)\n");
    printf("Parcurgem si mutam elementele < pivot in stanga:\n");
    printf("- 6 > 2 => nu facem nimic\n");
    printf("- 3 > 2 => nu facem nimic\n");
    printf("- 8 > 2 => nu facem nimic\n");
    printf("- 5 > 2 => nu facem nimic\n");
    printf("Pivotul 2 se muta la inceput => [2, 3, 8, 5, 6]\n\n");

    // Pas 2
    printf("Trecerea 2:\n");
    printf("Sublista din dreapta pivotului: [3, 8, 5, 6]\n");
    printf("Alegem pivotul = 6\n");
    printf("- 3 < 6 => ramane pe loc\n");
    printf("- 8 > 6 => il lasam\n");
    printf("- 5 < 6 => il mutam inaintea lui 8\n");
    printf("Pivotul 6 se plaseaza intre 5 si 8 => [3, 5, 6, 8]\n\n");

    // Pas 3
    printf("Trecerea 3:\n");
    printf("Sublista din stanga pivotului 6: [3, 5]\n");
    printf("Pivot = 5\n");
    printf("- 3 < 5 => ramane pe loc\n");
    printf("Pivotul 5 ramane pe pozitie => [3, 5]\n\n");

    printf("Sublista din dreapta pivotului 6: [8]\n");
    printf("Doar un element => nu sortam\n\n");

    // Rezultatul final
    printf("Lista sortata final: [2, 3, 5, 6, 8]\n\n");

    printf("Complexitate timp:\n");
    printf("- Caz favorabil (pivotul imparte lista egal): O(n log n)\n");
    printf("- Caz mediu: O(n log n)\n");
    printf("- Caz defavorabil (pivotul e mereu cel mai mic/mare): O(n^2)\n\n");

    printf("Caracteristici:\n");
    printf("- In-place: Da (nu foloseste memorie suplimentara semnificativa)\n");
    printf("- Stabil: Nu\n");
    printf("- Eficient pe liste mari si distribuite aleator\n");
    printf("- Folosit in multe biblioteci standard de sortare\n\n");

    printf("Cand e util Quick Sort:\n");
    printf("- Pentru liste mari\n");
    printf("- Cand performanta este importanta\n");
    printf("- Cand memoria suplimentara trebuie minimizata\n");

    printf("\n=======================\n\n");
}
void info_bucket_sort(){
    printf("\n=== BUCKET SORT ===\n\n");

    printf("Bucket Sort este un algoritm de sortare eficient, mai ales atunci cand datele sunt distribuite uniform.\n");
    printf("Functioneaza pe principiul distribuirii elementelor in \"bucket-uri\" (cosuri sau categorii),\n");
    printf("fiecare bucket fiind apoi sortat individual.\n\n");

    printf("Etapele algoritmului sunt:\n");
    printf("1. Gasim valoarea minima si maxima din vector\n");
    printf("2. Creem un numar de bucket-uri (de obicei in functie de dimensiunea vectorului)\n");
    printf("3. Repartizam fiecare element in bucket-ul corespunzator (in functie de valoare)\n");
    printf("4. Sortam fiecare bucket individual (de obicei cu Insertion Sort)\n");
    printf("5. Concatenam toate bucket-urile pentru a obtine vectorul final sortat\n\n");

    printf("Bucket Sort este foarte eficient cand:\n");
    printf("- Valorile sunt distribuite uniform\n");
    printf("- Valorile sunt intr-un interval cunoscut (ex: 0 - 100)\n\n");

    printf("Sa luam exemplul: [29, 25, 3, 49, 9, 37, 21, 43]\n\n");

    // Pas 1
    printf("Pas 1: Cautam valoarea minima si maxima\n");
    printf("Min = 3, Max = 49\n\n");

    // Pas 2
    printf("Pas 2: Alegem sa folosim 5 bucket-uri (exemplu)\n");
    printf("Fiecare bucket va acoperi un interval: (49 - 3) / 5 = ~9.2 -> rotunjim la 10\n");
    printf("Bucket 0: [0 - 9], Bucket 1: [10 - 19], ... Bucket 4: [40 - 49]\n\n");

    // Pas 3
    printf("Pas 3: Repartizam valorile in bucket-uri:\n");
    printf("- 29 -> Bucket 2\n");
    printf("- 25 -> Bucket 2\n");
    printf("- 3  -> Bucket 0\n");
    printf("- 49 -> Bucket 4\n");
    printf("- 9  -> Bucket 0\n");
    printf("- 37 -> Bucket 3\n");
    printf("- 21 -> Bucket 2\n");
    printf("- 43 -> Bucket 4\n\n");

    printf("Bucket-urile dupa repartizare:\n");
    printf("Bucket 0: [3, 9]\n");
    printf("Bucket 1: []\n");
    printf("Bucket 2: [29, 25, 21]\n");
    printf("Bucket 3: [37]\n");
    printf("Bucket 4: [49, 43]\n\n");

    // Pas 4
    printf("Pas 4: Sortam fiecare bucket:\n");
    printf("Bucket 0: [3, 9] -> deja sortat\n");
    printf("Bucket 2: [29, 25, 21] -> sortat devine [21, 25, 29]\n");
    printf("Bucket 4: [49, 43] -> sortat devine [43, 49]\n\n");

    // Pas 5
    printf("Pas 5: Concatenam toate bucket-urile:\n");
    printf("Rezultat final: [3, 9, 21, 25, 29, 37, 43, 49]\n\n");

    printf("Complexitate timp:\n");
    printf("- Caz optim (distributie uniforma + sortare rapida in bucket-uri): O(n)\n");
    printf("- Caz mediu: intre O(n) si O(n log n)\n");
    printf("- Caz defavorabil (toate valorile intra in acelasi bucket): O(n^2)\n\n");

    printf("Caracteristici:\n");
    printf("- In-place: NU (foloseste memorie suplimentara pentru bucket-uri)\n");
    printf("- Stabil: Depinde (daca sortarea interna este stabila)\n");
    printf("- Rapid pentru date numerice distribuite uniform\n");
    printf("- Mai potrivit pentru float-uri decat pentru intregi cu distributie neuniforma\n\n");

    printf("Cand e util Bucket Sort:\n");
    printf("- Cand valorile sunt distribuite uniform intr-un interval\n");
    printf("- Cand avem date reale (float-uri) sau puncte care trebuie grupate\n");
    printf("- Cand avem nevoie de performanta ridicata si avem memorie suplimentara\n");

    printf("\n=======================\n\n");
}
void info_selection_sort(){
    printf("\n=== SELECTION SORT ===\n\n");

    printf("Selection Sort este un algoritm simplu de sortare, intuitiv, dar ineficient pentru liste mari.\n");
    printf("Functioneaza astfel:\n");
    printf("1. Gaseste cel mai mic element din lista\n");
    printf("2. Il muta la inceputul listei (pozitia corecta)\n");
    printf("3. Repeta procesul pentru restul elementelor\n\n");

    printf("Sa luam exemplul: [29, 10, 14, 37, 13]\n\n");

    // Pas 1
    printf("Pas 1: Cautam minimul in [29, 10, 14, 37, 13] => 10\n");
    printf("Schimbam 10 cu 29 => [10, 29, 14, 37, 13]\n\n");

    // Pas 2
    printf("Pas 2: Cautam minimul in [29, 14, 37, 13] => 13\n");
    printf("Schimbam 13 cu 29 => [10, 13, 14, 37, 29]\n\n");

    // Pas 3
    printf("Pas 3: Cautam minimul in [14, 37, 29] => 14 (deja e pe pozitie)\n");

    // Pas 4
    printf("Pas 4: Cautam minimul in [37, 29] => 29\n");
    printf("Schimbam 29 cu 37 => [10, 13, 14, 29, 37]\n\n");

    printf("Lista sortata: [10, 13, 14, 29, 37]\n\n");

    printf("Complexitate timp:\n");
    printf("- Oricare caz: O(n^2) (deoarece cautarea minimului se face de fiecare data)\n\n");

    printf("Caracteristici:\n");
    printf("- In-place: Da\n");
    printf("- Stabil: NU (poate schimba ordinea elementelor egale)\n");
    printf("- Usor de inteles si implementat, dar ineficient\n\n");

    printf("Cand e util Selection Sort:\n");
    printf("- Liste foarte mici\n");
    printf("- Cand simplitatea e mai importanta decat performanta\n");

    printf("\n=======================\n\n");
}
void info_merge_sort(){
    printf("\n=== MERGE SORT ===\n\n");

    printf("Merge Sort este un algoritm eficient si stabil, bazat pe divide et impera.\n");
    printf("Ideea este:\n");
    printf("1. Impartim lista in jumatati pana ajungem la subliste de 1 element\n");
    printf("2. Apoi le combinam (merge) intr-o ordine sortata\n\n");

    printf("Exemplu: [38, 27, 43, 3, 9, 82, 10]\n\n");

    // Impartire
    printf("Impartim lista in doua: [38, 27, 43] si [3, 9, 82, 10]\n");
    printf("Continuam impartirea:\n");
    printf("[38, 27, 43] -> [38], [27], [43] => le combinam: [27, 38, 43]\n");
    printf("[3, 9, 82, 10] -> [3], [9], [82], [10] => combinam: [3, 9], [10, 82] => [3, 9, 10, 82]\n");

    printf("Combinam cele doua parti: [27, 38, 43] si [3, 9, 10, 82]\n");
    printf("Rezultat final: [3, 9, 10, 27, 38, 43, 82]\n\n");

    printf("Complexitate timp:\n");
    printf("- Caz favorabil, mediu si defavorabil: O(n log n)\n\n");

    printf("Caracteristici:\n");
    printf("- In-place: NU (foloseste memorie suplimentara pentru interclasare)\n");
    printf("- Stabil: DA (pastreaza ordinea elementelor egale)\n");
    printf("- Foarte bun pentru liste mari sau fisiere externe\n\n");

    printf("Cand e util Merge Sort:\n");
    printf("- Pentru date mari care nu incap in RAM\n");
    printf("- Cand avem nevoie de un algoritm stabil\n");

    printf("\n=======================\n\n");
}

void info_heap_sort(){
    printf("\n=== HEAP SORT ===\n\n");

    printf("Heap Sort este un algoritm de sortare bazat pe o structura de date numita heap (max-heap).\n");
    printf("Ideea de baza:\n");
    printf("1. Construim un heap din lista (max-heap)\n");
    printf("2. Scoatem elementul maxim (radacina) si il punem la sfarsitul listei\n");
    printf("3. Refacem heap-ul si repetam pana e sortata toata lista\n\n");

    printf("Exemplu: [4, 10, 3, 5, 1]\n\n");

    printf("Pas 1: Construim max-heap: [10, 5, 3, 4, 1]\n");
    printf("Pas 2: Scoatem 10, il punem la final => [1, 5, 3, 4, 10] -> refacem heap: [5, 4, 3, 1, 10]\n");
    printf("Pas 3: Scoatem 5, punem la final => [1, 4, 3, 5, 10] -> heap: [4, 1, 3, 5, 10]\n");
    printf("... repetam ...\n");
    printf("Lista finala: [1, 3, 4, 5, 10]\n\n");

    printf("Complexitate timp:\n");
    printf("- Oricare caz: O(n log n)\n\n");

    printf("Caracteristici:\n");
    printf("- In-place: DA\n");
    printf("- Stabil: NU\n");
    printf("- Util pentru cazuri unde nu conteaza ordinea elementelor egale\n\n");

    printf("Cand e util Heap Sort:\n");
    printf("- Cand avem nevoie de sortare garantat O(n log n)\n");
    printf("- Cand nu ne intereseaza stabilitatea\n");

    printf("\n=======================\n\n");
}
void info_radix_sort(){
    printf("\n=== RADIX SORT ===\n\n");

    printf("Radix Sort sorteaza numerele cifra cu cifra, incepand de la cifra cea mai putin semnificativa (LSD).\n");
    printf("Este eficient pentru numere intregi si poate folosi Counting Sort ca sortare intermediara.\n\n");

    printf("Etape:\n");
    printf("1. Se sorteaza numerele dupa ultima cifra (unitati)\n");
    printf("2. Apoi dupa zeci, sute etc., pastrand ordinea\n\n");

    printf("Exemplu: [170, 45, 75, 90, 802, 24, 2, 66]\n");

    printf("Pas 1: sortare dupa unitati => [170, 90, 802, 2, 24, 45, 75, 66]\n");
    printf("Pas 2: sortare dupa zeci    => [802, 2, 24, 45, 66, 170, 75, 90]\n");
    printf("Pas 3: sortare dupa sute    => [2, 24, 45, 66, 75, 90, 170, 802]\n\n");

    printf("Complexitate timp:\n");
    printf("- O(d * (n + k)), unde d = numar de cifre, k = baza\n\n");

    printf("Caracteristici:\n");
    printf("- In-place: NU (foloseste sortari intermediare)\n");
    printf("- Stabil: DA\n");
    printf("- Foarte eficient pentru numere mari cu cifre putine\n");

    printf("Cand e util Radix Sort:\n");
    printf("- Cand avem multe numere intregi mari, dar cu numar mic de cifre\n");
    printf("- Cand vrem o sortare stabila si eficienta\n");

    printf("\n=======================\n\n");
}

void to_lowercase_transform(char*string){
    for (int i=0;string[i];i++){
        string[i]=tolower(string[i]);
    }
}
// Forward declarations for menus
static void sort_algo_menu(void);
static void search_algo_menu(void);

// Sorting algorithms implemented
static void bubbleSort(void);
static void quickSort(void);
static void insertionSort(void);
static void selectionSort(void);
static void countingSort(void);

// Stubs for not-yet-implemented sorting algorithms (to avoid linker errors)
static void mergeSort_stub(void);
static void heapSort_stub(void);
static void shellSort_stub(void);
static void radixSort_stub(void);
static void bucketSort_stub(void);

// Stubs for search algorithms (not implemented yet)
static void dfs_stub(void);
static void bfs_stub(void);
static void dijkstra_stub(void);
static void a_star_stub(void);
static void jump_search_stub(void);

// Internal helper for quick sort
static void quickSortLogic(int arr[], int l, int r);

// Utilities
static int* generate_random_array(int n, int a, int b);
static void print_array(const int arr[], int n);

// ======================= Utilities =======================
static int* generate_random_array(int n, int a, int b){
    if (n <= 0) return NULL;
    if (a > b) { int t = a; a = b; b = t; }
    int* arr = (int*)malloc((size_t)n * sizeof(int));
    if (!arr) return NULL;
    int range = b - a + 1;
    for (int i = 0; i < n; ++i){
        arr[i] = a + (range > 0 ? (rand() % range) : 0);
    }
    return arr;
}

static void print_array(const int arr[], int n){
    for (int i = 0; i < n; ++i){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// ======================= Sorting Implementations =======================
static void bubbleSort(void){
    int nr_elem, a, b;
    printf("Introduceti nr. de elemente: \n\n");
    if (scanf("%d", &nr_elem) != 1) return;
    printf("Introduceti valoarea minima < - > maxima pentru valorile vectorului: ");
    if (scanf("%d %d", &a, &b) != 2) return;

    int *arr = generate_random_array(nr_elem, a, b);
    if (nr_elem <= 0 || !arr){
        printf("Eroare!\n");
        free(arr);
        return;
    }

    printf("Vector initial: ");
    print_array(arr, nr_elem);

    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < nr_elem - 1; ++i){
            if (arr[i] > arr[i + 1]){
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = true;
            }
        }
    } while (swapped);

    printf("Vector sortat: ");
    print_array(arr, nr_elem);

    free(arr);
}

static void insertionSort(void){
    int nr_elem, a, b;
    printf("Introduceti nr. de elemente: \n\n");
    if (scanf("%d", &nr_elem) != 1) return;
    printf("Introduceti valoarea minima < - > maxima pentru valorile vectorului: ");
    if (scanf("%d %d", &a, &b) != 2) return;

    int *arr = generate_random_array(nr_elem, a, b);
    if (nr_elem <= 0 || !arr){
        printf("Eroare!\n");
        free(arr);
        return;
    }

    printf("Vector initial: ");
    print_array(arr, nr_elem);

    for (int i = 1; i < nr_elem; ++i){
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }

    printf("Vector sortat: ");
    print_array(arr, nr_elem);

    free(arr);
}

static void selectionSort(void){
    int nr_elem, a, b;
    printf("Introduceti nr. de elemente: ");
    if (scanf("%d", &nr_elem) != 1) return;
    printf("Introduceti valoarea minima < - > maxima pentru valorile vectorului: ");
    if (scanf("%d %d", &a, &b) != 2) return;

    int *arr = generate_random_array(nr_elem, a, b);
    if (nr_elem <= 0 || !arr){
        printf("Eroare!\n");
        free(arr);
        return;
    }

    printf("Vector initial: ");
    print_array(arr, nr_elem);

    for (int i = 0; i < nr_elem - 1; ++i){
        int min_idx = i;
        for (int j = i + 1; j < nr_elem; ++j){
            if (arr[j] < arr[min_idx]) min_idx = j;
        }
        if (min_idx != i){
            int tmp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = tmp;
        }
    }

    printf("Vector sortat: ");
    print_array(arr, nr_elem);

    free(arr);
}

static void countingSort(void){
    int nr_elem, a, b;
    printf("Introduceti nr. de elemente: ");
    if (scanf("%d", &nr_elem) != 1) return;
    printf("Introduceti valoarea minima < - > maxima pentru valorile vectorului: ");
    if (scanf("%d %d", &a, &b) != 2) return;

    int *arr = generate_random_array(nr_elem, a, b);
    if (nr_elem <= 0 || !arr){
        printf("Eroare!\n");
        free(arr);
        return;
    }

    printf("Vector initial: ");
    print_array(arr, nr_elem);

    // Find actual min and max in array (counting sort with offset supports negatives)
    int min_val = arr[0];
    int max_val = arr[0];
    for (int i = 1; i < nr_elem; ++i){
        if (arr[i] < min_val) min_val = arr[i];
        if (arr[i] > max_val) max_val = arr[i];
    }
    int range = max_val - min_val + 1;
    int offset = -min_val;

    int *counts = (int*)calloc((size_t)range, sizeof(int));
    if (!counts){
        printf("Eroare alocare memorie!\n");
        free(arr);
        return;
    }

    for (int i = 0; i < nr_elem; ++i){
        counts[arr[i] + offset]++;
    }

    int idx = 0;
    for (int v = 0; v < range; ++v){
        while (counts[v]-- > 0){
            arr[idx++] = v - offset;
        }
    }

    printf("Vector sortat: ");
    print_array(arr, nr_elem);

    free(counts);
    free(arr);
}

static void quickSort(void){
    int nr_elem, a, b;
    printf("Introduceti nr. de elemente: \n\n");
    if (scanf("%d", &nr_elem) != 1) return;
    printf("Introduceti valoarea minima < - > maxima pentru valorile vectorului: ");
    if (scanf("%d %d", &a, &b) != 2) return;

    int *arr = generate_random_array(nr_elem, a, b);
    if (nr_elem <= 0 || !arr){
        printf("Eroare!\n");
        free(arr);
        return;
    }

    printf("Vector initial: ");
    print_array(arr, nr_elem);

    quickSortLogic(arr, 0, nr_elem - 1);

    printf("Vector sortat: ");
    print_array(arr, nr_elem);

    free(arr);
}

static void quickSortLogic(int arr[], int l, int r){
    if (l >= r) return;
    int pivot = arr[r];
    int i = l - 1;
    for (int j = l; j < r; ++j){
        if (arr[j] <= pivot){
            ++i;
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
    int p = i + 1;
    int tmp = arr[p];
    arr[p] = arr[r];
    arr[r] = tmp;

    if (p - 1 > l) quickSortLogic(arr, l, p - 1);
    if (p + 1 < r) quickSortLogic(arr, p + 1, r);
}
static void more_info_menu(void){
    
    printf("\n Explicatii \n");
    printf("Introdu numele unui algoritm de sortare/cautare pentru a afla care este mecanismul din spate: ");
    getchar(); 
    char *char_input=(char*)malloc(50*sizeof(char));
    fgets(char_input,50,stdin);
    char_input[strcspn(char_input,"\n")]=0;
    to_lowercase_transform(char_input);

    if (strcmp(char_input,"bubble")==0){
        info_bubble_sort();
    }
}
// ======================= Stubs (placeholders) =======================
void countSortLogic(int arr[], int n) {
    if (n <= 0) return;
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    int *counter = (int *)calloc(max + 1, sizeof(int)); 
    if (!counter) {
        printf("Eroare la alocarea memoriei!\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        counter[arr[i]]++;
    }

    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (counter[i] > 0) {
            arr[index++] = i;
            counter[i]--;
        }
    }
    free(counter);
}
void bucketSortLogic(int *arr,int n){
    if (n<=0)return;
    int min=arr[0];
    int max=arr[0];
    for(int i=1;i<=n;i++){
        if(arr[i]<min)min=arr[i];
        if(arr[i]>max)max=arr[i];
    }
    int rangeBucket=(max-min+1)/max_buckets+1;
    int **buckets_matrix=malloc(max_buckets*sizeof(int*));
    int *bucketsSize=calloc(max_buckets,sizeof(int));
    for(int i=0;i<max_buckets;i++){
        buckets_matrix[i]=malloc((n+1)*sizeof(int));
    }

    //sortare fiecare bucket

    int index=0;
    for(int i=0;i<max_buckets;i++){
        if(bucketsSize[i]>0){
            insertionSort(buckets_matrix[i],bucketsSize[i]);
            for(int j=0;j<bucketsSize[i];j++){
                arr[index++]=buckets_matrix[i][j];
            }
        }
        free(buckets_matrix[i]);
    }
    free(buckets_matrix);
    free(bucketsSize);
}
static void countSort(void){
      int nr_elem, a, b;
    printf("Introduceti nr. de elemente: \n\n");
    if (scanf("%d", &nr_elem) != 1) return;
    printf("Introduceti valoarea minima < - > maxima pentru valorile vectorului: ");
    if (scanf("%d %d", &a, &b) != 2) return;

    int *arr = generate_random_array(nr_elem, a, b);
    if (nr_elem <= 0 || !arr){
        printf("Eroare!\n");
        free(arr);
        return;
    }

    printf("Vector initial: ");
    print_array(arr, nr_elem);

    countSortLogic(arr,nr_elem - 1);

    printf("Vector sortat: ");
    print_array(arr, nr_elem);

    free(arr);
}
static void heapSort_stub(void){
    printf("Heap Sort nu este inca implementat.\n");
}
static void shellSort_stub(void){
    printf("Shell Sort nu este inca implementat.\n");
}
void radixSortLogic(int*arr,int n){

int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    for(int exp=1;max/exp>0;exp*=10){
        countSort(arr,n,exp);
    }
}
static void radixSort(void){
  int nr_elem, a, b;
    printf("Introduceti nr. de elemente: \n\n");
    if (scanf("%d", &nr_elem) != 1) return;
    printf("Introduceti valoarea minima < - > maxima pentru valorile vectorului: ");
    if (scanf("%d %d", &a, &b) != 2) return;

    int *arr = generate_random_array(nr_elem, a, b);
    if (nr_elem <= 0 || !arr){
        printf("Eroare!\n");
        free(arr);
        return;
    }

    printf("Vector initial: ");
    print_array(arr, nr_elem);

    radixSortLogic(arr, nr_elem - 1);

    printf("Vector sortat: ");
    print_array(arr, nr_elem);

    free(arr);
}
static void bucketSort(void){
      int nr_elem, a, b;
    printf("Introduceti nr. de elemente: \n\n");
    if (scanf("%d", &nr_elem) != 1) return;
    printf("Introduceti valoarea minima < - > maxima pentru valorile vectorului: ");
    if (scanf("%d %d", &a, &b) != 2) return;

    int *arr = generate_random_array(nr_elem, a, b);
    if (nr_elem <= 0 || !arr){
        printf("Eroare!\n");
        free(arr);
        return;
    }

    printf("Vector initial: ");
    print_array(arr, nr_elem);

    bucketSortLogic(arr,nr_elem - 1);

    printf("Vector sortat: ");
    print_array(arr, nr_elem);

    free(arr);
}
void merge(int* arr,int left,int mid,int right){
    int size1=mid-left+1;
    int size2=right-mid;
    int *left_subvector=malloc(size1*sizeof(int));
    int *right_subvector=malloc(size2*sizeof(int));
    for(int i=0;i<size1;i++){
        left_subvector[i]=arr[left+i];
    }
    for(int j=0;j<size2;j++){
        right_subvector[j]=arr[mid+j+1];
    }
    int i=0,j=0,k=left;
    while(i<size1&&j<size2){
        if(left_subvector[i]<=right_subvector[j]){
            arr[k++]=left_subvector[i++];
        }else{
            arr[k++]=right_subvector[j++];
        }
    }
    while(i<size1){
        arr[k++]=left_subvector[i++];
    }
    while(j<size2){
        arr[k++]=right_subvector[j++];
    }
    free(left_subvector);
    free(right_subvector);

}
void mergeSortLogicRecursiveCall(int*arr,int left_index,int right_index){
    if(left_index<right_index){
        int mid=left_index+(right_index-left_index)/2;
        mergeSortLogicRecursiveCall(arr,left,mid);
        mergeSortLogicRecursiveCall(arr,mid+1,right);
        
        mergeLogic(arr,left,mid,right);
    }
}
void mergeSortLogic(int*arr,int right_index){
    mergeSortLogicRecursiveCall(arr,0,right);
}
static void mergeSort(void){
      int nr_elem, a, b;
    printf("Introduceti nr. de elemente: \n\n");
    if (scanf("%d", &nr_elem) != 1) return;
    printf("Introduceti valoarea minima < - > maxima pentru valorile vectorului: ");
    if (scanf("%d %d", &a, &b) != 2) return;

    int *arr = generate_random_array(nr_elem, a, b);
    if (nr_elem <= 0 || !arr){
        printf("Eroare!\n");
        free(arr);
        return;
    }

    printf("Vector initial: ");
    print_array(arr, nr_elem);

    mergeSortLogic(arr,nr_elem - 1);

    printf("Vector sortat: ");
    print_array(arr, nr_elem);

    free(arr);
}

void shellSortLogic(int *arr,int n){
    for(int gap=n/2;gap>0;gap/=2){
        for(int i=gap;i<n;i++){
            int temp=arr[i];
            int j;
            for(j=i;j>=gap && arr[j-gap]>temp;j-=gap){
                arr[j]=arr[j-gap];
            }
            arr[j]=temp;
        }
    }
}
static void shellSort(void) {
    int nr_elem, a, b;

    printf("Introduceti nr. de elemente: ");
    if (scanf("%d", &nr_elem) != 1) return;

    printf("Introduceti valoarea minima < - > maxima pentru valorile vectorului: ");
    if (scanf("%d %d", &a, &b) != 2) return;

    int *arr = generate_random_array(nr_elem, a, b);
    if (nr_elem <= 0 || !arr) {
        printf("Eroare la generarea vectorului!\n");
        free(arr);
        return;
    }

    printf("Vector initial: ");
    print_array(arr, nr_elem);

    shellSortLogic(arr, nr_elem);

    printf("Vector sortat: ");
    print_array(arr, nr_elem);

    free(arr);
}
void heapify(int *arr,int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[left]>arr[largest]){
        largest=left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        int temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;
        heapify(arr,n,largest);
    }
}
void heapSortLogic(int*arr,int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
    for(int i=n-1;i>0;i--;){
        int temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        heapify(arr,i,0);
    }
}
static void heapSort(void){
     int nr_elem, a, b;

    printf("Introduceti nr. de elemente: ");
    if (scanf("%d", &nr_elem) != 1) return;

    printf("Introduceti valoarea minima < - > maxima pentru valorile vectorului: ");
    if (scanf("%d %d", &a, &b) != 2) return;

    int *arr = generate_random_array(nr_elem, a, b);
    if (nr_elem <= 0 || !arr) {
        printf("Eroare la generarea vectorului!\n");
        free(arr);
        return;
    }

    printf("Vector initial: ");
    print_array(arr, nr_elem);

    heapSortLogic(arr, nr_elem);

    printf("Vector sortat: ");
    print_array(arr, nr_elem);

    free(arr);
}

static void dfs(void){
    printf("DFS nu este inca implementat.\n");
}
static void bfs(void){
    printf("BFS nu este inca implementat.\n");
}
static void dijkstra(void){
    printf("Dijkstra nu este inca implementat.\n");
}
static void a_star(void){
    printf("A* nu este inca implementat.\n");
}
static void jump_search(void){
    printf("Jump Search nu este inca implementat.\n");
}

// ======================= Menus =======================
static void sort_algo_menu(void){
    int int_input;
    printf("\n Sortari \n");
    printf("1. Bubble Sort\n");
    printf("2. Quick Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Selection Sort\n");
    printf("5. Merge Sort \n");
    printf("6. Heap Sort \n");
    printf("7. Shell Sort \n");
    printf("8. Counting Sort\n");
    printf("9. Radix Sort \n");
    printf("10. Bucket Sort \n");
    printf("Alege :");
    if (scanf("%d", &int_input) ==1 && int_input>=1 && int_input<=10){
    switch(int_input){
        case 1:{
            clock_t f_time = clock();
            bubbleSort();
            f_time = clock() - f_time;
            double exec_time = ((double)f_time)/CLOCKS_PER_SEC;
            printf("Execution time - > %.7f seconds \n", exec_time);
            break;}
        case 2:{
            clock_t f_time = clock();
            quickSort();
            f_time = clock() - f_time;
            double exec_time = ((double)f_time)/CLOCKS_PER_SEC;
            printf("Execution time - > %.7f seconds \n", exec_time);
            break;}
        case 3:{
            clock_t f_time = clock();
            insertionSort();
            f_time = clock() - f_time;
            double exec_time = ((double)f_time)/CLOCKS_PER_SEC;
            printf("Execution time - > %.7f seconds \n", exec_time);
            break;}
        case 4:{
            clock_t f_time = clock();
            selectionSort();
            f_time = clock() - f_time;
            double exec_time = ((double)f_time)/CLOCKS_PER_SEC;
            printf("Execution time - > %.7f seconds \n", exec_time);
            break;}
        case 5:{
            clock_t f_time = clock();
            mergeSort();
            f_time = clock() - f_time;
            double exec_time = ((double)f_time)/CLOCKS_PER_SEC;
            printf("Execution time - > %.7f seconds \n", exec_time);
            break;}
        case 6:{
            clock_t f_time = clock();
            heapSort();
            f_time = clock() - f_time;
            double exec_time = ((double)f_time)/CLOCKS_PER_SEC;
            printf("Execution time - > %.7f seconds \n", exec_time);
            break;}
        case 7:{
            clock_t f_time = clock();
            shellSort();
            f_time = clock() - f_time;
            double exec_time = ((double)f_time)/CLOCKS_PER_SEC;
            printf("Execution time - > %.7f seconds \n", exec_time);
            break;}
        case 8:{
            clock_t f_time = clock();
            countingSort();
            f_time = clock() - f_time;
            double exec_time = ((double)f_time)/CLOCKS_PER_SEC;
            printf("Execution time - > %.7f seconds \n", exec_time);
            break;}
        case 9:{
            clock_t f_time = clock();
            radixSort();
            f_time = clock() - f_time;
            double exec_time = ((double)f_time)/CLOCKS_PER_SEC;
            printf("Execution time - > %.7f seconds \n", exec_time);
            break;}
        case 10:{
            clock_t f_time = clock();
            bucketSort();
            f_time = clock() - f_time;
            double exec_time = ((double)f_time)/CLOCKS_PER_SEC;
            printf("Execution time - > %.7f seconds \n", exec_time);
            break;}
        default:
            printf("Optiune invalida\n\n");
            break;
    }
}else{
    char char_input=int_input+'0';
    if(strcmp(char_input,"Q")==0){
        exit(0);
    }
    else if (strcmp(char_input,"q")==0){
        printf("\n");
        return;
    }
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
if (scanf("%d", &int_input) ==1 && int_input>=1 && int_input<=10){
    switch(int_input){
        case 1:{
            clock_t f_time = clock();
            dfs();
            f_time = clock() - f_time;
            double exec_time = ((double)f_time)/CLOCKS_PER_SEC;
            printf("Execution time - > %.7f seconds \n", exec_time);
            break;}
        case 2:{
            clock_t f_time = clock();
            bfs();
            f_time = clock() - f_time;
            double exec_time = ((double)f_time)/CLOCKS_PER_SEC;
            printf("Execution time - > %.7f seconds \n", exec_time);
            break;}
        case 3:{
            clock_t f_time = clock();
            dijkstra();
            f_time = clock() - f_time;
            double exec_time = ((double)f_time)/CLOCKS_PER_SEC;
            printf("Execution time - > %.7f seconds \n", exec_time);
            break;}
        case 4:{
            clock_t f_time = clock();
            a_star();
            f_time = clock() - f_time;
            double exec_time = ((double)f_time)/CLOCKS_PER_SEC;
            printf("Execution time - > %.7f seconds \n", exec_time);
            break;}
        case 5:{
            clock_t f_time = clock();
            jump_search();
            f_time = clock() - f_time;
            double exec_time = ((double)f_time)/CLOCKS_PER_SEC;
            printf("Execution time - > %.7f seconds \n", exec_time);
            break;}
        default: 
            printf("Optiune invalida\n");
            break;
    }
}else{
    char char_input=int_input+'0';
    if(strcmp(char_input,"Q")==0){
        exit(0);
    }
    else if (strcmp(char_input,"q")==0){
        printf("\n");
        return;
    }
}
}

int main(void){

    srand((unsigned)time(NULL));
    char *input=(char*)malloc(15*sizeof(char));
do {
    printf("Alege :\n1. Alg Sortari\n2. Alg Cautari\nIesire (q/Q)\n\n");
    if (scanf("%14s", input) != 1) return 0;

    if (strcmp(input, "1") == 0) {
        sort_algo_menu();
    } else if (strcmp(input, "2") == 0) {
        search_algo_menu();

    }else if (strcmp(input,"3")==0){
        more_info_menu();
    } 
    
    else if (strcmp(input, "q") == 0 || strcmp(input, "Q") == 0) {
        printf("Ai iesit din program!\n");
    } else {
        printf("Optiune invalida\n");
    }
} while (strcmp(input, "q") != 0 && strcmp(input, "Q") != 0);
free(input);
    return 0;
}
>>>>>>> 6135c0b (sm changes)

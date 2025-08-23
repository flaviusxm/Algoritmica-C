#include<stdio.h>
#include<malloc.h>

void sort_algo_menu(){

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
    printf("Introduceti elemente pentru a realiza sortari \n\n");
    printf("Numar elemente: ");
    
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
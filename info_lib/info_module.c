#include <stdio.h>
void info_bubble_sort(){ 
    printf("\n=== BUBBLE SORT ===\n\n");
    printf("Compara elemente adiacente si le interschimba daca sunt in ordinea gresita.\n");
    printf("La fiecare trecere prin lista, cel mai mare element 'urca' spre final.\n\n");

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

    printf("Complexitate spatiu:\n");
    printf("Complexitate spatiu: O(1) - sortare in loc\n\n");

    printf("\n=====================\n\n");

}

void info_insertion_sort(){
    printf("\n=== INSERTION SORT ===\n\n");


    printf("Pasi Insertion Sort:\n");
    printf("1. Consideram primul element ca fiind deja sortat\n");
    printf("2. Pentru fiecare element urmator (de la al doilea la ultimul):\n");
    printf("   - Il salvam ca 'key'\n");
    printf("   - Comparam key cu elementele din stanga (deja sortate)\n");
    printf("   - Mutam elementele mai mari decat key cu o pozitie la dreapta\n");
    printf("   - Inseram key in pozitia gasita\n\n");

    printf("Luam urmatorul exemplu: [6, 3, 8, 5, 2]\n\n");

    printf("Initial: [6, 3, 8, 5, 2]\n");
    printf("Primul element (6) este considerat sortat\n\n");

    printf("Trecerea 1 (key = 3):\n");
    printf("Compar 3 cu 6 => 3 < 6 => mut 6 la dreapta: [6, 6, 8, 5, 2]\n");
    printf("Am ajuns la inceput => insert 3: [3, 6, 8, 5, 2]\n\n");

    printf("Trecerea 2 (key = 8):\n");
    printf("Compar 8 cu 6 => 8 > 6 => stop, ramane pe loc: [3, 6, 8, 5, 2]\n\n");

    printf("Trecerea 3 (key = 5):\n");
    printf("Compar 5 cu 8 => 5 < 8 => mut 8: [3, 6, 8, 8, 2]\n");
    printf("Compar 5 cu 6 => 5 < 6 => mut 6: [3, 6, 6, 8, 2]\n");
    printf("Compar 5 cu 3 => 5 > 3 => stop, insert 5: [3, 5, 6, 8, 2]\n\n");

    printf("Trecerea 4 (key = 2):\n");
    printf("Compar 2 cu 8 => mut 8: [3, 5, 6, 8, 8]\n");
    printf("Compar 2 cu 6 => mut 6: [3, 5, 6, 6, 8]\n");
    printf("Compar 2 cu 5 => mut 5: [3, 5, 5, 6, 8]\n");
    printf("Compar 2 cu 3 => mut 3: [3, 3, 5, 6, 8]\n");
    printf("Am ajuns la inceput => insert 2: [2, 3, 5, 6, 8]\n\n");

    printf("Lista sortata final: [2, 3, 5, 6, 8]\n\n");

    printf("Complexitate timp:\n");
    printf("- Caz favorabil (lista sortata): O(n) - doar verificari\n");
    printf("- Caz mediu: O(n^2)\n");
    printf("- Caz defavorabil (lista invers sortata): O(n^2)\n\n");

    printf("Complexitate spatiu: O(1) - sortare in loc\n\n");

    printf("\n=======================\n\n");
}


void info_quick_sort() {
    printf("\n========== QUICK SORT ==========\n\n");

    printf("Quick Sort este un algoritm de sortare bazat pe principiul 'divide et impera'.\n");
    printf("Functioneaza astfel:\n");
    printf("  1. Alegem un element pivot din lista\n");
    printf("  2. Partitionam lista astfel incat:\n");
    printf("     - Elementele mai mici decat pivotul sa fie in stanga\n");
    printf("     - Elementele mai mari decat pivotul sa fie in dreapta\n");
    printf("     - Pivotul sa fie plasat in pozitia sa finala\n");
    printf("  3. Aplicam recursiv algoritmul pe sublistele din stanga si dreapta pivotului\n\n");

    printf("Exemplu detaliat: [6, 3, 8, 5, 2]\n\n");

    printf("PAS 1: Partiționare întreagă listă (pivot = 2 - ultimul element)\n");
    printf("Lista initiala: [6, 3, 8, 5, 2]\n");
    printf("Pivot = 2\n");
    printf("i = -1 (index pentru elemente mai mici decat pivot)\n");
    printf("j = 0: 6 > 2 => doar incrementam j\n");
    printf("j = 1: 3 > 2 => doar incrementam j\n");
    printf("j = 2: 8 > 2 => doar incrementam j\n");
    printf("j = 3: 5 > 2 => doar incrementam j\n");
    printf("j = 4: pivotul se muta la pozitia i+1 (0)\n");
    printf("DUPA PARTITION: [2, 3, 8, 5, 6]\n");
    printf("Pivotul 2 este acum in pozitia sa finala!\n\n");

    printf("PAS 2: Sortam sublista dreapta [3, 8, 5, 6] (pivot = 6)\n");
    printf("Lista: [3, 8, 5, 6]\n");
    printf("Pivot = 6\n");
    printf("i = -1\n");
    printf("j = 0: 3 < 6 => swap arr[0] cu arr[0] => i=0, j=1: [3, 8, 5, 6]\n");
    printf("j = 1: 8 > 6 => doar j++\n");
    printf("j = 2: 5 < 6 => swap arr[1] cu arr[2] => i=1, j=3: [3, 5, 8, 6]\n");
    printf("j = 3: pivot swap arr[i+1] cu arr[3] => swap arr[2] cu arr[3]\n");
    printf("DUPA PARTITION: [3, 5, 6, 8]\n");
    printf("Pivotul 6 este acum in pozitia sa finala!\n\n");

    printf("PAS 3: Sortam sublista stanga [3, 5] (pivot = 5)\n");
    printf("Lista: [3, 5]\n");
    printf("Pivot = 5\n");
    printf("i = -1\n");
    printf("j = 0: 3 < 5 => swap arr[0] cu arr[0] => i=0, j=1: [3, 5]\n");
    printf("j = 1: pivot swap arr[i+1] cu arr[1] => swap arr[1] cu arr[1]\n");
    printf("DUPA PARTITION: [3, 5]\n");
    printf("Pivotul 5 este in pozitia finala!\n\n");

    printf("PAS 4: Sublista [8] are doar un element => deja sortata\n\n");

    printf("REZULTAT FINAL: [2, 3, 5, 6, 8]\n\n");

    printf("Complexitate timp:\n");
    printf("  - Caz favorabil: O(n log n) - pivotul imparte lista in jumatati egale\n");
    printf("  - Caz mediu:     O(n log n)\n");
    printf("  - Caz defavorabil: O(n^2) - pivotul este cel mai mic/mare element\n\n");

    printf("Complexitate spatiu: O(log n) pentru stiva de recursivitate\n\n");

    printf("\n================================\n\n");
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
    printf("Min = 3, Max = 49\n");
    printf("Interval total: 49 - 3 = 46\n\n");

    // Pas 2 - explicatie putin mai clara
    printf("Pas 2: Alegem sa folosim 5 bucket-uri\n");
    printf("Lungime interval per bucket: 46 / 5 = 9.2 -> rotunjim la 10\n");
    printf("Bucket 0: [3 - 13)   -> valori 3-12\n");
    printf("Bucket 1: [13 - 23)  -> valori 13-22\n");
    printf("Bucket 2: [23 - 33)  -> valori 23-32\n");
    printf("Bucket 3: [33 - 43)  -> valori 33-42\n");
    printf("Bucket 4: [43 - 53)  -> valori 43-52\n\n");

    // Pas 3 - cu calcul explicit pentru fiecare
    printf("Pas 3: Repartizam valorile in bucket-uri:\n");
    printf("- 29 -> (29-3)/10 = 2.6 -> Bucket 2\n");
    printf("- 25 -> (25-3)/10 = 2.2 -> Bucket 2\n");
    printf("- 3  -> (3-3)/10 = 0    -> Bucket 0\n");
    printf("- 49 -> (49-3)/10 = 4.6 -> Bucket 4\n");
    printf("- 9  -> (9-3)/10 = 0.6  -> Bucket 0\n");
    printf("- 37 -> (37-3)/10 = 3.4 -> Bucket 3\n");
    printf("- 21 -> (21-3)/10 = 1.8 -> Bucket 1\n");
    printf("- 43 -> (43-3)/10 = 4.0 -> Bucket 4\n\n");

    printf("Bucket-urile dupa repartizare:\n");
    printf("Bucket 0: [3, 9]\n");
    printf("Bucket 1: [21]\n");
    printf("Bucket 2: [29, 25]\n"); 
    printf("Bucket 3: [37]\n");
    printf("Bucket 4: [49, 43]\n\n");

    // Pas 4
    printf("Pas 4: Sortam fiecare bucket (cu Insertion Sort):\n");
    printf("Bucket 0: [3, 9] -> deja sortat\n");
    printf("Bucket 1: [21] -> un singur element\n");
    printf("Bucket 2: [29, 25] -> sortat devine [25, 29]\n");
    printf("Bucket 3: [37] -> un singur element\n");
    printf("Bucket 4: [49, 43] -> sortat devine [43, 49]\n\n");

    // Pas 5
    printf("Pas 5: Concatenam toate bucket-urile in ordine:\n");
    printf("Bucket 0 + Bucket 1 + Bucket 2 + Bucket 3 + Bucket 4\n");
    printf("Rezultat final: [3, 9, 21, 25, 29, 37, 43, 49]\n\n");

    printf("Complexitate timp:\n");
    printf("- Caz optim (distributie uniforma): O(n + k) unde k = numar bucket-uri\n");
    printf("- Caz mediu: O(n + k)\n");
    printf("- Caz defavorabil (toate valorile in acelasi bucket): O(n^2)\n\n");

    printf("Complexitate spatiu: O(n + k) - memorie pentru bucket-uri si elemente\n\n");

    printf("Caracteristici:\n");
    printf("- In-place: NU (foloseste memorie suplimentara pentru bucket-uri)\n");
    printf("- Stabil: DA (daca sortarea interna este stabila)\n");
    printf("- Rapid pentru date distribuite uniform\n");
    printf("- Ideal pentru float-uri in intervalul [0,1)\n\n");

    printf("Cand e util Bucket Sort:\n");
    printf("- Cand valorile sunt distribuite uniform intr-un interval\n");
    printf("- Pentru date reale (float-uri) intre 0 si 1\n");
    printf("- Cand avem memorie suplimentara disponibila\n");
    printf("- In combinatie cu alti algoritmi pentru sortare externa\n");

    printf("\n=======================\n\n");
}

void info_selection_sort(){
    printf("\n=== SELECTION SORT ===\n\n");

    printf("Selection Sort este un algoritm simplu de sortare bazat pe selectia repetata a minimului.\n");
    printf("Functioneaza astfel:\n");
    printf("1. Impartim lista in 2 parti: partea sortata (stanga) si nesortata (dreapta)\n");
    printf("2. La fiecare pas, gasim cel mai mic element din partea nesortata\n");
    printf("3. Il schimbam cu primul element din partea nesortata\n");
    printf("4. Extindem partea sortata cu un element\n\n");

    printf("Sa luam exemplul: [29, 10, 14, 37, 13]\n\n");

    printf("Initial: [29, 10, 14, 37, 13]\n");
    printf("Partea sortata: [] | Partea nesortata: [29, 10, 14, 37, 13]\n\n");

    // Pas 1
    printf("Pas 1: Cautam minimul in partea nesortata [29, 10, 14, 37, 13]\n");
    printf("Minimul este 10 (la index 1)\n");
    printf("Schimbam 10 cu primul element (29) => [10, 29, 14, 37, 13]\n");
    printf("Partea sortata: [10] | Partea nesortata: [29, 14, 37, 13]\n\n");

    // Pas 2
    printf("Pas 2: Cautam minimul in [29, 14, 37, 13]\n");
    printf("Minimul este 13 (la index 4)\n");
    printf("Schimbam 13 cu primul element (29) => [10, 13, 14, 37, 29]\n");
    printf("Partea sortata: [10, 13] | Partea nesortata: [14, 37, 29]\n\n");

    // Pas 3
    printf("Pas 3: Cautam minimul in [14, 37, 29]\n");
    printf("Minimul este 14 (la index 2) - deja pe pozitia corecta\n");
    printf("Nu este necesar swap => [10, 13, 14, 37, 29]\n");
    printf("Partea sortata: [10, 13, 14] | Partea nesortata: [37, 29]\n\n");

    // Pas 4
    printf("Pas 4: Cautam minimul in [37, 29]\n");
    printf("Minimul este 29 (la index 4)\n");
    printf("Schimbam 29 cu primul element (37) => [10, 13, 14, 29, 37]\n");
    printf("Partea sortata: [10, 13, 14, 29] | Partea nesortata: [37]\n\n");

    // Pas 5
    printf("Pas 5: Partea nesortata are doar un element [37] - deja sortat\n");
    printf("Lista finala sortata: [10, 13, 14, 29, 37]\n\n");

    printf("Complexitate timp:\n");
    printf("- Caz favorabil: O(n^2)\n");
    printf("- Caz mediu: O(n^2)\n");
    printf("- Caz defavorabil: O(n^2)\n");

    printf("Complexitate spatiu: O(1) - sortare in loc\n\n");

    printf("\n=======================\n\n");
}
void info_merge_sort(){
    printf("\n=== MERGE SORT ===\n\n");

    printf("Merge Sort este un algoritm eficient si stabil, bazat pe strategia 'divide et impera'.\n");
    printf("Functioneaza in doua etape principale:\n");
    printf("1. DIVIDE: Imparte recursiv lista in subliste mai mici pana ajunge la subliste de 1 element\n");
    printf("2. IMPERA: Interclaseaza (merge) sublistele in ordine sortata\n\n");

    printf("Exemplu detaliat: [38, 27, 43, 3, 9, 82, 10]\n\n");

    printf("=== FAZA DE DIVIZARE ===\n");
    printf("Nivel 0: [38, 27, 43, 3, 9, 82, 10]\n");
    printf("Nivel 1: [38, 27, 43] si [3, 9, 82, 10]\n");
    printf("Nivel 2: [38], [27, 43], [3, 9], [82, 10]\n");
    printf("Nivel 3: [38], [27], [43], [3], [9], [82], [10]\n\n");

    printf("=== FAZA DE INTERCLASARE ===\n");
    
    printf("Interclasare nivel 3 -> nivel 2:\n");
    printf("[27] si [43] => compar 27 cu 43 => [27, 43]\n");
    printf("[3] si [9] => compar 3 cu 9 => [3, 9]\n");
    printf("[82] si [10] => compar 82 cu 10 => [10, 82]\n");
    printf("Dupa interclasare nivel 2: [38], [27, 43], [3, 9], [10, 82]\n\n");

    printf("Interclasare nivel 2 -> nivel 1:\n");
    printf("[38] si [27, 43]:\n");
    printf("  Compar 38 cu 27 => adaug 27 => [27]\n");
    printf("  Compar 38 cu 43 => adaug 38 => [27, 38]\n");
    printf("  Ramane 43 => adaug 43 => [27, 38, 43]\n");
    
    printf("[3, 9] si [10, 82]:\n");
    printf("  Compar 3 cu 10 => adaug 3 => [3]\n");
    printf("  Compar 9 cu 10 => adaug 9 => [3, 9]\n");
    printf("  Ramane [10, 82] => adaug 10, 82 => [3, 9, 10, 82]\n");
    printf("Dupa interclasare nivel 1: [27, 38, 43] si [3, 9, 10, 82]\n\n");

    printf("Interclasare nivel 1 -> nivel 0 (final):\n");
    printf("[27, 38, 43] si [3, 9, 10, 82]:\n");
    printf("  Compar 27 cu 3 => adaug 3 => [3]\n");
    printf("  Compar 27 cu 9 => adaug 9 => [3, 9]\n");
    printf("  Compar 27 cu 10 => adaug 10 => [3, 9, 10]\n");
    printf("  Compar 27 cu 82 => adaug 27 => [3, 9, 10, 27]\n");
    printf("  Compar 38 cu 82 => adaug 38 => [3, 9, 10, 27, 38]\n");
    printf("  Compar 43 cu 82 => adaug 43 => [3, 9, 10, 27, 38, 43]\n");
    printf("  Ramane 82 => adaug 82 => [3, 9, 10, 27, 38, 43, 82]\n\n");

    printf("REZULTAT FINAL: [3, 9, 10, 27, 38, 43, 82]\n\n");

    printf("Complexitate timp:\n");
    printf("- Caz favorabil: O(n log n)\n");
    printf("- Caz mediu: O(n log n)\n");
    printf("- Caz defavorabil: O(n log n)\n");

    printf("Complexitate spatiu: O(n) - necesita memorie auxiliara pentru interclasare\n\n");

    printf("Procesul de interclasare (merge):\n");
    printf("- Se folosesc doi pointeri, unul pentru fiecare sublista\n");
    printf("- Se compara elementele de la pointeri si se alege minimul\n");
    printf("- Se avanseaza pointerul pentru sublista din care s-a ales elementul\n");
    printf("- Se repeta pana se epuizeaza ambele subliste\n\n");

    printf("\n=======================\n\n");
}

void info_heap_sort(){
    printf("\n=== HEAP SORT ===\n\n");

    printf("Heap Sort este un algoritm de sortare bazat pe structura de date Heap (ansamblu).\n");
    printf("Utilizeaza un max-heap unde radacina este intotdeauna elementul maxim.\n");
    printf("Algoritmul functioneaza in doua etape principale:\n");
    printf("1. BUILD-HEAP: Construim un max-heap din lista initiala\n");
    printf("2. SORTARE: Extragem repetat maximul si refacem heap-ul\n\n");

    printf("Exemplu detaliat: [4, 10, 3, 5, 1]\n\n");

    printf("=== CONSTRUIRE MAX-HEAP ===\n");
    printf("Lista initiala: [4, 10, 3, 5, 1]\n");
    printf("Reprezentare arbore:\n");
    printf("        4\n");
    printf("      /   \\\n");
    printf("     10    3\n");
    printf("    /  \\\n");
    printf("   5    1\n\n");

    printf("Heap-ificare de la coada la radacina:\n");
    printf("Nod 5 (val 5): frunza => OK\n");
    printf("Nod 10 (val 10): compar cu fii 5 si 1 => 10 > 5 si 10 > 1 => OK\n");
    printf("Nod 3 (val 3): frunza => OK\n");
    printf("Nod 4 (val 4): compar cu fii 10 si 3 => 4 < 10 => SWAP cu 10\n");
    printf("Arbore dupa swap:\n");
    printf("        10\n");
    printf("      /   \\\n");
    printf("     4     3\n");
    printf("    /  \\\n");
    printf("   5    1\n\n");

    printf("Continuam heap-ificare subarbore:\n");
    printf("Nod 4 (val 4): compar cu fii 5 si 1 => 4 < 5 => SWAP cu 5\n");
    printf("Arbore final max-heap:\n");
    printf("        10\n");
    printf("      /   \\\n");
    printf("     5     3\n");
    printf("    /  \\\n");
    printf("   4    1\n");
    printf("Lista dupa build-heap: [10, 5, 3, 4, 1]\n\n");

    printf("=== FAZA DE SORTARE ===\n");
    
    printf("Pas 1: Extragem maximul (10) si il schimbam cu ultimul element (1)\n");
    printf("Swap: [10, 5, 3, 4, 1] => [1, 5, 3, 4, 10]\n");
    printf("Heap-ificam din radacina (1):\n");
    printf("Compar 1 cu fii 5 si 3 => 1 < 5 => SWAP cu 5\n");
    printf("Dupa heap-ificare: [5, 1, 3, 4, 10]\n");
    printf("Element sortat: [10]\n\n");

    printf("Pas 2: Extragem maximul (5) si il schimbam cu ultimul (4)\n");
    printf("Swap: [5, 1, 3, 4, 10] => [4, 1, 3, 5, 10]\n");
    printf("Heap-ificam din radacina (4):\n");
    printf("Compar 4 cu fii 1 si 3 => 4 > 1 dar 4 < 3? (Gresit - corect: 4 > 1 si 4 > 3?)\n");
    printf("Corect: 4 > 1 si 4 > 3? Da, 4 > 3 => ramane pe loc\n");
    printf("Dupa heap-ificare: [4, 1, 3, 5, 10]\n");
    printf("Elemente sortati: [5, 10]\n\n");

    printf("Pas 3: Extragem maximul (4) si il schimbam cu ultimul (3)\n");
    printf("Swap: [4, 1, 3, 5, 10] => [3, 1, 4, 5, 10]\n");
    printf("Heap-ificam din radacina (3):\n");
    printf("Compar 3 cu fii 1 si 4 => 3 < 4 => SWAP cu 4\n");
    printf("Dupa heap-ificare: [4, 1, 3, 5, 10]\n");
    printf("Elemente sortati: [4, 5, 10]\n\n");

    printf("Pas 4: Extragem maximul (4) si il schimbam cu ultimul (1)\n");
    printf("Swap: [4, 1, 3, 5, 10] => [1, 4, 3, 5, 10]\n");
    printf("Heap-ificam din radacina (1):\n");
    printf("Compar 1 cu fii 4 si 3 => 1 < 4 => SWAP cu 4\n");
    printf("Dupa heap-ificare: [4, 1, 3, 5, 10]\n");
    printf("Elemente sortati: [3, 4, 5, 10]\n\n");

    printf("Pas 5: Ultimul element (1) este deja singur => sortat\n");
    printf("REZULTAT FINAL: [1, 3, 4, 5, 10]\n\n");

    printf("Complexitate timp:\n");
    printf("- Build-Heap: O(n)\n");
    printf("- n extrageri cu heap-ificare: O(n log n)\n");
    printf("- Total: O(n log n) in toate cazurile\n\n");

    printf("Complexitate spatiu: O(1) - sortare in loc\n\n");

    printf("\n=======================\n\n");
}
void info_radix_sort(){
    printf("\n=== RADIX SORT ===\n\n");

    printf("Radix Sort este un algoritm de sortare care proceseaza numerele cifra cu cifra,\n");
    printf("incepand de la cifra cea mai putin semnificativa (LSD - Least Significant Digit).\n");
    printf("Foloseste un algoritm stabil (de obicei Counting Sort) pentru sortarea pe fiecare cifra.\n\n");

    printf("Etapele algoritmului:\n");
    printf("1. Gasim numarul maxim pentru a determina numarul de cifre\n");
    printf("2. Pentru fiecare cifra (de la unitati la cifra maxima):\n");
    printf("   - Distribuim numerele in 10 coșuri (0-9) dupa cifra curenta\n");
    printf("   - Reasamblam numerele in ordinea coșurilor 0-9\n");
    printf("   - Pastram ordinea relativa a numerelor cu aceeasi cifra\n\n");

    printf("Exemplu detaliat: [170, 45, 75, 90, 802, 24, 2, 66]\n\n");

    printf("Pas 0: Gasim numarul maxim = 802 (3 cifre) => vom face 3 treceri\n\n");

    printf("=== TRECEREA 1 - CIFRA UNITATILOR ===\n");
    printf("Sortam dupa ultima cifra:\n");
    printf("Coș 0: 170, 090, 802, 002\n");
    printf("Coș 1: \n");
    printf("Coș 2: \n");
    printf("Coș 3: \n");
    printf("Coș 4: 024\n");
    printf("Coș 5: 045, 075\n");
    printf("Coș 6: 066\n");
    printf("Coș 7: \n");
    printf("Coș 8: \n");
    printf("Coș 9: \n");
    printf("Reasamblam din coșuri: [170, 90, 802, 2, 24, 45, 75, 66]\n\n");

    printf("=== TRECEREA 2 - CIFRA ZECILOR ===\n");
    printf("Sortam dupa a doua cifra (pastrand ordinea din trecerea anterioara):\n");
    printf("Coș 0: 802, 002\n");
    printf("Coș 1: \n");
    printf("Coș 2: 024, 024\n");
    printf("Coș 3: \n");
    printf("Coș 4: 045\n");
    printf("Coș 5: \n");
    printf("Coș 6: 066\n");
    printf("Coș 7: 170, 075\n");
    printf("Coș 8: \n");
    printf("Coș 9: 090\n");
    printf("Reasamblam din coșuri: [802, 2, 24, 45, 66, 170, 75, 90]\n\n");

    printf("=== TRECEREA 3 - CIFRA SUTELOR ===\n");
    printf("Sortam dupa a treia cifra (pastrand ordinea din trecerile anterioare):\n");
    printf("Coș 0: 002, 024, 045, 066, 075, 090\n");
    printf("Coș 1: 170\n");
    printf("Coș 2: \n");
    printf("Coș 3: \n");
    printf("Coș 4: \n");
    printf("Coș 5: \n");
    printf("Coș 6: \n");
    printf("Coș 7: \n");
    printf("Coș 8: 802\n");
    printf("Coș 9: \n");
    printf("Reasamblam din coșuri: [2, 24, 45, 66, 75, 90, 170, 802]\n\n");

    printf("REZULTAT FINAL: [2, 24, 45, 66, 75, 90, 170, 802]\n\n");

    printf("Complexitate timp:\n");
    printf("- O(d * (n + k)) unde:\n");
    printf("  d = numarul de cifre ale celui mai mare numar\n");
    printf("  n = numarul de elemente de sortat\n");
    printf("  k = baza (10 pentru zecimal)\n");
    printf("- In practica: O(d * n) deoarece k = 10 este constant\n\n");

    printf("Complexitate spatiu: O(n + k) - necesita memorie pentru coșuri\n\n");

    

    printf("\n=======================\n\n");
}
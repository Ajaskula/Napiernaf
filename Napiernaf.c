#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
/*funkcja void iton(int x, int **a, int *n) zapisuje reprezentacje liczby x w dynamicznie zalokowanej n-elementowej tablicy a
zgodnie z konwencją napier-NAF*/
void iton(int x, int **a, int *n){//podaje tablicę i jej rozmiar, który będę dynamicznie zmianiał
    int *wynik=NULL;//deklaruję wskaźnik na tymczasową tablicę
    int rozmiar=0;//na początku ustawiam rozmiar tablicy na zero
    int i=0;//iterator pętli
    int y=-x;//zmienna pomocnicza, której użyję gdy podana do zaprezentowania liczba będzie ujemna

    if(x==2147483647){//rozpatruje przypadki dla których zastosowana później metoda nie zadziała

        rozmiar=2;//rozmiar tablicy
        wynik=realloc(wynik,(size_t) rozmiar*sizeof *wynik);//wynik staje się wskaźnikiem na nową tablicę
        assert(wynik!=NULL);//sprawdzam czy wynik nie jest NULL'em. Dla bezpieczeństwa
        wynik[0]=-1;//odpowiednie wartości w komórkach tablicy
        wynik[1]=31;

    }

    if(x==-2147483647){//przypadek skrajny

        rozmiar=2;//rozmiar tablicy
        wynik=realloc(wynik,(size_t) rozmiar*sizeof *wynik);//wynik staje się wskaźnikiem na nową tablicę
        assert(wynik!=NULL);//sprawdzam czy wynik nie jest NULL'em. Dla bezpieczeństwa
        wynik[0]=0;//odpowiednie wartości w komórkach tablicy
        wynik[1]=-32;

    }

    if(x==-2147483648){//przypadek skrajny

        rozmiar=1;//rozmiar tablicy
        wynik=realloc(wynik,(size_t) rozmiar*sizeof *wynik);//wynik staje się wskaźnikiem na nową tablicę
        assert(wynik!=NULL);//sprawdzam czy wynik nie jest NULL'em. Dla bezpieczeństwa
        wynik[0]=-32;//odpowiednia wartość w komórce tablic

    }

    if(x>0&&x!=2147483647){//kiedy x jest dodatni i nie spełnia powyższych warunków

        while(x>0){//dopóki podana liczba jest większa od zera wykonuje algorytm

            if(x%2!=0){//jeśli nieparzysta

                rozmiar++;//zwiększamy rozmiar tablicy o 1
                wynik=realloc(wynik,(size_t) rozmiar*sizeof *wynik);//wynik staje się wskaźnikiem na nową, większą tablicę
                assert(wynik!=NULL);//sprawdzam czy wynik nie jest NULL'em. Dla bezpieczeństwa

                if(2-x%4>0)//warunek deycujący co zapisuję do ostatniego miejsca tablicy

                    wynik[rozmiar-1]=i;//zapisujemy na ostatnie miejse w tablicy odpowiednią wartość

                else

                    wynik[rozmiar-1]=-i-1;//zapisuje na odpowiednie miejsce w tabeli odpowiednią wartość

                x-=2-x%4;//zmieniamy wartość x zgodnie z widoczną formułą
            }
        x=x/2;//zmieniamy wartość x
        i++;//inkrementujemy iterator pętli
        }
    }
    if(x<0&&x>-2147483647){//jeśli x nie spełnia wyższych warunków i jest ujemny

        while(y>0){//dopóki podana liczba jest większa od zera

            if(y%2!=0){//jeśli pezekazana przez nas liczba jest nieparzysta

                rozmiar++;//zwiększamy rozmair tablicy
                wynik=realloc(wynik,(size_t) rozmiar*sizeof *wynik);//wynik staje się wskaźnikiem na nową większą tablicę
                assert(wynik!=NULL);//sprawdzam czy wynik nie jest NULL'em. Dla bezpieczeństwa

                if(2-y%4>0)

                    wynik[rozmiar-1]=-i-1;//zapisujemy jako wynik 1 lub -1

                else

                    wynik[rozmiar-1]=i;//zapiesuję do tablicy odpowiednią wartość

                y-=2-y%4;//modyfukuje wartość y
            }
        y=y/2;//y/2
        i++;//zwiększam iterator pętli
        }
    }
    *a=wynik;//wskaźnik do tablicy a staje się wskaźnikiem na początek tablicy do której zapisujemy kolejne znaki 
    *n=rozmiar;//wartość wielkości tablicy staje się równa iteratorowi
}
/*funkcja ntoi przyjmuję n-elementową tablicę, w której zaprezentowana jest liczba w systemie napier-NAF.
Funkcja zwraca zaprezentowaną w tablicy liczbę jako liczbę w systemie dziesiętnym jeśli mieści się ona
w zakresie typu int, w przeciwnym wypadku zwraca 0*/
int ntoi(int *a, int n){
    if(n>0&&a[n-1]>32)//jeśli ostatnia liczba w tablicy jest większa niż 32

        return 0;//zwracamy 0

    if(n>0&&a[n-1]<-33)//jeśli ostatnia liczba w tablicy jest mniejsza niż -33

        return 0;//zwracamy 0

    long long int wynik=0;//tworzymy zmienną która będzie reprezentować wynik, i którą zwrócimy

    //tworzymy lokalną kopię tablicy, aby nie modyfikowac danych wejściowych
    int *a_copy=NULL;//wskaźnik
    int a_size=n;//rozmiar tablicy
    a_copy=realloc(a_copy,(size_t) (a_size)*sizeof(int));//alokujemy tablicę

    for(int i=0; i<a_size; i++){//kopiujemy wartości podanej tablicy

        a_copy[i]=a[i];

    }

    int pom=1;//zmienna pomocnicza, która pomoże nam w obliczeniu wartości wyniku

    while(a_size>0){

        if(a_copy[0]==0)
        wynik+=pom;//dodaję zmienną pomocniczą do wyniku
        if(a_copy[0]==-1)
        wynik-=pom;//odejmuje zmienną pomocniczą od wyniku
        pom+=pom;//zwiększam zmienną pomocniczą
        
        
        if(a_copy[0]==0||a_copy[0]==-1){//jeśli tablica zaczyna się w ten sposób będziemy ją skracać

            int *a_copy2=NULL;//tworzymy wskaźnik na nową tablicę
            int a_size2=a_size-1;//rozmiar nowej tablicy będzie o 1 mniejszy od razmiaru tablicy a_copy
            a_copy2=realloc(a_copy2,(size_t) (a_size2)*sizeof(int));//alokujemy tablicę a_copy2

            for(int i=0; i<a_size2; i++){

                a_copy2[i]=a_copy[i+1];//kopiujemy wartości tablicy a_copy do tablicy a_copy2 zaczynając od drugiego elementu

            }

        a_copy=realloc(a_copy,(size_t) (a_size--)*sizeof(int));//zmiejszamy tablicę a_copy

        for(int i=0;i<a_size;i++){

            a_copy[i]=a_copy2[i];//przepisujemy do tablicy a_copy wartości z tablicy a_copy2

        }

        free(a_copy2);//zwalniamy tablicę pomocniczą a_copy2

        }

        if(a_size>0)//jeśli rozmiar tablicy a_copy jest większy od zera to zmieniamy wartości w tablicy

            for(int i=0; i<a_size; i++){

                if(a_copy[i]>0)//jeśli element i-ty jest dodatni

                    a_copy[i]--;//zmiejszmy i-ty element tablicy

                if(a_copy[i]<-1)//jeśli jest mniejszy od -1

                    a_copy[i]++;//zwiększamy i-ty element tablicy

            }

    }

    free(a_copy);//zwalniamy pomocniczą tablicę 

    if(wynik<=2147483647&&wynik>=-2147483648)//jeśli spełniony jest warunek

        return (int)wynik;//zwracamy wynik

    return 0;//zwracamy 0
}

/*funkcja dodaje dwie liczby zaprezentowane w namier-NAF w an-elementowej tablicy a i bn-elementowej tablicy b
funkcja zwraca reprezentację sumy w cn-elementowej tablicy c*/
void nadd(int *a, int an, int *b, int bn, int **c, int *cn){

//ustawiam rozmiar tablicy wynikowej na zero i alokuje taką ilość pamięci
(*cn)=0;
(*c)=malloc((size_t)(*cn)*sizeof(int));

int rozmiar_c=0;//przechowuje informacje o rozmiare tablicy c
int ja=0;//iterator tablicy a
int jb=0;//iterator tablicy b
int p_a;//informuję do jakiej potęgi 2 odnosi sie element w komórce tablicy a
int p_b;//informuję do jakiej potęgi 2 odnosi sie element w komórce tablicy b

//dopóki oba iteratory nie osiągną romziarów tablic będziemy po nich spacerować
while(ja<an||jb<bn){

    if(ja>=an&&jb<bn){//dopisujemy resztę tablicy b

        rozmiar_c++;//zwiększamy zmienną przechowywującą wartość rozmiaru tablicy c
        *c=realloc(*c,(size_t) rozmiar_c*sizeof(int));//alokujemy odpowiednią ilość pamięci
        assert(*c!=NULL);//sprawdzam czy *c nie jest NULL'em. Dla bezpieczeństwa
        (*c)[rozmiar_c-1]=b[jb];//uzupełniamy ostatni element tablicy b
        jb++;//inkrementujemy iterator tablicy b

    }

    if(ja<an&&jb>=bn){//dopisuje resztę tablicy a

        rozmiar_c++;//zwiększamy zmienną przechowywującą wartość rozmiaru tablicy c
        *c=realloc(*c,(size_t) rozmiar_c*sizeof(int));//alokujemy odpowiednią ilość pamięci
        assert((*c)!=NULL);//sprawdzam czy *c nie jest NULL'em. Dla bezpieczeństwa
        (*c)[rozmiar_c-1]=a[ja];//uzupełniamy ostatni element tablicy a
        ja++;//inkrementujemy iterator tablicy a

    }

    if(ja<an&&jb<bn){//sprawdzamy, na którą komórkę patrzymy

        if(a[ja]>=0)//jeśli ja-ty element jest >=0

            p_a=a[ja];//spawdzamy 2 do jakiej potęgi odnosi się ja-ty element tablicy a

        else//w przeciwnym wypadku

            p_a=-a[ja]-1;//spawdzamy 2 do jakiej potęgi odnosi się ja-ty element tablicy a

        if(b[jb]>=0)//jeśli jb-ty element jest >=o

            p_b=b[jb];//spawdzamy 2 do jakiej potęgi odnosi się ja-ty element tablicy b

        else//w przeciwnym wypadku

            p_b=-b[jb]-1;//spawdzamy 2 do jakiej potęgi odnosi się ja-ty element tablicy b


        if(p_a>p_b){//p_b wskazuje na mniejszy element
        
            rozmiar_c++;//zwiększam informację o ramizarze tablicy c
            *c=realloc(*c,(size_t) rozmiar_c*sizeof(int));//alokuje odpowiednią ilość pamięci
            assert((*c)!=NULL);//sprawdzam czy *c nie jest NULL'em. Dla bezpieczeństwa
            (*c)[rozmiar_c-1]=b[jb];//zapisuję na ostatni element tablicy c odpowiedni element z b
            jb++;//inkrementuje iterator tablicy b

        }

        if(p_b>p_a){//p_a wskazuje na mniejszy element
        
            rozmiar_c++;//zwiększam informację o ramizarze tablicy c
            *c=realloc(*c,(size_t) rozmiar_c*sizeof(int));//alokuje odpowiednią ilość pamięci
            assert((*c)!=NULL);//sprawdzam czy *c nie jest NULL'em. Dla bezpieczeństwa
            (*c)[rozmiar_c-1]=a[ja];//zapisuję na ostatni element tablicy c odpowiedni element z a
            ja++;//inkrementuje iterator tablicy a

        }

        if(p_a==p_b){//oba elementy wskazują na element takiej samej wagi

            if(a[ja]>=0&&b[jb]>=0){//jeśli oba odnoszą się do wartości dodatniej przekazujemy o 1 więcej niż wartość do tablicy c

                rozmiar_c++;//zwiększam informację o rozmiarze tablicy c
                *c=realloc(*c,(size_t) rozmiar_c*sizeof(int));//alokuje odpowiednią ilość pamięci
                assert((*c)!=NULL);//sprawdzam czy *c nie jest NULL'em. Dla bezpieczeństwa
                (*c)[rozmiar_c-1]=a[ja]+1;//zapisuję odpowiednio ostatni element tablicy c

            }

            if(a[ja]<0&&b[jb]<0){//jeśli oba elementy odnoszą się do wartości ujemnej przekazujemy o 1 mniej niż wartość do tablic c

                rozmiar_c++;//zwiększam informację o rozmiarze tablicy c
                *c=realloc(*c,(size_t) rozmiar_c*sizeof(int));
                assert((*c)!=NULL);//sprawdzam czy *c nie jest NULL'em. Dla bezpieczeństwa
                (*c)[rozmiar_c-1]=a[ja]-1;//zapisuję odpowiednio ostatni element tablicy c

            }

            ja++;//inkrementuje oba iteratory
            jb++;//

        }
    }
    //w zależności od tego jakie są ostatnie dwa elementy tablicy c modyfiukjemy je w taki sposób aby zachowywały napier-NAF
        if(rozmiar_c>1&&(*c)[rozmiar_c-1]>=0&&(*c)[rozmiar_c-2]>=0){//jeśli oba są dodatnie
        
            if((*c)[rozmiar_c-1]-(*c)[rozmiar_c-2]==1){//różnica jest równa 1

            (*c)[rozmiar_c-2]=-1-(*c)[rozmiar_c-2];
            (*c)[rozmiar_c-1]++;

            }

            if((*c)[rozmiar_c-1]-(*c)[rozmiar_c-2]==0){
            
                (*c)[rozmiar_c-2]++;
                rozmiar_c--;
                *c=realloc(*c,(size_t) rozmiar_c*sizeof(int));
            }
        }
        
        if(rozmiar_c>1&&(*c)[rozmiar_c-1]<0&&(*c)[rozmiar_c-2]<0){//jeśli oba są ujemne
        
            if((*c)[rozmiar_c-1]-(*c)[rozmiar_c-2]==-1){
                (*c)[rozmiar_c-1]--;
                (*c)[rozmiar_c-2]=-1-(*c)[rozmiar_c-2];

            }

             if((*c)[rozmiar_c-1]-(*c)[rozmiar_c-2]==0){
            
                (*c)[rozmiar_c-2]--;
                rozmiar_c--;
                *c=realloc(*c,(size_t) rozmiar_c*sizeof(int));

            }
        }

        if(rozmiar_c>1&&(*c)[rozmiar_c-1]>=0&&(*c)[rozmiar_c-2]<0){//poprzednie jest mniejsze
        
            if((*c)[rozmiar_c-1]==abs((*c)[rozmiar_c-2])){//skracamy tablice
            
                (*c)[rozmiar_c-2]=-1+(*c)[rozmiar_c-1];
                rozmiar_c--;
                *c=realloc(*c,(size_t) rozmiar_c*sizeof(int));

            }

            if(rozmiar_c>1&&(*c)[rozmiar_c-1]==abs((*c)[rozmiar_c-2]+1)){//skracamy tablicę

                rozmiar_c-=2;
                *c=realloc(*c,(size_t) rozmiar_c*sizeof(int));

            }
        }

        if(rozmiar_c>1&&(*c)[rozmiar_c-1]<0&&(*c)[rozmiar_c-2>=0]){//poprzednie jest większe
        
            if((*c)[rozmiar_c-1]+(*c)[rozmiar_c-2]==-2){//skracamy tablice

            (*c)[rozmiar_c-2]=1+(*c)[rozmiar_c-1];
            rozmiar_c--;
            *c=realloc(*c,(size_t) rozmiar_c*sizeof(int));

            }
            
            if(rozmiar_c>1&&(*c)[rozmiar_c-1]+(*c)[rozmiar_c-2]==-1){
                rozmiar_c-=2;
                *c=realloc(*c,(size_t) rozmiar_c*sizeof(int));

            }
        }

} 
*cn=rozmiar_c;//zapisuje rozmiar c na wskaźnik do romziaru tablic c
}

//funkcja pomocnicza obliczająca wartość bezwzględną liczby
int abs(int x){

    if(x>0)

        return x;

    else

        return -x;

}

/*funkcja odejmuje dwie liczby zaprezentowane w namier-NAF w an-elementowej tablicy a i bn-elementowej tablicy b
funkcja zwraca reprezentację sumy w cn-elementowej tablicy c*/
void nsub(int *a, int an, int *b, int bn, int **c, int *cn){

//tworzymy kopię tablicy b, aby nie niszczyć danych wejściowych
int *b_copy=NULL;
int size_b_copy=bn;
b_copy=realloc(b_copy,(size_t) (size_b_copy)*sizeof(int));

for(int i=0; i<size_b_copy;i++){//zamieniam liczbę w tablicy b_copy na liczbę do niej przeciwną

    b_copy[i]=-b[i]-1;

}

nadd(a, an, b_copy, size_b_copy, &(*c), cn);//dodaję liczbę z tablicy a i liczbę przeciwną do liczby z tablicy b
free(b_copy);//zwalniam tablicę pomocniczą
}

/*funkcja mnoży dwie liczby z tablic a i b i wynika zapisuje do cn-elementowej tablicy c*/
void nmul(int *a, int an, int *b, int bn, int **c, int *cn){
//dla bezpieczeństwa ustawiam rozmiar tablicy c na zero i alokuje taką ilość pamięci
(*cn)=0;
*c=malloc((size_t)(*cn)*sizeof(int));

for(int j=0; j<bn; j++){//pętla porusza się po kolejnych elementach tablicy b

    int *temporary_Arrey=NULL;//przy każdej zmianie j będziemy tworzyć nową tymczasową tablicę
    int temporary_Size=0;//ustalamy jej rozmiar

    for(int i=0; i<an; i++){//pętla porusza się po kolejnych elementach tablicy a

        if(temporary_Size==i){//jeśli rozmiar tymczasowej tablicy jest równy iteratorowi pętli

            temporary_Size++;//zwiększam rozmiar tablicy tymczasowej
            temporary_Arrey=realloc(temporary_Arrey,(size_t) temporary_Size*sizeof *temporary_Arrey);//alokuje pamięć

            if(a[i]>=0&&b[j]>=0){//jeśli oba nieujemne

                temporary_Arrey[temporary_Size-1]=a[i]+b[j];//zapiuję odpowiednią wartość do tablicy

                }else if(a[i]<0&&b[j]<0){//jeśli oba ujemne

                    temporary_Arrey[temporary_Size-1]=-a[i]-b[j]-2;//zapiuję odpowiednią wartość do tablicy

                    }else{//jeśli wariacje

                        int suma=0;//pomocnicza zmienna do zapisu kolejnego elementu tymczasowej tablicy

                        if(a[i]>=0)

                            suma+=a[i];//modyfikuję sumę

                        else

                             suma+=abs(a[i]+1);//modyfikuję sumę

                        if(b[j]>=0)

                            suma+=b[j];//modyfikuję sumę

                        else

                            suma+=abs(b[j]+1);//modyfikuję sumę

                        if(suma>=0)

                            temporary_Arrey[temporary_Size-1]=-suma-1;//zapisuję wartość do tymczasowej tablicy

                        else

                            temporary_Arrey[temporary_Size-1]=suma;//zapisuję wartość do tymczasowej tablicy
                    }
        }


    }//for i
    //chcemy scalić tablicę c, która jest początkowo pusta z tablicą, którą otrzymaliśmy wcześniej
    //przepiszemy tutaj tablicę c na tablicę pomocniczą
    int pn =(*cn);//przekazujemy rozmiar nowej tablicy
    int *p=(int *)malloc((size_t)pn*sizeof(int));//alokujemy pamięć
    //przepisujemy tablicę c
    for(int ii=0; ii<pn; ii++){
    p[ii]=(*c)[ii];
    }
    free(*c);//walaniamy c
    nadd(temporary_Arrey,temporary_Size,p,pn,&(*c),cn);//dodajemy tablicę i w wyniku dostajemy tablicę c
    free(temporary_Arrey);//zwalaniamy tablicę tymczasową
    free(p);//zwalniamy tablicę pomocniczą p
}//for j
}

/*funkcja podnosi do potęgi liczbe z tablicy a do potęgi o wykładniku z tblicy b*/
void nexp(int *a, int an, int *b, int bn, int **c, int *cn){
//ustawiam wartość wyniku na 1
(*cn)=1;
*c=malloc((size_t)(*cn)*sizeof(int));
(*c)[0]=0;
//robię lokalną kopię wykładnika;
int bn_copy=bn;
int *b_copy=(int *)malloc((size_t)bn * sizeof(int));
//stworzyliśmy lokalną kopię danych wejściowych żeby ich nie ruszać
for(int i=0;i<bn; i++){

        b_copy[i]=b[i];

}
//robimy też lokalną kopię podstawy
int *a_copy=NULL;
int an_copy=an;
a_copy=realloc(a_copy,(size_t) an*sizeof(int));

for(int i=0;i<an_copy; i++){

    a_copy[i]=a[i];

}
int *pom=b_copy;//zapamiętujemy wskaźnik na tablicę pomocniczą, żeby ją później zwolnić
int pomn=bn_copy;//długość tablicy pomocniczej

while(bn_copy>0){//dopóki długość wykładnika jest większa od zera stosujemy algorytm szybkiego mnożenia

    if(b_copy[0]==0||b_copy[0]==-1){//jeśli pierwszy element w tablicy
        //będziemy modyfikować tablicę c
        //musimy utworzyć kopię wyniku
        int *c_copy=NULL;
        int c_copy_size=*cn;
        c_copy=realloc(c_copy,(size_t)(*cn)*sizeof(int));

        for(int i=0; i<*cn; i++){//tworzę lokalną kopię wyniku

                c_copy[i]=(*c)[i];

        }

        free(*c);//zwalniamy wynik

        nmul(a_copy,an_copy,c_copy,c_copy_size,&(*c),cn);//tutaj pomnożymy nasz wynik, przez a^i

        free(c_copy);//zwalniamy kopię wyniku
    }

    //teraz chcemy podnieść do kwadratu a=a*a;
    //w tym celu przepiszemy nasze zmienne dwa razy
        int *a_copy1=NULL;
        int a_copy1_size=an_copy;
        a_copy1=realloc(a_copy1,(size_t)(an_copy)*sizeof(int));
        int *a_copy2=NULL;
        int a_copy2_size=an_copy;
        a_copy2=realloc(a_copy2,(size_t)(an_copy)*sizeof(int));

        for(int i=0; i<an_copy; i++){//tworzę lokalną kopię wyniku

            a_copy1[i]=a_copy[i];
            a_copy2[i]=a_copy[i];

        }

        free(a_copy);//zwalniamy kopię tablicy a

        nmul(a_copy1,a_copy1_size,a_copy2,a_copy2_size,&a_copy,&an_copy);

        free(a_copy1);//zwalniamy tablice, w kórych przechowywaliśmy kopie a_copy
        free(a_copy2);

//pozostało nam teraz zmienić wykładnik, a właściwe jego kopię
//jeśli mamy zero to obcinamy po prostu // w ten spsoób tutaj dostajemy parzyste
//jeśli mamy -1, 2 to przechodzi to na 0 //tu dostajemy nieparzyste
if(b_copy[0]==-1||b_copy[0]==0)//wchodzimy w pętle modyfikującą wykładnik
{
            if (bn_copy>1&&b_copy[0]==-1&&b_copy[1]==2){//jeśli długość wykładnika>1 i liczba =-1 to

                b_copy[1] = 0;//ten element staje się zerem
                b_copy++;//przechodzimy do następnego elelementu
                bn_copy--;//zmniejszamy rozmiar

                for(int i=1; i<bn_copy;i++){

                    if(b_copy[i]<0)
                    b_copy[i]++;
                    if(b_copy[i]>0)
                    b_copy[i]--;

                }
            }
            else if (bn_copy>1&&b_copy[0]==-1&&b_copy[1]!=2){//jeśli długość większa od 1 i 0 jest pierwszym elementem
            
                for(int i=1; i<bn_copy;i++){

                    if(b_copy[i]<0)
                    b_copy[i]++;
                    if(b_copy[i]>0)
                    b_copy[i]--;

                }

            }
            else if(b_copy[0]==0){
            
                b_copy++;
                bn_copy--;

                for(int i=0; i<bn_copy;i++){

                    if(b_copy[i]<0)
                    b_copy[i]++;
                    if(b_copy[i]>0)
                    b_copy[i]--;

                }
            }

        }else{

            for(int i=0; i<bn_copy;i++){

                    if(b_copy[i]<0)
                    b_copy[i]++;
                    if(b_copy[i]>0)
                    b_copy[i]--;

                }

        }
}//while
//zwalniamy lokalną kopię wykładnika i podstawy
free(a_copy);
b_copy=pom;//przekazujemy informację o pierwotnym wskaźniku na pierwszy element tablicy b_copy
bn_copy=pomn;//oraz o rozmiarze
free(b_copy);

}
//za słaba na testy
/*funkcja będzie dzielić podaną liczbę i do jednej tablicy zapyswać iloraz, a do drugiej resztę*/
void ndivmod(int *a, int an, int *b, int bn, int **q, int *qn, int **r, int *rn){
    //tworzę tablicę q przeznaczoną na iloczyn
    (*qn)=0;
(*q)=NULL;
//tworzę tablicę r, przeznaczoną na resztę
(*rn)=0;
(*r)=NULL;
//tablica pomocnicza z liczbą 1
int p[1]={0};
//tworzę 2 kopię tablicy a
int *a_copy1=NULL;
int size_a_copy1=an;
a_copy1=realloc(a_copy1,(size_t) size_a_copy1*sizeof(int));
for(int i=0; i<size_a_copy1; i++){
    a_copy1[i]=a[i];
}
int *a_copy2=NULL;
int size_a_copy2=an;
a_copy2=realloc(a_copy2,(size_t) size_a_copy1*sizeof(int));
for(int i=0; i<size_a_copy2; i++){
    a_copy2[i]=a[i];
}

//1) przypadek, dzielna i dzielnik>0
if(a[an-1]>=0&&b[bn-1]>=0){
while(size_a_copy2>0&&a_copy2[size_a_copy2-1]>=0&&size_a_copy2>0){//dopóki dzielna nie zacznie być ujemna
free(a_copy2);
nsub(a_copy1,size_a_copy1,b,bn,&a_copy2,&size_a_copy2);
//teraz muszę zamienić a_copy1 na a_copy2
size_a_copy1=size_a_copy2;
a_copy1=realloc(a_copy1,(size_t) size_a_copy1*sizeof(int));
for(int i=0; i<size_a_copy1;i++){
    a_copy1[i]=a_copy2[i];
}
//tworzymy pomocnicze q
int *q_copy=NULL;
int size_q_copy=0;
nadd((*q),(*qn),p,1,&q_copy,&size_q_copy);
free(*q);
(*q)=q_copy;
(*qn)=size_q_copy;
if(size_a_copy2>0&&a_copy2[size_a_copy2-1]<0){//jeśli liczba zaczeła być ujemna to zmiejszamy q o jeden i dodajemy 
//druga kopia q
int *q_copy2=NULL;//kopia naszego ilorazu
int size_q_copy2=0;//rozmiar ilorazu
nsub((*q),(*qn),p,1,&q_copy2,&size_q_copy2);//q jest już dobre, teraz żeby dostać resztę trzeba dodać a do b
free(*q);//zwalniamy iloraz
(*q)=q_copy;
(*qn)=size_q_copy;
nadd(a_copy2,size_a_copy2,b,bn,&(*r),rn);//r też jest już dobre
}
}
}
//2) przypadek, dzielna dodatnie, dzielnik ujemny
if(a[an-1]>=0&&b[bn-1]<0){
while(size_a_copy2>0&&a_copy2[size_a_copy2-1]>=0&&size_a_copy2>0){//bez zmian
free(a_copy2);
nadd(a_copy1,size_a_copy1,b,bn,&a_copy2,&size_a_copy2);//dodaje dzielnik
//
size_a_copy1=size_a_copy2;
a_copy1=realloc(a_copy1,(size_t) size_a_copy1*sizeof(int));
for(int i=0; i<size_a_copy1;i++){
    a_copy1[i]=a_copy2[i];
}
//tworzymy pomocnicze q
int *q_copy=NULL;
int size_q_copy=0;
nsub((*q),(*qn),p,1,&q_copy,&size_q_copy);
free(*q);
(*q)=q_copy;
(*qn)=size_q_copy;
if(size_a_copy2>0&&a_copy2[size_a_copy2-1]<0){//jeśli liczba zaczeła być ujemna to zwiększamy q o jeden  
//druga kopia q
int *q_copy2=NULL;
int size_q_copy2=0;
nadd((*q),(*qn),p,1,&q_copy2,&size_q_copy2);//q jest już dobre, teraz rzeby dostać resztę trzeba dodać a do b
free(*q);
(*q)=q_copy2;
(*qn)=size_q_copy2;
nsub(a_copy2,size_a_copy2,b,bn,&(*r),rn);//r też jest już dobre
}
}
}
//3) przypadek, dzielna ujemne, dzielnik ujemny
if(a[an-1]<0&&b[bn-1]<0){
while(size_a_copy2>0&&a_copy2[size_a_copy2-1]<0&&size_a_copy2>0){//bez zmian
free(a_copy2);
nsub(a_copy1,size_a_copy1,b,bn,&a_copy2,&size_a_copy2);//odejmuje dzielnik
size_a_copy1=size_a_copy2;
a_copy1=realloc(a_copy1,(size_t) size_a_copy1*sizeof(int));
for(int i=0; i<size_a_copy1;i++){
    a_copy1[i]=a_copy2[i];
}
//tworzymy pomocnicze q
int *q_copy=NULL;
int size_q_copy=0;
nadd((*q),(*qn),p,1,&q_copy,&size_q_copy);
free(*q);
(*q)=q_copy;
(*qn)=size_q_copy;
if(size_a_copy2>0&&a_copy2[size_a_copy2-1]>=0){//jeśli liczba zaczeła być dodatnia to q jest dobre 
//natomiast reszta to to co zostało w a_copy 2, więc dodaje to do pustej tablicy
int *k=NULL;
int kn=0;
nadd(a_copy2,size_a_copy2,k,kn,&(*r),rn);//r też jest już dobre
free(k);//tutaj reszta jest już dobra
}//if
}
}
//4) przypadek, dzielna ujemna, dzielnik dodatni
if(a[an-1]<0&&b[bn-1]>=0){
while(size_a_copy2>0&&a_copy2[size_a_copy2-1]<0&&size_a_copy2>0){//bez zmian
free(a_copy2);
nadd(a_copy1,size_a_copy1,b,bn,&a_copy2,&size_a_copy2);//odejmuje dzielnik
size_a_copy1=size_a_copy2;
a_copy1=realloc(a_copy1,(size_t) size_a_copy1*sizeof(int));
for(int i=0; i<size_a_copy1;i++){
    a_copy1[i]=a_copy2[i];
}
//tworzymy pomocnicze q
int *q_copy=NULL;
int size_q_copy=0;
nsub((*q),(*qn),p,1,&q_copy,&size_q_copy);
free(*q);
(*q)=q_copy;
(*qn)=size_q_copy;
if(size_a_copy2>0&&a_copy2[size_a_copy2-1]>=0){//jeśli liczba zaczeła być dodatnia to q jest dobre 
//natomiast reszta to to co zostało w a_copy 2, więc dodaje to do pustej tablicy
int *k=NULL;
int kn=0;
nadd(a_copy2,size_a_copy2,k,kn,&(*r),rn);//r też jest już dobre
free(k);//tutaj reszta jest już dobra
}//if
}
}
free(a_copy1);
free(a_copy2);
}

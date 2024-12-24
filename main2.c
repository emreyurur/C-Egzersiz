#include <stdio.h>
#include <stdlib.h> 
#include <time.h>


void tek_boyutlu_dizi_olustur(int **dizi, int eleman_sayisi){
    int i;
    *dizi=(int*)malloc(sizeof(int)*eleman_sayisi);
    
    for(i=0; i<eleman_sayisi; i++){
      //  *(*dizi+i)= rand()%10;
      (*dizi)[i]=rand()%10;
      // dizi[0][i]=rand()%10;
    }
}


int main (int argc, char** argv){
     int dizi1[5]={4,6,7,9,22};
    int *dinamik_dizi;
    int dinamik_dizi_uzunlugu;
    int **A,**B,**C;
    int *dizi;
    int eleman_sayisi;
    srand(time(NULL)); // rastgele (random) sayilar olusturmak icin
    eleman_sayisi=10;
    tek_boyutlu_dizi_olustur(&dizi, eleman_sayisi);;
}
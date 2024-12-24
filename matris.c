#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void tek_boyutlu_dizi_olustur(int **dizi,int eleman_sayisi){
    int i;
    *dizi=(int*)malloc(sizeof(int)*eleman_sayisi);
    for(i=0;i<eleman_sayisi;i++){
        (*dizi)[i]=rand()%10;
    }
}


void tek_boyutlu_dizi_yaz(int *dizi, int eleman_sayisi){
    int i;
    
    for(i=0; i<eleman_sayisi; i++){
         printf("%p ", (dizi+i));
    }
    printf("\n");
    for(i=0; i<eleman_sayisi; i++){
         printf("%11d ", *(dizi+i));
    }
    printf("\n");
}

void dinamik_matris_olustur1(int ***dizi,int satir,int sutun){
    int i,j;
    *dizi=(int**)malloc(satir*sizeof(int*));
    for(i=0; i<satir; i++){
       // *(*dizi+i)= (int*)malloc(sutun*sizeof(int)); 
        (*dizi)[i]= (int*)malloc(sutun*sizeof(int)); 
        for(j=0; j<sutun; j++)
        //    *(*(*dizi+i)+j)= rand()%2;
            (*dizi)[i][j]= rand()%2;
    }
}


int main(int argc, char** argv) {
    
    int dizi1[5]={4,6,7,9,22};
    int *dinamik_dizi;
    int dinamik_dizi_uzunlugu;
    int **A,**B,**C;
    int *dizi;
    int eleman_sayisi;
    srand(time(NULL)); // rastgele (random) sayilar olusturmak icin
    eleman_sayisi=10;
    tek_boyutlu_dizi_olustur(&dizi, eleman_sayisi);
    tek_boyutlu_dizi_yaz(dizi, eleman_sayisi);
    
    //dinamik_matris_olustur1(&A,5,6);
    printf("--- A matrisi ----\n");
}

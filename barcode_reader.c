#include <stdio.h>



int all_widths[]={212222,222122,222221,121223,121322,131222,122213,122312,132212,221213,221312,231212,112232,122132,122231,113222,123122,123221,223211,221132,221231,213212,223112,312131,311222,321122,321221,312212,322112,322211,212123,212321,232121,111323,131123,131321,112313,132113,132311,211313,231113,231311,112133,112331,132131,113123,113321,133121,313121,211331,231131,213113,213311,213131,311123,311321,331121,312113,312311,332111,314111,221411,431111,111224,111422,121124,121421,141122,141221,112214,112412,122114,122411,142112,142211,241211,221114,413111,241112,134111,111242,121142,121241,114212,124112,124211,411212,421112,421211,212141,214121,412121,111143,111341,131141,114113,114311,411113,411311,113141,114131,311141,411131,211412,211214,211232,233111};

int pattern2widths(int *pattern){
/*
Padroes sao compostos de 3 linhas e 3 colunas. 
Podendo Ocupar 1,2,3,4 espacos cada linha / coluna.
A soma das larguras deve ser 11 
Essa funcao transforma um array do pattern em larguras
ex: 11001100110 -> 22221
pattern[0] e sempre 1
pattern[11] eh sempre 0
*/
    int larguras = 1;
    for(int i=1;i<11;i++){ 
        if(pattern[i]==pattern[i-1]){
            larguras++;
        }else{
            larguras = larguras*10;
            larguras++;
        }
    }
    return larguras;
}


int widths2value(int larguras){
    for(int i=0;i<107;i++){
        if(larguras==all_widths[i]){
            return i;
        }
    }
    return -1;
}



void main(){
    int sym;
    int pattern[11] = {1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0};
    /*printf("Insert pattern. ex: 1 1 0 0 1 1 0 0 1 1 0: \n");
    scanf("%d",&pattern);*/

    int lar = pattern2widths(pattern);
    int val = widths2value(lar);

    for(int i=0;i<11;i++) printf("%d",pattern[i]);
    printf("\nLarguras: %d \n",lar);
    printf("Valor: %d \n",val);
}
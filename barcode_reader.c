#include <stdio.h>



int all_widths[]={212222,222122,222221,121223,121322,131222,122213,122312,132212,221213,221312,231212,112232,122132,122231,113222,123122,123221,223211,221132,221231,213212,223112,312131,311222,321122,321221,312212,322112,322211,212123,212321,232121,111323,131123,131321,112313,132113,132311,211313,231113,231311,112133,112331,132131,113123,113321,133121,313121,211331,231131,213113,213311,213131,311123,311321,331121,312113,312311,332111,314111,221411,431111,111224,111422,121124,121421,141122,141221,112214,112412,122114,122411,142112,142211,241211,221114,413111,241112,134111,111242,121142,121241,114212,124112,124211,411212,421112,421211,212141,214121,412121,111143,111341,131141,114113,114311,411113,411311,113141,114131,311141,411131,211412,211214,211232,233111};
//char serial_in[] = {'S','T',2,0xb2,0x00};
//69 = 10110010000
// 10110010 | 000(0 0000)
//  B2|00 = 178; 0


void serial2pattern(unsigned char * serial_in, unsigned char *patt){
    //ex: 
    //serial_in[] = {'S','T',2,0xb2,0x00};
    //patt = {1,0,1,1,0,0,1,0,0,0,0}; get 11 digits pattern from num_bytes bytes
    int num_bytes = serial_in[2];
    unsigned int all = 0;
    char bit;
    unsigned char bin[11];

    
    for(int j=3;j<3+num_bytes;j++){
        //printf("%d",j);
        all = (all << 8) | serial_in[j];
    }

    for(int i=32;i>=0;i--){
        bit = (all>>i)&1;
        if(bit){
            for(int j=0;j<11;j++){
                patt[j] = all>>(i-j)&1;
                //printf("%d",patt[j]);
            }
            break;
        }

    }

}


int pattern2widths(unsigned char *pattern){
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
    unsigned char serial_in[] = {'L','B', 2, 0xb2, 0};
    //char pattern[] = {1,0,1,1,0,0,1,0,0,0,0};
    unsigned char pat2[11];

    serial2pattern(serial_in,pat2);

    int lar = pattern2widths(pat2);
    int val = widths2value(lar);

    printf("Pattern: ");
    for(int i=0;i<11;i++) printf("%i",pat2[i]);
    printf("\nLarguras: %d \n",lar);
    printf("Valor: %d \n",val);
}


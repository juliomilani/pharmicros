// Turma A - Projeto pharmicross
//Julio Milani de Lucena (243876)
//Lucas Meurer Lameira (243875)

//Essa funcao ler o botao pressionado

//#include <reg51.h>
#include <stdio.h>

sfr porta3 = 0xB0;
sbit LED = porta3^5;
sfr porta0 = 0x80;
char bounce = 8;
char key_pressed;
unsigned char keypad[4][3] =	{{'1','2','3'},
            	                {'4','5','6'},
															{'7','8','9'},
															{'*','0','#'}};

void delay(){
    unsigned short a;
    for(a=0;a<100;a++);
}

char debounce(char linha, char coluna){
    char count = 0;
    char key_last = 0;	
    char key_now;
    char key_valid;

    porta0 = ~(1<<(7-linha));

    while(count != bounce){
        delay();
        key_now = porta0 & (1<<coluna);
        if(key_now == key_last){
            count++; 
        }
        else{
            count = 0;
        }
        key_last = key_now;
    }

    key_valid = key_now;
    return key_valid;
}

char key_detect(){
    unsigned char linha = 0;
    unsigned char coluna = 0;
    for(linha=0;linha<4;linha++){
        for(coluna=0;coluna<3;coluna++){
            if(!debounce(linha,coluna)){
                while(!debounce(linha,coluna));
                return keypad[linha][coluna];
            }
        }
    }

   return 0;
}
/*
void main(){
    while(1){
			key_pressed = key_detect();
			if(key_pressed=='6'||key_pressed=='5'){
				LED = !LED;
			}
		}
}*/

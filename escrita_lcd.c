//Pharmicros
//Julio Milani 243876, Lucas Lameira 243875
//Função de escrever no display 

#include <reg51.h>
sbit RS = P3^6;
sbit E = P3^7;

void atraso_timer0_40us()
{
	TMOD = 0x1; // timer 16 bits
	TF0 = 0; // flag = 0
	TH0 = 0xFF; // timer 74 periodos = 0x4A; FFFF-4A = FFB5
	TL0 = 0xB5;
	TR0 = 1; // start
	while( TF0 == 0 );
	TR0 = 0;
}

void atraso_timer0_1u65s()
{
	int i;
	for( i=0; i<40; i++ )
	{
			atraso_timer0_40us();
	}
}

void escrita_comando_lcd( char comando )
{
	RS = 0;
	E = 1;
	P1 = comando;
	E = 0;
	atraso_timer0_40us();
}

void escrita_dado_lcd( char dado )
{
	RS = 1;
	E = 1;
	P1 = dado;
	E = 0;
	atraso_timer0_40us();
}


void init_lcd()
{
	escrita_comando_lcd(0x38);  //00111000 F=0, N=1, DL=1 barramento de 8 bits...
	escrita_comando_lcd(0x0C); //00001100 D=1, C=0, B=0 display ativo...
	escrita_comando_lcd(0x06); //00000110 I/D=1, S=0 mensagem fixa...
	escrita_comando_lcd(0x01); //00000001 apagar display
	atraso_timer0_1u65s();
}

void print_lcd( char *mensagem )  
{
	char i = 0;
	while  ( mensagem[i] != 0 )
	{
			escrita_dado_lcd(mensagem[i]);
			i++;
	}
}

void cursor_lcd( char linha, char coluna )
{
	if ( linha == 0)
	{
			escrita_comando_lcd(0x80);
			while ( coluna != 0)
			{
					escrita_comando_lcd(0x14);  //shift cursor to the right
					coluna--;
			}
	}
	else
	{
			escrita_comando_lcd(0xC0); //comando de pular linha
			while ( coluna != 0)
			{
					escrita_comando_lcd(0x14);  //shift cursor to the right
					coluna--;
			}
	}
}

//void main()
//{
//	init_lcd();
//	cursor_lcd(0, 3);
//	print_lcd("Pharmicros");
//	cursor_lcd(1, 2);
//	print_lcd("Eh us guris");
	
//	while(1);
//}

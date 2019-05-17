//Pharmicros
//Julio Milani 243876, Lucas Lameira 243875
//Comunicacao serial

#include <reg51.h>

void serial_com_config()
{
	TMOD = 0x20;
	TH1 =  0xFD;  //19200 baud rate
	SCON = 0x50;	//mode 1
	TR1 = 1;  //timer1 
}

void enviar_dado( char dado )
{
	SBUF = dado;  //transmissao de caractere via registro sbuf 
	while( TI == 0 ); //espera ate terminar transmissao
	TI = 0; //clear TI flag
}

void enviar_palavra( char *palavra )  
{
	char i = 0;
	while  ( palavra[i] != 0 )
	{
			enviar_dado( palavra[i] );
			i++;
	}
}

char receber_dado()
{
	while( RI == 0 );  //espera terminar recepcao do dado
	RI = 0;	//clear RI flag
	return(SBUF);  //recepcao do caractere via registro sbuf
}

char receber_palavra( char n )
{
	char dados[20];  //ele nao aceita char_dados[n]
	char i;
	for( i=0; i<n; i++ )
	{
		dados[i] = receber_dado();
	}
	return(dados);
}


	
	

	






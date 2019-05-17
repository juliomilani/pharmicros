//Pharmicros
//Julio Milani 243876, Lucas Lameira 243875
//Comunicacao serial - protocolo de recebimento

#include <reg51.h>
static void msg_travar_terminal();
static void msg_liberar_terminal();
static void msg_recebimento_horario();
static void msg_codigo_barra();
static char receber_dado();
static char receber_palavra( char n );
static void init_lcd();
static void print_lcd(char*);
static void data_horario( char, char, char, char );
static void main();

void protocolo_recebimento()
{
	char dado1, dado2, dado3, dado4, dados;
	char dia, mes, hora, min;
	char n;
	
	dado1 = receber_dado();
	if ( dado1 == 'S' )
	{
		dado2 = receber_dado();
		switch ( dado2 )
		{
			case 'T' :				//travar terminal
				msg_travar_terminal();
				init_lcd();
				print_lcd("FORA DE OPERACAO");
					dado3 = receber_dado();
					dado4 = receber_dado();
					while ( dado3 != 'S' && dado4 != 'L' )		//liberar terminal
					{
						dado3 = receber_dado();
						dado4 = receber_dado();
					}
					msg_liberar_terminal();
					main();
					break;
			
			case 'L' :				//liberar terminal
				msg_liberar_terminal();	
				main();
				break;
			
			case 'H' :				//date e horario
				dia = receber_dado();
				mes = receber_dado();
				hora = receber_dado();
				min = receber_dado();
				data_horario( dia, mes, hora, min);
				msg_recebimento_horario();
				break;
			
			case 'O' :				//mensagem de resposta do servidor a entrada de operador
				n = receber_dado();
				dados = receber_palavra(n);
				init_lcd();
				print_lcd("dados");
				//atraso_3s();
				break;
			
			case 'A' :				//venda aberta
				break;
			
			case 'P' :				//consulta de produto
				n = receber_dado();
				dados = receber_palavra(n);
				break;
			
			case 'C' :				//comfirmação de venda
				n = receber_dado();
				dados = receber_palavra(n);
				break;
			
			case 'F' :				//sessao de venda fechada
				break;
			
			case 'X' :				//fechamento da sessao do operador
				break;
			
			case 'I' :				//envio de impressao de comprovante
				break;
		}
	}
	
	else if ( dado1 == 'L' )
	{
		dado2 = receber_dado();
		if ( dado2 == 'B' )	//codigo de barra
		{
				n = receber_dado();
				dados = receber_palavra(n);
				msg_codigo_barra();
				//barcode_reader();	
		}
	}
}
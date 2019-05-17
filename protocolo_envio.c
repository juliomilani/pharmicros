//Pharmicros
//Julio Milani 243876, Lucas Lameira 243875
//Comunicacao serial - protocolo de envio

#include <reg51.h>

static void enviar_dado( char dado );
static void enviar_palavra( char *palavra ); 

void msg_travar_terminal()
{
	enviar_palavra("PT");
}

void msg_liberar_terminal()
{
	enviar_palavra("PL");
}

void msg_recebimento_horario()
{
	enviar_palavra("PH");
}

void msg_entrada_operador( char *operador, char *senha )
{
	char n =14;
	enviar_palavra("PO");
	enviar_dado(n);
	enviar_palavra(operador);
	enviar_palavra(senha);
}

void msg_vendas_aberta()
{
	enviar_palavra("PA");
}

void msg_consulta_produto( char *produto )
{
	char n =7;
	enviar_palavra("PP");
	enviar_dado(n);
	enviar_palavra(produto);
}

void msg_confirmacao_compra( char *confirmar )	
{
	char n =2;
	enviar_palavra("PC");
	enviar_dado(n);
	enviar_palavra(confirmar);
}

void msg_venda_fechada()
{
	enviar_palavra("PF");
}

void msg_fechar_sessao()
{
	enviar_palavra("PX");
}

void msg_print_comprovante( char *n, char *imprimir) //pensar
{
	enviar_palavra("PI");
	enviar_palavra(n);	//enviar em 2 bytes ??
	enviar_palavra(imprimir);
}

void msg_codigo_barra()
{
	enviar_palavra("PB");
}



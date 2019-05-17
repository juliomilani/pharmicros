//void atraso_60s()
//{
	//fazer timer de 60s
//}

void data_horario( char dia, char mes, char hora, char min )
{
	while( min < 60 )
	{
		//atraso_60s();
		min++;
	}
	min = 0;
	if ( hora < 24 )
	{
		hora++;
	}
	else
	{
		hora = 0;
		if ( dia < 30 )  //teria q fazer um switch case para cada mes
		{
			dia++;
		}
		else
		{
			dia = 0;
			if ( mes < 12 )
			{
				mes++;
			}
			else
			{
				mes = 0;
			}
		}
	}
	//botar variaveis em alguma porta, registrador
	data_horario( dia, mes, hora, min );
}
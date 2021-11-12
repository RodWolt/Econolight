#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*CADASTRA O CONSUMO DOS ÚLTIMOS 12, 6, 3 MESES E A PESSOA INFORMA QUANTO GOSTARIA DE ECONOMIZAR */


float cadastroMeta();
float economiaC();
float metaFinal, consumo;
int pontos=0;
int main() 
{
	cadastroMeta();
	printf("\nMeta Final>: %.2f%%", metaFinal);
	printf("\nConsumo inicial>: %.2f kwatts", consumo);
	economiaC();
	return 0;
}

float cadastroMeta()
	{
		//todos os textos dentro dos printf's e nomes de variáveis são temporários
		float meta, meta2=0;
		int mes, check;
		//Escolher quantos meses;
		printf("Gostaria de cadastrar o consumo de -3-, -6- ou -12- meses?>: ");
		scanf("%d", &mes);
		switch (mes)
		{
			case 3:
				printf("Consumo total nos %d meses, em kwatts>: ", mes);
				scanf("%f", &consumo);
				//Deixei as 2 formas de adicionar a meta, de acordo com a discussão que tivemos, a meta vai ser salva em % do valor original
				printf("Como gostaria de estipular sua meta? -1- para usar Porcentagem, -2- para usar Numero inteiro>: ");
				scanf("%d", &check);
				if(check==1)
				{
					printf("Quanto gostaria de economizar?(Porcentagem)>: ");
					scanf("%f", &meta);
					meta2 = consumo - (consumo * (meta/100));//inteiro atraves da %
					metaFinal = meta;
					printf("Para economizar %.2f%%, voce devera consumir %.2f kwatts em %d meses.", meta, meta2, mes);
					break;
				}
				else if(check==2)
				{
					printf("Quanto gostaria de economizar?(Inteiro)>: ");
					scanf("%f", &meta);
					meta2 = (meta/consumo)*100; //porcentagem
					metaFinal = meta2;
					printf("Quer economizar %.2f%% de seu consumo anterior em %d meses.", meta2, mes);
					break;
				}
			case 6:
				printf("Consumo total nos %d meses, em kwatts>: ", mes);
				scanf("%f", &consumo);
				printf("Como gostaria de estipular sua meta? -1- para usar Porcentagem, -2- para usar Numero inteiro>: ");
				scanf("%d", &check);
				if(check==1)
				{
					printf("Quanto gostaria de economizar?(Porcentagem)>: ");
					scanf("%f", &meta);
					meta2 = consumo - (consumo * (meta/100));
					metaFinal = meta;
					printf("Para economizar %.2f%%, voce devera consumir %.2f kwatts em %d meses.", meta, meta2, mes);
					break;
				}
				else if(check==2)
				{
					printf("Quanto gostaria de economizar?(Inteiro)>: ");
					scanf("%f", &meta);
					meta2 = (meta/consumo)*100;
					metaFinal = meta2;
					printf("Quer economizar %.2f%% de seu consumo anterior em %d meses.", meta2, mes);
					break;
				}
			case 12:
				printf("Consumo total nos %d meses, em kwatts>: ", mes);
				scanf("%f", &consumo);
				printf("Como gostaria de estipular sua meta? -1- para usar Porcentagem, -2- para usar Numero inteiro>: ");
				scanf("%d", &check);
				if(check==1)
				{
					printf("Quanto gostaria de economizar?(Porcentagem)>: ");
					scanf("%f", &meta);
					meta2 = consumo - (consumo * (meta/100));
					metaFinal = meta;
					printf("Para economizar %.2f%%, voce devera consumir %.2f kwatts em %d meses.", meta, meta2, mes);
					break;
				}
				else if(check==2)
				{
					printf("Quanto gostaria de economizar?(Inteiro)>: ");
					scanf("%f", &meta);
					meta2 = (meta/consumo)*100;
					metaFinal = meta2;
					printf("Quer economizar %.2f%% de seu consumo anterior em %d meses.", meta2, mes);
					break;
				}
				
		//retorna o valor final pra ser usado em outras funções.
		return consumo;
		return metaFinal;			
		}
		
	}

float economiaC()
{
	float consumo2, economia;
	printf("\nConsumo>: ");
	scanf("%f", &consumo2);
	if (consumo2 >= consumo) //Checa se o novo consumo é maior ou igual ao anterior
	{
		printf("Nao houve economia.");
	}
	else if (consumo2 < consumo)
	{
		//Caso seja menor, checa de quanto foi a economia em %
		economia = 100-(consumo2/consumo)*100;
		if (economia >= metaFinal)
		{
			printf("Atingiu a meta de %.2f, ecomonizou %.2f", metaFinal, economia);
			pontos+=200;
		}
		else if (economia < metaFinal)
		{
			printf("Nao atingiu a meta de %.2f, ecomonizou apenas %.2f", metaFinal, economia);
			pontos+=50;
		}
	}
	printf("\nPontos>: %d", pontos);
}

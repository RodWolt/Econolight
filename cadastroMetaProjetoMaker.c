#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define VERD 1
#define FALSO 0
float cadastroMeta();
float economiaC();
float metaFinal, consumo;
int pontos=0;
int cumpriu;
int main() 
{
	cadastroMeta();
	printf("\nMeta Final>: %.2f%%", metaFinal);
	printf("\nConsumo inicial>: %.2f kwatts\n", consumo);
	economiaC();
	return 0;
}

float cadastroMeta()
	{
		//todos os textos dentro dos printf's e nomes de variáveis são temporários
		float meta, meta2=0, cons;
		int mes, check, i=1;
		//Escolher quantos meses;
		printf("Gostaria de cadastrar o consumo de -3-, -6- ou -12- meses?\n>: ");
		scanf("%d", &mes);
		switch (mes)
		{
			case 3:
				do{
					printf("-------------\nConsumo do mes %d\n>:", i);
					scanf("%f",&cons);
					consumo+=cons;
					i++;
				}while(i<=mes);
				//Deixei as 2 formas de adicionar a meta, de acordo com a discussão que tivemos, a meta vai ser salva em % do valor original
				printf("-------------\nComo gostaria de estipular sua meta? -1- para usar Porcentagem, -2- para usar Numero inteiro\n>: ");
				scanf("%d", &check);
				if(check==1)
				{
					printf("-------------\nQuanto gostaria de economizar?(Porcentagem)\n>: ");
					scanf("%f", &meta);
					meta2 = consumo - (consumo * (meta/100));//inteiro atraves da %
					metaFinal = meta;
					printf("-------------\nPara economizar %.2f%%, voce devera consumir %.2f kwatts em %d meses.", meta, meta2, mes);
					break;
				}
				else if(check==2)
				{
					printf("-------------\nQuanto gostaria de economizar?(Inteiro)\n>: ");
					scanf("%f", &meta);
					meta2 = (meta/consumo)*100; //porcentagem
					metaFinal = meta2;
					printf("-------------\nQuer economizar %.2f%% de seu consumo anterior em %d meses.", meta2, mes);
					break;
				}
			case 6:
				do{
					printf("-------------\nConsumo do mes %d\n>:", i);
					scanf("%f",&cons);
					consumo+=cons;
					i++;
				}while(i<=mes);
				printf("-------------\nComo gostaria de estipular sua meta? -1- para usar Porcentagem, -2- para usar Numero inteiro\n>: ");
				scanf("%d", &check);
				if(check==1)
				{
					printf("-------------\nQuanto gostaria de economizar?(Porcentagem)\n>: ");
					scanf("%f", &meta);
					meta2 = consumo - (consumo * (meta/100));
					metaFinal = meta;
					printf("-------------\nPara economizar %.2f%%, voce devera consumir %.2f kwatts em %d meses.", meta, meta2, mes);
					break;
				}
				else if(check==2)
				{
					printf("-------------\nQuanto gostaria de economizar?(Inteiro)\n>: ");
					scanf("%f", &meta);
					meta2 = (meta/consumo)*100;
					metaFinal = meta2;
					printf("-------------\nQuer economizar %.2f%% de seu consumo anterior em %d meses.", meta2, mes);
					break;
				}
			case 12:
				do{
					printf("-------------\nConsumo do mes %d\n>:", i);
					scanf("%f",&cons);
					consumo+=cons;
					i++;
				}while(i<=mes);
				printf("-------------\nComo gostaria de estipular sua meta? -1- para usar Porcentagem, -2- para usar Numero inteiro\n>: ");
				scanf("%d", &check);
				if(check==1)
				{
					printf("-------------\nQuanto gostaria de economizar?(Porcentagem)\n>: ");
					scanf("%f", &meta);
					meta2 = consumo - (consumo * (meta/100));
					metaFinal = meta;
					printf("-------------\nPara economizar %.2f%%, voce devera consumir %.2f kwatts em %d meses.", meta, meta2, mes);
					break;
				}
				else if(check==2)
				{
					printf("-------------\nQuanto gostaria de economizar?(Inteiro)\n>: ");
					scanf("%f", &meta);
					meta2 = (meta/consumo)*100;
					metaFinal = meta2;
					printf("-------------\nQuer economizar %.2f%% de seu consumo anterior em %d meses.", meta2, mes);
					break;
				}
				
		return consumo;
		return metaFinal;			
		}
		
	}

float economiaC()
{
	float consumo2, economia;
	printf("-------------\nConsumo\n>: ");
	scanf("%f", &consumo2);
	if (consumo2 >= consumo)
	{
		printf("-------------\nNao houve economia.");
	}
	else if (consumo2 < consumo)
	{
		economia = 100-(consumo2/consumo)*100;
		if (economia >= metaFinal)
		{
			printf("-------------\nAtingiu a meta de %.2f, ecomonizou %.2f", metaFinal, economia);
			cumpriu=VERD;
		}
		else if (economia < metaFinal)
		{
			printf("-------------\nNao atingiu a meta de %.2f, ecomonizou apenas %.2f", metaFinal, economia);
			cumpriu=FALSO;
		}
	}
	if(cumpriu==VERD)
	{
		if(metaFinal<=10)
		{pontos+=100;}
		else if(metaFinal<=20)
		{pontos+=200;}
		else if(metaFinal<=30)
		{pontos+=300;}
		else if(metaFinal<=40)
		{pontos+=400;}
	}
	else if(cumpriu==FALSO)
	{pontos+=0;}	
	printf("\nPontos = %d", pontos);
	return pontos;
}

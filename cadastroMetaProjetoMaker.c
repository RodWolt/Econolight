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
		fflush(stdin);
		scanf("%d", &mes);
		switch (mes)
		{
			case 3:
				do{
					system("cls");
					printf("-------------\nConsumo do mês %d\n>:", i);
					fflush(stdin);
					scanf("%f",&cons);
					consumo+=cons;
					i++;
				}while(i<=mes);
				//Deixei as 2 formas de adicionar a meta, de acordo com a discussão que tivemos, a meta vai ser salva em % do valor original
				system("cls");
				printf("-------------\nConsumo total nos %d meses>: %.2f kwatts", mes, consumo);
				printf("\n-------------\nComo gostaria de estipular sua meta? -1- para usar Porcentagem, -2- para usar Numero inteiro\n>: ");
				fflush(stdin);
				scanf("%d", &check);
				if(check==1)
				{
					system("cls");
					printf("-------------\nQuanto gostaria de economizar?(Porcentagem)\n>: ");
					fflush(stdin);
					scanf("%f", &meta);
					meta2 = consumo - (consumo * (meta/100));//inteiro atraves da %
					metaFinal = meta;
					system("cls");
					printf("-------------\nPara economizar %.2f%%, você deverá consumir %.2f kwatts em %d meses.", meta, meta2, mes);
					break;
				}
				else if(check==2)
				{
					system("cls");
					printf("-------------\nQuanto gostaria de economizar?(Inteiro)\n>: ");
					fflush(stdin);
					scanf("%f", &meta);
					metaFinal = (meta/consumo)*100; // porcentagem
					meta2 = consumo - meta;
					system("cls");
					printf("-------------\nQuer economizar %.2f%% de seu consumo anterior em %d meses.", metaFinal, mes);
					printf("\n-------------\nPara economizar %.2f%%, você deverá consumir %.2f kwatts em %d meses.", metaFinal, meta2, mes);
					break;
				}
			case 6:
				do{
					system("cls");
					printf("-------------\nConsumo do mês %d\n>:", i);
					fflush(stdin);
					scanf("%f",&cons);
					consumo+=cons;
					i++;
				}while(i<=mes);
				system("cls");
				printf("-------------\nConsumo total nos %d meses>: %.2f kwatts", mes, consumo);
				printf("\n-------------\nComo gostaria de estipular sua meta? -1- para usar Porcentagem, -2- para usar Numero inteiro\n>: ");
				fflush(stdin);
				scanf("%d", &check);
				if(check==1)
				{
					system("cls");
					printf("-------------\nQuanto gostaria de economizar?(Porcentagem)\n>: ");
					fflush(stdin);
					scanf("%f", &meta);
					meta2 = consumo - (consumo * (meta/100));
					metaFinal = meta;
					system("cls");
					printf("-------------\nPara economizar %.2f%%, você deverá consumir %.2f kwatts em %d meses.", meta, meta2, mes);
					break;
				}
				else if(check==2)
				{
					system("cls");
					printf("-------------\nQuanto gostaria de economizar?(Inteiro)\n>: ");
					fflush(stdin);
					scanf("%f", &meta);
					metaFinal = (meta/consumo)*100;
					meta2 = consumo - meta;
					system("cls");
					printf("-------------\nQuer economizar %.2f%% de seu consumo anterior em %d meses.", metaFinal, mes);
					printf("\n-------------\nPara economizar %.2f%%, você deverá consumir %.2f kwatts em %d meses.", metaFinal, meta2, mes);
					break;
				}
			case 12:
				do{
					system("cls");
					printf("-------------\nConsumo do mês %d\n>:", i);
					fflush(stdin);
					scanf("%f",&cons);
					consumo+=cons;
					i++;
				}while(i<=mes);
				system("cls");
				printf("-------------\nConsumo total nos %d meses>: %.2f kwatts", mes, consumo);
				printf("\n-------------\nComo gostaria de estipular sua meta? -1- para usar Porcentagem, -2- para usar Numero inteiro\n>: ");
				fflush(stdin);
				scanf("%d", &check);
				if(check==1)
				{
					system("cls");
					printf("-------------\nQuanto gostaria de economizar?(Porcentagem)\n>: ");
					fflush(stdin);
					scanf("%f", &meta);
					meta2 = consumo - (consumo * (meta/100));
					metaFinal = meta;
					system("cls");
					printf("-------------\nPara economizar %.2f%%, você deverá consumir %.2f kwatts em %d meses.", meta, meta2, mes);
					break;
				}
				else if(check==2)
				{
					system("cls");
					printf("-------------\nQuanto gostaria de economizar?(Inteiro)\n>: ");
					fflush(stdin);
					scanf("%f", &meta);
					metaFinal = (meta/consumo)*100;
					meta2 = consumo - meta;
					system("cls");
					printf("-------------\nQuer economizar %.2f%% de seu consumo anterior em %d meses.", metaFinal, mes);
					printf("\n-------------\nPara economizar %.2f%%, você deverá consumir %.2f kwatts em %d meses.", metaFinal, meta2, mes);
					break;
				}
			default:
               	printf("-------------\nDigite uma opção valida.\n-------------\n");
               	cadastroMeta();
               	break;
				
		}
		printf("\nConsumo inicial>: %.2f kwatts", consumo);
		printf("\nMeta Final>: %.2f%%", metaFinal);
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

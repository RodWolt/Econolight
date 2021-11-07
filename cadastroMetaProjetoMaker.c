#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


/*CADASTRA O CONSUMO DOS �LTIMOS 12, 6, 3 MESES E A PESSOA INFORMA QUANTO GOSTARIA DE ECONOMIZAR */
float cadastroMeta();
/*--------------------------------------------------------------------------------
>Eu s� criei essa variavel global pra ter certeza que a fun��o estava retornando oq eu queria<      */
float metaFinal;
/*------------------------------------------------------------------------------*/
int main() 
{
	cadastroMeta();
	printf("\nMeta Final>: %.2f", metaFinal);
	return 0;
}

float cadastroMeta()
	{
		//todos os textos dentro dos printf's e nomes de vari�veis s�o tempor�rios
		float kwatts, meta, porcentagem=0;
		int mes, check;
		//Escolher quantos meses;
		printf("Gostaria de cadastrar o consumo de -3-, -6- ou -12- meses?>: ");
		scanf("%d", &mes);
		switch (mes)
		{
			case 3:
				printf("Consumo total nos %d meses, em kwatts>: ", mes);
				scanf("%f", &kwatts);
				//Deixei as 2 formas de adicionar a meta, mas no final a metaFinal vai ser em kwatts para o n�mero de meses escolhidos.
				printf("Como gostaria de estipular sua meta? -1- para usar Porcentagem, -2- para usar Numero inteiro>: ");
				scanf("%d", &check);
				if(check==1)
				{
					printf("Quanto gostaria de economizar?(Porcentagem)>: ");
					scanf("%f", &meta);
					metaFinal = kwatts - (kwatts * (meta/100));
					printf("Para economizar %.2f%%, voce devera consumir %.2f kwatts em %d meses.", meta, metaFinal, mes);
					break;
				}
				else if(check==2)
				{
					printf("Quanto gostaria de economizar?(Inteiro)>: ");
					scanf("%f", &meta);
					porcentagem = (meta/kwatts)*100;
					metaFinal = meta;
					printf("Quer economizar %%%.2f de seu consumo anterior em %d meses.", porcentagem, mes);
					break;
				}
			case 6:
				printf("Consumo total nos %d meses, em kwatts>: ", mes);
				scanf("%f", &kwatts);
				printf("Como gostaria de estipular sua meta? -1- para usar Porcentagem, -2- para usar Numero inteiro>: ");
				scanf("%d", &check);
				if(check==1)
				{
					printf("Quanto gostaria de economizar?(Porcentagem)>: ");
					scanf("%f", &meta);
					metaFinal = kwatts - (kwatts * (meta/100));
					printf("Para economizar %.2f%%, voce devera consumir %.2f kwatts em %d meses.", meta, metaFinal, mes);
					break;
				}
				else if(check==2)
				{
					printf("Quanto gostaria de economizar?(Inteiro)>: ");
					scanf("%f", &meta);
					porcentagem = (meta/kwatts)*100;
					metaFinal = meta;
					printf("Quer economizar %%%.2f de seu consumo anterior em %d meses.", porcentagem, mes);
					break;
				}
			case 12:
				printf("Consumo total nos %d meses, em kwatts>: ", mes);
				scanf("%f", &kwatts);
				printf("Como gostaria de estipular sua meta? -1- para usar Porcentagem, -2- para usar Numero inteiro>: ");
				scanf("%d", &check);
				if(check==1)
				{
					printf("Quanto gostaria de economizar?(Porcentagem)>: ");
					scanf("%f", &meta);
					metaFinal = kwatts - (kwatts * (meta/100));
					printf("Para economizar %.2f%%, voce devera consumir %.2f kwatts em %d meses.", meta, metaFinal, mes);
					break;
				}
				else if(check==2)
				{
					printf("Quanto gostaria de economizar?(Inteiro)>: ");
					scanf("%f", &meta);
					porcentagem = (meta/kwatts)*100;
					metaFinal = meta;
					printf("Quer economizar %%%.2f de seu consumo anterior em %d meses.", porcentagem, mes);
					break;
				}
				
		//retorna o valor final pra ser usado em outras fun��es.
		return metaFinal;			
		}
		
	}

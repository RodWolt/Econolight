#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
void simConsumo();

int main() {
	
	simConsumo();
	return 0;
}


void simConsumo (){
	
	setlocale(LC_ALL,"");
	int esc, i;
	float watt, tempo, consumo=0;
	printf("\nEscolha o n�mero de aparelhos que ser�o lan�ados..:");
	scanf("%d", &esc);
	
		for(i=1; i<=esc; i++)
		{	
		printf("\nDigite a potencia em Watt do aparelho %d..:", i);
		scanf("%f", &watt);
		printf("\nDigite o tempo em horas estimado em que o aparelho fica ligado por dia..:");
		scanf("%f", &tempo);
		consumo = consumo + ((watt/1000)*(tempo)*30);
		}
	printf("\nO consumo estimado para o m�s �..: %.2f KWh", consumo );
}

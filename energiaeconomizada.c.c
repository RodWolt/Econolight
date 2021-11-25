#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float WEconomizado();

int main() {
	
	WEconomizado();
	return 0;
           
		   }

float WEconomizado()
    
   
   {
   	     setlocale(LC_ALL,"");
	     float watts, wattsEconom, tempo, Econom=0;
	    
		 printf("Qual é a sua estimativa de consumo? ");
	     scanf("%f", &watts);
	     printf("Quanto de consumo foi efetivado? ");
	     scanf("%f", &wattsEconom);
	     Econom = (watts - wattsEconom)*100/watts;
	     
	     printf("Você economizou..: %.2f%% de energia", Econom );
   }

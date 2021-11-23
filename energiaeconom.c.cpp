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
	     float watts, wattsEconom, tempo, Econom=0, EconomY=0;
	    
		 printf("Qual é a sua estimativa de consumo? ");
	     scanf("%f", &watts);
	     printf("Quanto de consumo foi efetivado? ");
	     scanf("%f", &wattsEconom);
	     Econom = (watts - wattsEconom)*1000;
	     EconomY = (watts - wattsEconom)/1000;
		 printf("Você economizou..: %.2f Watts / %.2f Khw ", Econom , EconomY  );
	     
   }

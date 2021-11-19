#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int numero;

int main (int argc, char *argv[])

{
	setlocale(LC_ALL,"Portuguese");
	
	printf("Sistemas\n\n");
	printf("1- Adicionar clientes\n");
	printf("2- Adicionar produtos\n");
	printf("3- Ver lista de clientes\n");
	printf("4- Ver lista de produtos\n");
	printf("\nEscolha a opção desejada: \n");
	scanf("%d", &numero);
	switch(numero)
	{
	    case 1:
	    	system("cls"); 
	    	
	    	break;
	
	    case 2:
	        system("cls"); 
	    	
	    	break;
	    
		case 3:
			system("cls"); 
	    	
	    	break;
	    	
	    case 4:
	    	system("cls"); 
	    	
	    	break;
	}
	
	system("pause");
	
	return 0;
}

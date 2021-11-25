#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>

#define C_SIZE 5
#define TAMANHO 5
#define VERD 1
#define FALSO 0

struct data{
    int dia;
    int mes;
    int ano;
};

 struct cliente{
    int id; // -1 indica que a posição do elemento no vetor está vazia
    char nome[20];
    char sobrenome[20];
    struct data dataNasc;
    char telefone[20];
    char email[30];
    int pontos;
} vetCliente[TAMANHO];


void IDcheckStrings();
int inicializarCliente();
int entradaCliente();
int incluirCliente();
void menuProvedor();

UINT CPAGE_DEFAULT;

int main(){
    setlocale(LC_ALL,"Portuguese");
    int typeProgram;

    //startUpCarr();
    //startUpProd();
    //startUpClientes();    
	inicializarCliente();

// Começo do programa

    while(1){
        system("cls");
        printf("Você é o cliente ou o provedor?\n");
        printf("1 - Cliente\n");
        printf("2 - Provedor\n");
        printf("0 - Sair do programa\n");
        printf("Opção: ");
        fflush(stdin);
        scanf("%d", &typeProgram);

        switch(typeProgram){
            case 1:
                clienteMenu();
                break;
            case 2:
            	menuProvedor();
                break;
            case 0:
                exit(0);
            default:
                printf("Digite uma opção valida...\n");
                system("pause");
                system("cls");
        }
    }

    SetConsoleOutputCP(CPAGE_DEFAULT);
    return 0;
}

void clienteMenu(){
    int id, numCliente, op;

    do{
        IDcheckStrings();
        fflush(stdin);
        while(scanf("%d", &id) != 1 || id < 1){
            if(getchar() == 'e') return;
            printf("\nA ID de cliente é composta apenas de digitos e maior que 0...\n\n");
            system("pause");
            IDcheckStrings();
            fflush(stdin);
        }
        for(numCliente = 0; numCliente < C_SIZE; numCliente++)
            if(vetCliente[numCliente].id == id) break;
        
        if(vetCliente[numCliente].id != id){
            printf("\nEste ID de cliente não é valido...\n\n");
            system("pause");
        }
    }while(vetCliente[numCliente].id != id);

    while(1){
        system("cls");
        printf("O que deseja fazer?\n");
        printf("1 - Ver Pontos\n");
        printf("2 - Estimativa de consumo\n");
        printf("3 - Informar meta energetica\n");
        printf("4 - Informar Watts economizados\n");
        printf("5 - Ver lista de produtos\n");
        printf("6 - Colocar ou Tirar produtos do carrinho\n");
        printf("7 - Ver Carrinho\n");
        printf("9 - Voltar ao início\n");
        printf("0 - Sair do programa\n");
        printf("Opção: ");
        fflush(stdin);
        scanf("%d", &op);

        switch(op){
            case 1:
                verPontos(vetCliente, numCliente);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 9:
                return;
            case 0:
                SetConsoleOutputCP(CPAGE_DEFAULT);
                exit(0);
            default:
                printf("Digite uma opção valida...\n");
                system("pause");
                system("cls");
        }
    }
}

void IDcheckStrings(){
    system("cls");
    printf("Para voltar ao início digite 'e'\n\n");
    printf("Sua ID de cliente : ");
}

/*void verPontos(Pessoa vetCliente[], int numCliente){
    system("cls");
    printf("Pontos registrados: %d\n\n", vetCliente[numCliente].pontos);
    system("pause");
}*/
void menuProvedor()
{
	int numero;
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
			incluirCliente();
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
int inicializarCliente()
{
  int resp = FALSO;
  int i;
    for(i=0;i<TAMANHO; i++) 
          {
           vetCliente[i].id = -1;
          }
         resp = VERD;
    return resp;
}
int entradaCliente(int pos)
{ // posição livre para a inclusão
      int resp = FALSO;
      printf("\n**********Inclusão de novo registro!********");
      printf("\nIdentificador: ");
      scanf("%d", vetCliente[pos].id);
      printf("\nNome..:");
      scanf("%s", vetCliente[pos].nome); // não vai poder ter espaço no nome
      printf("\nSobrenome..:");
      scanf("%s", vetCliente[pos].sobrenome);
      printf("\nData Nasc - (DDMMAAAA)..:");
      scanf("%d %d %d", &vetCliente[pos].dataNasc.dia,
      &vetCliente[pos].dataNasc.mes, &vetCliente[pos].dataNasc.ano);
      printf("\nTelefone..:");
      scanf("%s", vetCliente[pos].telefone);
      printf("\nEmail..:");
      scanf("%s", vetCliente[pos].email);
      printf("\nPontos..:");
      scanf("%d", &vetCliente[pos].pontos);
      resp = VERD;
return resp;
}
int incluirCliente()
{
    int resp = FALSO;
    int i;
    int posicao=-1;
    for(i=0;i<TAMANHO; i++){// verificar se tem espaço
    if(vetCliente[i].id==-1){
    posicao = i;
    break;
}
}
    if(posicao!=-1) {
        if(entradaCliente(posicao)){
        resp = VERD;
}
}       else {
        resp = FALSO;
}
   return resp;
}

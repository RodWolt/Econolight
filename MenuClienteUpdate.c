#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define C_SIZE 5

typedef struct{ // usado para teste trocar pelo criado por quem ficou responsavel por criar a estrutura
    int IDcliente, pontos;
} Pessoa;

Pessoa clientes[C_SIZE];

void IDcheckStrings();
void verPontos(Pessoa clientes[], int numCliente);

UINT CPAGE_DEFAULT;

int main(){

    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    int typeProgram;

    //startUpCarr();
    //startUpProd();
    //startUpClientes();    

    clientes[0].IDcliente = 1;
    clientes[0].pontos = 99999;

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
                break;
            case 0:
                SetConsoleOutputCP(CPAGE_DEFAULT);
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
    int IDcliente, numCliente, op;

    do{
        IDcheckStrings();
        fflush(stdin);
        while(scanf("%d", &IDcliente) != 1 || IDcliente < 1){
            if(getchar() == 'e') return;
            printf("\nA ID de cliente é composta apenas de digitos e maior que 0...\n\n");
            system("pause");
            IDcheckStrings();
            fflush(stdin);
        }
        for(numCliente = 0; numCliente < C_SIZE; numCliente++)
            if(clientes[numCliente].IDcliente == IDcliente) break;
        
        if(clientes[numCliente].IDcliente != IDcliente){
            printf("\nEste ID de cliente não é valido...\n\n");
            system("pause");
        }
    }while(clientes[numCliente].IDcliente != IDcliente);

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
                verPontos(clientes, numCliente);
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

void verPontos(Pessoa clientes[], int numCliente){
    system("cls");
    printf("Pontos registrados: %d\n\n", clientes[numCliente].pontos);
    system("pause");
}

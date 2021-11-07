#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void enterStrings();
void IDcheckStrings();
void verPontos();

int main(){

    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

	int typeProgram, op, IDcliente/*, i*/;

// Começo do programa
start:
    enterStrings();
    fflush(stdin);
    while(scanf("%d", &typeProgram) != 1 || typeProgram < 0 || typeProgram > 2){
        printf("\nDigite uma opção valida...\n\n");
        system("pause");
        enterStrings(); // limpa o buffer de entrada
    }

    if(typeProgram == 0){
        SetConsoleOutputCP(CPAGE_DEFAULT);
        exit(0);
    }

    IDcheckStrings();
    fflush(stdin);
    while(typeProgram == 1 && scanf("%d", &IDcliente) != 1){
        if(getchar() == 'e') goto start;
        printf("\nDigite uma opção valida...\n\n");
        system("pause");
        IDcheckStrings();
        fflush(stdin);
    }

    // for(i = 0, i < structSize, i++)
        // if(structName[i].IDcliente == IDcliente) break; //cliente vai ser structName[i].IDcliente;
    
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
                verPontos();
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
                goto start;
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

void enterStrings(){
    system("cls");
    printf("Você é o cliente ou o provedor?\n");
    printf("1 - Cliente\n");
    printf("2 - Provedor\n");
    printf("0 - Sair do programa\n");
    printf("Opção: ");
}

void IDcheckStrings(){
    system("cls");
    printf("Para voltar ao início digite 'e'\n\n");
    printf("Sua ID de cliente : ");
}

void verPontos(){
    int pontos = 1000;
    system("cls");
    //utilizara a struct para chamar o IDcliente e ver quantos pontos ele tem
    printf("Pontos registrados: %d", pontos /*structName[i].pontos*/);
    printf("\n\n");
    system("pause");
}
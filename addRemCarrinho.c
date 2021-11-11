#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct{
    int IDproduto;
    char nome[20];
    float valor;
} Item;

typedef struct{
    Item info;
    int numComprado;
    float valorFinal;
} Loja;

static const Item prodDefaultValues = {0,"",0};
static const Loja carrDefaultValues = {{0,"",0},0,0};

Item produtos[3];
Loja carrinho[2];

void startCarr();
void addProd();
void addProdCar();
void remProdCar();

int main(){
    
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    int op;

    addProd();
    startCarr();

    while(1){
        system("cls");
        printf("O que deseja fazer?\n");
        printf("1 - Adicionar Produtos ao Carrinho\n");
        printf("2 - Retirar Produtos ao Carrinho\n");
        printf("0 - Sair do programa\n");
        printf("Opção: ");
        fflush(stdin);
        scanf("%d", &op);

        switch(op){
            case 1:
                addProdCar();
                break;
            case 2:
                remProdCar();
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

    return 0;    
}

void startCarr(){
    carrinho[0] = carrDefaultValues;
    carrinho[1] = carrDefaultValues;

    return;
}

void addProd(){
    produtos[0].IDproduto = 1;
    strcpy(produtos[0].nome,"cupom eletronicos");
    produtos[0].valor = 12.55;

    produtos[1].IDproduto = 2;
    strcpy(produtos[1].nome,"cupom carros");
    produtos[1].valor = 3250.55;

    produtos[2].IDproduto = 3;
    strcpy(produtos[2].nome,"cupom restaurantes");
    produtos[2].valor = 54.55;

    produtos[3].IDproduto = 4;
    strcpy(produtos[3].nome,"cupom mercados");
    produtos[3].valor = 150.55;

    return;
}

void addProdCar(){

    int IDprod, numProd, pSize;
    int numCarr, carrSize;
    char keepadding;

    pSize = sizeof(produtos)/sizeof(produtos[0]);
    carrSize = sizeof(carrinho)/sizeof(carrinho[0]);

    do{
        for(numCarr = 0; numCarr < carrSize; numCarr++){
            if(carrinho[numCarr].info.IDproduto == 0) break;
        }
        if(numCarr == carrSize){
            system("cls");
            printf("O carrinho se encontra cheio por favor completar o pedido\n");
            printf("ou remover um produto antes de adicionar outro\n\n");
            system("pause");
            return;
        }

        do{
            system("cls");
            printf("ID do produto: ");
            fflush(stdin);
            while(scanf("%d", &IDprod) != 1 || IDprod < 1){
                if(getchar() == 'e') return;
                printf("\nDigite uma opção valida...\n\n");
                system("pause");
                system("cls");
                printf("ID do produto: ");
                fflush(stdin);
            }
            for(numProd = 0; numProd < pSize; numProd++)
                if(produtos[numProd].IDproduto == IDprod) break;
            
            if(produtos[numProd].IDproduto != IDprod){
                printf("\nEste ID de produto não é valido...\n\n");
                system("pause");
            }
        }while(produtos[numProd].IDproduto != IDprod);

        carrinho[numCarr].info = produtos[numProd];

        printf("\nDeseja adicionar mais produtos?(s/n) ");
        fflush(stdin);
        while(scanf("%c", &keepadding) != 1 || (keepadding != 's' && keepadding != 'n')){
            printf("\nDigite uma opção valida...\n\n");
            system("pause");
            system("cls");
            printf("\nDeseja adicionar mais produtos?(s/n) ");
            fflush(stdin);
        }

    }while(keepadding == 's');

    return;
}

void remProdCar(){
    int IDprod, numProd, pSize;
    int numCarr, carrSize;
    char keepremoving;

    pSize = sizeof(produtos)/sizeof(produtos[0]);
    carrSize = sizeof(carrinho)/sizeof(carrinho[0]);

    do{
        if(carrinho[0].info.IDproduto == 0){
            system("cls");
            printf("O carrinho já se encontra vazio\n\n");
            system("pause");
            return;
        }

        do{
            system("cls");
            printf("ID do produto: ");
            fflush(stdin);
            while(scanf("%d", &IDprod) != 1 || IDprod < 1){
                if(getchar() == 'e') return;
                printf("\nDigite uma opção valida...\n\n");
                system("pause");
                system("cls");
                printf("ID do produto: ");
                fflush(stdin);
            }
            for(numProd = 0; numProd < pSize; numProd++)
                if(produtos[numProd].IDproduto == IDprod) break;
            
            for(numCarr = 0; numCarr < carrSize-1; numCarr++)
                if(carrinho[numCarr].info.IDproduto == IDprod) break;
            
            if(produtos[numProd].IDproduto != IDprod || carrinho[numCarr].info.IDproduto != IDprod){
                printf("\nEste ID de produto não é valido ou não se encontra no carrinho...\n\n");
                system("pause");
            }
        }while(produtos[numProd].IDproduto != IDprod || carrinho[numCarr].info.IDproduto != IDprod);

        carrinho[numCarr] = carrDefaultValues;

        for(; numCarr < carrSize-1; numCarr++){
            if(carrinho[numCarr].info.IDproduto == 0 && carrinho[numCarr+1].info.IDproduto != 0){
                carrinho[numCarr] = carrinho[numCarr+1];
                carrinho[numCarr+1] = carrDefaultValues;
            }
        }

        printf("\nDeseja retirar mais produtos?(s/n) ");
        fflush(stdin);
        while(scanf("%c", &keepremoving) != 1 || (keepremoving != 's' && keepremoving != 'n')){
            printf("\nDigite uma opção valida...\n\n");
            system("pause");
            system("cls");
            printf("\nDeseja retirar mais produtos?(s/n) ");
            fflush(stdin);
        }

    }while(keepremoving == 's');

    return;
}

// Thiago Sant'Anna Machado
// Mat: 20212101791
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define PROD_SIZE 4
#define CARR_SIZE 2

typedef struct{
    int IDproduto;
    char nome[20];
    float valor;
} Item;

typedef struct{
    Item info;
    int quantidade;
    float valorTotal;
} Loja;

const Item prodDefaultValues = {0,"",0};
const Loja carrDefaultValues = {{0,"",0},0,0};

Item produtos[PROD_SIZE];
Loja carrinho[CARR_SIZE];


void startCarr();
void addProd();
void addProdCar();
void remProdCar();
void showCarrSpotInfo(int numCarr);
void showProdInfo(int numProd);

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
        printf("3 - Mostrar carrinho\n");
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
            case 3:
                listCarr();
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

    int IDprod, numProd; // produto
    int numCarr; // carrinho
    int quant;
    char keepAdding;

    do{
        do{
            system("cls");
            printf("Digite 'e' para voltar ao menu inicial\n\n");
            printf("ID do produto: ");
            fflush(stdin);
            while(scanf("%d", &IDprod) != 1 || IDprod < 1){
                if(tolower(getchar()) == 'e') return;
                printf("\nDigite uma opção valida...\n\n");
                system("pause");
                system("cls");
                printf("ID do produto: ");
                fflush(stdin);
            }
            for(numProd = 0; numProd < PROD_SIZE; numProd++)
                if(produtos[numProd].IDproduto == IDprod) break;
            
            if(produtos[numProd].IDproduto != IDprod){
                printf("\nEste ID de produto não é valido...\n\n");
                system("pause");
            }
        }while(produtos[numProd].IDproduto != IDprod);

        for(numCarr = 0; numCarr < CARR_SIZE; numCarr++)
            if(carrinho[numCarr].info.IDproduto == 0 || carrinho[numCarr].info.IDproduto == IDprod) break;

        if(numCarr == CARR_SIZE){
            system("cls");
            printf("O carrinho se encontra cheio por favor completar o pedido\n");
            printf("ou remover um produto antes de adicionar outro\n\n");
            system("pause");
        }
        else if(carrinho[numCarr].quantidade == 0){
            system("cls");
            printf("Caso não deseje adicionar o produto coloque quantidade 0\n\n");
            showProdInfo(numProd);
            printf("Quantidade: ");
            fflush(stdin);
            while(scanf("%d", &quant) != 1 || quant < 0){
                printf("\nDigite uma opção valida...\n\n");
                system("pause");
                system("cls");
                showProdInfo(numProd);
                printf("Quantidade: ");
                fflush(stdin);
            }
            if(quant > 0){
                carrinho[numCarr].info = produtos[numProd];
                carrinho[numCarr].quantidade = quant;
                carrinho[numCarr].valorTotal = carrinho[numCarr].quantidade*carrinho[numCarr].info.valor;
            }
        }
        else{
            system("cls");
            showCarrSpotInfo(numCarr);
            printf("Quantidade a adicionar: ");
            fflush(stdin);
            while(scanf("%d", &quant) != 1 || quant < 0){
                printf("\nDigite uma opção valida...\n\n");
                system("pause");
                system("cls");
                showCarrSpotInfo(numCarr);
                printf("Quantidade: ");
                fflush(stdin);
            }
            carrinho[numCarr].quantidade += quant;
            carrinho[numCarr].valorTotal = carrinho[numCarr].quantidade*carrinho[numCarr].info.valor;
        }

        printf("\nDeseja adicionar mais produtos?(s/n) ");
        fflush(stdin);
        while(scanf("%c", &keepAdding) != 1 || (keepAdding != 's' && keepAdding != 'n')){
            printf("\nDigite uma opção valida...\n\n");
            system("pause");
            system("cls");
            printf("\nDeseja adicionar mais produtos?(s/n) ");
            fflush(stdin);
        }

    }while(keepAdding == 's');

    return;
}

void remProdCar(){
    int IDprod, quant;
    int numCarr;
    char keepRemoving;

    do{
        if(carrinho[0].info.IDproduto == 0){
            system("cls");
            printf("O carrinho já se encontra vazio\n\n");
            system("pause");
            return;
        }

        do{
            system("cls");
            printf("Digite 'e' para voltar ao menu inicial\n\n");
            printf("ID do produto: ");
            fflush(stdin);
            while(scanf("%d", &IDprod) != 1 || IDprod < 1){
                if(tolower(getchar()) == 'e') return;
                printf("\nDigite uma opção valida...\n\n");
                system("pause");
                system("cls");
                printf("ID do produto: ");
                fflush(stdin);
            }
            
            for(numCarr = 0; numCarr < CARR_SIZE-1; numCarr++)
                if(carrinho[numCarr].info.IDproduto == IDprod) break;
            
            if(carrinho[numCarr].info.IDproduto != IDprod){
                printf("\nEste ID de produto não é valido ou não se encontra no carrinho...\n\n");
                system("pause");
            }
        }while(carrinho[numCarr].info.IDproduto != IDprod);

        system("cls");
        printf("Caso deseje remover o produto todo digite um valor negativo ou uma quantidade maior ou igual\n");
        showCarrSpotInfo(numCarr);
        printf("Quantidade que deseja remover: ");
        fflush(stdin);
        while(scanf("%d", &quant) != 1){
            printf("\nDigite uma opção valida...\n\n");
            system("pause");
            system("cls");
            printf("Caso deseje remover o produto todo digite um valor negativo ou uma quantidade maior ou igual\n");
            showCarrSpotInfo(numCarr);
            printf("Quantidade que deseja remover: ");
            fflush(stdin);
        }

        if(quant < 0 || quant >= carrinho[numCarr].quantidade)
            carrinho[numCarr] = carrDefaultValues;
        else{
            carrinho[numCarr].quantidade -= quant;
            carrinho[numCarr].valorTotal = carrinho[numCarr].quantidade*carrinho[numCarr].info.valor;
        }

        for(; numCarr < CARR_SIZE-1; numCarr++){
            if(carrinho[numCarr].info.IDproduto == 0 && carrinho[numCarr+1].info.IDproduto != 0){
                carrinho[numCarr] = carrinho[numCarr+1];
                carrinho[numCarr+1] = carrDefaultValues;
            }
        }

        printf("\nDeseja retirar mais produtos?(s/n) ");
        fflush(stdin);
        while(scanf("%c", &keepRemoving) != 1 || (keepRemoving != 's' && keepRemoving != 'n')){
            printf("\nDigite uma opção valida...\n\n");
            system("pause");
            system("cls");
            printf("\nDeseja retirar mais produtos?(s/n) ");
            fflush(stdin);
        }

    }while(keepRemoving == 's');

    return;
}

void listCarr(){
    int numCarr; // carrinho
    float valorFinal = 0;

    system("cls");
    for(numCarr = 0; numCarr < CARR_SIZE; numCarr++){
        if(carrinho[numCarr].info.IDproduto == 0) break;
        printf("ID do Produto: %d\n", carrinho[numCarr].info.IDproduto);
        printf("Nome do Produto: %s\n", carrinho[numCarr].info.nome);
        printf("Valor Total: %d * %.2f = %.2f\n\n", carrinho[numCarr].quantidade, carrinho[numCarr].info.valor, carrinho[numCarr].valorTotal);
        valorFinal += carrinho[numCarr].valorTotal;
    }
    printf("Valor total do carrinho: %.2f\n\n", valorFinal);
    system("pause");
    return;
}

void showCarrSpotInfo(int numCarr){
    printf("ID do Produto: %d\n", carrinho[numCarr].info.IDproduto);
    printf("Nome do Produto: %s\n", carrinho[numCarr].info.nome);
    printf("Quantidade: %d\n", carrinho[numCarr].quantidade);
    printf("Valor Total: %d * %.2f = %.2f\n\n", carrinho[numCarr].quantidade, carrinho[numCarr].info.valor, carrinho[numCarr].valorTotal);
}

void showProdInfo(int numProd){
    printf("ID do Produto: %d\n", produtos[numProd].IDproduto);
    printf("Nome do Produto: %s\n", produtos[numProd].nome);
    printf("Valor do Produto: %.2f\n\n", produtos[numProd].valor);
}
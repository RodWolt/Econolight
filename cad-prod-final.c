#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define TAMANHO 5
#define VERD 1
#define FALSO 0

struct data{
       int dia;
       int mes;
       int ano;
};

struct produto{
      int id; // -1 indica que a posição do elemento no vetor está vazia
      int cod;
      char nome[20];
      int qtd;
      int valor;

} vetProduto[TAMANHO];

// Função inicializarProduto
  int inicializarProduto(){
  int resp = FALSO;
  int i;
    for(i=0;i<TAMANHO; i++){
        vetProduto[i].id = -1;
    }
    resp = VERD;
return resp;
}

//entradaProduto()
   int entradaProduto(int pos){ // posição livre para a inclusão
   int resp = FALSO;
       printf("\n**********Inclusão de novo registro!********");
       printf("\nIdentificador: %d", pos);
       vetProduto[pos].id = pos;
       printf("\nCódigo..:");
       scanf("%d", vetProduto[pos].codigo); // não vai poder ter espaço no nome
       printf("\nNome..:");
       scanf("%s", vetProduto[pos].nome);
       printf("\nQuantidade..:");
       scanf("%d", vetProduto[pos].qtd);
       printf("\nValor..:");
       scanf("%d", &vetProduto[pos].valor);
       resp = VERD;
return resp;
}

//ListarProduto
int listarProduto(){
   int resp = FALSO;
   int i;
   for(i=0;i<TAMANHO; i++){
        if(vetProduto[i].id != -1){
               printf("\n***************************************");
               printf("\nIdentificador..: %d", vetProduto[i].id);
               printf("\nCódigo..: %d", vetProduto[i].codigo);
               printf("\nNome..: %s", vetProduto[i].nome);
               printf("\nQuantidade..: %d", vetProduto[i].qtd);
               printf("\nValor..: %d", vetProduto[i].valor);

}
}
resp = VERD;
return resp;
}

// buscarProduto()
   int buscarProduto(int pos){
       int resp = FALSO;
       int i;
       printf("\n***************************************");
       printf("\nIdentificador..: %d", vetProduto[pos].id);
       printf("\nCodigo..: %ds", vetProduto[pos].codigo);
       printf("\nNome..: %s", vetProduto[pos].sobrenome);
       printf("\nQuantidade..: %d", vetProduto[pos].qtd);
       printf("\nValor..: %d", vetProduto[pos].valor);
   resp = VERD;
return resp;
}



//incluirProduto()
  int incluirProduto(){
     int resp = FALSO;
     int i;
     int posicao=-1;
        for(i=0;i<TAMANHO; i++){// verificar se tem espaço
            if(vetProduto[i].id==-1){
            posicao = i;
            break;
}
}
    if(posicao!=-1) {
       if(entradaProduto(posicao)){
       resp = VERD;
}
   }else {
   resp = FALSO;
}
   return resp;
}

// AlterarProduto
int alterarProduto(){
    int resp = FALSO;
    int pos=-1;
    char confirma;
       listarProduto();
       printf("\n**************ALTERAÇÃO*********************");
       printf("\nQual é o identificador do Registro?");
       scanf("%d", &pos);
       fflush(stdin);// limpeza do buffer do teclado para nãopular leituras
            if(buscarProduto(pos)){
               printf("\nDeseja Alterar este Registro [s/n]?");
               scanf("%c", &confirma);
                    if(confirma=='s' || confirma == 'S'){
                    entradaProduto(pos);
                    resp = VERD;
    }
    }
return resp;
}

//excluirProduto()
     int excluirProduto(){
     int resp = FALSO;
     int pos=-1;
     char confirma;
          listarProduto();
               printf("\n**************EXCLUSÃO*********************");
               printf("\nQual é o identificador do Registro?");
               scanf("%d", &pos);
               fflush(stdin);// limpeza do buffer do teclado para nãopular leituras
                     if(buscarProduto(pos)){
                     printf("\nConfirma a EXCLUSÃO do Registro [s/n]?");
                     scanf("%c", &confirma);
                          if(confirma=='s' || confirma == 'S'){
                          vetProduto[pos].id = -1;
                          resp = VERD;
           }
}
return resp;
}


int main() {
    setlocale(LC_ALL, "Portuguese");
    int continua = VERD; // VERD é uma constante que possui o valor 1
        if(inicializarProduto()){
               printf("\nProduto Inicializado!");
      } else {
              printf("\nERRO: Produto NÃO Inicializado!");
      }
        char opcao;
    // menu principal
    do {
           printf("\n***************************************");
           printf("\nProduto");
           printf("\ni - Inclusão.");
           printf("\na - Alteração.");
           printf("\ne - Exclusão.");
           printf("\nl - Listar.");
           printf("\ns - Sair.");
           printf("\nEscolha sua opção [i, a, e, l, s]:");
           scanf("%c", &opcao);

switch(opcao){
          case 'i' :
          case 'I' : printf("***** Inclusão *****");
          //incluirProduto();
               if(incluirProduto()){
               printf("\nRegistro Incluído!");
              } else {
               printf("\nERRO ao Incluir Produto!");
               }
          break;
          case 'a' :
          case 'A' : printf("***** Alteração *****");
              if(alterarProduto()){
              printf("\nRegistro Alterado!");
              } else {
              printf("\nERRO ao Alterar Produto!");
              }
          break;

          case 'e' :
          case 'E' : printf("***** Exclusão *****");
               if(excluirProduto()){
               printf("\nRegistro Excluído!");
               } else {
               printf("\nERRO ao Excluir Produto!");
               }
          break;

          case 'l' :
          case 'L' : printf("***** Listagem *****");
               if(listarProduto()){
               printf("\nProdutos listados!");
               } else {
               printf("\nERRO ao Listar Produto!");
               }
          break;

          case 's' :
          case 'S' : printf("***** Saída do Programa *****");
          continua = FALSO;
          break;

 default: printf("\nOpção inválida!!!");

 }
fflush(stdin);// limpeza do buffer do teclado para não pular leituras
}while(continua);

return 0;
}

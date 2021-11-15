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
int id; // -1 indica que a posi��o do elemento no vetor est� vazia
int cod;
char nome[20];
int qtd;
int valor;

} vetProduto[TAMANHO];

// Fun��o inicializarProduto
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
int entradaProduto(int pos){ // posi��o livre para a inclus�o
int resp = FALSO;
printf("\n**********Inclus�o de novo registro!********");
printf("\nIdentificador: %d", pos);
vetProduto[pos].id = pos;
printf("\nC�digo..:");
scanf("%d", vetProduto[pos].codigo); // n�o vai poder ter espa�o no nome
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
printf("\nC�digo..: %d", vetProduto[i].codigo);
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
for(i=0;i<TAMANHO; i++){// verificar se tem espa�o
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
printf("\n**************ALTERA��O*********************");
printf("\nQual � o identificador do Registro?");
scanf("%d", &pos);
fflush(stdin);// limpeza do buffer do teclado para n�opular leituras
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
printf("\n**************EXCLUS�O*********************");
printf("\nQual � o identificador do Registro?");
scanf("%d", &pos);
fflush(stdin);// limpeza do buffer do teclado para n�opular leituras
if(buscarProduto(pos)){
printf("\nConfirma a EXCLUS�O do Registro [s/n]?");
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
int continua = VERD; // VERD � uma constante que possui o valor 1
if(inicializarProduto()){
printf("\nProduto Inicializado!");
} else {
printf("\nERRO: Produto N�O Inicializado!");
}
char opcao;
// menu principal
do {
printf("\n***************************************");
printf("\nProduto");
printf("\ni - Inclus�o.");
printf("\na - Altera��o.");
printf("\ne - Exclus�o.");
printf("\nl - Listar.");
printf("\ns - Sair.");
printf("\nEscolha sua op��o [i, a, e, l, s]:");
scanf("%c", &opcao);

 switch(opcao){
case 'i' :
case 'I' : printf("***** Inclus�o *****");
//incluirProduto();
if(incluirProduto()){
printf("\nRegistro Inclu�do!");
} else {
printf("\nERRO ao Incluir Produto!");
}
break;
case 'a' :
case 'A' : printf("***** Altera��o *****");
if(alterarProduto()){
printf("\nRegistro Alterado!");
} else {
printf("\nERRO ao Alterar Produto!");
}
break;

 case 'e' :
case 'E' : printf("***** Exclus�o *****");
if(excluirProduto()){
printf("\nRegistro Exclu�do!");
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
case 'S' : printf("***** Sa�da do Programa *****");
continua = FALSO;
break;

 default: printf("\nOp��o inv�lida!!!");

 }
fflush(stdin);// limpeza do buffer do teclado para n�o pular leituras
}while(continua);

return 0;
}

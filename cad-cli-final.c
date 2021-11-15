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

 struct cliente{
int id; // -1 indica que a posi��o do elemento no vetor est� vazia
char nome[20];
char sobrenome[20];
struct data dataNasc;
char telefone[20];
char email[30];
int pontos;
} vetCliente[TAMANHO];

// Fun��o inicializarcliente
int inicializarCliente(){
int resp = FALSO;
int i;
for(i=0;i<TAMANHO; i++){
vetCliente[i].id = -1;
}
resp = VERD;
return resp;
}

//entradacliente()
int entradaCliente(int pos){ // posi��o livre para a inclus�o
int resp = FALSO;
printf("\n**********Inclus�o de novo registro!********");
printf("\nIdentificador: %d", pos);
vetCliente[pos].id = pos;
printf("\nNome..:");
scanf("%s", vetCliente[pos].nome); // n�o vai poder ter espa�o no nome
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

//ListarCliente
int listarCliente(){
int resp = FALSO;
int i;
for(i=0;i<TAMANHO; i++){
if(vetCliente[i].id != -1){
printf("\n***************************************");
printf("\nIdentificador..: %d", vetCliente[i].id);
printf("\nNome..: %s", vetCliente[i].nome);
printf("\nSobrenome..: %s", vetCliente[i].sobrenome);
printf("\nData Nasc..: %02d/%02d/%04d", vetCliente[i].dataNasc.dia,
vetCliente[i].dataNasc.mes, vetCliente[i].dataNasc.ano);
printf("\nTelefone..: %s", vetCliente[i].telefone);
printf("\nEmail..: %s", vetCliente[i].email);
printf("\nPontos..: %d", vetCliente[i].pontos);

}
}
resp = VERD;
return resp;
}

// buscarCliente()
int buscarCliente(int pos){
int resp = FALSO;
int i;
printf("\n***************************************");
printf("\nIdentificador..: %d", vetCliente[pos].id);
printf("\nNome..: %s", vetCliente[pos].nome);
printf("\nSobrenome..: %s", vetCliente[pos].sobrenome);
printf("\nData Nasc..: %02d/%02d/%04d", vetCliente[pos].dataNasc.dia,
vetCliente[pos].dataNasc.mes, vetCliente[pos].dataNasc.ano);
printf("\nTelefone..: %s", vetCliente[pos].telefone);
printf("\nEmail..: %s", vetCliente[pos].email);
printf("\nPontos..: %d", vetCliente[pos].email);
resp = VERD;
return resp;
}



//incluirCliente()
int incluirCliente(){
int resp = FALSO;
int i;
int posicao=-1;
for(i=0;i<TAMANHO; i++){// verificar se tem espa�o
if(vetCliente[i].id==-1){
posicao = i;
break;
}
}
if(posicao!=-1) {
if(entradaCliente(posicao)){
resp = VERD;
}
}else {
resp = FALSO;
}
return resp;
}

// AlterarCliente
int alterarCliente(){
int resp = FALSO;
int pos=-1;
char confirma;
listarCliente();
printf("\n**************ALTERA��O*********************");
printf("\nQual � o identificador do Registro?");
scanf("%d", &pos);
fflush(stdin);// limpeza do buffer do teclado para n�opular leituras
if(buscarCliente(pos)){
printf("\nDeseja Alterar este Registro [s/n]?");
scanf("%c", &confirma);
if(confirma=='s' || confirma == 'S'){
entradaCliente(pos);
resp = VERD;
}
}
return resp;
}

//excluirCliente()
int excluirCliente(){
int resp = FALSO;
int pos=-1;
char confirma;
listarCliente();
printf("\n**************EXCLUS�O*********************");
printf("\nQual � o identificador do Registro?");
scanf("%d", &pos);
fflush(stdin);// limpeza do buffer do teclado para n�opular leituras
if(buscarCliente(pos)){
printf("\nConfirma a EXCLUS�O do Registro [s/n]?");
scanf("%c", &confirma);
if(confirma=='s' || confirma == 'S'){
vetCliente[pos].id = -1;
resp = VERD;
}
}
return resp;
}


int main() {
setlocale(LC_ALL, "Portuguese");
int continua = VERD; // VERD � uma constante que possui o valor 1
if(inicializarCliente()){
printf("\nCliente Inicializado!");
} else {
printf("\nERRO: Cliente N�O Inicializado!");
}
char opcao;
// menu principal
do {
printf("\n***************************************");
printf("\nCliente");
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
//incluirCliente();
if(incluirCliente()){
printf("\nRegistro Inclu�do!");
} else {
printf("\nERRO ao Incluir Cliente!");
}
break;
case 'a' :
case 'A' : printf("***** Altera��o *****");
if(alterarCliente()){
printf("\nRegistro Alterado!");
} else {
printf("\nERRO ao Alterar Cliente!");
}
break;

 case 'e' :
case 'E' : printf("***** Exclus�o *****");
if(excluirCliente()){
printf("\nRegistro Exclu�do!");
} else {
printf("\nERRO ao Excluir Cliente!");
}
break;

case 'l' :
case 'L' : printf("***** Listagem *****");
if(listarCliente()){
printf("\nClientes listados!");
} else {
printf("\nERRO ao Listar Cliente!");
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

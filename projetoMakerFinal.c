#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>

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

struct produto{
      int id; // -1 indica que a posição do elemento no vetor está vazia
      int codigo;
      char nome[20];
      int qtd;
      int valor;

} vetProduto[TAMANHO];


void IDcheckStrings();
int inicializarCliente();
int entradaCliente();
int incluirCliente();
void menuProvedor();
int alterarCliente();
int excluirCliente();
int listarCliente();
int buscarCliente();
int inicializarProduto();
int menuAddProduto();
void clienteMenu();
void verPontos(int numCliente);
void menuAddCliente();
UINT CPAGE_DEFAULT;




int main(){
    setlocale(LC_ALL,"Portuguese");
    int typeProgram;

    //startUpCarr();
    //startUpProd();
    //startUpClientes();    
	inicializarCliente();
	inicializarProduto();
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
//                exit(0);
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
        while(scanf("%d", &id) != 1 || id < 0){
            if(getchar() == 'e') return;
            printf("\nA ID de cliente é composta apenas de digitos positivos...\n\n");
            system("pause");
            IDcheckStrings();
            fflush(stdin);
        }
        for(numCliente = 0; numCliente < TAMANHO; numCliente++)
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
                verPontos(numCliente);
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

void verPontos(int numCliente){
    system("cls");
    printf("Pontos registrados: %d\n\n", vetCliente[numCliente].pontos);
    system("pause");
}
void menuProvedor()
{
	int numero;
	while (1){
	system("cls");
	printf("\nSistemas\n\n");
	printf("1- Adicionar clientes\n");
	printf("2- Adicionar produtos\n");
	printf("3- Ver lista de clientes\n");
	printf("4- Ver lista de produtos\n");
	printf("0- Voltar ao menu incial\n");
	printf("\nEscolha a opção desejada: \n");
	scanf("%d", &numero);
	switch(numero)
	{
	    case 1:
	    	system("cls"); 
			menuAddCliente();
	    	break;
	
	    case 2:
	        system("cls"); 
	    	
	    	break;
	    
		case 3:
			system("cls"); 
	    	listarClientes();
	    	break;
	    	
	    case 4:
	    	system("cls"); 
	    	
	    	break;
	    	
	    case 0:
	    	return;
	}
	}

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
      fflush(stdin);
	  scanf("%d", &vetCliente[pos].id);;
      printf("\nNome..:");
      fflush(stdin);
	  scanf("%s", vetCliente[pos].nome); // não vai poder ter espaço no nome
      printf("\nSobrenome..:");
      fflush(stdin);
	  scanf("%s", vetCliente[pos].sobrenome);
      printf("\nData Nasc - (DDMMAAAA)..:");
      fflush(stdin);
	  scanf("%d %d %d", &vetCliente[pos].dataNasc.dia,
      &vetCliente[pos].dataNasc.mes, &vetCliente[pos].dataNasc.ano);
      printf("\nTelefone..:");
      fflush(stdin);
	  scanf("%s", vetCliente[pos].telefone);
      printf("\nEmail..:");
      fflush(stdin);
	  scanf("%s", vetCliente[pos].email);
      printf("\nPontos..:");
      fflush(stdin);
	  scanf("%d", &vetCliente[pos].pontos);
      resp = VERD;
return resp;
}
int incluirCliente()
{
    int resp = FALSO;
    int i;
    int posicao=-1;
    	for(i=0;i<TAMANHO; i++)
		{// verificar se tem espaço
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

void menuAddCliente() {
    int continua = VERD; // VERD é uma constante que possui o valor 1
    char opcao;
// menu principal
		do {
          printf("\n***************************************");
          printf("\nCliente");
          printf("\ni - Inclusão.");
          printf("\na - Alteração.");
          printf("\ne - Exclusão.");
          printf("\nl - Listar.");
          printf("\ns - Sair.");
          printf("\nEscolha sua opção [i, a, e, l, s]:");
          fflush(stdin);
		  scanf("%c", &opcao);

		switch(opcao){
       
           	case 'i' :
           	case 'I' : printf("***** Inclusão *****");
           //incluirCliente();
                    if(incluirCliente()){
                    printf("\nRegistro Incluído!");
                    } else {
                    printf("\nERRO ao Incluir Cliente!");
                 }
           break;
           	case 'a' :
           	case 'A' : printf("***** Alteração *****");
                     if(alterarCliente()){
                     printf("\nRegistro Alterado!");
                     } else {
                    printf("\nERRO ao Alterar Cliente!");
           }
           break;

          	case 'e' :
          	case 'E' : printf("***** Exclusão *****");
                   if(excluirCliente()){
                   printf("\nRegistro Excluído!");
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
         	case 'S' : printf("***** Saída do Programa *****");
         continua = FALSO;
         break;

         default: printf("\nOpção inválida!!!");

 }
fflush(stdin);// limpeza do buffer do teclado para não pular leituras
}while(continua);

return;
}

int alterarCliente(){
       int resp = FALSO;
       int pos=-1;
       char confirma;
       listarCliente();
       printf("\n**************ALTERAÇÃO*********************");
       printf("\nQual é o identificador do Registro?");
       scanf("%d", &pos);
       fflush(stdin);// limpeza do buffer do teclado para nãopular leituras
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
     printf("\n**************EXCLUSÃO*********************");
     printf("\nQual é o identificador do Registro?");
     scanf("%d", &pos);
     fflush(stdin);// limpeza do buffer do teclado para nãopular leituras
     if(buscarCliente(pos)){
     printf("\nConfirma a EXCLUSÃO do Registro [s/n]?");
     scanf("%c", &confirma);
     if(confirma=='s' || confirma == 'S'){
     vetCliente[pos].id = -1;
     resp = VERD;
}
}
return resp;
}

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
       fflush(stdin);
	   scanf("%d", vetProduto[pos].codigo); // não vai poder ter espaço no nome
       printf("\nNome..:");
       fflush(stdin);
	   scanf("%s", vetProduto[pos].nome);
       printf("\nQuantidade..:");
       fflush(stdin);
	   scanf("%d", vetProduto[pos].qtd);
       printf("\nValor..:");
       fflush(stdin);
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
       printf("\nNome..: %s", vetProduto[pos].nome);
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
       fflush(stdin);
	   scanf("%d", &pos);
       	    if(buscarProduto(pos)){
               printf("\nDeseja Alterar este Registro [s/n]?");
               fflush(stdin);
			   scanf("%c", &confirma);
                    if(confirma=='s' || confirma == 'S'){
                    entradaProduto(pos);
                    resp = VERD;
    }
    }
return resp;
}

//excluir produto
	    int excluirProduto(){
	    int resp = FALSO;
	    int pos=-1;
	    char confirma;
          listarProduto();
               printf("\n**************EXCLUSÃO*********************");
               printf("\nQual é o identificador do Registro?");
               fflush(stdin);
			   scanf("%d", &pos);
                    if(buscarProduto(pos)){
                     printf("\nConfirma a EXCLUSÃO do Registro [s/n]?");
                     fflush(stdin);
					 scanf("%c", &confirma);
                          if(confirma=='s' || confirma == 'S'){
                          vetProduto[pos].id = -1;
                          resp = VERD;
           }
}
return resp;
}

int menuAddProduto() {
    
    int continua = VERD; // VERD é uma constante que possui o valor 1
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
		   fflush(stdin);
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
}while(continua);

return 0;
}


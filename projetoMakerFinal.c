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
    float metaFinal;
    float consumo;
} vetCliente[TAMANHO];

struct produto{
      int id; // -1 indica que a posição do elemento no vetor está vazia
      int codigo;
      char nome[20];
      int qtd;
      int valor;

} vetProduto[TAMANHO];

typedef struct{
    struct produto info;
    int quantidade;
    int valorTotal;
} Loja;


Loja carrinho[TAMANHO];


void IDcheckStrings();
int inicializarCliente();
int entradaCliente();
int incluirCliente();
void menuProvedor();
int alterarCliente();
int excluirCliente();
int listarCliente();
int buscarCliente();
int listarProduto();
int inicializarProduto();
int menuAddProduto();
float cadastroMeta(int numCliente);
float WEconomizado(int numCliente);
void clienteMenu();
void verPontos(int numCliente);
void menuAddCliente();
void simConsumo ();
void addProdCar();
void remProdCar();
void inicializarCarr();
void listCarr();
void showCarrSpotInfo(int numCarr);
void showProdInfo(int numProd);
UINT CPAGE_DEFAULT;
float metaFinal, consumo;




int main(){
    setlocale(LC_ALL,"Portuguese");
    int typeProgram;

    //startUpCarr();
    //startUpProd();
    //startUpClientes(); 
	inicializarCarr();   
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
        printf("2 - Simulação de consumo\n");
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
            	simConsumo();
                break;
            case 3:
            	cadastroMeta(numCliente);
                break;
            case 4:
            	WEconomizado(numCliente);
                break;
            case 5:
            	listarProduto();
                break;
            case 6:
            	menuCarrinho();
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
	    	menuAddProduto();
	    	break;
	    
		case 3:
			system("cls"); 
	    	listarCliente();
	    	system("pause");
	    	break;
	    	
	    case 4:
	    	system("cls"); 
	    	listarProduto();
	    	system("pause");
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
	   scanf("%d", &vetProduto[pos].codigo); // não vai poder ter espaço no nome
       printf("\nNome..:");
       fflush(stdin);
	   scanf("%s", vetProduto[pos].nome);
       printf("\nQuantidade..:");
       fflush(stdin);
	   scanf("%d", &vetProduto[pos].qtd);
       printf("\nValor..:");
       fflush(stdin);
	   scanf("%d", &vetProduto[pos].valor);
       resp = VERD;
return resp;
}

//ListarProduto
int listarProduto()
{
   int resp = FALSO;
   int i;
   for(i=0;i<TAMANHO; i++)
   {
        if(vetProduto[i].id != -1)
		{
               printf("\n***************************************");
               printf("\nIdentificador..: %d", vetProduto[i].id);
               printf("\nCódigo..: %d", vetProduto[i].codigo);
               printf("\nNome..: %s", vetProduto[i].nome);
               printf("\nQuantidade..: %d", vetProduto[i].qtd);
               printf("\nValor..: %d\n", vetProduto[i].valor);
               

		}
	}
	system("pause");
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

float cadastroMeta(int numCliente)
	{
		//todos os textos dentro dos printf's e nomes de variáveis são temporários
		float meta, meta2=0, cons;
		int mes, check, i=1;
		//Escolher quantos meses;
		system("cls");
		printf("Gostaria de cadastrar o consumo de -3-, -6- ou -12- meses? -0- Cancelar\n>: ");
		fflush(stdin);
		scanf("%d", &mes);
		switch (mes)
		{
			case 3:
				do{
					printf("*************\nConsumo do mês %d\n>:", i);
					fflush(stdin);
					scanf("%f",&cons);
					vetCliente[numCliente].consumo+=cons;
					i++;
				}while(i<=mes);
				//Deixei as 2 formas de adicionar a meta, de acordo com a discussão que tivemos, a meta vai ser salva em % do valor original
				vetCliente[numCliente].consumo = (vetCliente[numCliente].consumo/mes);
				system("cls");
				printf("*************\nConsumo médio nos %d meses>: %.2f kwatts", mes, vetCliente[numCliente].consumo);
				printf("\n*************\nComo gostaria de estipular sua meta?");
				printf("\n1- para usar Porcentagem");
				printf("\n2- para usar Numero inteiro\n>: ");
				fflush(stdin);
				scanf("%d", &check);
				if(check==1)
				{
					system("cls");
					printf("-*************\nQuanto gostaria de economizar?(Porcentagem)\n>: ");
					fflush(stdin);
					scanf("%f", &meta);
					meta2 = vetCliente[numCliente].consumo - (vetCliente[numCliente].consumo * (meta/100));//inteiro atraves da %
					vetCliente[numCliente].metaFinal = meta;
					system("cls");
					printf("*************\nPara economizar %.2f%%, você deverá consumir até %.2f kwatts em %d meses.", meta, meta2, mes);
					break;
				}
				else if(check==2)
				{
					system("cls");
					printf("*************\nQuanto gostaria de economizar?(Inteiro)\n>: ");
					fflush(stdin);
					scanf("%f", &meta);
					vetCliente[numCliente].metaFinal = (meta/vetCliente[numCliente].consumo)*100; // porcentagem
					meta2 = vetCliente[numCliente].consumo - meta;
					system("cls");
					printf("*************\nQuer economizar %.2f%% de seu consumo anterior em %d meses.", vetCliente[numCliente].metaFinal, mes);
					printf("\n*************\nPara economizar %.2f%%, você deverá consumir até %.2f kwatts em %d meses.", vetCliente[numCliente].metaFinal, meta2, mes);
					break;
				}
			case 6:
				do{
					printf("*************\nConsumo do mês %d\n>:", i);
					fflush(stdin);
					scanf("%f",&cons);
					vetCliente[numCliente].consumo+=cons;
					i++;
				}while(i<=mes);
				system("cls");
				printf("*************\nConsumo médio nos %d meses>: %.2f kwatts", mes, vetCliente[numCliente].consumo);
				printf("\n*************\nComo gostaria de estipular sua meta?");
				printf("\n1- para usar Porcentagem");
				printf("\n2- para usar Numero inteiro\n>: ");
				fflush(stdin);
				scanf("%d", &check);
				if(check==1)
				{
					system("cls");
					printf("*************\nQuanto gostaria de economizar?(Porcentagem)\n>: ");
					fflush(stdin);
					scanf("%f", &meta);
					meta2 = vetCliente[numCliente].consumo - (vetCliente[numCliente].consumo * (meta/100));
					vetCliente[numCliente].metaFinal = meta;
					system("cls");
					printf("*************\nPara economizar %.2f%%, você deverá consumir até %.2f kwatts em %d meses.", meta, meta2, mes);
					break;
				}
				else if(check==2)
				{
					system("cls");
					printf("*************\nQuanto gostaria de economizar?(Inteiro)\n>: ");
					fflush(stdin);
					scanf("%f", &meta);
					vetCliente[numCliente].metaFinal = (meta/vetCliente[numCliente].consumo)*100;
					meta2 = vetCliente[numCliente].consumo - meta;
					system("cls");
					printf("*************\nQuer economizar %.2f%% de seu consumo anterior em %d meses.", vetCliente[numCliente].metaFinal, mes);
					printf("\n*************\nPara economizar %.2f%%, você deverá consumir até %.2f kwatts em %d meses.", vetCliente[numCliente].metaFinal, meta2, mes);
					break;
				}
			case 12:
				do{
					system("cls");
					printf("*************\nConsumo do mês %d\n>:", i);
					fflush(stdin);
					scanf("%f",&cons);
					vetCliente[numCliente].consumo+=cons;
					i++;
				}while(i<=mes);
				system("cls");
				printf("*************\nConsumo médio nos %d meses>: %.2f kwatts", mes, vetCliente[numCliente].consumo);
				printf("\n*************\nComo gostaria de estipular sua meta?");
				printf("\n1- para usar Porcentagem");
				printf("\n2- para usar Numero inteiro\n>: ");
				fflush(stdin);
				scanf("%d", &check);
				if(check==1)
				{
					system("cls");
					printf("*************\nQuanto gostaria de economizar?(Porcentagem)\n>: ");
					fflush(stdin);
					scanf("%f", &meta);
					meta2 = vetCliente[numCliente].consumo - (vetCliente[numCliente].consumo * (meta/100));
					vetCliente[numCliente].metaFinal = meta;
					system("cls");
					printf("*************\nPara economizar %.2f%%, você deverá consumir até %.2f kwatts em %d meses.", meta, meta2, mes);
					break;
				}
				else if(check==2)
				{
					system("cls");
					printf("*************\nQuanto gostaria de economizar?(Inteiro)\n>: ");
					fflush(stdin);
					scanf("%f", &meta);
					vetCliente[numCliente].metaFinal = (meta/vetCliente[numCliente].consumo)*100;
					meta2 = vetCliente[numCliente].consumo - meta;
					system("cls");
					printf("*************\nQuer economizar %.2f%% de seu consumo anterior em %d meses.", vetCliente[numCliente].metaFinal, mes);
					printf("\n*************\nPara economizar %.2f%%, você deverá consumir até %.2f kwatts em %d meses.", vetCliente[numCliente].metaFinal, meta2, mes);
					break;
				}
			case 0:
				return;
			default:
               	printf("*************\nDigite uma opção valida.\n*************\n");
               	cadastroMeta(numCliente);
               	break;
				
		}
		printf("\nConsumo inicial>: %.2f kwatts", vetCliente[numCliente].consumo);
		printf("\nMeta Final>: %.2f%%\n", vetCliente[numCliente].metaFinal);
		system("pause");		
	}
		
	
float WEconomizado(int numCliente)
   {
	     float watts, wattsEconom, tempo, Econom=0;
	    
	     printf("Quanto de consumo foi efetivado? ");
	     scanf("%f", &wattsEconom);
	     Econom = (vetCliente[numCliente].consumo - wattsEconom)*100/vetCliente[numCliente].consumo;     
	     printf("Você economizou..: %.2f%% de energia", Econom );
	     if (Econom >= vetCliente[numCliente].metaFinal)
		{
			printf("\n*************\nAtingiu a meta de %.2f, economizou %.2f", vetCliente[numCliente].metaFinal, Econom);
			if(metaFinal<=5)
			{vetCliente[numCliente].pontos+=100;}
			else if(metaFinal<=10)
			{vetCliente[numCliente].pontos+=200;}
			else if(metaFinal<=15)
			{vetCliente[numCliente].pontos+=300;}
			else if(metaFinal<=20)
			{vetCliente[numCliente].pontos+=400;}
		}
		else if (Econom < vetCliente[numCliente].metaFinal)
		{
			printf("\n*************\nNao atingiu a meta de %.2f, ecomonizou apenas %.2f", vetCliente[numCliente].metaFinal, Econom);

		}
		printf("\nPontos atuais: %d\n", vetCliente[numCliente].pontos);
	     system("pause");
   }
void simConsumo (){
	
	int esc, i;
	float watt, tempo, consumo=0;
	printf("\nEscolha o número de aparelhos que serão lançados..:");
	scanf("%d", &esc);
	
		for(i=0; i<esc; i++)
		{	
		printf("\nDigite a potencia em Watt do aparelho %d..:", (i+1));
		scanf("%f", &watt);
		printf("\nDigite o tempo em horas estimado em que o aparelho fica ligado por dia..:");
		scanf("%f", &tempo);
		consumo = consumo + ((watt/1000)*(tempo)*30);
		}
	printf("\nO consumo estimado para o mês é..: %.2f KWh\n", consumo );
	system("pause");
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
            while(scanf("%d", &IDprod) != 1 || IDprod < 0){
                if(tolower(getchar()) == 'e') return;
                printf("\nDigite uma opção valida...\n\n");
                system("pause");
                system("cls");
                printf("ID do produto: ");
                fflush(stdin);
            }
            for(numProd = 0; numProd < TAMANHO; numProd++)
                if(vetProduto[numProd].id == IDprod) break;
            
            if(vetProduto[numProd].id != IDprod){
                printf("\nEste ID de produto não é valido...\n\n");
                system("pause");
            }
        }while(vetProduto[numProd].id != IDprod);

        for(numCarr = 0; numCarr < TAMANHO; numCarr++)
            if(carrinho[numCarr].info.id == -1 || carrinho[numCarr].info.id == IDprod) break;

        if(numCarr == TAMANHO){
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
                carrinho[numCarr].info = vetProduto[numProd];
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
void showCarrSpotInfo(int numCarr){
    printf("ID do Produto: %d\n", carrinho[numCarr].info.id);
    printf("Nome do Produto: %s\n", carrinho[numCarr].info.nome);
    printf("Quantidade: %d\n", carrinho[numCarr].quantidade);
    printf("Valor Total: %d * %d = %d\n\n", carrinho[numCarr].quantidade, carrinho[numCarr].info.valor, carrinho[numCarr].valorTotal);
}
void showProdInfo(int numProd){
    printf("ID do Produto: %d\n", vetProduto[numProd].id);
    printf("Nome do Produto: %s\n", vetProduto[numProd].nome);
    printf("Valor do Produto: %d\n\n", vetProduto[numProd].valor);
}
void inicializarCarr()
{
  int i;
    for(i=0;i<TAMANHO; i++) 
          {
           carrinho[i].info.id = -1;
          }
}
int menuCarrinho()
{
	int op;
	 while(1){
        system("cls");
        printf("O que deseja fazer?\n");
        printf("1 - Adicionar Produtos ao Carrinho\n");
        printf("2 - Retirar Produtos ao Carrinho\n");
        printf("3 - Mostrar carrinho\n");
        printf("0 - Sair do carrinho\n");
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
                return;
            default:
                printf("Digite uma opção valida...\n");
                system("pause");
                system("cls");
        }
    }

    return 0;    
}

void remProdCar(){
    int IDprod, quant;
    int numCarr;
    char keepRemoving;

    do{
        if(carrinho[0].info.id == -1){
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
            while(scanf("%d", &IDprod) != 1 || IDprod < 0){
                if(tolower(getchar()) == 'e') return;
                printf("\nDigite uma opção valida...\n\n");
                system("pause");
                system("cls");
                printf("ID do produto: ");
                fflush(stdin);
            }
            
            for(numCarr = 0; numCarr < TAMANHO-1; numCarr++)
                if(carrinho[numCarr].info.id == IDprod) break;
            
            if(carrinho[numCarr].info.id != IDprod){
                printf("\nEste ID de produto não é valido ou não se encontra no carrinho...\n\n");
                system("pause");
            }
        }while(carrinho[numCarr].info.id != IDprod);

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
            carrinho[numCarr].info.id = -1;
        else{
            carrinho[numCarr].quantidade -= quant;
            carrinho[numCarr].valorTotal = carrinho[numCarr].quantidade*carrinho[numCarr].info.valor;
        }

        for(; numCarr < TAMANHO-1; numCarr++){
            if(carrinho[numCarr].info.id == -1 && carrinho[numCarr+1].info.id != -1){
                carrinho[numCarr] = carrinho[numCarr+1];
                carrinho[numCarr+1].info.id = -1;
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
    int valorFinal = 0;

    system("cls");
    for(numCarr = 0; numCarr < TAMANHO; numCarr++){
        if(carrinho[numCarr].info.id == -1) break;
        printf("ID do Produto: %d\n", carrinho[numCarr].info.id);
        printf("Nome do Produto: %s\n", carrinho[numCarr].info.nome);
        printf("Valor Total: %d * %d = %d\n\n", carrinho[numCarr].quantidade, carrinho[numCarr].info.valor, carrinho[numCarr].valorTotal);
        valorFinal += carrinho[numCarr].valorTotal;
    }
    printf("Valor total do carrinho: %d\n\n", valorFinal);
    system("pause");
    return;
}

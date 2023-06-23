#include <stdio.h>  // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das string

int registro() // Fun��o respons�vel por cadastear os usu�rios no sistema
{
	//inicio da cria��o de vari�veis/string
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	// final da cria��o de vari�veis/string
	
	printf ("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); // Respons�vel por copiar os valores das string
	
	FILE *file;// cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e abre, "w" de escrever
	fprintf(file,cpf); // salva o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // Abrir o arquivo, "a" de atualizar o arquivo aberto
	fprintf(file,","); // essa virgula vai separar as informa��es na �rea de consulta
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informa��es do usu�rio
	scanf("%s", nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abre o arquivo, "a" de atualizar as informa��es
	fprintf(file,nome); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo, "a" de atualizar as informa��es 
	fprintf(file,","); // essa virgula vai separar as informa��es na �rea de consulta
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando informa��es do usu�rio
	scanf("%s", sobrenome); // %s refere-se a string
	
	file = fopen(arquivo, "a"); //abre o arquivo, "a" de atualizar
	fprintf(file,sobrenome); //salva o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo,"a"); //abre o arquivo, "a" de atualizar as informa��es 
	fprintf(file,","); // essa virgula vai separar as informa��es na �rea de consulta
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Coletando informa��es do usu�rio
	scanf("%s", cargo); // %s refere-se a string
	
	file = fopen(arquivo,"a"); //abre o arquivo, "a" de atualizar
	fprintf(file,cargo); //salva o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	system("pause"); //pausa o sistema 
}


int consulta()
{
	setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
	//inicio da cria��o de vari�veis/string
	 char cpf [40];
	 char conteudo [200];
	 // final da cria��o de vari�veis/string
	 
	 printf ("Digite o CPF a ser consultado\n\n"); //Solicita��o de dados do us�rio
	 scanf ("%s", cpf); // %s refere-se a string
	 
	 FILE *file; // cria o arquivo
	 file= fopen(cpf, "r"); // abre o arquivo, "r" de ready para ler o arquivo
	 
	 if(file == NULL) // Valida��o do arquivo, se existe ou n�o
	 {
	 	printf ("N�o foi possivel abrir o arquivo, n�o localizado!.\n\n");
	 }
	 
	 while(fgets(conteudo, 200, file) != NULL) // "while" la�o de repeti��o, enquanto 
	 {
	 	printf("\n Essas s�o as informa��es do us�rio: "); //Visualiza��o dos dados do usu�rio solicitado
	 	printf("%s", conteudo); // %s refere-se a string
	 	printf ("\n\n");
	 }
	 
	 system("pause"); // fun��o para dar um pause no sistema
	 
	 
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf [40];
	
	printf("Digite o CPF do usu�rio a ser deletado: \n\n");
	scanf("%s", cpf);
	
	remove(cpf); // importamos essa fun��o da biblioteca
	
	FILE *file; // criar o arquivo
	file = fopen (cpf, "r"); // abrir o arquivo, "r" de ready para ler as informa��es
	
	if(file == NULL) // valida��o do arquivo
	{
		printf("O usu�rio n�o se encontra no sistema!. \n\n");
		system("pause");
	}
	
}

int main ()

{ 
    int opcao=0; // definindo vari�veis
    int x=1; 
	
	for(x=1;x=1;)
    {
	
		system("cls"); //comando para limpar a tela
		
		setlocale(LC_ALL, "Portuguese");  //definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); // in�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n"); 
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Op��o:\n\n"); //fim do menu
	
		scanf("%d", &opcao); // armazenando a escolha do usu�rio
	
		system("cls"); //repons�vel por limpar a tela
		
		switch(opcao)
		{
			case 1: //in�cio da sele��o do menu
				registro();
				break; //comando para fechar a chave no switch case
				
			case 2:
				consulta();
				break;
				
			case 3:
				deletar();
				break;
				
			default:
				printf("Essa op��o n�o est� dispon�vel\n\n");
				system("pause");
				break; //fim da sele��o
		}	
	}
}


#include <stdio.h>  // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> // biblioteca responsável por cuidar das string

int registro() // Função responsável por cadastear os usuários no sistema
{
	//inicio da criação de variáveis/string
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	// final da criação de variáveis/string
	
	printf ("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); // Responsável por copiar os valores das string
	
	FILE *file;// cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e abre, "w" de escrever
	fprintf(file,cpf); // salva o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // Abrir o arquivo, "a" de atualizar o arquivo aberto
	fprintf(file,","); // essa virgula vai separar as informações na área de consulta
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informações do usuário
	scanf("%s", nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abre o arquivo, "a" de atualizar as informações
	fprintf(file,nome); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo, "a" de atualizar as informações 
	fprintf(file,","); // essa virgula vai separar as informações na área de consulta
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando informações do usuário
	scanf("%s", sobrenome); // %s refere-se a string
	
	file = fopen(arquivo, "a"); //abre o arquivo, "a" de atualizar
	fprintf(file,sobrenome); //salva o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo,"a"); //abre o arquivo, "a" de atualizar as informações 
	fprintf(file,","); // essa virgula vai separar as informações na área de consulta
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Coletando informações do usuário
	scanf("%s", cargo); // %s refere-se a string
	
	file = fopen(arquivo,"a"); //abre o arquivo, "a" de atualizar
	fprintf(file,cargo); //salva o valor da variável
	fclose(file); // fecha o arquivo
	
	system("pause"); //pausa o sistema 
}


int consulta()
{
	setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
	//inicio da criação de variáveis/string
	 char cpf [40];
	 char conteudo [200];
	 // final da criação de variáveis/string
	 
	 printf ("Digite o CPF a ser consultado\n\n"); //Solicitação de dados do usário
	 scanf ("%s", cpf); // %s refere-se a string
	 
	 FILE *file; // cria o arquivo
	 file= fopen(cpf, "r"); // abre o arquivo, "r" de ready para ler o arquivo
	 
	 if(file == NULL) // Validação do arquivo, se existe ou não
	 {
	 	printf ("Não foi possivel abrir o arquivo, não localizado!.\n\n");
	 }
	 
	 while(fgets(conteudo, 200, file) != NULL) // "while" laço de repetição, enquanto 
	 {
	 	printf("\n Essas são as informações do usário: "); //Visualização dos dados do usuário solicitado
	 	printf("%s", conteudo); // %s refere-se a string
	 	printf ("\n\n");
	 }
	 
	 system("pause"); // função para dar um pause no sistema
	 
	 
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf [40];
	
	printf("Digite o CPF do usuário a ser deletado: \n\n");
	scanf("%s", cpf);
	
	remove(cpf); // importamos essa função da biblioteca
	
	FILE *file; // criar o arquivo
	file = fopen (cpf, "r"); // abrir o arquivo, "r" de ready para ler as informações
	
	if(file == NULL) // validação do arquivo
	{
		printf("O usuário não se encontra no sistema!. \n\n");
		system("pause");
	}
	
}

int main ()

{ 
    int opcao=0; // definindo variáveis
    int x=1; 
	
	for(x=1;x=1;)
    {
	
		system("cls"); //comando para limpar a tela
		
		setlocale(LC_ALL, "Portuguese");  //definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); // início do menu
		printf("Escolha a opção desejada do menu:\n\n"); 
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opção:\n\n"); //fim do menu
	
		scanf("%d", &opcao); // armazenando a escolha do usuário
	
		system("cls"); //reponsável por limpar a tela
		
		switch(opcao)
		{
			case 1: //início da seleção do menu
				registro();
				break; //comando para fechar a chave no switch case
				
			case 2:
				consulta();
				break;
				
			case 3:
				deletar();
				break;
				
			default:
				printf("Essa opção não está disponível\n\n");
				system("pause");
				break; //fim da seleção
		}	
	}
}


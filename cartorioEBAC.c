#include <stdio.h> //biblioteca de comunicação com o usuário 
#include <stdlib.h> //biblioteca de alocação  de espaços de memória 
#include <locale.h> // biblioteca de alocaçao de texto por região 
#include <string.h> // biblioteca responsavel por cuidar das striings 

int registro() //função responsavel por cadastrar os usuários no sistema 
{  
	//inicio da cração de variáveis/strings  
   char arquivo[40]; 
   char cpf[40];
   char nome[40];
   char sobrenome[40];
   char cargo [40]; 
   // final da criação de variáveis/strings 
	printf("Digite o cpf a ser cadastrado: ");// coletando informação do usuário
	scanf("%s", cpf);	//%s refere-se a string

	strcpy(arquivo, cpf); // responsavel por copiar os valores das string 
	
	FILE *file; // cria os aqruivos 
	file = fopen(arquivo, "w"); // cria os arquivos 
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser Cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a  ser Cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser Cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");

}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
	  printf("Não foi possível abrir o arquivo, não localizado! \n");	
	}   

	while(fgets(conteudo, 200,file) !=NULL)
	{	
	    printf("\nEssas são as informações do usuário: ");
	    printf("%s", conteudo);
	    printf("\n\n");
	}	

	system("pause");
	

}

int deletar()
{
	char cpf[40];

	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);

	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("o usuário não se encontra no sistema !.\n");
		system("pause");
	}
		
}



int main()   
{
    int opcao=0;  //definindo variaveis 
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
	
		system ("cls");
		for(laco=1;laco=1;)
		{	
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese");  //definindo a linguagem 
    
		printf("### Cartório da EBAC ###\n\n");//inicio do menu
    	printf("Escolha a Opção Desejada do Menu:\n\n");
    	printf("\t1 - Registrar Nomes\n");
    	printf("\t2 - Consultar Nomes\n");
    	printf("\t3 - Deletar Nomes\n\n");//fim do menu 
    	printf("\t4 - Sair do sistema\n\n");
    	printf("Opção:");
    	scanf("%d", &opcao); //armazenando a escolha do usuário 
    
    
		system("cls"); //reponsavel por limpar a tela 
    
    
    	switch(opcao) //inicio da seleçao de menu
    	{
	    	case 1:
	    	registro(); // chamada de funçoes 
	   	 	break;
	    
	    	case 2:
	    	consulta();
    		break;
    	
    		case 3:
    		deletar();
			break;
		
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
		
			default:
			printf("Esta opcao não esta disponível\n");
			system("pause");
			break;
	
		}    
    
 	}

 	}
 	
 		else
 		printf("Senha incorreta!");
	
}

#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <unistd.h>
#include <windows.h>

#define true 1
#define false 0
#define boolean int
#define QTD_PERSONAGENS 20

struct personagem {
	int numeroID;
	char nome[51];
	char classe[30];
    char raca[30];
    int ataque;
    int defesa;
    int vida;
    int mana;       
};

struct personagem personagem[QTD_PERSONAGENS];
int id = 0;

void criarPersonagem();
void consultarPersonagem();
void exibeTodosPersonagens();
void removerPersonagem();
void alterarPersonagem();
void jogarDados();
void clearScreen();



int main() {

//Aceitar acentos
UINT PT_BR = 65001;
UINT DEFAULT = GetConsoleOutputCP();
SetConsoleOutputCP(PT_BR);

 		int opcao = 0;
		while (opcao != 9)  {
            Inicio();
            printf("\n");                                        
            printf("                                    0=={==========-      MENU     -===========}==0\n");                                          
            printf("\n");
			printf("                                    Digite a sua opção:\n");
			printf("                                    [1] - Criar Personagem\n");
			printf("                                    [2] - Consultar Personagem\n");
			printf("                                    [3] - Alterar Personagem\n");
			printf("                                    [4] - Remover Personagem\n");
			printf("                                    [5] - Exibir todos os personagens\n");
            printf("                                    [6] - Jogar os dados\n");
			printf("                                    [9] - Sair do sistema\n");
			printf("\n");
            printf("                                    Sua opção: ");
      scanf("%d",&opcao);
 			switch (opcao)  {
			case 1: // Criar Personagem
				clearScreen();
                criarPersonagem();
                getch();
                clearScreen();
				break;
			case 2: // Consultar Personagem
                clearScreen();
				consultarPersonagem();
                getch();
                clearScreen();
				break;
			case 3: // Alterar Personagem
                clearScreen();
				alterarPersonagem();
                getch();
                clearScreen();
				break;
			case 4: // Remover Personagem
                clearScreen();
				removerPersonagem();
                getch();
                clearScreen();
				break;
            case 5: // Exibe todos os Personagens
                clearScreen();
				exibeTodosPersonagens();
                getch();
                clearScreen();
				break;
			case 6: // Joga Dado
                clearScreen();
				jogarDados();
                getch();
                clearScreen();
				break;
			}	
		}
		// Encerramento do programa...
		printf("\nÉ o fim da aventura...\n");
        getch();

SetConsoleOutputCP(DEFAULT);
}

void flush_in()
{
   int ch;

   while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){  }
}

int procurarID(int numero) {
		int i = 0;
		boolean achou;
    for (achou = false; ((achou == false) && (i < id) );) {
			if ( personagem[i].numeroID == numero ) {
				achou = true;
			} else {
				i++;
			}
		}
		if (achou == false)
			    i = -1;
		return i;
}


void criarPersonagem()  {
    int numeroID = 0;
    char nome[51];
    int opcaoclasse;
	char classe[30];
    int opcaoraca;
    char raca[30];
    int ataque;
    int defesa;
    int vida = 100; 
    int mana;

    printf("§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§\n");
    printf(" 0=={==========-    CRIAR PERSONAGEM    -===========}==0 §\n");
    printf("§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§\n");
    printf("\n");

    //Número ID
    printf("DIGITE O NÚMERO DE ID DO PERSONAGEM (3 DÍGITOS):");
    scanf("%d",&numeroID);
    // limpa o buffer do teclado.
    flush_in();

    //Nome
    printf("\nDIGITE O NOME DO PERSONAGEM:");
    fgets(nome, sizeof(nome), stdin);


    //Escolher raça
    printf("\nESCOLHA A RAÇA DO SEU PERSONAGEM E ATRIBUTOS BASE:\n");
	  printf("\n1 - Humano | Ataque: 60 | Defesa: 50 | Mana: 60 | Vida: 100\n");
	  printf("\n2 - Elfo | Ataque: 70 | Defesa: 40 | Mana: 70 | Vida: 100 \n");
	  printf("\n3 - Anão | Ataque: 70 | Defesa: 60 | Mana: 50 | Vida: 100\n");
	  printf("\n4 - Orc | Ataque: 75 | Defesa: 70 | Mana: 35 | Vida: 100\n");
    printf("\nDigite a sua opção:");
    scanf("%d",&opcaoraca);
    switch (opcaoraca)  {
			case 1: // Humano
                strcpy (raca, "Humano");
                ataque = 60;
                defesa = 50;
                mana = 60;
                printf("\nVocê escolheu ser humano!\n");
				break;
			case 2: // Elfo
                strcpy (raca, "Elfo");
                ataque = 80;
                defesa = 40;
                mana = 70;
                printf("\nVocê escolheu ser elfo!\n");
				break;
			case 3: // Anão
                strcpy (raca, "Anão");
                ataque = 70;
                defesa = 60;
                mana = 50;
                printf("\nVocê escolheu ser anão!\n");
				break;
			case 4: // Orc
                strcpy (raca, "Orc");
                ataque = 75;
                defesa = 50;
                mana = 70;
                printf("\nVocê escolheu ser orc!\n");
				break;
    }

    printf("\n[O\\\\\\\\\\\\\\[=====================================================-\n");

    //Escolher Classe
    printf("\nESCOLHA A CLASSE DO SEU PERSONAGEM E ATRIBUTOS ADICIONAIS:\n");
	  printf("\n1 - Arqueiro | Ataque: +25 | Defesa: +0 | Mana: +15 | Vida: +10 \n");
	  printf("\n2 - Mago | Ataque: +0 | Defesa: +10| Mana: +30 | Vida: +10\n");
	  printf("\n3 - Paladino | Ataque: +30 | Defesa: +15 | Mana: +0 | Vida: +5\n");
	  printf("\n4 - Berserker | Ataque: +10 | Defesa: +30 | Mana: +10 | Vida: +0\n");
    printf("\nDigite a sua opção:");
    scanf("%d",&opcaoclasse);

    switch (opcaoclasse)  {
			case 1: // Arqueiro
                strcpy (classe, "Arqueiro");
                ataque = ataque + 25;
                mana = mana + 15;
                vida = vida + 10;
                printf("\nVocê escolheu ser um arqueiro!\n");
				break;
			case 2: // Mago
                strcpy (classe, "Mago");
                defesa = defesa + 10;
                mana = mana + 30;
                vida = vida + 10;
                printf("\nVocê escolheu ser um mago!\n");
				break;
			case 3: // Paladino
                strcpy (classe, "Paladino");
                ataque = ataque + 30;
                defesa = defesa + 15;
                vida = vida + 5;
                printf("\nVocê escolheu ser um paladino!\n");
				break;
			case 4: // Berserker
                strcpy (classe, "Berserker");
                ataque = ataque + 30;
                defesa = defesa + 15;
                vida = vida + 5;
                printf("\nVocê escolheu ser um berserker!\n");
				break;
    }

    if (id < QTD_PERSONAGENS)  {
        if ( procurarID(numeroID) == -1)  {
        	personagem[id].numeroID = numeroID;
		    strcpy(personagem[id].nome, nome);
            strcpy(personagem[id].raca, raca);
            strcpy(personagem[id].classe, classe);
            personagem[id].ataque = ataque;
            personagem[id].defesa = defesa;
            personagem[id].mana = mana;
            personagem[id].vida = vida;
		    
		    id = id + 1;

		    printf("\nPersonagem criado. Você está pronto para sua jornada!!");
            printf("\n ");
        	return;
	    }
	printf("\nUm personagem com esse ID já foi cadastrado no sistema, tente novamente com outro ID.");
	return;
    }
    printf("\nJá atingimos o número máximo de personganes criados");
    return;
}

void alterarPersonagem() {

    int numeroID = 0;
    char nome[51];
    int opcaoclasse;
	char classe[30];
    int opcaoraca;
    char raca[30];
    int ataque;
    int defesa;
    int vida = 100;
    int mana;

    printf("§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§\n");
    printf("§ 0=={==========-    ALTERAR PERSONAGEM    -===========}==0 §\n");
    printf("§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§\n");
    printf("\n");

  printf("Digite o ID do personagem para verificação:");
  scanf("%d",&numeroID);
  // limpa o buffer do teclado.
  flush_in();

	int i = procurarID(numeroID);
	if (i != -1) {

        printf("\nDIGITE O NOVO NOME DO PERSONAGEM:");
        fgets(nome, sizeof(nome), stdin);
        strcpy(personagem[i].nome, nome);

        int opcaoraca;
        printf("\nESCOLHA A RAÇA DO SEU PERSONAGEM:\n");
	    printf("1 - Humano \n");
	    printf("2 - Elfo \n");
	    printf("3 - Anão \n");
	    printf("4 - Orc\n");
        printf("\nDigite a sua opção:");
        scanf("%d",&opcaoraca);
        switch (opcaoraca)  {
		        case 1: // Humano
                    strcpy (raca, "Humano");
                    printf("\nVocê escolheu ser um Humano!\n");
			        break;
		        case 2: // Elfo
                    strcpy (raca, "Elfo");
                    printf("\nVocê escolheu ser um Elfo!\n");
			        break;
		        case 3: // Anão
                    strcpy (raca, "Anão");
                    printf("\nVocê escolheu ser um Anão!\n");
			        break;
		        case 4: // Orc
                    strcpy (raca, "Orc");
                    printf("\nVocê escolheu ser um Orc!\n");
			        break;
        }

        //Escolher Classe
        int opcaoclasse;
        printf("\nESCOLHA A CLASSE DO SEU PERSONAGEM:\n");
	    printf("1 - Arqueiro \n");
	    printf("2 - Mago \n");
	    printf("3 - Paladino \n");
	    printf("4 - Berserker\n");
        printf("\nDigite a sua opção:");
        scanf("%d",&opcaoclasse);
        switch (opcaoclasse)  {
		        case 1: // Arqueiro
                    strcpy (classe, "Arqueiro");
                    printf("\nVocê escolheu ser um arqueiro!\n");
			        break;
		        case 2: // Mago
                    strcpy (classe, "Mago");
                    printf("\nVocê escolheu ser um mago!\n");
			        break;
		        case 3: // Paladino
                    strcpy (classe, "Paladino");
                    printf("\nVocê escolheu ser um paladino!\n");
			        break;
		        case 4: // Berserker
                    strcpy (classe, "Berserker");
                    printf("\nVocê escolheu ser um berserker!\n");
			        break;
        }

        printf("\nATRIBUTOS\n");

        //Definir ataque
        printf("\nDIGITE O VALOR DE ATAQUE DO PERSONAGEM (um número de 10 a 150):");
        scanf("%d",&ataque);
        if (ataque >= 10 && ataque <= 150) {
            personagem[i].ataque = ataque;
        }
        

        //Definir defesa
        printf("\nDIGITE O VALOR DE DEFESA DO PERSONAGEM (um número de 10 a 150):");
        scanf("%d",&defesa);
        if (ataque >= 10 && defesa <= 150) {
           personagem[i].defesa = defesa;
        }
        
        //Definir ataque
        printf("\nDIGITE O VALOR DE MANA DO PERSONAGEM (um número de 10 a 150):");
        scanf("%d",&mana);
        if (ataque >= 10 && mana <= 150) {
           personagem[i].mana = mana;
        } 
        

        //Definir ataque
        printf("\nDIGITE O VALOR DE VIDA DO PERSONAGEM (um número de 10 a 150):");
        scanf("%d",&vida);
        if (ataque >= 10 && vida <= 150) {
           personagem[i].vida = vida;
        } 
         
        
        strcpy(personagem[i].raca, raca);
        strcpy(personagem[i].classe, classe);
        

        printf("\nSeu guerreiro foi atualizado. Vá e vença!!");
            printf("\n ");
        	return;
	} else {
		printf("\nO ID do personagem não foi encontrado no sistema.\n");
		return ;
	}
}

void exibeTodosPersonagens()  {
	printf("§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§\n");
    printf("§ 0=={==========-     TODOS OS PERSONAGEM     -===========}==0 §\n");
    printf("§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§\n");
    printf("\n ");

		printf("\nVeja a lista de todos os nossos guerreiros: \n");
		int i;
    for (i = 0; i < id; i = i + 1)  {
      printf("\nID: %d", personagem[i].numeroID);
			printf("\nNome: %s", personagem[i].nome);
			printf("\nRaça: %s", personagem[i].raca);
			printf("\nClasse: %s",personagem[i].classe);
			printf("\n ");
            printf("\nATRIBUTOS");
            printf("\nAtaque: %d",personagem[i].ataque);
            printf("\nDefesa: %d",personagem[i].defesa);
            printf("\nMana: %d",personagem[i].mana);
            printf("\nVida: %d\n",personagem[i].vida);
            printf("\n[O\\\\\\\\[===============================-\n");
	}
}

void consultarPersonagem(){
    int numeroID = 0;

    clearScreen();
    printf("§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§\n");
    printf("§ 0=={==========-     CONSULTAR PERSONAGEM     -===========}==0 §\n");
    printf("§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§\n");
    printf("\n ");

    printf("\nDigite o número de ID do personagem: ");
    scanf("%d", &numeroID);

    int i = procurarID(numeroID);
    if (i == -1){
        printf("\nPersonagem não encontrado.");
    }else{
        printf("\nID: %d", personagem[i].numeroID);
        printf("\nNome do personagem: %s", personagem[i].nome);
        printf("\nRaça: %s", personagem[i].raca);
        printf("\nClasse: %s", personagem[i].classe);
        printf("\n");
        printf("\nATRIBUTOS\n");
        printf("\nAtaque: %d", personagem[i].ataque);
        printf("\nDefesa: %d", personagem[i].defesa);
        printf("\nMana: %d", personagem[i].mana);
        printf("\nVida: %d", personagem[i].vida);
    }
}

void removerPersonagem() {
    
    int numeroID = 0;
	printf("§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§\n");
    printf("§ 0=={==========-     REMOVER PERSONAGEM     -===========}==0 §\n");
    printf("§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§\n");
    printf("\n ");

    printf("\nDigite o ID do personagem: ");
    scanf("%d", &numeroID);

    int i = procurarID(numeroID);
    if (i != -1) {
        
        int opcaoremover;
        printf("\n[!] VOCÊ REALMENTE DESEJA REMOVER ESSE PERSONAGEM?\n");
	    printf("1 - Sim \n");
	    printf("2 - Não \n");
      printf("Digite sua opção:");
        scanf("%d",&opcaoremover);
        switch (opcaoremover)  {
		        case 1: // Sim
                    id--;
                    personagem[i] = personagem[id];
                    printf("\nPersonagem removido do sistema!\n");
                    return;
                    break;
		        case 2: // Nãoo
                    printf("\nRetornando para o menu.\n");
                    return;
			        break;
        }        
    } else {
        printf("\nO ID do personagem não foi encontrado no sistema.");
        return;
    }
}
void jogarDados(){
    int dados_lados = 0;
   
    printf("§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§\n");
    printf("§ 0=={==========-     JOGAR DADOS     -===========}==0 §\n");
    printf("§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§\n");
    printf("\n ");

    printf("\nQuantos lados terá o dado? ");
    scanf("%d", &dados_lados);

    if(dados_lados != 0){
        printf("\nD%d escolhido.O destino do seu personagem foi traçado!!\n\nO número é: %d\n",dados_lados, rand() % dados_lados);
    }
    else{
        printf("Digite um número válido");
    }
}

void Inicio(){
    printf("\n");

            printf("            ()                                                                                        ()\n");
            printf("            )(                                                                                        )(\n");
         printf("         o======o                                                                                  o======o\n");
            printf("            ||     ::::::::  :::::::::  :::    ::: :::::::::        :::::::::  :::::::::   ::::::::   ||\n");                   
            printf("            ||   :+:    :+: :+:    :+: :+:    :+: :+:    :+:       :+:    :+: :+:    :+: :+:    :+:   ||\n"); 
            printf("            ||   +:+        +:+    +:+ +:+    +:+ +:+    +:+       +:+    +:+ +:+    +:+ +:+          ||\n");        
            printf("            ||   +#+        +#++:++#:  +#+    +:+ +#+    +:+       +#++:++#:  +#++:++#+  :#:          ||\n");        
            printf("            ||   +#+        +#+    +#+ +#+    +#+ +#+    +#+       +#+    +#+ +#+        +#+   +#+#   ||\n");        
            printf("            ||   #+#    #+# #+#    #+# #+#    #+# #+#    #+#       #+#    #+# #+#        #+#    #+#   ||\n"); 
            printf("            ||     ########  ###    ###  ########  #########        ###    ### ###         ########   ||\n");                                                                                                       
       printf("       ,c88888888b                                                                               ,c88888888b\n");
      printf("      ,88888888888b                           CRIE SEU PERSONAGEM DE RPG                        ,88888888888b\n");
      printf("       88888888888Y                                                                              88888888888Y\n");
printf(" ,,;,,;;*Y888888Y*,,,,,,,;;,;                                                              ,,;,,;;*Y888888Y*,,,,,,,;;,;\n");  
printf("\n");

    
}
void clearScreen()
{
  const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
  write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}
	/*
    Arquivo: •	Sistema_de_gerenciamento_de_recursos_humanos.c
	Autor: Heitor dos Reis Ribeiro
	         J

	Descrição:
*/

//-----DIRETIVAS-----//
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<string.h>
//-----DIRETIVAS-----//

//-----DEFINICAO_DE_TIPOS-----//

/* Estrutura de dados necessária para agrupar todas as variáveis sob o mesmo tipo de dados. A ideia aqui é utilizar uma estrutura de dados
para permitir que, ao armazenar os dados de uma mesma entidade, isso possa ser feito com apenas uma única variável.*/

typedef struct data DATA;
/* A entidade data possui as variáveis dia, mes e ano */
struct data
{
  int dia;
  int mes;
  int ano;
};
typedef struct funcionario funcionario;

struct funcionario
/* A entidade funcionario possui as variáveis nome, matricula, email, salario e admissao */
{
  char nome[80];
  char matricula[80];
  char email[80];
  char salario[80];
  DATA admissao;
};
//-----DEFINICAO_DE_TIPOS-----//

//-----INTERFACE-----//
/* Assinatura da função (declaração da função/protótipo)*/
void menu_principal();
void desenvolvedores();
void cadastrar();
void listar();
void verificar();
void editar();
void remover();
//-----INTERFACE-----//

//-----MAIN-----//
int main ()
{
  // A função setlocale garante que caracteres especiais e acentuação sejam exibidos normalmente na execução.
  setlocale(LC_ALL, "Portuguese");
  int opcao;

  /* Faça o menu até que a opção seja diferente de zero */
  do
  {
    menu_principal(); /* Função para exibição do menu principal */
    printf("Escolha uma opção: ");
    scanf ("%d",&opcao);  /* Receber a escolha do usuário */

    /*Switch Case para controlar o fluxo do programa e permitir especificar uma função diferente para ser executada dentro das opções */
    switch (opcao){
      case 1:
        /* Função para cadastrar */
        cadastrar();
      break;

      case 2:
        /* Função para verificar a existência de uma matrícula no banco de dados */
        verificar();
      break;

      case 3:
        /* Função para listar a matrícula dos funcionários */
        listar();
      break;

      case 4:
        /* Função para remover uma matrícula do banco de dados */
        remover();
      break;

      case 5:
        /* Função para editar uma matrícula no banco de dados */
        editar();
      break;

      case 6:
        /* Função para exibir informações dos desenvolvedores */
        desenvolvedores();
      break;

      case 0:
        /* Caso a opção seja zero, agradecer a visita */
        printf ("Obrigado pela visita!\n");
        getch();
      break;

      default:
        /* Tratamento de opção inválida do usuário */
        printf ("Opção Inválida! Digite uma das opções listadas no menu: ");
        getch();
      break;
    }
    /* Se a opção for zero, finaliza a execução */
  } while (opcao!=0);
}

//-----IMPLEMENTACAO-----//

/***
 *  MENU PRINCIPAL
***/
void menu_principal()
{
    /* Limpar a tela do funcionário com system ("cls") */
    system ("cls");
    printf(" -------------------------------------------------\n\n");
    printf("   Bem vindo ao sistema de Cadastro de Funcionário\n\n");
    printf ("--------------------- MENU ----------------------\n\n");
    printf ("| 1 - Cadastro\n                                    \n|");
    printf ("| 2 - Verificação de matrícula\n                    \n|");
    printf ("| 3 - Listar\n                                      \n|");
    printf ("| 4 - Excluir\n                                     \n|");
    printf ("| 5 - Alterar\n                                     \n|");
    printf ("| 6 - Desenvolvedores\n                             \n|");
    printf ("| 0 - Sair\n\n                                      \n|");
    printf(" -------------------------------------------------\n\n");
}

/***
 *      CADASTRO
***/
/* Os arquivos permitem a gravação de dados em uma execução de forma permanente. Suas vantagens são a permanência de informações
disponíveis mesmo após a execução do programa; A grande quantidade de dados que podem ser armazenados; E o acesso concorrente, onde
vários outros programas podem acessar esse arquivo.
*/
void cadastrar()
{
  /* Na linguagem C, o arquivo é manipulado através de um ponteiro especial para esse arquivo. A função desse ponteiro é justamente
  "apontar" a localização de um registro. Somente assim é possível realizar a manipulação de arquivos em C
  O tipo FILE está definido na biblioteca <stdio.h> */
  FILE* arquivo;
  funcionario fc; /* Variável do tipo funcionário contendo os campos definidos na Estutura */

  /* A função fopen é responsável pela abertura do arquivo. Sua assinatura é:

    fopen (char nome_do_arquivo, char modo);

    O campo nome_do_arquivo determina qual arquivo deverá ser aberto. Lembrando que este nome deve ser válido no sistema operacional que
    estiver sendo utilizado. O campo modo diz a função fopen() que tipo de uso você vai fazer no arquivo. Aqui, estamos utilizando o modo
    "ab" que acrescenta dados binários no fim do arquivo com o arquivo sendo binário.
   */
  arquivo = fopen("cadastro.txt", "ab");

  /* Tratamento de erro: Se o arquivo retornar nulo, exibe mensagem de erro de abertura.*/
  if (arquivo == NULL){
    printf("Problemas na abertura do arquivo!\n");
  }

  /* Se não der erro de abertura: */
  else
  {
    /* Faça enquanto a opção for igual a "s" */
    do
    {
      /* Limpar a tela do funcionário com system ("cls") */
      system("cls");

      /* Limpar o buffer do teclado do funcionário */
      fflush(stdin);
      /* Coletar o nome do funcionário e armazenar no campo nome dentro da estrutura de dados funcionario */
      printf("Digite o seu nome completo: ");
      gets(fc.nome);

      /* Limpar o buffer do teclado do funcionário */
      fflush(stdin);
      /* Coletar o email do funcionário e armazenar no campo email dentro da estrutura de dados funcionario */
      printf("Digite o seu email: ");
      gets(fc.email);

      /* Limpar o buffer do teclado do funcionário */
      fflush(stdin);
      /* Coletar a matricula do funcionário e armazenar no campo matricula dentro da estrutura de dados funcionario */
      printf("Digite o sua matricula: ");
      gets(fc.matricula);

      /* Limpar o buffer do teclado do funcionário */
      fflush(stdin);
      /* Coletar o salario do funcionário e armazenar no campo salario dentro da estrutura de dados funcionario */
      printf("Digite o seu salario: ");
      gets(fc.salario);

      /* Coletar a data de admissao do funcionário e armazenar no campo admissao dentro da estrutura de dados funcionario */
      printf("Digite sua data de admissão (Ex.: xx/xx/xxxx): ");
      scanf("%d %d %d", &fc.admissao.dia, &fc.admissao.mes, &fc.admissao.ano);

      /* A função fwrite permite a escrita de um bloco de bytes em arquivos, sendo usada preferencialmente com arquivos binários.
      Sua assinatura é:

      fwrite(void bloco, int numero_de_bytes, int total, FILE* arquivo)

      No campo bloco está a região da memória onde está os dados, no nosso caso o endereço da váriavel fc.
      O campo numero_de_bytes é o tamanho de cada posição de memória a ser escrita, que é o tamanho de funcionario
      O campo total é a quantidade de blocos de memória de tamanho numero_de_bytes que devem ser escritos, apenas 1 funcionario
      Por fim, o campo arquivo é o ponteiro que apontará ao arquivo os dados serão escritos.
      */
      fwrite(&fc, sizeof(funcionario), 1, arquivo);

      /* Pergunta ao usuário se gostaria de cadastrar mais algum funcionário */
      printf("Deseja cadastrar mais alguém? (s/n)? ");

    /* Se a opção for s, o bloco de instrução se repetirá */
    }while (getche() == 's' );
    /* fclose será responsável por fechar o arquivo após a escrita */
  } fclose(arquivo);

}

/***
 *      LISTAR
***/
void listar()
{
  FILE* arquivo;
  funcionario fc;

  /* O tipo de uso da função fopen() nesse caso será abrir um arquivo binário para leitura */
  arquivo = fopen("cadastro.txt", "rb");

  /* Tratamento de erro: Se o arquivo retornar nulo, exibe mensagem de erro de abertura.*/
  if (arquivo == NULL){
    printf("Problemas na abertura do arquivo!\n");
  }
  /* Se não der erro de abertura: */
  else
  {
    /* A função fread permite a leitura de um bloco de bytes em arquivos, sendo usada preferencialmente em arquivos binários.
    Sua assinatura é:

    fread(void buffer, int bytes, int count, FILE arquivo)

    No campo buffer, será um ponteiro para um bloco de memória
    No campo bytes, será o tamanho de cada elemento a ser lido em bytes
    No campo count, será o número de elementos, o tamanho de cada elementos é bytes de tamanho
    Por fim, o campo arquivo é o ponteiro que apontará ao arquivo os dados serão lidos.
    */

    /* Então enquanto a função fread() retornar uma linha de bytes */
    while(fread(&fc, sizeof(funcionario), 1, arquivo)==1)
    {
      /* Mostre o nome */
      printf("Nome: %s\n", fc.nome);

      /* Mostre a matricula */
      printf("Matricula: %s\n", fc.matricula);

      /* Mostre o email */
      printf ("Email: %s\n", fc.email);

      /* Mostre o salario */
      printf("Salario: %s\n", fc.salario);

      /* Mostre a data de admissão */
      printf("Data de admissão: %d/%d/%d\n", fc.admissao.dia, fc.admissao.mes, fc.admissao.ano);
      printf("-----------------------------------------------\n\n");
    }
  }
  printf("Para retornar ao menu digite 0\n");

  /* fclose será responsável por fechar o arquivo após a escrita */
  fclose(arquivo);
  /* Espera que o usuário digite uma tecla para retornar, ou seja, pausar o terminal */
  getch();
}

/***
 *      CADASTRO
***/
void verificar()
{
  FILE* arquivo;
  funcionario fc;

  /* Variável responsável para coletar a matrícula do funcionário */
  char matricula1[30];


  /* O tipo de uso da função fopen() nesse caso será abrir um arquivo binário para leitura e escrita */
  arquivo = fopen("cadastro.txt", "r+b");

  /* Tratamento de erro: Se o arquivo retornar nulo, exibe mensagem de erro de abertura.*/
  if (arquivo == NULL)
  {
    printf("Problemas na abertura do arquivo!\n");
  }
  /* Se não der erro de abertura: */
  else
  {
    /* Limpar o buffer do teclado do funcionário */
    fflush(stdin);

    /* Coletar matrícula */
    printf("Digite a matrícula que você deseja vefificar se consta no sistema:");
    gets(matricula1);

    /* Então enquanto a função fread() retornar uma linha de bytes */
    while(fread(&fc, sizeof(funcionario), 1, arquivo)==1)
    {
      /* Para se comparar o conteúdo de duas strings deve-se usar a função strcmp(), localizada na biblioteca
      <string.h>
      Sua assinatura é:

      strcmp(endereco_da_string1, endereco_da_string2);
       */

      /* Se a comparação da matrícula informada pelo usuário com as matrículas listadas,
      se possuir irá retornar zero */
      if(strcmp(matricula1,fc.matricula) == 0){   // comparar a matricula que recebeu com as matriculas ja listadas, se for igual retorna 0

        printf("\n----------A matricula já está cadastrada com os dados---------\n");

        printf("Nome: %s\n", fc.nome);
        printf("Matricula: %s\n", fc.matricula);
        printf ("Email: %s\n", fc.email);
        printf("Salario: %s\n", fc.salario);
        printf("Data de admissão: %d/%d/%d\n", fc.admissao.dia, fc.admissao.mes, fc.admissao.ano);
        printf("-----------------------------------------------\n\n");
      }
      /* Se a comparação retornar um, significa que não há a matrícula informada pelo usuário no banco de dados: */
      else
      {
        printf("\nA matricula não consta no sistema, volte ao menu e cadastre :D\n");
        printf("------------------------------------------------------------------------\n\n");
      }

    }
  }
  printf("Para retornar ao menu digite 0\n");

  /* fclose será responsável por fechar o arquivo após a escrita */
  fclose(arquivo);

  /* Espera que o usuário digite uma tecla para retornar, ou seja, pausar o terminal */
  getch();
}

/***
 *      EDITAR
***/
void editar()
{
  FILE* temp;
  FILE* arquivo;
  funcionario fc;
  char matricula2[30];

  /* O tipo de uso da função fopen() nesse caso será abrir um arquivo binário para leitura */
  arquivo = fopen("cadastro.txt","rb");

  /* Abre um arquivo binário para escrita */
  temp = fopen("tmp.txt","wb");

  /* Tratamento de erro: Se os dois arquivos retornarem nulo, exibe mensagem de erro de abertura.*/
  if(arquivo == NULL && temp == NULL)
  {
    printf("Problemas na abertura do arquivo!\n");
    getch();
  }
  /* Se não der erro de abertura: */
  else
    {
      /* Limpar o buffer do teclado do funcionário */
      fflush(stdin);

      /* Coletar matrícula para edição */
      printf("Digite a matrícula do usuário em que pertende editar os dados: \n ");
      gets(matricula2);

      /* Então enquanto a função fread() retornar uma linha de bytes */
      while(fread(&fc, sizeof(funcionario), 1, arquivo) == 1)
      {
        /* Se a comparação da matrícula informada pelo usuário com as matrículas listadas,
        se possuir irá retornar zero */
        if(strcmp(matricula2,fc.matricula) == 0)
        {
          /* Mostre o nome */
          printf("Nome: %s\n", fc.nome);
          /* Mostre a matrícula */
          printf("Matricula: %s\n", fc.matricula);
          /* Mostre o email */
          printf ("Email: %s\n", fc.email);
          /* Mostre o salario */
          printf("Salario: %s\n", fc.salario);
          /* Mostre a data de admissão */
          printf("Data de admissão: %d/%d/%d\n", fc.admissao.dia, fc.admissao.mes, fc.admissao.ano);
          printf("-----------------------------------------------\n\n");
        }
        /* Se a comparação retornar um, significa que não há a matrícula informada pelo usuário no banco de dados: */
        else
          {
            /* Permite a edição de um bloco no arquivo*/
            fwrite(&fc, sizeof(funcionario), 1, temp);
          }
      }
        /* fclose será responsável por fechar o arquivo após a escrita */
        fclose(arquivo);
        fclose(temp);

        /* Limpar o buffer do teclado do funcionário */
        fflush(stdin);

    /* Se a comparação da matrícula informada pelo usuário com as matrículas listadas,
    se possuir irá retornar zero */
    if(strcmp(matricula2,fc.matricula) == 0)
    {
      /* Questiona o usuário sobre certeza ao editar */
      printf("Tem a certeza que pertende alterar os dados do usuário(s/n)?\n ");

        /* Se tiver certeza */
        if(getche() == 's')
        {
          /* Para deletar um arquivo em C basta utilizar a função remove(). Essa função recebe um único
          parâmetro com o nome do arquivo que será deletado, e retorna zero caso tenha êxito.
          Caso não tenha, retornará -1
          */

          /* A função rename() faz com que o arquivo indicado no primeiro parâmetro tenha o seu nome trocado
          pelo nome indicado no segundo parâmetro, para que assim possamos atualizar o banco de dados */

          /* Então se a exclusão e renomeação do arquivo for bem sucedida */
          if(remove("cadastro.txt") == 0 && rename ("tmp.txt", "cadastro.txt") == 0)
          {
            FILE* arquivo;
            funcionario fc;

            /* O tipo de uso da função fopen() nesse caso será para acrescentar dados binários no fim do arquivo e assim atualizar os dados do funcionário*/
            arquivo = fopen("cadastro.txt", "ab");
            printf("\n------------Digite seus novos dados------------ \n");

            /* Limpar o buffer do teclado do funcionário */
            fflush(stdin);
            printf("\nDigite o nome completo: ");
            gets(fc.nome);

            /* Limpar o buffer do teclado do funcionário */
            fflush(stdin);
            printf("Digite o sua matricula atual (inalterável): ");
            gets(fc.matricula);

            /* Limpar o buffer do teclado do funcionário */
            fflush(stdin);
            printf("Digite o email: ");
            gets(fc.email);

            /* Limpar o buffer do teclado do funcionário */
            fflush(stdin);
            printf("Digite o salario: ");
            gets(fc.salario);

            printf("Digite a data de admissão (utilize o espaço)");
            scanf("%d %d %d", &fc.admissao.dia, &fc.admissao.mes, &fc.admissao.ano);

            printf("-----------------------------------------------\n\n");

            /* Irá escrever todos os novos dados coletados no arquivo */
            fwrite(&fc, sizeof(funcionario), 1, arquivo);

            printf("\n\nDados do usuário alterados com sucesso!\n");
          }

          else
          /* Se a exclusão não for bem sucedida, irá remover o arquivo */
            {
              remove("tmp.txt");
            }
        }
    }
    /* Se a comparação retornar um, significa que não há a matrícula informada pelo usuário no banco de dados: */
    else {
      printf("\nA matricula não consta no sistema, volte ao menu e cadastre :D\n");
        printf("------------------------------------------------------------------------\n\n");
  }


    printf("Para retornar ao menu digite 0\n");
    /* fclose será responsável por fechar o arquivo após a escrita */
    fclose(temp);
    fclose(arquivo);

    /* Espera que o usuário digite uma tecla para retornar, ou seja, pausar o terminal */
    getch();
  }
}

/***
 *      REMOVER
***/
void remover()
{
    FILE* temp;
    FILE* arquivo;
    funcionario fc;
    char matricula3[30];

  /* O tipo de uso da função fopen() nesse caso será abrir um arquivo binário para leitura */
  arquivo = fopen("cadastro.txt","rb");
  /* Abre um arquivo binário para escrita */
  temp = fopen("tmp.txt","wb");

  /* Tratamento de erro: Se os dois arquivos retornarem nulo, exibe mensagem de erro de abertura.*/
  if(arquivo == NULL && temp == NULL)
  {
      printf("Problemas na abertura do arquivo!\n");
      getch();
  }
  /* Se não der erro de abertura: */
  else
  {
    /* Limpar o buffer do teclado do funcionário */
    fflush(stdin);

    /* Solicita matrícula para exclusão */
    printf("Digite a matrícula para excluir: ");
    gets(matricula3);
    /* Então enquanto a função fread() retornar uma linha de bytes */
    while(fread(&fc,sizeof(funcionario),1,arquivo)==1)
    {
      /* Se a comparação da matrícula informada pelo usuário com as matrículas listadas,
      se possuir irá retornar zero */
      if(strcmp(matricula3,fc.matricula)==0)
      {
        /* Solicita confirmação de dados */
        printf("\nPor gentileza, confirme seus dados:\n");
        /* Limpar o buffer do teclado do funcionário */
        fflush(stdin);
        printf("\nDigite o nome completo: ");
        gets(fc.nome);

        /* Limpar o buffer do teclado do funcionário */
        fflush(stdin);
        printf("Digite o email: ");
        gets(fc.email);

        /* Limpar o buffer do teclado do funcionário */
        fflush(stdin);
        printf("Digite o salario: ");
        gets(fc.salario);

        printf("Digite a data de admissão (utilize o espaço)");
        scanf("%d %d %d", &fc.admissao.dia, &fc.admissao.mes, &fc.admissao.ano);

        printf("-----------------------------------------------\n\n");
      }
      else
        {
          /* Permite a edição de um bloco no arquivo*/
          fwrite(&fc,sizeof(funcionario),1,temp);
        }
    }

  /* fclose será responsável por fechar o arquivo após a escrita */
  fclose(arquivo);
  fclose(temp);

    /* Se a comparação da matrícula informada pelo usuário com as matrículas listadas,
    se possuir irá retornar zero */
    if(strcmp(matricula3,fc.matricula)==0)
    {

      /* Limpar o buffer do teclado do funcionário */
      fflush(stdin);

      /* Confirmação de exclusão */
      printf("Deseja deletar (s/n)? ");

      /* Se for confirmado */
      if(getche()=='s')
      {
        /* Então se a exclusão e renomeação do arquivo for bem sucedida */
        if(remove("cadastro.txt")==0  &&  rename("tmp.txt","cadastro.txt")==0)
        {
          printf("\nOperacao realizada com sucesso!\n");
        }

        else
        {
          /* Se a exclusão não for bem sucedida, irá remover o arquivo */
            remove("tmp.txt");
        }
    }

    /* Se a comparação retornar um, significa que não há a matrícula informada pelo usuário no banco de dados: */
    } else {
      printf("\nA matricula não consta no sistema, volte ao menu e cadastre :D\n");
        printf("------------------------------------------------------------------------\n\n");
  }


  printf("Para retornar ao menu digite 0\n");

  /* fclose será responsável por fechar o arquivo após a escrita */
  fclose(temp);
  fclose(arquivo);
  getch();
  }
}

void desenvolvedores(){
  system ("cls");

  printf("------------ O programa foi desenvolvido por: -------------\n\n");

  printf("Nome: Heitor dos Reis Ribeiro\n");
  printf("Email: heitorhendo1@hotmail.com\n");
  printf("Matrícula: 20211012268  \n");
  printf("-----------------------------------------------\n\n");

  printf("Nome: Jean Carlos Paiva de Medeiros\n");
  printf("Email: jeanmyjean@outlook.com\n");
  printf("Matrícula: 2021012150 \n");
  printf("-----------------------------------------------\n\n");

  printf("Nome: Luma Eduarda Santos Besse\n");
  printf("Email: lumabs5294@gmail.com\n");
  printf("Matrícula: 2021011912 \n");
  printf("-----------------------------------------------\n\n");

  printf("Nome: Matheus Henrique Corrêa Rodrigues Freitas\n");
  printf("Email: matheushrf@outlook.com\n");
  printf("Matrícula: 2021012179 \n");
  printf("-----------------------------------------------\n\n");

  printf("Para retornar ao menu digite 0\n");
  getch();
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_dados
{
   char matricula[30]; // chave
   char nome[255];
   char fone[15];
   float notas[2];
};

struct no
{
   struct s_dados dados;
   struct no *prox;
   struct no *ant;
};

// Prototipos de funcoes:

int main()
{
   // Iniciando lista:
   struct no *lista = NULL;

   // Iniciando dados1:
   struct s_dados dados1;
   strcpy(dados1.nome, "Hiel Saraiva");
   strcpy(dados1.matricula, "202301");
   strcpy(dados1.fone, "85996852901");
   dados1.notas[0] = 7.8f;
   dados1.notas[1] = 9.6f;

   // Iniciando dados2:
   struct s_dados dados2;
   strcpy(dados2.nome, "Geni Saraiva");
   strcpy(dados2.matricula, "202302");
   strcpy(dados2.fone, "85988441830");
   dados2.notas[0] = 10.0f;
   dados2.notas[1] = 8.5f;

   // Iniciando dados3:
   struct s_dados dados3;
   strcpy(dados3.nome, "Rodrigo");
   strcpy(dados3.matricula, "202303");
   strcpy(dados3.fone, "85988442342");
   dados3.notas[0] = 1.0f;
   dados3.notas[1] = 3.5f;

   // Iniciando dados4:
   struct s_dados dados4;
   strcpy(dados4.nome, "Conrado");
   strcpy(dados4.matricula, "202304");
   strcpy(dados4.fone, "85988442233");
   dados4.notas[0] = 5.0f;
   dados4.notas[1] = 4.5f;

   // Iniciando dados5:
   struct s_dados dados5;
   strcpy(dados4.nome, "Roberta Alanis");
   strcpy(dados4.matricula, "202305");
   strcpy(dados4.fone, "85988444223");
   dados4.notas[0] = 9.0f;
   dados4.notas[1] = 7.5f;

   // Testando funcoes:


}

// Inserir no comeco(TO DO):


// Inserir no final(TO DO):


// Inserir ordenando em ordem crescente(TO DO):


// Remover(TO DO):


// Esvaziar lista(TO DO):


// Alterar(TO DO):


// Buscar(TO DO):


// Listar todos(TO DO):


// Funcoes auxiliares(TO DO):


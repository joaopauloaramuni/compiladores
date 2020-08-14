/****************************************************************************************************
 * Universidade FUMEC             									                                *
 * Compiladores                                   											   	    *
 * Prof. João Paulo Aramuni     																	*
 * Parser 2                                                 	  									*
 * Algoritmo que implementa um Analisador Sintático Descendente Recursivo  							*
 * para a Gramática Livre de Contexto: S -> aSb | ba | y				    							*
 ****************************************************************************************************/

//Bibliotecas
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

char prxtk;       // contem o proximo token 
char tokens[256]; // tabela de tokens reconhecidos pela analise lexica
int tk;		      // indice do vetor de tokens		
int numtk;		  // indica o numero de tokens	
int erro = 0;     // booleano que indica se houve erro

void verifica (char token)
{
  if (token == prxtk) {
    tk ++;
    prxtk = tokens [tk];  
  }
  else { 
     printf("Erro! esperado token: %c  recebido: %c\n", token, prxtk);
     erro = 1;
  }
}

void S ()
{
 if (prxtk == 'a') {
   verifica ('a');
   S ();
   verifica ('b'); 
 }
 else 
  if (prxtk == 'b' && tokens[tk+1] == 'a') {
    verifica ('b');
    verifica ('a'); 
  }
  else 
  if (prxtk != 'b') {
    printf ("Erro! Esperado simbolos a ou b\n");
	erro = 1;
  }

}
 

void lexico () {  
  // neste exemplo a analise lexica somente le os caracteres do arquivo 
  // e joga para o vetor tokens.
  printf ("Informe a sentenca a ser avaliada: ");
  gets (tokens);
}


int main() {
  
  // clrscr();
  printf ("ASDR exemplo para gramatica:\n\tS -> aSb \n\t   | ba | y \n\n"); 
  lexico (); // realiza analise lexica
  tk = 0;
  numtk = strlen(tokens);
  prxtk = tokens [tk];
  S ();  // inicia a analise sintatica
  if (!erro)
	if (tk >= numtk)
      printf ("\n\nA sentenca avaliada pertence a gramatica!!");
    else {
	  printf ("\n\nO sufixo a seguir nao foi reconhecido: ");
	  while (tokens [tk] != '\x0') 
		printf ("%c", tokens[tk++]);
	}
 getch();
}


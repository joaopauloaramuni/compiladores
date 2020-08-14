/****************************************************************************************************
 * Universidade FUMEC             									                                *
 * Compiladores                                   											   	    *
 * Prof. João Paulo Aramuni     																	*
 * Scanner 2                                                 	  									*
 * Verifica a validade de expressões da forma  vr-1  op  vr-2        								*
 * onde vr-n será um número inteiro e op será um operador aritmético qualquer					    *
 * Ao encontrar uma expressão valida ele não encerra, mas continua a verificação,				    *
 * aceitando expressões da forma  vr-1 op vr-2 op vr-3												*
 * 																									*
 * PERMITINDO ESPAÇO EM BRANCO																		*
 ****************************************************************************************************/

//Bibliotecas
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

//Define's
#define op "+/-*"
#define num  "0123456789"
#define letra "abcdefghijklmnopqrstuvxzABCDEFGHIJKLMNOPQRSTUVXZ"

int search(char a, const char * str) {
	int j = 0, ret = 0;
	while (str[j] && !ret) {
		ret = (str[j] == a);
		j++;
	}
	return (ret);
}

int main() {
	char automato[60];
	int i = 0, state = 0;

	printf("\tCompiladores - Scanner 2\n");
	printf("\nAutomato para reconhecer expressoes aritmeticas");
	printf("\nDigite a expressao (ate 60 digitos): \n");

	gets(automato);
	while (state != 8) {
		switch (state) {
		case 0:
			while (automato[i] == ' ') {
				i++;
			}
			if (search(automato[i], letra)) {
				state = 1;
				i++;
			} else {
				printf("\nString invalida!!!");
				getchar();
				exit(1);
			}
			break;
		case 1:
			while (search(automato[i], letra)) {
				i++;
			}
			if (automato[i] == ' ') {
				state = 3;
				i++;
			} else if (automato[i] == '=') {
				state = 4;
				i++;
			} else if  (search(automato[i], num)) {
				  state = 2;
				  i++;
			} else {
				printf("\nString invalida!!!");
				getchar();
				exit(1);
			}
			break;
		case 2:
			while (search(automato[i], num)) {
				i++;
			}
			if (automato[i] == ' ') {
				state = 3;
				i++;
			} else if (automato[i] == '=') {
				state = 4;
				i++;
			} else {
				printf("\nString invalida!!!");
				getchar();
				exit(1);
			}
			break;
		case 3:
			while (automato[i] == ' ') {
				i++;
			}
			if (automato[i] == '=') {
				state = 4;
				i++;
			} else {
				printf("\nString invalida!!!");
				getchar();
				exit(1);
			}
			i++;
			break;
		case 4:
			while (automato[i] == ' ') {
				i++;
			}
			if (search(automato[i], letra)) {
				state = 5;
				i++;
			} else if (search(automato[i], num)) {
				state = 6;
				i++;
			} else {
				printf("\nString invalida!!!");
				getchar();
				exit(1);
			}
			break;
		case 5:
			while (search(automato[i], letra)) {
				i++;
			}
			if (search(automato[i], num)) {
				state = 6;
				i++;
			} else if (automato[i] == ' ') {
				state = 7;
				i++;
			} else if (search(automato[i], op)) {
				state = 4;
				i++;
			} else if (automato[i] == '\0') {
				state = 8;
			} else {
				printf("\nString invalida!!!");
				getchar();
				exit(1);
			}
			break;
		case 6:
			while (search(automato[i], num)) {
				i++;
			}
			if (automato[i] == ' ') {
				state = 7;
				i++;
			} else if (search(automato[i], op)) {
				state = 4;
				i++;
			} else if (automato[i] == '\0') {
				state = 8;
			} else {
				printf("\nString invalida!!!");
				getchar();
				exit(1);
			}
			break;
		case 7:
			while (automato[i] == ' ') {
				i++;
			}
			if (search(automato[i], op)) {
				state = 4;
				i++;
			} else if (automato[i] == '\0') {
				state = 8;
			} else {
				printf("\nString invalida!!!");
				getchar();
				exit(1);
			}
			break;
		}
	}
	printf("\nString Valida");
	getchar();
}

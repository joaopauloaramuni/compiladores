/****************************************************************************************************
 * Universidade FUMEC             									                                *
 * Compiladores                                   											   	    *
 * Prof. João Paulo Aramuni     																	*
 * Scanner 3                                                 	  									*
 * Verifica a validade de expressões da forma  vr-1  op  vr-2        								*
 * onde vr-n será um número inteiro e op será um operador aritmético qualquer					    *
 * Ao encontrar uma expressão valida ele não encerra, mas continua a verificação,				    *
 * aceitando expressões da forma  vr-1 op vr-2 op vr-3												*
 * 																									*
 * PERMITINDO ESPAÇO EM BRANCO 																		*
 * COM =																							*
 ****************************************************************************************************/

//Bibliotecas
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

//Define's
#define oper "+/-*="
#define num  "0123456789"
#define letra "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvXxWwXxYyZz"

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

	printf("\tCompiladores - Scanner 3 \n");
	printf("\nAutomato para reconhecer expressoes aritmeticas");
	printf("\nDigite a expressao (ate 60 digitos): \n");
	gets(automato);

	while (state != 12) {
		switch (state) {
		case 0:
			while (automato[i] == ' ') {
				i++;
			}
			if (search(automato[i], letra)) {
				i++;
				state = 1;
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
			if (search(automato[i], num)) {
				i++;
				state = 2;
			} else if (automato[i] == ' ') {
				i++;
				state = 3;
			} else if (automato[i] == '=') {
				i++;
				state = 4;
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
				i++;
				state = 3;
			} else if (automato[i] == '=') {
				i++;
				state = 4;
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
				i++;
				state = 4;
			} else {
				printf("\nString invalida!!!");
				getchar();
				exit(1);

			}
			break;
		case 4:
			while (automato[i] == ' ') {
				i++;
			}
			if (search(automato[i], letra)) {
				i++;
				state = 5;
			} else if (search(automato[i], num)) {
				i++;
				state = 6;
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
			if (automato[i] == ' ') {
				i++;
				state = 7;
			} else if (search(automato[i], num)) {
				i++;
				state = 6;
			} else if (search(automato[i], oper)) {
				i++;
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
				i++;
				state = 7;
			} else if (search(automato[i], oper)) {
				i++;
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
			if (search(automato[i], oper)) {
				i++;
				state = 8;
			} else {
				printf("\nString invalida!!!");
				getchar();
				exit(1);
			}
			break;
		case 8:
			while (automato[i] == ' ') {
				i++;
			}
			if (search(automato[i], letra)) {
				i++;
				state = 9;
			} else if (search(automato[i], num)) {
				i++;
				state = 10;
			} else {
				printf("\nString invalida!!!");
				getchar();
				exit(1);
			}
			break;
		case 9:
			while (search(automato[i], letra)) {
				i++;
			}
			if (search(automato[i], num)) {
				i++;
				state = 10;
			} else if (automato[i] == ' ') {
				i++;
				state = 11;
			} else if (search(automato[i], oper)) {
				i++;
				state = 8;
			} else if (automato[i] == '\0') {
				state = 12;
			} else {
				printf("\nString invalida!!!");
				getchar();
				exit(1);
			}
			break;
		case 10:
			while (search(automato[i], num)) {
				i++;
			}
			if (automato[i] == ' ') {
				i++;
				state = 11;
			} else if (search(automato[i], oper)) {
				i++;
				state = 8;
			} else if (automato[i] == '\0') {
				state = 12;
			} else {
				printf("\nString invalida!!!");
				getchar();
				exit(1);
			}
			break;
		case 11:
			while (automato[i] == ' ') {
				i++;
			}
			if (search(automato[i], oper)) {
				i++;
				state = 8;
			} else if (automato[i] == '\0') {
				state = 12;
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

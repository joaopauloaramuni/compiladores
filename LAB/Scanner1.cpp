/****************************************************************************************************
 * Universidade FUMEC             									                                *
 * Compiladores                                   											   	    *
 * Prof. João Paulo Aramuni     																	*
 * Scanner 1                                                 	  									*
 * Verifica a validade de expressões da forma  vr-1  op  vr-2        								*
 * onde vr-n será um número inteiro e op será um operador aritmético qualquer					    *
 * Ao encontrar uma expressão valida ele não encerra, mas continua a verificação,				    *
 * aceitando expressões da forma  vr-1 op vr-2 op vr-3												*
 ****************************************************************************************************/

//Bibliotecas
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

//Define's
#define oper "+/-*"
#define num  "0123456789"
#define let "abcdefghijklmnopqrstuvxzwyABCDEFGHIJKLMNOPQRSTUVXZWY"

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

	printf("\tCompiladores - Scanner 1\n");
	printf("\nAutomato para reconhecer expressoes aritmeticas");
	printf("\nDigite a expressao (ate 60 digitos): \n");
	gets(automato);

	while (state != 6) {
		switch (state) {
		case 0:
			if (search(automato[i], let)) {
				state = 1;
			} else {
				printf("\nString invalida1!!!");
				getchar();
				exit(1);
			}
			i++;
			break;
		case 1:
			while (search(automato[i], let)) {
				i++;
			}
			if (search(automato[i], num)) {
				state = 2;
				i++;
			} else if ((automato[i] == '=')) {
				state = 3;
				i++;
			} else {
				printf("\nString invalida2!!!");
				getchar();
				exit(1);
			}
			break;
		case 2:
			while (search(automato[i], num)) {
				i++;
			}
			if ((automato[i] == '=')) {
				state = 3;
				i++;
			} else {
				printf("\nString invalida3!!!");
				getchar();
				exit(1);
			}
			break;
		case 3:
			if (search(automato[i], num)) {
				state = 5;
			} else if (search(automato[i], let)) {
				state = 4;
			} else {
				printf("\nString invalida4!!!");
				getchar();
				exit(1);
			}
			i++;
			break;
		case 4:
			while (search(automato[i], let)) {
				i++;
			}
			if (search(automato[i], oper)) {
				state = 3;
				i++;
			} else if (search(automato[i], num)) {
				state = 5;
				i++;
			} else if (automato[i] == '\0') {
				state = 6;
			} else {
				printf("\nString invalida5!!!");
				getchar();
				exit(1);
			}
			break;
		case 5:
			while (search(automato[i], num)) {
				i++;
			}
			if (search(automato[i], oper)) {
				state = 3;
				i++;
			} else if (automato[i] == '\0') {
				state = 6;
			} else {
				printf("\nString invalida6!!!");
				getchar();
				exit(1);
			}
			break;
		}
	}
	printf("\nString Valida");
	getchar();
}

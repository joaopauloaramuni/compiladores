/****************************************************************************************************
 * Universidade FUMEC             									                                *
 * Compiladores                                   											   	    *
 * Prof. João Paulo Aramuni     																	*
 * Scanner 4                                                 	  									*
 * Verifica a validade de expressões da forma  vr-1  op  vr-2        								*
 * onde vr-n será um número inteiro e op será um operador aritmético qualquer					    *
 * Ao encontrar uma expressão valida ele não encerra, mas continua a verificação,				    *
 * aceitando expressões da forma  vr-1 op vr-2 op vr-3												*
 * 																									*
 * PERMITINDO ESPAÇO EM BRANCO 																		*
 * OPERADORES +-*: 																					*
 ****************************************************************************************************/

//Bibliotecas
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

//Define's
#define oper "+-*:"
#define num  "0123456789"
#define letra "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

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

	printf("\tCompiladores - Scanner 4 \n");
	printf("\nAutomato para reconhecer expressoes aritmeticas");
	printf("\nDigite a expressao (ate 60 digitos): \n");
	gets(automato);

	while (state != 30) {
		switch (state) {
		case 0:
			while (automato[i] == ' ') {
				i++;
			}
			if (automato[i] == '/'){
				i++;
				state = 1;
			} else if(search(automato[i], letra)){
				i++;
				state = 4;
			} else {
				printf("String invalida!!!");
				getchar();
				exit(1);
			}

			break;

		case 1:
			if (automato[i] == '*') {
				i++;
				state = 2;
			} else {
				printf("String invalida!!!");
				getchar();
				exit(1);
			}
			break;

		case 2:
			while (automato[i] != '*') {
				i++;
			}
			if (automato[i] == '*') {
				i++;
				state = 3;
			} else {
				printf("String invalida!!!");
				getchar();
				exit(1);
			}

			break;

		case 3:
			while (automato[i] == '*') {
				i++;
			}
			if ((automato[i] != '*') && (automato[i] != '/')) {
				i++;
				state = 2;
			} else if (automato[i] == '/') {
				i++;
				state = 0; 

			} else {
				printf("String invalida!!!");
				getchar();
				exit(1);
			}

			break;

		case 4:
			while (search(automato[i], letra)) {
				i++;
			}
			if (search(automato[i], num)) {
				state = 5;
				i++;
			} else if (automato[i] == '=') {
				state = 10;
				i++;
			} else if (automato[i] == ' ') {
				state = 6;
				i++;
			} else if (automato[i] == '/') {
				state = 7;
				i++;
			} else {
				printf("String invalida!!!");
				getchar();
				exit(1);
			}
			break;

		case 5:
		
			while (search(automato[i], num)) {
				i++;
			}
			 if (automato[i] == ' ') {
				state = 6;
				i++;
			} else if (automato[i] == '/') {
				state = 7;
				i++;
			} else if (automato[i] == '=') {
				state = 10;
				i++;
			} else {
				printf("String invalida!!!");
				getchar();
				exit(1);
			}
			break;

		case 6:
			while (automato[i] == ' ') {
				i++;
			}
			if (automato[i] == '/') {
				i++;
				state = 7;
			} else if (automato[i] == '=') {
				i++;
				state = 10;
			} else {
				printf("String invalida!!!");
				getchar();
				exit(1);
			}

			break;

		case 7:
			if (automato[i] == '*') {
				i++;
				state = 8;
			} else {
				printf("String invalida!!!");
				getchar();
				exit(1);
			}

			break;

		case 8:
			while(automato[i] != '*') {
				i++;
			} if (automato[i] == '*') {
				state = 9;
				i++;
			} else {
				printf("\nString invalida!!!");
				getchar();
				exit(1);
			}
			break;
			
		case 9:
			while (automato[i] == '*') {
				i++;
			}
			if (automato[i] == '/') {
				state = 6;
				i++;
			} else if ((automato[i] != '*') && (automato[i] != '/')) {
				state = 8;
				i++;
			} else {
				printf("\nString invalida!!!");
				getchar();
				exit(1);
			}

			break;
		case 10:
			while (automato[i] == ' ') {
				i++;
			}
			if (search(automato[i], letra)) {
				state = 14;
				i++;
			} else if (search(automato[i], num)) {
				state = 15;
				i++;
			} else if (automato[i] == '/') {
				state = 11;
				i++;
			} else {
				printf("\nString invalida!!!");
				getchar();
				exit(1);
			}
			break;

		case 11:
			if (automato[i] == '*') {
				i++;
				state = 12;
			} else {
				printf("String invalida!!!");
				getchar();
				exit(1);
			}
			break;

		case 12:
			while (automato[i] != '*') {
				i++;
			}
			if (automato[i] == '*') {
				i++;
				state = 13;
			} else {
				printf("String invalida!!!");
				getchar();
				exit(1);
			}

			break;

		case 13:
			while (automato[i] == '*') {
				i++;
			}
			if ((automato[i] != '*') && (automato[i] != '/')) {
				i++;
				state = 12;
			} else if (automato[i] == '/') {
				i++;
				state = 10;

			} else {
				printf("String invalida!!!");
				getchar();
				exit(1);
			}

			break;

		case 14:
			while (search(automato[i], letra)) {
				i++;
			}
			if (search(automato[i], oper)) {
				state = 20;
				i++;
			} else if (search(automato[i], num)) {
				state = 15;
				i++;
			} else if (automato[i] == ' ') {
				state = 16;
				i++;
			} else if (automato[i] == '/') {
				i++;
				state = 17;

			} else {
				printf("String invalida!!!");
				getchar();
				exit(1);
			}
			break;

		case 15:
			while (search(automato[i], num)) {
				i++;
			}
			if (search(automato[i], oper)) {
				state = 20;
				i++;
			}

			else if (automato[i] == ' ') {
				state = 16;
				i++;
			} else if (automato[i] == '/') {
				i++;
				state = 17;

			} else {
				printf("String invalida!!!");
				getchar();
				exit(1);
			}
			break;

		case 16:
			while (automato[i] == ' ') {
				i++;
			} 
			if (automato[i] == '/') {
				i++;
				state = 17;
			} 	if (search(automato[i], oper)) {
				i++;
				state = 20;
			} else {
				printf("String invalida!!!");
				getchar();
				exit(1);
			}
			break;

		case 17:
			
			if (automato[i] == '*') {
				i++;
				state = 18;
			} else if (automato[i] == '/') {
				i++;
				state = 21;
			} else if (automato[i] == ' ') {
				i++;
				state = 20;
			} else if (search(automato[i], letra)) {
				i++;
				state = 24;
			} else if (search(automato[i], num)) {
				i++;
				state = 25;
			} else  {
				printf("String invalida!!!");
				getchar();
				exit(1);
			}

			break;

		case 18:
			while (automato[i] != '*') {
				i++;
			}
			if ((automato[i] == '*')) {
				i++;
				state = 19;
			} else {
				printf("String invalida!!!");
				getchar();
				exit(1);
			}

			break;

		case 19:
			while (automato[i] == '*') {
				i++;
			}
			if ((automato[i] != '*') && (automato[i] != '/')) {
				state = 18;
				i++;
			} else if (automato[i] == '/') {
				state = 16;
				i++;
			} else {
				printf("String invalida!!!");
				getchar();
				exit(1);
			}

			break;
		case 20:
			while (automato[i] == ' ') {
				i++;
			}
			if (search(automato[i], letra)) {
				state = 24;
				i++;
			} else if (search(automato[i], num)) {
				state = 25;
				i++;
			} else if (automato[i] == '/') {
				i++;
				state = 21;

			} else {
				printf("\nString invalida!!!");
				getchar();
				exit(1);
			}
			break;
		
		case 21:
			if (automato[i] == '*') {
				i++;
				state = 22;
			} else {
				printf("String invalida!!!");
				getchar();
				exit(1);
			}
			break;

		case 22:
			while (automato[i] != '*') {
				i++;
			}
			if (automato[i] == '*') {
				i++;
				state = 23;
			} else {
				printf("String invalida!!!");
				getchar();
				exit(1);
			}

			break;

		case 23:
			while (automato[i] == '*') {
				i++;
			}
			if ((automato[i] != '*') && (automato[i] != '/')) {
				i++;
				state = 22;
			} else if (automato[i] == '/') {
				i++;
				state = 20;

			} else {
				printf("String invalida!!!");
				getchar();
				exit(1);
			}

			break;

		case 24:
			while (search(automato[i], letra)) {
				i++;
			}
			if (search(automato[i], num)) {
				state = 25;
				i++;
			} else if (search(automato[i], oper)) {
				state = 20;
				i++;
			} else if (automato[i] == ' ') {
				state = 26;
				i++;
			} else if (automato[i] == '/') {
				state = 27;
				i++;
			} else if (automato[i] == '\0') {
				state = 30;
			} else {
				printf("\nString invalida!!!");
				getchar();
				exit(1);
			}

			break;

		case 25:
			while (search(automato[i], num)) {
				i++;
			}
			if (search(automato[i], oper)) {
				state = 20;
				i++;
			} else if (automato[i] == ' ') {
				state = 26;
				i++;
			} else if (automato[i] == '/') {
				i++;
				state = 27;
			} else if (automato[i] == '\0') {
				state = 30;
			} else {
				printf("\nString invalida!!!");
				getchar();
				exit(1);
			}
			break;

		case 26:
			while (automato[i] == ' ') {
				i++;
			}
			if (search(automato[i], oper)) {
				state = 20;
				i++;
			} else if (automato[i] == '/') {
				i++;
				state = 27;

			} else if (automato[i] == '\0') {
				state = 30;
			} else {
				printf("\nString invalida!!!");
				getchar();
				exit(1);
			}

			break;

		case 27:
			if (automato[i] == '*') {
				i++;
				state = 28;
			} else if (automato[i] == ' ') {
				i++;
				state = 20;
			} else if (automato[i] == '/') {
				i++;
				state = 21;
			} else if (search(automato[i], letra)) {
				i++;
				state = 24;
			} else if (search(automato[i], num)) {
				i++;
				state = 25;
			} else  {
				printf("String invalida!!!");
				getchar();
				exit(1);
			}
			break;

		case 28:
			while (automato[i] != '*') {
				i++;
			}
			if (automato[i] == '*') {
				i++;
				state = 29;
			} else {
				printf("String invalida!!!");
				getchar();
				exit(1);
			}

			break;

		case 29:
			while (automato[i] == '*') {
				i++;
			}
			if ((automato[i] != '*') && (automato[i] != '/')) {
				i++;
				state = 28;
			} else if (automato[i] == '/') {
				i++;
				state = 26;

			} else {
				printf("String invalida!!!");
				getchar();
				exit(1);
			}

			break;

		}
	}

	printf("String Valida");
	getchar();
}



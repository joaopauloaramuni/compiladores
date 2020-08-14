/****************************************************************************************************
 * Universidade FUMEC             									                                *
 * Compiladores                                   											   	    *
 * Prof. João Paulo Aramuni     																	*
 * Scanner 5                                                	  									*
 * Verifica a validade de expressões da forma  vr-1  op  vr-2        								*
 * onde vr-n será um número inteiro e op será um operador aritmético qualquer					    *
 * Ao encontrar uma expressão valida ele não encerra, mas continua a verificação,				    *
 * aceitando expressões da forma  vr-1 op vr-2 op vr-3												*
 * 																									*
 * PERMITINDO ESPAÇO EM BRANCO 																		*
 * OPERADORES +/-*>< e ARQUIVO DE ENTRADA															*
 * ATENÇÃO: DEIXAR UMA LINHA VAZIA (enter) AO FINAL DO ARQUIVO DE ENTRADA							*
 * OBS: Onde estiver testando (10 ou 13) significa o código da tabela ASCII para:					*
 * 10 - Próxima linha (/n) e 13 - início da linha (/r)					    						*
 ****************************************************************************************************/

//Bibliotecas
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

//Define's
#define oper "+/-*><"
#define num  "0123456789"
#define letra  "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

int search(char a, const char * str) {
	int j = 0, ret = 0;
	while (str[j] && !ret) {
		ret = (str[j] == a);
		j++;
	}
	return (ret);
}
int scanner(char automato[100]) {
	int i = 0, state = 0;
	while (state != 6) {
		switch (state) {
		case 0:
			while (automato[i] == ' ' || search(automato[i], oper)
					|| search(automato[i], letra) || automato[i] == '=') {
				i++;
			}
			if (search(automato[i], num)) {
				state = 1;
				i++;
			} else if (automato[i] == '/') {
				state = 2;
				i++;
			} else if (automato[i] == 10 || automato[i] == 13) {
				state = 6;
			} else {
				return state;
			}
			break;

		case 1:
			while (search(automato[i], num)) {
				i++;
			}
			if (automato[i] == ' ' || search(automato[i], oper)
					|| automato[i] == '=') {
				state = 0;
				i++;
			} else if (automato[i] == '/') {
				state = 2;
				i++;
			} else if (automato[i] == 10 || automato[i] == 13) {
				state = 6;
			} else {
				return state;
			}
			break;

		case 2:
			if (automato[i] == ' ' || search(automato[i], letra)
					|| search(automato[i], oper) || search(automato[i], num)) {
				state = 0;
				i++;
			} else if (automato[i] == '*') {
				state = 3;
				i++;
			} else if (automato[i] == '/') {
				state = 4;
				i++;
			} else {
				return state;
			}
			break;

		case 3:
			while (automato[i] == ' ' || search(automato[i], oper)
					|| search(automato[i], num) || search(automato[i], letra)
					|| automato[i] == '=' || automato[i] == '/') {
				i++;
			}
			if (automato[i] == '*') {
				state = 5;
				i++;
			} else {
				return state;
			}
			break;

		case 4:
			while (automato[i] == ' ' || search(automato[i], oper)
					|| search(automato[i], num) || search(automato[i], letra)
					|| automato[i] == '=' || automato[i] == '/') {
				i++;
			}
			if (automato[i] == 10 || automato[i] == 13) {
				state = 6;
			} else {
				return state;
			}
			break;

		case 5:
			while (automato[i] == '*') {
				i++;
			}
			if (automato[i] == ' ' || search(automato[i], oper)
					|| search(automato[i], num) || search(automato[i], letra)
					|| automato[i] == '=') {
				state = 3;
				i++;
			} else if (automato[i] == '/') {
				state = 0;
				i++;
			} else {
				return state;
			}
			break;

		}
	}
	return -1;
}
int main(void) {
	char massaF[100], resultados[200], *expressoes[200];

	printf("\tCompiladores - Scanner 5 \n");
	printf("\nDigite o nome do arquivo da massa de teste:");
	scanf("%s", massaF);
	FILE * pFile, *pFile2;
	char mystring[100];

	pFile = fopen(massaF, "r");

	pFile2 = fopen("saida.txt", "w+");

	if (pFile == NULL)
		perror("Error opening file");
	else {
		int i = 0;
		while (fgets(mystring, 100 * 100, pFile) != NULL) {
			if (scanner(mystring) == -1) {
				printf("\nExpressao correta - %s", mystring);
				fprintf(pFile2, "\nExpressao correta - %s", mystring);
			} else {
				printf("\nExpressao Incorreta - State: %d - %s",
						scanner(mystring), mystring);
				fprintf(pFile2, "\nExpressao Incorreta State: %d - %s",
						scanner(mystring), mystring);
			}
			printf("%d", i);
			i++;
		}
		fclose(pFile);
		fclose(pFile2);
		getch();
	}
}

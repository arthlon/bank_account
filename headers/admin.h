#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#ifndef RECORD_H
#define RECORD_H

typedef struct {
	char agency[4];							/* número da agência */
	char number[5];							/* número da conta (ID) 5 dígitos, primeiro dígito é o número da agência */
	double balance;							/* saldo da conta */
	double creditLimit;						/* limite de crédito */
} Account;

typedef struct {
	size_t index;							/* index para organizar os dados em arquivo */
	time_t createdIn;						/* data de criação */
	char firstName[20];						/* primeiro nome do cliente */
	char lastName[60];						/* sobrenome nome do cliente */
	char cpf[12];							/* cpf do cliente */
	char password[21];						/* senha do cliente */
	Account accountData;					/* dados da conta */
} Client;

typedef struct {
	size_t index;
	char string[20];
} Names;

FILE *agencyRecords;

void createRandomClients();
void showClients();
void createPrintFile();
void delectAccountLowerValue();
int openFile(char *agencyNumber, char *openMode);

#endif
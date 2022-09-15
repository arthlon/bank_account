#include "../headers/record.h"
#include "../headers/ui.h"

void createAccount(char *agencyNumber) {
	Client clientModel;
}

void createRandomClients() {
	system("cls");
	system("MODE con cols=50 lines=10");
	centerWindow();
	
	char agencyNumber[4];
	
	printf(" - Informe a agencia (ex. 001): ");
	scanf("%s", &agencyNumber);
	fflush(stdin);
	
	if(atoi(agencyNumber) == 0) {
		printf(" Operacao cancelada\n\n ");
		system("pause");
		return;
	}
	
	if(openFile(agencyNumber, "wb")) {
		void calcFileSize(FILE *fPtr, Names namesModel, Names *array, char *fPath, int *fElementPtr, int *fSizePtr);
		
		int maxAccounts = 9999, numAccounts = 0;
		int firstNamesElements = 0, firstNamesSize = 0;
		int lastNamesElements = 0, lastNamesSize = 0;
		Client clientModel = {0, 0, "", "", "", "", "", 0.0, 0.0};
		Names namesModel = {0, ""};
		Names firstNames[300];
		Names lastNames[1000];
		FILE *fFirstNames;
		FILE *fLastNames;
		
		do {
			printf(" - Informe a qtd de contas (< 9999): ");
			scanf("%d", &numAccounts);
			fflush(stdin);
			if(numAccounts <= maxAccounts) break;
			system("cls");
			printf(" ERRO! Nao pode ser maior que 9999. . .\n");
		} while(numAccounts > maxAccounts);
		
		for(size_t i = 0; i < maxAccounts; i++) {
			fwrite(&clientModel, sizeof(Client), 1, agencyRecords);
		}
		fclose(agencyRecords);
		
		calcFileSize(fFirstNames, namesModel, firstNames, "data/app_data/first_names.dat", &firstNamesElements, &firstNamesSize);
		calcFileSize(fFirstNames, namesModel, lastNames, "data/app_data/last_names.dat", &lastNamesElements, &lastNamesSize);
		
		if(openFile(agencyNumber, "rb+")) {
			void defineLimit(double *balancePtr, double *creditLimitPtr);
			size_t index = 0;
			rewind(agencyRecords);
			srand(time(NULL));
			for(size_t i = 0; i < numAccounts; i++) {
				Client clientModel = {0, 0, "", "", "", "", "", 0.0, 0.0};
				
				clientModel.index = i + 1;
				clientModel.createdIn = time(NULL);
				index = rand() % firstNamesElements;
				strcpy(clientModel.firstName, firstNames[index].string);
				for(size_t i = 0; i < 1 + rand() % 3; i++) {
					index = rand() % lastNamesElements;
					strcat(clientModel.lastName, lastNames[index].string);
					strcat(clientModel.lastName, " ");
				}
				for(size_t i = 0; i < 11; i++) {
					index = 1 + rand() % 9;
					char c;
					itoa(index, &c, 10);
					strcat(clientModel.cpf, &c);
				}
				strcpy(clientModel.accountData.agency, agencyNumber);
				int number = atoi(agencyNumber) * 10000 + i + 1;
				char c[6];
				itoa(number, c, 10);
				strcpy(clientModel.accountData.number, c);
				float decimal = (1 + rand() * 99 / RAND_MAX);
				decimal /= 100;
				clientModel.accountData.balance = (50 + rand() * (5000 - 50) / RAND_MAX) + decimal;
				//clientModel.accountData.balance = 50.00 + rand() * (5000.00 - 50.00) / RAND_MAX;
				/* O limite de crédito é aproximadamente 5x o valor que a pessoa tem em conta (em intervalos de 500.00)*/
				defineLimit(&clientModel.accountData.balance, &clientModel.accountData.creditLimit);
				
				fseek(agencyRecords, i * sizeof(Client), SEEK_SET);
				fwrite(&clientModel, sizeof(Client), 1, agencyRecords);
			}
			fclose(agencyRecords);
		}
		printf("\n Arquivo criado com sucesso.\n\n ");
		system("pause");
	}	
}

void showClients() {
	system("cls");
	system("MODE con cols=50 lines=10");
	centerWindow();
	
	char agencyNumber[4];
	printf(" - Informe a agencia: ");
	scanf("%s", &agencyNumber);
	fflush(stdin);
	
	if(openFile(agencyNumber, "rb")) {
		system("cls");
		system("MODE con cols=160 lines=30");
		centerWindow();
		setBuffer(160, 10100);
	
		Client clientModel = {0, 0, "", "", "", "", "", 0.0, 0.0};
		struct tm *createdIn;
		
		printf(" %-8s%-60s%-15s%-10s%-10s%-15s%-15s%-21s\n",
			"Index",
			"Nome",
			"CPF",
			"Agencia",
			"Conta",
			"Saldo",
			"Limite",
			"Criado em"
		);
			
		fread(&clientModel, sizeof(Client), 1, agencyRecords);
		while(!feof(agencyRecords)) {
			if(clientModel.index != 0) {
				createdIn = localtime(&clientModel.createdIn);
				char fullName[60] = "";
				strcat(fullName, clientModel.firstName);
				strcat(fullName, " ");
				strcat(fullName, clientModel.lastName);
				printf(" %-8d%-60s%-15s%-10s%-10s%-15.2f%-15.2f%d/%d/%d as %d:%d:%d\n", 
					clientModel.index,
					fullName,
					clientModel.cpf,
					clientModel.accountData.agency,
					clientModel.accountData.number,
					clientModel.accountData.balance,
					clientModel.accountData.creditLimit,
					createdIn->tm_mday, createdIn->tm_mon + 1, createdIn->tm_year + 1900,
					createdIn->tm_hour, createdIn->tm_min, createdIn->tm_sec
				);
			}
			fread(&clientModel, sizeof(Client), 1, agencyRecords);
		}
		fclose(agencyRecords);
		printf("\n\n ");
		system("pause");
	}	
}

void createPrintFile() {
	system("cls");
	system("MODE con cols=50 lines=10");
	centerWindow();
	
	char agencyNumber[4];
	printf(" - Informe a agencia: ");
	scanf("%s", &agencyNumber);
	fflush(stdin);
	
	if(openFile(agencyNumber, "rb")) {
		Client clientModel = {0, 0, "", "", "", "", "", 0.0, 0.0};
		struct tm *createdIn;
		
		FILE *outputAgencyRecords;
		char filePath[40] = "data/output_data/";
		char number[4] = "";
		strcpy(number, agencyNumber);
		strcat(filePath, "agency_");
		strcat(filePath, number);
		strcat(filePath, "_clients_data.csv");
		if((outputAgencyRecords = fopen(filePath, "wb")) == NULL) {
			printf(" O arquivo nao pode ser aberto.\n\n ");
			system("pause");
		} else {
			fprintf(outputAgencyRecords, " %-8s;%-60s;%-15s;%-10s;%-10s;%-15s;%-15s;%-21s;\n",
				"Index",
				"Nome",
				"CPF",
				"Agencia",
				"Conta",
				"Saldo",
				"Limite",
				"Criado em"
			);
			
			rewind(agencyRecords);
			fread(&clientModel, sizeof(Client), 1, agencyRecords);
			while(!feof(agencyRecords)) {
				if(clientModel.index != 0) {
					createdIn = localtime(&clientModel.createdIn);
					char fullName[60] = "";
					strcat(fullName, clientModel.firstName);
					strcat(fullName, " ");
					strcat(fullName, clientModel.lastName);
					fprintf(outputAgencyRecords, " %-8d;%-60s;%-15s;%-10s;%-10s;%-15.2f;%-15.2f;%d/%d/%d as %d:%d:%d\n", 
						clientModel.index,
						fullName,
						clientModel.cpf,
						clientModel.accountData.agency,
						clientModel.accountData.number,
						clientModel.accountData.balance,
						clientModel.accountData.creditLimit,
						createdIn->tm_mday, createdIn->tm_mon + 1, createdIn->tm_year + 1900,
						createdIn->tm_hour, createdIn->tm_min, createdIn->tm_sec
					);
				}
				fread(&clientModel, sizeof(Client), 1, agencyRecords);
			}
			fclose(agencyRecords);
		}
		fclose(outputAgencyRecords);
		printf("\n Arquivo criado com sucesso.\n\n ");
		system("pause");
	}
}

int openFile(char *agencyNumber, char *openMode) {
	char filePath[40] = "data/app_data/";
	char number[4] = "";
	
	strcpy(number, agencyNumber);
	strcat(filePath, "agency_");
	strcat(filePath, number);
	strcat(filePath, "_clients_data.dat");
	
	if((agencyRecords = fopen(filePath, openMode)) == NULL) {
		printf(" O arquivo nao pode ser aberto.\n\n ");
		system("pause");
		return 0;
	}
	return 1;
}

void calcFileSize(FILE *fPtr, Names namesModel, Names *array, char *fPath, int *fElementPtr, int *fSizePtr) {
	if((fPtr = fopen(fPath, "rb")) == NULL) {
		printf(" Impossível abrir o arquivo.");	
	} else {
		size_t index = 0;
		fread(&namesModel, sizeof(Names), 1, fPtr);
		while(!feof(fPtr)) {
			index = namesModel.index;
			if(namesModel.index != 0) {
				*fElementPtr += 1;
				array[index].index = namesModel.index;
				strcpy(array[index].string, namesModel.string);
				index++;
			}
			*fSizePtr += 1;
			fread(&namesModel, sizeof(Names), 1, fPtr);
		}
		fclose(fPtr);
	}
}

void defineLimit(double *balancePtr, double *creditLimitPtr) {
	double hold, limit;
	hold = *balancePtr * 5;
	limit = lround(hold / 500.00);
	limit *= 500.00;	
	
	*creditLimitPtr = limit;
}










#include "../headers/ui.h"
#include "../headers/admin.h"
#include "../headers/user.h"

void createAccount() {
	system("cls");
	system("MODE con cols=85 lines=27");
	centerWindow();
	
	char agencyNumber[4];
	int index = 0;
	printf(" - Informe a agencia: ");
	scanf("%s", agencyNumber);
	
	if(openFile(agencyNumber, "rb+")) {
		Client clientModel = {0, 0, "", "", "", "", "", "", 0.0, 0.0};
		
		fread(&clientModel, sizeof(Client), 1, agencyRecords);
		while(!feof(agencyRecords)) {
			if(clientModel.index != 0) {
				index++;
			} else {
				break;
			}
			fread(&clientModel, sizeof(Client), 1, agencyRecords);
		}
		
		char password[20], confirmPassword[20];

		clientModel.index = index + 1;
		clientModel.createdIn = time(NULL);
		fflush(stdin);
		printf(" - Informe o seu nome: ");
		scanf("%[^\n]s", clientModel.firstName);
		fflush(stdin);
		printf(" - Informe o seu sobrenome: ");
		scanf("%[^\n]s", clientModel.lastName);
		fflush(stdin);
		printf(" - Informe o seu CPF: ");
		scanf("%s", clientModel.cpf);
		fflush(stdin);
		do {
			size_t i = 0;
			char c;
			printf(" - Informe uma senha (min 8, max 20 caracteres): ");
			while(1) {
				c = getch();
				if(c == 13) break;
		        password[i] = c;
		        putchar('*');
		        i++;
		    }
		    password[i] = '\0';
			fflush(stdin);
			i = 0;
			printf("\n - Repita a senha: ");
			while(1) {
				c = getch();
				if(c == 13) break;
		        confirmPassword[i] = c;
		        putchar('*');
		        i++;
		    }
		    confirmPassword[i] = '\0';
			fflush(stdin);
			if(strcmp(password, confirmPassword)) {
				printf("\n Atenção! as senhas não conferem\n");
			}
		} while(strcmp(password, confirmPassword));
		strcpy(clientModel.password, password);
		
		strcpy(clientModel.accountData.agency, agencyNumber);
		int number = atoi(agencyNumber) * 10000 + index + 1;
		char c[6];
		itoa(number, c, 10);
		strcpy(clientModel.accountData.number, c);
		printf("\n - Informe o valor do deposito inicial (. para decimal): ");
		scanf("%lf", &clientModel.accountData.balance);
		fflush(stdin);
		defineLimit(&clientModel.accountData.balance, &clientModel.accountData.creditLimit);
		
		fseek(agencyRecords, index * sizeof(Client), SEEK_SET);
		fwrite(&clientModel, sizeof(Client), 1, agencyRecords);
		
		fclose(agencyRecords);
		printf("\n\n Cadastro realizado com sucesso\n\n ");
		system("pause");
		
	}
}

Client accessAccount() {
	system("cls");
	system("MODE con cols=50 lines=10");
	centerWindow();
	
	char agencyNumber[4] = "";
	printf(" - Informe a agencia: ");
	scanf("%s", &agencyNumber);
	fflush(stdin);
	
	if(openFile(agencyNumber, "rb")) {
		Client clientModel = {0, 0, "", "", "", "", "", "", 0.0, 0.0};
		char cpf[12] = "", password[21] = "";
		size_t i = 0;
		char c = '\0';
		
		printf("\n Insisa seu CPF: ");
		scanf("%s", &cpf);
		printf(" Insira sua senha: ");
		while(1) {
			c = getch();
			if(c == 13) break;
	        password[i] = c;
	        putchar('*');
	        i++;
		}
		password[i] = '\0';
		fflush(stdin);
		
		fread(&clientModel, sizeof(Client), 1, agencyRecords);
		while(!feof(agencyRecords)) {
			if(clientModel.index != 0 && !strcmp(clientModel.cpf, cpf)) {
				if(!strcmp(clientModel.password, password)) {
					printf("\n\n Login efetuado com sucesso!\n\n ");
					system("pause");
					return clientModel;
				} else {
					printf("\n\n Usuario e senha nao conferem!\n\n ");
					system("pause");
					return;
				}
			}
			fread(&clientModel, sizeof(Client), 1, agencyRecords);
		}
		
		fclose(agencyRecords);
		printf("\n\n Cliente nao cadastrado!\n\n ");
		system("pause");
		return;
	}
}










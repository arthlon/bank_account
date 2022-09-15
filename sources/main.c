#include "../headers/ui.h"
#include "../headers/admin.h"
#include "../headers/user.h"

void adminMenu();
void userMenu();
void accountInfo(Client *loggedInCLient);

int main(int argc, char *argv[]) {
	char i;
	int index;
	centerWindow();
	
	splashScreen();
	
	do {
		MenuItems items = {"ACESSAR CONTA", "CRIAR CONTA", "ACESSO ADMIN", "", "", "", "", "SAIR"};
		mainScreen(&items);
		scanf("%c", &i);
		while(getchar() != '\n');
		index = atoi(&i);
		
		switch(index) {
			case 1:
				userMenu();
				break;
			case 2:
				createAccount();
				break;
			case 3:
				adminMenu();
				break;
			default:
				break;
		}
	} while(i != 's' && i != 'S');
	
	system("cls");
	printf("\n Programa encerrado com sucesso. . .\n ");

	return 0;
}

void adminMenu() {
	char i;
	int index;

	do {
		MenuItems items = {"GERAR CONTAS", "MOSTRAR CONTAS", "IMPRIMIR CONTAS", "EXCLUIR < VALOR", "", "", "", "SAIR"};
		mainScreen(&items);
		scanf("%c", &i);
		while(getchar() != '\n');
		index = atoi(&i);
		
		switch(index) {
			case 1:
				createRandomClients();
				break;
			case 2:
				showClients();
				break;
			case 3:
				createPrintFile();
				break;
			case 4:
				delectAccountLowerValue();
				break;
			default:
				break;
		}
	} while(i != 's' && i != 'S');
}

void userMenu() {
	char i;
	int index;
	Client loggedInCLient = {0, 0, "", "", "", "", "", "", 0.0, 0.0};
	
	loggedInCLient = accessAccount();
	if(!loggedInCLient.index) return;
	
	do {
		MenuItems items = {"SALDO", "", "", "", "", "", "", "SAIR"};
		mainScreen(&items);
		scanf("%c", &i);
		while(getchar() != '\n');
		index = atoi(&i);
		
		switch(index) {
			case 1:
				accountInfo(&loggedInCLient);
				break;
			default:
				break;
		}
	} while(i != 's' && i != 'S');
}

void accountInfo(Client *loggedInCLient) {
	char i;
	size_t isLogInIndex = 0;
	
	do {
		MenuItems items = {"Criada em:", "Saldo:", "Limite:", "", "", "", "", "SAIR"};
		infoScreen(&items, loggedInCLient);
		scanf("%c", &i);
		while(getchar() != '\n');
		
	} while(i != 's' && i != 'S');
}










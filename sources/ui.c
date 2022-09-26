#include "../headers/ui.h"

void splashScreen() {
	system("MODE con cols=85 lines=27");
	system("COLOR 4F");
	centerWindow();
	
	printf(
		".....................................................................................\n"
		".....................................................................................\n"
		"...    ____      ____     ______________     ____      ____     ____      ____    ...\n"
		"...   |    \\    /    |   |              |   |    |    |    |   \\    \\    /    /   ...\n"
		"...   |     \\  /     |   |____      ____|   |    |    |    |    \\    \\  /    /    ...\n"
		"...   |      \\/      |        |    |         \\   \\    /   /      \\    \\/    /     ...\n"
		"...   |              |        |    |          \\   \\  /   /       /         /      ...\n"
		"...   |    |\\  /|    |        |    |           \\   \\/   /       /    /\\    \\      ...\n"
		"...   |    | \\/ |    |        |    |            \\      /       /    /  \\    \\     ...\n"
		"...   |____|    |____|        |____|             \\____/       /____/    \\____\\    ...\n"
		"...                                                                               ...\n"
		".....................................................................................\n"
		".....................................................................................\n"
		"...    _____________           ____          ____      ____     ____      ____    ...\n"
		"...   |     ____    \\         /    \\        |    \\    |    |   |    |    /    /   ...\n"
		"...   |    |    \\    |       /      \\       |      \\  |    |   |    |  /    /     ...\n"
		"...   |    |____/   /       /   /\\   \\      |        \\|    |   |    |/    /       ...\n"
		"...   |     ____    \\      /   /__\\   \\     |         |    |   |         |        ...\n"
		"...   |    |    \\    |    /    ____    \\    |    |\\        |   |    |\\    \\       ...\n"
		"...   |    |____/    |   |    |    |    |   |    |  \\      |   |    |  \\    \\     ...\n"
		"...   |_____________/    |____|    |____|   |____|    \\____|   |____|    \\____\\   ...\n"
		"...                                                                               ...\n"
		".....................................................................................\n"
		"....................................................................................."
	);
	printf("\n\n                  ");
	system("pause");
}

void mainScreen(MenuItems *items) {
	system("cls");
	system("MODE con cols=60 lines=40");
	centerWindow();
	
	printf(
		"   ______________________________________________________   \n"
		"  |                       MTVX BANK                      |  \n"              
		"  |              SELECIONE A OPCAO DESEJADA              |  \n"
		"  |         ____________________________________         |  \n"
		"  |  ____  |                                    |  ____  |  \n"
		"  | |  1 | | %-17s%17s | | 5  | |  \n"
		"  | |____| |                                    | |____| |  \n"
		"  |  ____  |                                    |  ____  |  \n"
		"  | |  2 | | %-17s%17s | | 6  | |  \n"
		"  | |____| |                                    | |____| |  \n"
		"  |  ____  |                                    |  ____  |  \n"
		"  | |  3 | | %-17s%17s | | 9  | |  \n"
		"  | |____| |                                    | |____| |  \n"
		"  |  ____  |                                    |  ____  |  \n"
		"  | |  4 | | %-17s%17s | | S  | |  \n"
		"  | |____| |                                    | |____| |  \n"
		"  |        |____________________________________|        |  \n"
		"  |       /    ___   ___   ___    ___________    \\       |  \n"
		"  |      /    | 1 | | 2 | | 3 |  | CANCELA X |    \\      |  \n"
		"  |     |     |___| |___| |___|  |___________|     |     |  \n"
		"  |     |      ___   ___   ___    ___________      |     |  \n"
		"  |     |     | 4 | | 5 | | 6 |  | CORRIGE I |     |     |  \n"
		"  |     |     |___| |___| |___|  |___________|     |     |  \n"
		"  |     |      ___   ___   ___    ___________      |     |  \n"
		"  |     |     | 7 | | 8 | | 9 |  | ENTRA   O |     |     |  \n"
		"  |     |     |___| |___| |___|  |___________|     |     |  \n"
		"  |     |      ___   ___   ___    ___________      |     |  \n"
		"  |     |     | X | | 0 | | < |  |     >     |     |     |  \n"
		"  |     |     |___| |___| |___|  |___________|     |     |  \n"
		"  |     | ________________________________________ |     |  \n"
		"  |     |                                          |     |  \n"
		"  |     |       ____________________________       |     |  \n"
		"  |     |      /____________________________\\      |     |  \n"
		"  |     |     (______________________________)     |     |  \n"
		"  |     |      \\____________________________/      |     |  \n"
		"  |     |                                          |     |  \n"
		"  |_____|__________________________________________|_____|  ",
		items->item1, items->item5,
		items->item2, items->item6,
		items->item3, items->item9,
		items->item4, items->itemS
	);
		
	printf("\n\n Informe o indice desejado: ");
}

void infoScreen(MenuItems *items, Client *loggedInCLient) {
	system("cls");
	system("MODE con cols=60 lines=40");
	centerWindow();
	
	char cCreatedInData[24] = "";
	char balance[18] = "R$ ";
	char creditLimit[18] = "R$ ";
	char buffer[sizeof(int) * 8 + 1];
	int temp = 0;
	struct tm *createdIn = localtime(&loggedInCLient->createdIn);
	
	if(createdIn->tm_mday < 10) strcat(cCreatedInData, "0");
	itoa(createdIn->tm_mday, buffer, 10);
	strcat(cCreatedInData, buffer);
	strcat(cCreatedInData, "/");
	if(createdIn->tm_mon < 10) strcat(cCreatedInData, "0");
	itoa(createdIn->tm_mon + 1, buffer, 10);
	strcat(cCreatedInData, buffer);
	strcat(cCreatedInData, "/");
	if(createdIn->tm_year < 10) strcat(cCreatedInData, "0");
	itoa(createdIn->tm_year + 1900, buffer, 10);
	strcat(cCreatedInData, buffer);
	
	strcat(cCreatedInData, " as ");
	
	if(createdIn->tm_hour < 10) strcat(cCreatedInData, "0");
	itoa(createdIn->tm_hour, buffer, 10);
	strcat(cCreatedInData, buffer);
	strcat(cCreatedInData, ":");
	if(createdIn->tm_min < 10) strcat(cCreatedInData, "0");
	itoa(createdIn->tm_min, buffer, 10);
	strcat(cCreatedInData, buffer);
	strcat(cCreatedInData, ":");
	if(createdIn->tm_sec < 10) strcat(cCreatedInData, "0");
	itoa(createdIn->tm_sec, buffer, 10);
	strcat(cCreatedInData, buffer);
	
	itoa(loggedInCLient->accountData.balance, buffer, 10);
	strcat(balance, buffer);
	temp = fmod(loggedInCLient->accountData.balance, 1) * 100;
	strcat(balance, ".");
	itoa(temp, buffer, 10);
	strcat(balance, buffer);
	
	itoa(loggedInCLient->accountData.creditLimit, buffer, 10);
	strcat(creditLimit, buffer);
	temp = fmod(loggedInCLient->accountData.creditLimit, 1.0) * 100;
	strcat(creditLimit, ".");
	itoa(temp, buffer, 10);
	strcat(creditLimit, buffer);
	
	printf(
		"   ______________________________________________________   \n"
		"  |                       MTVX BANK                      |  \n"              
		"  |              SELECIONE A OPCAO DESEJADA              |  \n"
		"  |         ____________________________________         |  \n"
		"  |  ____  |                                    |  ____  |  \n"
		"  | |  1 | | %-12s%21s | | 5  | |  \n"
		"  | |____| |                                    | |____| |  \n"
		"  |  ____  |                                    |  ____  |  \n"
		"  | |  2 | | %-17s%17s | | 6  | |  \n"
		"  | |____| |                                    | |____| |  \n"
		"  |  ____  |                                    |  ____  |  \n"
		"  | |  3 | | %-17s%17s | | 9  | |  \n"
		"  | |____| |                                    | |____| |  \n"
		"  |  ____  |                                    |  ____  |  \n"
		"  | |  4 | | %-17s%17s | | S  | |  \n"
		"  | |____| |                                    | |____| |  \n"
		"  |        |____________________________________|        |  \n"
		"  |       /    ___   ___   ___    ___________    \\       |  \n"
		"  |      /    | 1 | | 2 | | 3 |  | CANCELA X |    \\      |  \n"
		"  |     |     |___| |___| |___|  |___________|     |     |  \n"
		"  |     |      ___   ___   ___    ___________      |     |  \n"
		"  |     |     | 4 | | 5 | | 6 |  | CORRIGE I |     |     |  \n"
		"  |     |     |___| |___| |___|  |___________|     |     |  \n"
		"  |     |      ___   ___   ___    ___________      |     |  \n"
		"  |     |     | 7 | | 8 | | 9 |  | ENTRA   O |     |     |  \n"
		"  |     |     |___| |___| |___|  |___________|     |     |  \n"
		"  |     |      ___   ___   ___    ___________      |     |  \n"
		"  |     |     | X | | 0 | | < |  |     >     |     |     |  \n"
		"  |     |     |___| |___| |___|  |___________|     |     |  \n"
		"  |     | ________________________________________ |     |  \n"
		"  |     |                                          |     |  \n"
		"  |     |       ____________________________       |     |  \n"
		"  |     |      /____________________________\\      |     |  \n"
		"  |     |     (______________________________)     |     |  \n"
		"  |     |      \\____________________________/      |     |  \n"
		"  |     |                                          |     |  \n"
		"  |_____|__________________________________________|_____|  ",
		items->item1, cCreatedInData,
		items->item2, balance, 
		items->item3, creditLimit,
		items->item4, items->itemS
	);
		
	printf("\n\n Informe o indice desejado: ");
}

void centerWindow() {
	/* trata dos tamanhos e posições do console para centralizar */
	int screenWidth, screenHeight, windowWidth, windowHeight, posX, posY;
	RECT rect;
	HWND consoleWindow = GetConsoleWindow();
	/* pega o tamanho do monitor em polegadas */
	screenWidth = GetSystemMetrics(SM_CXSCREEN);
	screenHeight = GetSystemMetrics(SM_CYSCREEN);
	/* pega as posições do console em polegadas */
	GetWindowRect(consoleWindow, &rect);
	/* calcula o tamanho do console em polegadas */
	windowWidth = rect.right - rect.left;
	windowHeight = rect.bottom - rect.top;
	/* calcula a posição em que deve ser colocado o console centralizado */
	posX = screenWidth / 2 - windowWidth / 2;
	posY = screenHeight / 2 - windowHeight / 2;
	/* define a posição do console */
	SetWindowPos(consoleWindow, 0, posX, posY, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
}

void setBuffer(int cols, int rows) {
	HANDLE wHnd;    /* para gravar no console */
	/* configura os HANDLE */
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    /* cria um coord para tamanho de buffer */
    COORD bufferSize = {cols, rows};
    SetConsoleScreenBufferSize(wHnd, bufferSize);
}










#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "../headers/admin.h"

#ifndef UI_H
#define UI_H

typedef struct {
	char item1[18];
	char item2[18];
	char item3[18];
	char item4[18];
	char item5[18];
	char item6[18];
	char item9[18];
	char itemS[18];
} MenuItems;

void centerWindow();
void setBuffer(int cols, int rows);
void splashScreen();
void mainScreen(MenuItems *items);
void infoScreen(MenuItems *items, Client *loggedInCLient);

#endif
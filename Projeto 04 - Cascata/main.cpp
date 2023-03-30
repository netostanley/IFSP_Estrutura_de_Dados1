#include <iostream>
#include <locale.h>
#include <windows.h>
#include <algorithm>
using namespace std;

void coordenadas(short x, short y)
{
	COORD coord = {x, y};
	SetConsoleCursorPosition(GetStdHandle ( STD_OUTPUT_HANDLE ), coord);
}


int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");
	
	string msg;
	
	cout << "Digite aqui uma frase: ";
	getline(cin, msg);
	int tamanho = msg.length();
	string m2 = msg;
	
	system("cls");

	
	coordenadas (60,5); // tamanho da tela de 120 colunas (tela minimizada)
	cout << msg;
	
	for (int i = 0; i < tamanho; i++)
		{
			coordenadas(60,5);
			cout << msg;
			msg.replace(i, 1, " "); // posição que a msg será realocada; números de caracteres que serão reclocados da msg principal; " ": será a string que será colocada no lugar da velha
			coordenadas(60,5);
			cout << msg;
			
			for(int j = 5; j <= 20; j++)
			{
				coordenadas(60+ i, j);
				cout << m2[i];
				Sleep(40);
				coordenadas(60 + i, j);
				
				if (j < 20)
				{
					cout << " ";
				}
			}
			
		}
		
		return 0;
}
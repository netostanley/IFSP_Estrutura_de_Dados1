#include <iostream>
#include <locale.h>
#include <algorithm>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");
	
	string msg;
	
	
	cout << "Digite aqui uma mensagem: ";
	getline(cin, msg); // para ler a mensagem inteira digitada pelo usuário
	
	msg.erase(remove(msg.begin(), msg.end(), ' '), msg.end()); // removendo todos os espaços da mensagem digitada
	
	string msgInvertida = msg;
	
	reverse(msgInvertida.begin(), msgInvertida.end()); //inversão da mensagem
	
	
	if (msg == msgInvertida)
	{
		cout << "É um palindromo!" << endl;
	}
	else 
	{
		cout << "Não é um palindromo" << endl;
	}
	
	return 0;
	
}
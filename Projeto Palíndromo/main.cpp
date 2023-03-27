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
	getline(cin, msg); // para ler a mensagem inteira digitada pelo usu�rio
	
	msg.erase(remove(msg.begin(), msg.end(), ' '), msg.end()); // removendo todos os espa�os da mensagem digitada
	
	string msgInvertida = msg;
	
	reverse(msgInvertida.begin(), msgInvertida.end()); //invers�o da mensagem
	
	
	if (msg == msgInvertida)
	{
		cout << "� um palindromo!" << endl;
	}
	else 
	{
		cout << "N�o � um palindromo" << endl;
	}
	
	return 0;
	
}
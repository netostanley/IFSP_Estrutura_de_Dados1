#include <iostream>
#include <locale.h>
#include <string>
#include <iomanip>
#include <stdlib.h>
using namespace std;

class Data
{
	private:
		int dia;
		int mes;
		int ano;
    public:
    	Data(int dia, int mes, int ano) {
			this->dia = dia;
            this->mes = mes;
			this->ano = ano;			
		}
    	Data() {
			this->dia = 0;
            this->mes = 0;
			this->ano = 0;			
		}
		void setDia(int dia) {
			this->dia = dia;
		}
		void setMes(int mes) {
			this->mes = mes;
		}
		void setAno(int ano) {
			this->ano = ano;
		}
		int getDia() {
			return this->dia;
		}
		int getMes() {
			return this->mes;
		}
		int getAno() {
			return this->ano;
		}
		
        Data* dia_seguinte()
		{
			Data *d1;
			int diasNoMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
			d1 = new Data(this->dia, this->mes, this->ano);
			if (d1->ano%4==0)
			{
				diasNoMes[1]++;
			}
			d1->dia++;
			if(d1->dia > diasNoMes[d1->mes-1])
			{
				d1->dia = 1;
				if (++d1->mes > 12)
				{
					d1->mes = 1;
					d1->ano++;
				}
			}
			return d1;
		}
		 	
};

class Contato {
	private:
		string email;
		string nome;
		string telefone;
		Data dtnasc;

	public: 
		
	
		Contato() {
			this->email = "Invalid";
			this->nome = "Invalid";
			this->telefone = "Invalid";
	   	}
	   	
	   	Contato(string email, string nome, string telefone, Data dtnasc) {
            this->email = email;
			this->nome = nome;
			this->telefone = telefone;
			this->dtnasc = dtnasc;
	    }
	    
	    void setEmail(string email) {
			this->email = email;
		}
		
		void setNome(string nome) {
			this->nome = nome;
		}
		
		void setTelefone(string telefone) {
			this->telefone = telefone;
		}
		
		void setDtnasc(Data dtnasc) {
			this->dtnasc = dtnasc;
		}
		
		string getEmail() {
			return this->email;
		}
		
		string getNome() {
			return this->nome;
		}
		
		string getTelefone() {
			return this->telefone;
		}
		
		Data getDtnasc() {
			return this->dtnasc;
		}
		
		int Idade() {
			int idade = 2023 - dtnasc.getAno();
			return idade;
		}
		
};

	float CalcMediaIdades(Contato arrayC[], int tamanho)
	{
		int SomaIdades= 0;
		
		for (int i = 0; i < tamanho; i++)
		{
			SomaIdades += arrayC[i].Idade();
		}
		
		float MediaIdades = static_cast<float>(SomaIdades)/tamanho;
		
		return MediaIdades;
	}

int main(int argc, char** argv)
{
	
	setlocale(LC_ALL, "");
	
	Data array[10];
	Contato arrayC[10];
	
	string Nome, Telefone, Email;
	int DtNasc;
	int soma=0;
	int MaisVelho = -9999999;
	
	int cont = 1;
	
	for (int x = 0; x < 10; x++) {
		
		cout << cont << "º Contato" << endl;
		cout << "Escreva o ano de nascimento: ";
		cin >> DtNasc;
		array[x].setAno(DtNasc);
		arrayC[x].setDtnasc(array[x]);
		
		cout << "Digite o nome: ";
		cin >> Nome;
		arrayC[x].setNome(Nome);
		
		cout << "Digite o email: ";
		cin >> Email;
		arrayC[x].setEmail(Email);
		
		cout << "Digite o telefone: ";
		cin >> Telefone;
		arrayC[x].setTelefone(Telefone);
		cout << " ";
		cont++;
		
	}
	
	system ("cls");
	
	for (int y = 0; y < 10; y++) {
		cout << "-------------------------" << endl;
		cout << "Nome: " << arrayC[y].getNome() << endl;
		cout << "Email: " << arrayC[y].getEmail() << endl;
		cout << "Telefone: " << arrayC[y].getTelefone() << endl;
		cout << "Idade: " << arrayC[y].Idade() << endl;
		cout << "-------------------------" << endl;
	}
	
	
	cout << "Média das idades dos contatos: " << CalcMediaIdades(arrayC, 3) << endl;
	
	cout << "Contatos com idade maior do que a média: ";
	
	for (int y =0; y < 10; y++) 
	{
		if (arrayC[y].Idade() > CalcMediaIdades(arrayC, 3)) 
		{
			cout << arrayC[y].getNome() << endl; 
		}
		
		if (arrayC[y].Idade() >= 18) 
		{
			soma++;
		}
	}
	
	cout << "Contatos maiores de idade: " << soma << endl;
	

	
	for (int y =0; y < 10; y++) 
	{
		
		if( MaisVelho <= arrayC[y].Idade())
		{
			MaisVelho = arrayC[y].Idade();
		}
		
	}
	
	for (int y =0; y < 10; y++) 
	{
		
		if( arrayC[y].Idade() == MaisVelho)
		{
			cout << "-------------------------" << endl;
			cout << "Nome: " << arrayC[y].getNome() << endl;
			cout << "Email: " << arrayC[y].getEmail() << endl;
			cout << "Telefone: " << arrayC[y].getTelefone() << endl;
			cout << "-------------------------" << endl;
			
		}
		
	}
	
	return 0;
}
#include <iostream>
#include <locale.h>
#include <string>
#include <iomanip>
#include <stdlib.h>

using namespace std;


class Funcionario {
	private:
		int prontuario;
		double salario;
		string nome;
		
	public:
		void setProntuario(int prontuario) {
			this->prontuario = prontuario;
		}
		void setNome(string nome) {
			this->nome = nome;
		}
		void setSalario(double salario) {
			this->salario = salario;
		}
		
		int getProntuario() {
			return this->prontuario;
		}
		
		double getSalario() {
			return this->salario;
		}
		
		string getNome() {
			return this->nome;
		}
		
		Funcionario* Init() {
			return NULL;
		}
		
		Funcionario() {
			this->prontuario = 0;
			this->nome = "";
			this->salario = 0;
		}
		

		
};

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");
	int flag = -1;
	int prontFlag = 0;
	int counter = 0;
	double totalSal = 0;
	Funcionario arrayF[100];
	
	
	
	string nometemp;
	double salariotemp;
	int prontuariotemp;
	
	
	do {
		
		cout << "======MENU========" << endl;
		cout << "|| 0. Sair      ||" << endl;
		cout << "|| 1. Incluir   ||" << endl;
		cout << "|| 2. Excluir   ||" << endl;
		cout << "|| 3. Pesquisar ||" << endl;
		cout << "|| 4. Listar    ||" << endl;
		cout << "==================" << endl;
		
		cin >> flag;
		cout << endl;

		
		switch(flag) {
			case 0:
				flag = 0;
				system ("cls");
				cout << "Saindo...";
				break;
			case 1:
				system ("cls");
				cout << "Nome do funcionário: ";
				cin >> nometemp;
				arrayF[counter].setNome(nometemp);
				
				do {
					prontFlag = 0;
					cout << endl;
					cout << "Prontuário: ";
					cin >> prontuariotemp;
					
					
					for (int i = 0; i < 100; i++) {
							if (prontuariotemp == arrayF[i].getProntuario()) {
								cout << "Esse prontuário já está em uso, utilize outro." << endl;
								prontFlag = 0;
								break;
							}
							else {
								prontFlag = 1;
							}
						
					}
					
					arrayF[counter].setProntuario(prontuariotemp);
				}
				while(prontFlag == 0);
				
				cout << endl;
				cout << "Salário: ";
				cin >> salariotemp;
				arrayF[counter].setSalario(salariotemp);
				totalSal = totalSal + salariotemp;
				system ("cls");
				
				break;
				
			case 2:
				int procPront;
				
				system ("cls");
				cout << "Digite o número do prontuário que deseja excluir:" << endl;
				cin >> procPront;
				
				for (int cont = 0; cont < 100; cont++) {
					
					if (procPront == arrayF[cont].getProntuario() && procPront != 0) {
						arrayF[cont].setProntuario(0);
						arrayF[cont].setNome("");
						arrayF[cont].setSalario(0);
						cout << "Prontuário CB" << procPront << " apagado com sucesso!" << endl;
						break;
					}
					else if (cont == 99)
					{
						cout << "O prontuário digitado não foi encontrado!" << endl;
					}
				}
				
				break;
					
			case 3:
				int pesq;
				
				system ("cls");
				cout << "Digite o prontuário do funcionário a ser pesquisado:" << endl;
				cin >> pesq;
				cout << endl;
				
				for (int cont = 0; cont < 100; cont++) {
					
					if (pesq == arrayF[cont].getProntuario() && pesq != 0) {
						cout << "Nome: " << arrayF[cont].getNome() << endl;
						cout << "Prontuário: CB" << arrayF[cont].getProntuario() << endl;
						cout << "Salário: R$" << arrayF[cont].getSalario() << endl;
						break;
					}
					else if (cont == 99)
					{
						cout << "O prontuário digitado não foi encontrado!" << endl;
					}
				}
				
				cout << endl;
				
				break;	
			
			case 4:
				
				system ("cls");
				cout << "==== LISTA DE FUNCIONÁRIOS ====" << endl;
				cout << endl;
				
				for (int cont = 0; cont < 100; cont++) {
					
					if (arrayF[cont].getProntuario() != 0) {
						cout << "Nome: " << arrayF[cont].getNome() << endl;
						cout << "Prontuário: CB" << arrayF[cont].getProntuario() << endl;
						cout << "Salário: R$" << arrayF[cont].getSalario() << endl << endl;
						break;
					}
					else if (cont == 99)
					{
						cout << "Não há funcionários para listar!" << endl;
						cout << endl;
						cout << endl;
					}
				}
				cout << endl;
				cout << "Valor total de salários: R$" << fixed << setprecision(2) << totalSal << endl;
				
				break;
			
			default:
				system ("cls");
				cout << "Opção inválida!" << endl;
				break;
		}
		counter++;
	}
	while(flag != 0);
	
	return 0;

}
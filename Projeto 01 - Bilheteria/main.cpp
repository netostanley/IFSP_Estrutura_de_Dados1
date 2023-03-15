#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;

	const int linhas = 15;
	const int colunas = 40;
	int lugaresDisponiveis = linhas * colunas;
	string mapa[linhas][colunas];
	int fileira;
	int poltrona;
	int opcao;
	double preco;
	double faturamentoTotal = 0;
	int lugaresOcupados = 0;
	
	
	void mostrarMapa() 
	{
		cout << "		   ===================== 		   " << endl;
		cout << "		       MAPA DA SALA                " << endl;
		cout << "		   =====================		   " << endl;
		
		for (int i = 0; i < linhas; i++) 
		{
			for (int j = 0; j < colunas; j++) 
			{
				cout << mapa[i][j] << ". ";	
			}
			cout << endl;	
		}
		
		cout << endl;
		cout << "LEGENDA: " << endl;
		cout << " . <- vazio" << endl;
		cout << " # <- ocupado" << endl;
	}
	
	void reservarLugar() 
	{
	  if (fileira < 0 || fileira > linhas || poltrona < 0 || poltrona > colunas) {
	    cout << "Linha ou coluna inválida." << endl;
	  } 
	  else if (mapa[fileira][poltrona] == "# ") {
	    cout << "Lugar já está ocupado." << endl;
	  } 
	  else {
	    mapa[fileira-1][poltrona-1] = "# ";
	    lugaresDisponiveis--;
	    lugaresOcupados = lugaresOcupados++;
	    cout << endl;
	    cout << "Lugar reservado com sucesso." << endl;
	  }
	}
	
	void faturamento()
	{
		
		
		cout << "Qtde de lugares ocupados:			" << lugaresOcupados << endl;
		cout << "Valor da bilheteria:			R$" << faturamentoTotal << endl;
	}

int main()
{
	
	do {
		cout << endl;
		cout << "Selecione uma opção:" << endl;
		cout << "0. Finalizar" << endl;
		cout << "1. Reservar poltrona" << endl;
		cout << "2. Mapa de ocupação" << endl;
		cout << "3. Faturamento" << endl;
		cin >> opcao;

		
		
		switch(opcao)
		{
		case 0:
			cout << endl;
			cout << "Saindo... Até mais =)" << endl;
			cout << endl;
			
			break;
		case 1:
			system ("cls");
			mostrarMapa();
			
				cout << endl;
				cout << endl;
				cout << "Escolha uma fileira: ";
				cin >> fileira;
				cout << "Escolha uma poltrona: ";
				cin >> poltrona;
				
				reservarLugar();
			
			break;
		case 2:
			cout << endl;
			mostrarMapa();
			
			break;
		case 3:
			system ("cls");
			faturamento();
			
			break;
		default:
			cout << endl;
			cout << "Opçao invalida. Tente novamente: " << endl;
			cin >> opcao;
			break;
		}
		
		
		
	} while(opcao!=0);
	
	
	
	
	return 0;
}
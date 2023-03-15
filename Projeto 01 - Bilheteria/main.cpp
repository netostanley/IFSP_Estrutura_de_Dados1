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
    
	void iniciaMapa() 
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
	}
	
	void mostrarMapa() 
	{
		cout << "		   ===================== 		   " << endl;
		cout << "		       MAPA DA SALA                " << endl;
		cout << "		   =====================		   " << endl;
		
		for (int i = 0; i < linhas; i++) 
		{
			for (int j = 0; j < colunas; j++) 
			{		
				if(mapa[i][j] == "# ")
				{
					cout << mapa[i][j];
				}
				else
				{
					cout << mapa[i][j] << ". ";
				}
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
	  else if (mapa[fileira-1][poltrona-1] == "# ") {
	    cout << "Lugar já está ocupado." << endl;
	  } 
	  else {
	    mapa[fileira-1][poltrona-1] = "# ";
	    lugaresDisponiveis--;
	    lugaresOcupados++;
	    cout << endl;
	    cout << "Lugar reservado com sucesso." << endl;
	    
	    if (fileira-1 >= 0 && fileira-1 <= 5){
			faturamentoTotal = faturamentoTotal + 50;
		}
		else{
			if (fileira-1 > 5 && fileira-1 <= 10){
				faturamentoTotal = faturamentoTotal + 30;
			}
			else{
				if(fileira-1 > 10 && fileira-1 <= 15){
					faturamentoTotal = faturamentoTotal + 15;
				}
			}
		}
	  }
	}
	
	void faturamento()
	{
		cout << "Qtde de lugares ocupados:			" << lugaresOcupados << endl;
		cout << "Valor da bilheteria:			R$" << faturamentoTotal << endl;
	}

int main()
{
	
	iniciaMapa();
	
	do {
		cout << endl;
		cout << "Selecione uma opção:" << endl;
		cout << "0. Finalizar" << endl;
		cout << "1. Reservar poltrona" << endl;
		cout << "2. Mapa de ocupação" << endl;
		cout << "3. Faturamento" << endl;
		cout << endl;
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
			mostrarMapa();
			
				cout << endl;
				cout << endl;
				
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
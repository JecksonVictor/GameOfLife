#include <iostream>
#include <cstring>
#include <fstream>
#include <Colonia.h>

using namespace std;
int main(int argc, char const *argv[])
{ 
	char c;
	ifstream myfile;
	myfile.open (argv[1]);
	if (myfile.is_open()){
		int linhas, colunas;
		myfile >> linhas;
		myfile >> colunas;

		char symb;
		myfile >> symb;

		char got;
		Colonia life(linhas, colunas);
		for (int i = 0; i < linhas; ++i){
			for (int j = 0; j < colunas; ++j)			{
				myfile >> got;
				if (got == symb){
					//life.setAlive(i,j);
				}
			}
		}
		myfile.close();

		string namefile;
		cout << "Defina o nome do arquivo de saída: ";
		getline(cin, namefile);
		bool running = true;
		int geracao = 1;
		while (running){
			cout << geracao << "ª Geração" << endl;
			//cout << life;
			//life.update();
			//if (life.extinct() == true){
				//running = false;
				//cout << "Colonia instinta" << endl;
			//}
			//if (life.stable() == true){
				//running = false;
				//cout << "Colonia estável" << endl;
			//}
			//outputIt()
			geracao++;
			cout << "Digite algo para continuar, alt+z para sair...";
			string k;
			getline(cin, k);
		}
	}
	return 0;
}
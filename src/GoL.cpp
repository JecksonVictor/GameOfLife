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
		unsigned int linhas = myfile.get(linhas);
		myfile.get(c);
		unsigned int colunas = myfile.get(colunas);
		myfile.get(c);
		char symb = myfile.get(symb);
		myfile.get(c);
	}
	/*

	if (myfile.is_open()){
		unsigned int linhas = myfile.get(linhas);
		myfile.get(c);
		unsigned int colunas = myfile.get(colunas);
		myfile.get(c);
		char symb = myfile.get(symb);
		myfile.get(c);

		Colonia life(linhas, colunas);
		
		for (auto i(0u); i<linhas; ++i){
			for (auto j(0u); j<colunas+1; ++j){
				myfile.get(c);
				if (c == symb){
					life.setAlive(i,j);
				}
			}
		}
		myfile.close();
	}*/
	return 0;
}
#include <iostream> /*! std::cout */
#include <cstring> /*! string */
#include <fstream>/*! fstream | ofstream */
#include <Colonia.h> /*! Matrix Class & methods */

using namespace std; /*! namespace */

/*! Project main function */
int main(int argc, char const *argv[]) { 
	ifstream myfile; /*! Cria myfile como arquivo de leitura */
	myfile.open (argv[1]); /*! Abre argumento 1 em myfile */
	if (myfile.is_open()){ /*! Se abrir for verdade, então: */
		int linhas, colunas;
		/*! Lê linhas e colunas do arquivo */
		myfile >> linhas; 
		myfile >> colunas;

		char symb; /*! Simbolo usado para padronizar a leitura */
		myfile >> symb;

		char got; /*! Simbolos encontrados na leitura */

		Colonia life(linhas, colunas);/*! Cria Colonia da execução */

		/*! Lê todas as células vivas da base e as coloca como vivas na Colonia */
		for (int i = 0; i < linhas; ++i){
			for (int j = 0; j < colunas; ++j){
				myfile >> got;
				if (got == symb){
					life.setAlive(i,j);
				}
			}
		}
		myfile.close(); /*! Fecha conexão com a base */
		
		/*! Lê o nome do arquivo a ser salvo e salva-o em namefile */
		string namefile;
		cout << "Defina o nome do arquivo de saída: ";
		getline(cin, namefile);

		/*! Corrige o nome do arquivo para o colocar na pasta output como um txt*/
		string outname = "output/"; /*!  */
		outname += namefile += ".txt";

		/*! Abre a conexão com o arquivo a ser salvo */
		ofstream myfile;
		myfile.open (outname, ofstream::app);

		bool running = true; /*! Variável do loop */
		int geracao = 1; /*! Número da geração >= 1 */

		/*! Enquanto Colonia life != (extinta|estável|parada) */
		while (running){
			cout << geracao << "ª Geração" << endl;
			cout << life;

			Colonia copy(linhas, colunas);
			copy = life;
			/*! Realiza update */
			life.update(copy);

			/*! Se Colonia == (Extinta|Estável) -> Parar o while e informar ocorrência */
			if (life.extinct() == true){
				cout << "Colonia Extinta" << endl;
				return 0;
			}/*
			if (life.stable() == true){
				running = false;
				cout << "Colonia estável" << endl;
			}/*
			
			/*! Output in file */
			myfile << geracao << "ª geracao" << endl;
			myfile << life;
			geracao++;

			/*! Verifica se para ou continua */
			cout << "Tecle Enter para continuar, alt+z para sair...";
			string k;
			getline(cin, k);
		}
	}
	return 0; /*! Retorno 0 - main */
}
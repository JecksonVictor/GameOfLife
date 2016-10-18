#include <iostream> /*! ostream */
#include <vector>

using namespace std;

/*! Classe principal do projeto */
class Colonia {
	/*!  private space*/
private:
	int row; /*! Linhas da matriz*/
	int col; /*! Colunas da matriz */
	/*vector<vector<bool>> Life; /*! Ponteiro para ponteiro da variável booleana que guarda o status de cada célula
				* true -> viva
				* false -> morta
				*/
	bool **Life;


	/*!  public space*/
public:
	/*! Constructors */
	/*Colonia(){
		Life = NULL;
		row = 0;
		col = 0;
	}*/
	Colonia(int x, int y){
		row = y+2; //Cria bordas horizontais
		col = x+2; //Cria bordas verticais


		//std::vector<std::vector<bool>> Life;
		Life = new bool*[row]; /*! Aloca memória para uma linha */
		for (int i=0; i<row; ++i){
			Life[i] = new bool[col]; /*! Aloca memória para uma coluna */
			for (int j=0; j<col; ++j){
				//Life[i][j] = false; // Inicializa todos os mombros da matriz com 'false'
			}
		}
	}
	/*! Destructor */
	~Colonia(){
		/*for (int i = 0; i < row; ++i){
			delete Life[i]; ! Libera todas as linhas 
		}
		delete Life; /*! Deleta a variável */
		//delete Life[0];
	}
	
	/*! Poe uma célula com o status true */
	void setAlive(int x, int y){
		Life[x+1][y+1] = true; //(x+1 | y+1) Burlam a borda
	}

	/*! Poe uma célula com o status false */
	void setDead(int x, int y){
		Life[x+1][y+1] = false;//(x+1) | y+1) Burlam a borda
	}

	/*! Aplica as regras do jogo, criando uma tabela cópia para verificar os valores
	* Verifica e conta seus vizinhos, e no fim aplica ou não os métodos setAlive ou SetDead
	*/
	void update(const Colonia & other){
		//bool **copyLife = Life;

		for (int i = 1; i < row-1; ++i){
			for (int j = 1; j < col-1; ++j){
				int neighbors = 0;

				if (other.Life[i-1][j-1] == true){
					neighbors++;
				}
				if (other.Life[i-1][j] == true){
					neighbors++;
				}
				if (other.Life[i-1][j+1] == true){
					neighbors++;
				}
				if (other.Life[i][j-1] == true){
					neighbors++;
				}
				if (other.Life[i][j+1] == true){
					neighbors++;
				}
				if (other.Life[i+1][j-1] == true){
					neighbors++;
				}
				if (other.Life[i+1][j] == true){
					neighbors++;
				}
				if (other.Life[i+1][j+1] == true){
					neighbors++;
				}
				
				if (other.Life[i][j] == true){
					if (neighbors > 3){
						this->Life[i][j] = false;
					} else if (neighbors < 2){
						this->Life[i][j] = false;
					}
				} else {
					if (neighbors == 3){
						this->Life[i][j] = true;
					}
				};
			};
		}
	}

	/*! Verifica se todas as células estão mortas, se sim, a classifica como extinta */
	bool extinct(void){
		for (int i = 1; i < this->row-1; ++i){
			for (int j = 1; j < this->col-1; ++j){
				if (Life[i][j] == true){
					return false;
				}
			}
		}
		return true;
	}

	/*! Utiliza o atributo -friend para acessar os dados e repassa-los ao std::ostream */
	friend std::ostream & /*! friend ostream */
		operator<<(std::ostream & os,
			const Colonia & table) /*! friend == table */
		{
			for (auto i(1); i<table.row-1; ++i){
				for (auto j(1); j<table.col-1; ++j){
					if (table.Life[i][j] == true){
						os << "*"; /*! Imprime X para célula viva */
					} else {
						os << "."; /*! Imprime O para célula morta */
					}
				}
				os << std::endl;
			}
			os << std::endl;
		}

	/*! Sobrecarga operador de atribuição. Cria cópia de Matriz
	* ex: [this (A) = other(B)] -> A == B
	*/
	Colonia & operator = (const Colonia other){
		for (int i = 0; i < other.row; ++i)
		{
			for (int j = 0; j < other.col; ++j)
			{
				Life[i][j] = other.Life[i][j];
			}
		}
		return *this;
		/*row = other.row; /*! Copia número de linhas*/
		/*col = other.col; /*! Copia número de colunas */
		/*Life = new bool*[other.row];
		for (int i = 0; i < other.row; ++i)
		{
			Life[i] = new bool[other.col];
			for (int j = 0; j < other.col; ++j)
			{
				Life[i][j] = other.Life[i][j];
			}
		}
		return *this;
		/*for (int i=0; i<other.row; ++i){
			std::copy(&other.Life[i], &other.Life[other.row], &this->Life[i]); /*! std::copy copia todas as linhas de other para this, de 0 até other->row */
		
	}
};
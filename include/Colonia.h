#include <iostream> /*! ostream */

/*! Classe principal do projeto */
class Colonia {
	/*!  private space*/
private:
	int row; /*! Linhas da matriz*/
	int col; /*! Colunas da matriz */
	bool **Life; /*! Ponteiro para ponteiro da variável booleana que guarda o status de cada célula
				* true -> viva
				* false -> morta
				*/


	/*!  public space*/
public:
	/*! Constructors */
	Colonia(){
		Life = NULL;
		row = 0;
		col = 0;
	}
	Colonia(int x, int y){
		row = y+2; //Cria bordas horizontais
		col = x+2; //Cria bordas verticais

		Life = new bool*[row]; /*! Aloca memória para uma linha */
		for (int i=0; i<row; ++i){
			Life[row] = new bool[col]; /*! Aloca memória para uma coluna */
			for (int j=0; j<col; ++j){
				//Life[i][j] = false; // Inicializa todos os mombros da matriz com 'false'
			}
		}
	}
	/*! Destructor */
	~Colonia(){
		for (int i = 0; i < row; ++i){
			delete Life[i]; /*! Libera todas as linhas */
		}
		delete Life; /*! Deleta a variável */
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
	void update(void){
		/*Colonia copyLife (this->row, this->col);
		for (int i = 1; i < this->row-1; ++i){
			for (int j = 1; i < this->col-1; ++j){
				unsigned int neighbors;
				if (copyLife[i-1][j-1] == true)
					++neighbors;
				if (copyLife[i-1][j] == true)
					++neighbors;
				if (copyLife[i-1][j+1] == true)
					++neighbors;

				if (copyLife[i][j-1] == true)
					++neighbors;
				if (copyLife[i-1][j+1] == true)
					++neighbors;

				if (copyLife[i+1][j-1] == true)
					++neighbors;
				if (copyLife[i+1][j] == true)
					++neighbors;
				if (copyLife[i+1][j+1] == true)
					++neighbors;

				if (this[i][j] == true){
					if (neighbors > 3){
						setDead(i, j);
					}
					if (neighbors < 2){
						setDead(i, j);
					}
				}
				if (this[i][j] == false){
					if (neighbors == 3){
						setAlive(i, j);
					}
				}
			}
		}*/
	}

	/*! Verifica se todas as células estão mortas, se sim, a classifica como extinta */
	bool extinct(void){
		for (int i = 1; i < this->row-1; ++i){
			for (int j = 1; i < this->col-1; ++j){
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
					if (/*table.Life[i][j] == true*/ 1){
						os << "X"; /*! Imprime X para célula viva */
					} else {
						os << "O"; /*! Imprime O para célula morta */
					}
				}
				os << std::endl;
			}
			os << std::endl;
		}

	/*! Sobrecarga operador de atribuição. Cria cópia de Matriz
	* ex: [this (A) = other(B)] -> A == B
	*/
	Colonia & operator = (const Colonia & other){
		this->row = other.row; /*! Copia número de linhas*/
		this->col = other.col; /*! Copia número de colunas */
		for (int i=0; i<other.row; ++i){
			std::copy(&other.Life[i], &other.Life[other.row], &this->Life[i]); /*! std::copy copia todas as linhas de other para this, de 0 até other->row */
		}
	}
};

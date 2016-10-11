#include <iostream>

class Colonia {
private:
	int row;
	int col;
	bool **Life;
public:
	Colonia(int x, int y){
		row = y+2;
		col = x+2;

		Life = new bool*[row];
		for (int i=0; i<row; ++i){
			Life[row] = new bool[col];
			for (int j=0; j<col; ++j){
				//Life[i][j] = false;
			}
		}
	}
	~Colonia(){
		for (int i = 0; i < row; ++i){
			delete Life[i];
		}
		delete Life;
	}
	
	void setAlive(int x, int y){
		Life[x+1][y+1] = true;
	}

	void setDead(int x, int y){
		Life[x+1][y+1] = false;
	}

	void update(void){
		Colonia copyLife(Life.row, Life.col);
		for (int i = 1; i < Life.row-1; ++i){
			for (int j = 1; i < Life.col; ++j){
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

				if (copyLife[i][j] == true){
					if (neighbors > 3){
						setDead(i, j);
					}
					if (neighbors < 2){
						setDead(i, j);
					}
				}
				if (copyLife[i][j] == false){
					if (neighbors == 3){
						setAlive(i, j);
					}
				}
			}
		}
	}

	friend std::ostream &
		operator<<(std::ostream & os, const Colonia & table){
			for (auto i(1); i<table.row-1; ++i){
				for (auto j(1); j<table.col-1; ++j){
					if (table.Life[i][j] == true){
						os << "X";
					} else {
						os << "O";
					}
				}
				os << std::endl;
			}
			os << std::endl;
		}
};

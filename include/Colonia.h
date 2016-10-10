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
		for (auto i(0u); i<row; ++i){
			Life[row] = new bool[col];
			for (auto j(0u); j<col; j++){
				Life[i][j] = false;
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

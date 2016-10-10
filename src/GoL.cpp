#include <iostream>

class Colonia
{
private:
	using size = unsigned int;
	size row;
	size col;
	bool **Life;
public:
	Colonia(unsigned int x, unsigned y){
		row = y+2;
		col = x+2;

		Life = new bool[row][col]
		for (auto i(0u); i<row; ++i){
			for (auto j(0u); j<col; j++){
				Life[i][j] = false;
			}
		}
	}
	~Colonia(){
		delete [][] Life;
	}
	
	void setAlive(unsigned int x, unsigned int y){
		Life[x+1][y+1] = true;
	}

	friend std::ostream &
		operator<<(std::ostream & os, const Colonia & table){
			for (auto i(1); i<table.row-1; ++i){
				for (auto j(1); j<table.col-1; ++j){
					if (table[i][j] == true){
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

int main(int argc, char const *argv[])
{
	
	return 0;
}
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void initField(int** matrix, int w, int h) {
	int x = rand() % 4, y = rand() % 4;
	
	for(int row = 0; row < h; ++row){
		matrix[row] = new int[w];
		for(int col = 0; col < w; ++col){
			if(row == y && col == x){
				matrix[row][col] = 2;
			}
			else {
				matrix[row][col] = 0;
			}
		}	
	}
}

void displayField(int** matrix, int w, int h){
	for(int i = 0; i < w*8 + 1; ++i)
		std::cout << "_";
	std::cout << std::endl;
	for(int row = 0; row < h; ++row){
		std::cout << "|";
		for(int col = 0; col < w; ++col){
			if(matrix[row][col] == 0){
				std::cout << '\t';
			}
			else {
				std::cout << matrix[row][col] << '\t';
			}
			std::cout << "|";
		}
		std::cout << std::endl;
		for(int i = 0; i < w*8 + 1; ++i)
			std::cout << "_";
		std::cout << std::endl;
	}
}

void deleteMatrix(int** matrix, int w, int h) {
	for(int i = 0; i < h; ++i){
		delete matrix[i];
	}
	delete matrix;
}

int main() {
	srand(time(0));
	int** matrix = new int*[4];
	initField(matrix, 4, 4);
	while(true){
		displayField(matrix, 4, 4);
		
		system("cls");
	}
	
	deleteMatrix(matrix, 4, 4);
	_getch();	
	return 0;
}

// keystrokes
// All come with -32 before, then the number of the key (arrows)
// Up: 72, Down: 80, Left: 75, Right: 77 
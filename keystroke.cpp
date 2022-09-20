#include <iostream>
#include <conio.h>

int main() {
	while(char c = _getch()){
		std::cout << (int)c << std::endl;
	}
	_getch();
	return 0;
}
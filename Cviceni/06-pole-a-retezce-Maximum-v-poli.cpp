#include <iostream>
#include <string>
using namespace std;


int main() {
	int pole[] = { 10,5,23,8,12 };

	int velikost = sizeof(pole) / sizeof(pole[0]);

	int indexNejvetsiho = 0;
	for (int i = 1; i < velikost; i++) {
		if (pole[i] > pole[indexNejvetsiho]) {
			indexNejvetsiho = i;
		}
	}

	for (int i = 0; i < velikost; i++) {
		if (i == indexNejvetsiho) {
			cout << "Nejvetsi cislo je: " << pole[i] << endl;     // pokud místo pole dáme pouze i, vypíše nám to souřadnici čísla 23 - čili 2
		}
	}

	return 0;	
}

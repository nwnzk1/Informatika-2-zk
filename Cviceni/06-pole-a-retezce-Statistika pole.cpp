#include <iostream>
#include <string>
using namespace std;

int main() {
	int pole[5];
	int soucet = 0;
	int prumer = 0;

	for (int i = 0; i < 5; i++) {
		cout << "Zadej cisla: ";
		cin >> pole[i];

		soucet += pole[i];
	}

	prumer = soucet / 5;

	cout << "Ulozena cisla: ";
	for (int i = 0; i < 5; i++) {
		cout << pole[i] << " ";
	}

	cout << "\nSoucet: " << soucet << endl;
	cout << "Prumer: " << prumer << endl;
	
	
	return 0;	
}

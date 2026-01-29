#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main() {

	// VYTVOŘENÍ SOUBORU POMOCÍ OFSTREAM + KONTROLA OREVŘENÍ SOUBORU
	ofstream outFile("denicek.txt");
	if (!outFile.is_open()) {
		cerr << "Nelze otevrit soubor" << endl;
		return 1;
	}
	
	// ZAPIS DAT DO SOUBORU POMOCÍ KONZOLE
	string zapis_dat;

	cout << "Zapis si poznamky do denicku: " << endl;

	// WHILE SMYČKA PRO PSANÍ VĚCI - POKUD NAPÍŠU KONEC SKONČÍ NÁM A PROGRAM SE ZAVŘE
	while (getline(cin, zapis_dat)) {
		if (zapis_dat == "KONEC") {
			break;
		}
		// ZAPISOVANI DAT DO SOUBORU
		outFile << zapis_dat << endl;
	}

	//ZAVŘENÍ SOUBORU
	outFile.close();
	cout << "Ulozeno" << endl;
	return 0;
}

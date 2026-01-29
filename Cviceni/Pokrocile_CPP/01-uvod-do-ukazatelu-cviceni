#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
	
	// --- 1. a 2. část: Základy pointerů ---
	
	int cislo = 10;      // Klasická proměnná typu int

	int* pCislo;         // Deklarace pointeru (ukazatele) na typ int

	pCislo = &cislo;     // Do pointeru pCislo uložíme ADRESU proměnné 'cislo' (& je adresní operátor)
	*pCislo = 20;        // Dereference: Přes pointer přistoupíme k hodnotě na dané adrese a změníme ji na 20
	                     // Tímto se změnila i původní proměnná 'cislo'
	

	cout << pCislo << " " << cislo << endl;     // Výpis: adresa v paměti (hexadecimálně) a aktuální hodnota (20)


	// --- 3. část: Pointerová aritmetika a pole ---
	
	int cisla[] = { 10, 20, 30 }; // Pole tří čísel

	int* pPole = cisla;           // Název pole funguje jako adresa jeho prvního prvku (index 0)

	cout << *pPole << endl;       // Vypíše hodnotu, na kterou pointer míří (10)

	

	*pPole++;                     // Inkrementace pointeru: posune pointer na další prvek v paměti (o velikost int)
	cout << *pPole << endl;       // Vypíše 20

	*pPole++;                     // Posun pointeru na poslední prvek
	cout << *pPole << endl;       // Vypíše 30
}

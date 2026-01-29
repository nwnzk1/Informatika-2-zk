#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Definice struktury, která slouží jako šablona pro data o knize
struct Kniha {
	string nazev;      // Textový řetězec pro název knihy
	string autor;      // Textový řetězec pro jméno autora
	int rok_vydani;    // Celé číslo pro rok vydání
	double cena;       // Desetinné číslo pro cenu knihy
};

// Funkce pro výpis dat jedné konkrétní knihy na obrazovku
// (Předává se referencí 'const Kniha&', aby se data nekopírovala)
void vypisKnihu(const Kniha& k) {
	cout << k.nazev << " " << k.autor << " " << k.rok_vydani << " " << k.cena << endl;
}

int main() {

	// Vytvoření pole o velikosti 3, které obsahuje objekty typu Kniha
	Kniha knihovna[3] = {
		{"Kamil", "Ja", 2023, 10000.0},
		{"Pravo", "Ja", 2021, 2330.0},
		{"Matematika", "Potok", 2018, 200.0}
	};

	// Cyklus projdoucí celé pole, který postupně vypíše všechny knihy
	for (int i = 0; i < 3; i++) {
		vypisKnihu(knihovna[i]);
	}

	// Inicializace proměnné pro uložení indexu nejdražší knihy (začínáme od nuly)
	int nejdrazsiKniha = 0;
	
	// Cyklus, který porovnává ceny všech knih v poli
	for (int i = 0; i < 3; i++) {
		// Pokud je cena aktuální knihy vyšší než cena doposud nalezené nejdražší knihy
		if (knihovna[i].cena > knihovna[nejdrazsiKniha].cena) {
			nejdrazsiKniha = i; // Aktualizace indexu nejdražší knihy
		}
	}

	// Finální výpis knihy, která byla vyhodnocena jako nejdražší
	vypisKnihu(knihovna[nejdrazsiKniha]);

	return 0; // Ukončení programu
}

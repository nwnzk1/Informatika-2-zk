#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    // Vytvoření instance ifstream pro čtení ze souboru "denicek.txt"
    ifstream file("denicek.txt");

    // Kontrola, zda se soubor podařilo úspěšně otevřít (např. zda existuje)
    if (!file.is_open()) {
        // cerr se používá pro chybové výstupy
        cerr << "Soubor nelze otevrit" << endl;
        return 1; // Ukončení programu s chybovým kódem
    }

    string radek;       // Proměnná pro dočasné uložení načteného textu
    int pocet_radku = 0; // Inicializace počitadla řádků

    // Cyklus běží, dokud getline úspěšně načte další řádek ze souboru
    while (getline(file, radek)) {
        pocet_radku++; // Inkrementace (zvýšení) čísla řádku o 1
        
        // Výpis čísla řádku následovaného dvojtečkou a obsahem řádku
        cout << pocet_radku << ": " << radek << endl;
    }

    // Po dokončení práce je slušné soubor ručně uzavřít
    file.close();

    return 0; // Úspěšné ukončení programu
}

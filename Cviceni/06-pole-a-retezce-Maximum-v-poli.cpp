#include <iostream>
#include <string>
using namespace std;

int main() {
    // 1. Inicializace pole s pěti celými čísly
    int pole[] = { 10, 5, 23, 8, 12 };

    // 2. Výpočet počtu prvků v poli
    // sizeof(pole) je celková paměť (5 * 4 bajty = 20), sizeof(pole[0]) je jeden int (4 bajty)
    // 20 / 4 = 5 prvků
    int velikost = sizeof(pole) / sizeof(pole[0]);

    // 3. Předpokládáme, že největší číslo je na začátku (index 0)
    int indexNejvetsiho = 0;

    // 4. Cyklus projde pole od druhého prvku (index 1) až do konce
    for (int i = 1; i < velikost; i++) {
        // Pokud najdeme prvek, který je větší než ten náš dosavadní "vítěz"
        if (pole[i] > pole[indexNejvetsiho]) {
            // Zapamatujeme si jeho pozici (index)
            indexNejvetsiho = i;
        }
    }

    // 5. Kontrolní cyklus pro výpis výsledku
    for (int i = 0; i < velikost; i++) {
        // Pokud narazíme na index, který jsme si uložili jako největší...
        if (i == indexNejvetsiho) {
            // Vypíšeme hodnotu na tomto indexu (v tomto případě 23)
            cout << "Nejvetsi cislo je: " << pole[i] << endl;     
            // Poznámka: Pokud bys vypsal 'i', vypíšeš pozici (2), pokud 'pole[i]', vypíšeš hodnotu (23)
        }
    }

    return 0;	
}

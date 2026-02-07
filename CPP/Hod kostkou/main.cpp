#include <iostream>   // Základní vstup a výstup (cout, cin)
#include <vector>     // Dynamické pole 'vector' - ideální pro neznámý počet prvků
#include <string>     // Práce s textovými řetězci
#include <ctime>      // Potřebné pro time(0) - inicializace náhody podle času
#include <cstdlib>    // Obsahuje funkce rand() a srand()
#include <fstream>    // Práce se soubory (zápis do statistika.txt)
#include <algorithm>  // Standardní algoritmy (zde zatím nevyužito, ale dobré mít)

using namespace std;

/**
 * Funkce simulující hody kostkou a jejich následnou analýzu
 * @param pocet_hodu - určuje, kolikrát se má "hodit"
 */
void hodKostkou(int pocet_hodu) {
    
    // 1. PŘÍPRAVA DAT (Generování)
    vector<int> hody; // Vektor pro uložení všech jednotlivých hodů (např. 1, 6, 3...)

    for (int i = 0; i < pocet_hodu; i++) {
        // rand() % 6 vrací 0 až 5. Přičtením 1 posuneme rozsah na 1 až 6.
        int vysledek_hodu = (rand() % 6) + 1;
        
        // Funkce push_back přidá hodnotu na konec dynamického pole
        hody.push_back(vysledek_hodu);
    }

    // 2. VÝPOČET ČETNOSTÍ (Jak často padla která strana)
    // Vytvoříme pole o 7 prvcích (indexy 0-6). 
    // Index 0 nepoužijeme, indexy 1-6 odpovídají stěnám kostky.
    int cetnost[7] = { 0, 0, 0, 0, 0, 0, 0 }; // Všechny čítače nastavíme na nulu

    for (int i = 0; i < hody.size(); i++) {
        int co_padlo = hody[i]; // Zjistíme, co je uloženo v historii hodů
        cetnost[co_padlo]++;    // Inkrementujeme (zvýšíme o 1) hodnotu na odpovídajícím indexu
    }

    // Výpis tabulky četností do konzole
    for (int i = 1; i <= 6; i++) {
        cout << "Cislo " << i << " padlo " << cetnost[i] << "x" << endl;
    }

    // 3. HLEDÁNÍ EXTRÉMU (Modus - nejčastější hodnota)
    int nej_cetnost = -1; // Pomocná proměnná pro ukládání rekordního počtu padnutí
    int modus = 0;        // Sem uložíme, která stěna kostky to byla
    
    for (int i = 1; i <= 6; i++) {
        // Pokud aktuální číslo padlo víckrát než doposud nalezené maximum
        if (cetnost[i] > nej_cetnost) {
            nej_cetnost = cetnost[i]; // Přepíšeme rekord
            modus = i;               // Zapamatujeme si vítězné číslo
        }
    }

    // 4. VÝPOČET PRŮMĚRU
    double celkovy_soucet = 0; // Musí být double, aby dělení nebylo celočíselné
    for (int h : hody) {
        celkovy_soucet += h; // Sečteme všechna čísla ve vektoru
    }
    
    // Průměr = součet všech hodnot / počet prvků
    double prumer = celkovy_soucet / hody.size();

    // 5. ZÁPIS VÝSLEDKŮ DO SOUBORU
    ofstream stat("statistika.txt"); // Vytvoříme (nebo přepíšeme) soubor statistika.txt
    if (stat.is_open()) {
        stat << "--- STATISTIKA HODU ---" << endl;
        stat << "Pocet hodu: " << hody.size() << endl;
        stat << "Prumer: " << prumer << endl;
        stat << "Nejcastesi cislo: " << modus << " (padlo " << nej_cetnost << "x)" << endl;
        
        stat.close(); // Důležité: zavřít soubor, aby se data korektně uložila na disk
    }
}

int main() {
    // Inicializace generátoru náhodných čísel. 
    // Bez srand(time(0)) by při každém spuštění padala stejná sekvence čísel!
    srand(time(0)); 

    // Volání naší funkce pro 50 simulovaných hodů
    hodKostkou(50);

    return 0; // Úspěšné ukončení programu
}

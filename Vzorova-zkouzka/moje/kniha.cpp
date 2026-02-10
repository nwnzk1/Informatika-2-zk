#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

/**
 * Třída reprezentující knihu.
 * Splňuje princip zapouzdření (encapsulation) - data jsou skrytá.
 */
class Kniha {
private:
    std::string nazev;
    int rok;

public:
    // Konstruktor pro inicializaci objektu
    Kniha(std::string nazev, int rok) : nazev(nazev), rok(rok) {}

    // Gettery označené jako const, protože nemění stav objektu
    std::string getNazev() const { return nazev; }
    int getRok() const { return rok; }
};

int main() {
    std::vector<Kniha> knihovna;
    std::ifstream vstupniSoubor("knihy.txt");

    // Kontrola, zda se soubor podařilo otevřít
    if (!vstupniSoubor.is_open()) {
        std::cerr << "Chyba: Soubor knihy.txt nebyl nalezen!" << std::endl;
        return 1;
    }

    std::string radek;
    // Načítání souboru řádek po řádku
    while (std::getline(vstupniSoubor, radek)) {
        if (radek.empty()) continue; // Přeskočení prázdných řádků

        std::stringstream ss(radek);
        std::string rokStr, nazev;

        // Předpokládaný formát: "rok;název"
        // getline s oddělovačem ';' načte rok, zbytek řádku je název
        if (std::getline(ss, rokStr, ';') && std::getline(ss, nazev)) {
            try {
                int rok = std::stoi(rokStr);
                knihovna.emplace_back(nazev, rok);
            }
            catch (const std::exception& e) {
                std::cerr << "Chyba při parsování řádku: " << radek << std::endl;
            }
        }
    }
    vstupniSoubor.close();

    /**
     * Algoritmus: Řazení (Sorting)
     * Používáme std::sort z knihovny <algorithm>.
     * Jako třetí parametr předáváme lambda funkci, která definuje kritérium řazení.
     */
    std::sort(knihovna.begin(), knihovna.end(), [](const Kniha& a, const Kniha& b) {
        return a.getRok() < b.getRok(); // Od nejstarší po nejnovější
        });

    /**
     * Výstup: Filtrování a zápis do souboru
     */
    std::ofstream vystupniSoubor("vyber.txt");
    if (vystupniSoubor.is_open()) {
        for (const auto& kniha : knihovna) {
            // Podmínka: pouze knihy vydané po roce 2000
            if (kniha.getRok() > 2000) {
                vystupniSoubor << kniha.getRok() << ": " << kniha.getNazev() << std::endl;
            }
        }
        vystupniSoubor.close();
        std::cout << "Zpracování dokončeno. Výsledek uložen do vyber.txt." << std::endl;
    }
    else {
        std::cerr << "Chyba: Nepodařilo se vytvořit výstupní soubor." << std::endl;
        return 1;
    }

    return 0;
}

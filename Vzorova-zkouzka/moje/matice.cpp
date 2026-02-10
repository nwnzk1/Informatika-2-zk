#include <iostream>

/**
 * Tento program demonstruje manuální správu paměti na haldě (heap).
 * Budeme pracovat s maticí o rozměrech R x S.
 */

int main() {
    int radky, sloupce;

    // 1. ZÍSKÁNÍ ROZMĚRŮ OD UŽIVATELE
    std::cout << "Zadejte pocet radku: ";
    std::cin >> radky;
    std::cout << "Zadejte pocet sloupcu: ";
    std::cin >> sloupce;

    // Validace vstupu
    if (radky <= 0 || sloupce <= 0) {
        std::cerr << "Rozmery musi byt kladna cisla!" << std::endl;
        return 1;
    }

    // 2. DYNAMICKÁ ALOKACE PAMĚTI
    // Nejdříve vytvoříme pole ukazatelů (každý prvek ukazuje na jeden budoucí řádek)
    // int** matice je "ukazatel na ukazatel na int"
    int** matice = new int*[radky];

    // Pro každý řádek musíme alokovat samostatné pole pro celá čísla
    for (int i = 0; i < radky; ++i) {
        matice[i] = new int[sloupce];
    }

    std::cout << "\n--- Naplneni matice ---\n";

    // 3. NAPLNĚNÍ MATICE A VÝPOČET SOUČTŮ
    for (int i = 0; i < radky; ++i) {
        int soucetRadku = 0;
        std::cout << "Radek " << i + 1 << ":" << std::endl;

        for (int j = 0; j < sloupce; ++j) {
            std::cout << "  Zadejte prvek [" << i << "][" << j << "]: ";
            std::cin >> matice[i][j];
            
            // Průběžně přičítáme k součtu aktuálního řádku
            soucetRadku += matice[i][j];
        }

        // Výpis součtu pro konkrétní řádek
        std::cout << ">> Soucet " << i + 1 << ". radku je: " << soucetRadku << "\n\n";
    }

    // 4. ÚKLID (DEALOKACE) - KLÍČOVÁ ČÁST
    /**
     * Paměť musíme uvolňovat v OPAČNÉM pořadí, než jsme ji alokovali.
     * Kdybychom nejdříve smazali 'matice', ztratili bychom ukazatele na 
     * jednotlivé řádky a paměť by nešla uvolnit (Memory Leak).
     */
    
    // Nejdříve uvolníme každý jednotlivý řádek (pole intů)
    for (int i = 0; i < radky; ++i) {
        delete[] matice[i]; 
    }

    // Nakonec uvolníme hlavní pole ukazatelů
    delete[] matice;

    // Pro jistotu nastavíme na nullptr, abychom na uvolněnou paměť omylem nesahali
    matice = nullptr;

    std::cout << "Pamet byla uspesne uvolnena. Program konci." << std::endl;

    return 0;
}

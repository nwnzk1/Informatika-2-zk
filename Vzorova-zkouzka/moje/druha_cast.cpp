#include <iostream>
#include <vector>
#include <random>    // Moderní knihovna pro náhodná čísla
#include <algorithm> // Pro funkce jako min_element nebo max_element
#include <iomanip>   // Pro formátování výstupu (setprecision)

int main() {
    // --- 1. INICIALIZACE A GENEROVÁNÍ HODNOT ---
    
    const int POCET_MERENI = 100;
    const int MIN_TEPLOTA = -10;
    const int MAX_TEPLOTA = 35;

    // Inicializace generátoru (Mersenne Twister) pomocí seedu ze zařízení
    std::random_device rd;
    std::mt19937 gen(rd());
    // Definice rovnoměrného rozdělení v uzavřeném intervalu [MIN, MAX]
    std::uniform_int_distribution<> distrib(MIN_TEPLOTA, MAX_TEPLOTA);

    std::vector<int> teploty;
    teploty.reserve(POCET_MERENI); // Optimalizace: rezervace paměti dopředu

    for (int i = 0; i < POCET_MERENI; ++i) {
        teploty.push_back(distrib(gen));
    }

    // --- 2. VÝPOČET PRŮMĚRU, MINIMA A MAXIMA ---

    double soucet = 0;
    int min = teploty[0];
    int max = teploty[0];

    for (int t : teploty) {
        soucet += t;
        if (t < min) min = t;
        if (t > max) max = t;
    }

    double prumer = soucet / POCET_MERENI;

    // --- 3. VÝPOČET MODU (ČETNOST) ---

    /**
     * Pro výpočet četnosti použijeme "pomocné pole jako čítač".
     * Jelikož teploty jsou v rozsahu -10 až 35, celkový počet možných hodnot je:
     * (35 - (-10)) + 1 = 46.
     * Index 0 v poli bude reprezentovat -10°C, index 45 bude 35°C.
     */
    int rozsah = MAX_TEPLOTA - MIN_TEPLOTA + 1;
    std::vector<int> cetnost(rozsah, 0); // Pole naplněné nulami

    for (int t : teploty) {
        // Mapování teploty na index: t - (-10) -> t + 10
        int index = t - MIN_TEPLOTA;
        cetnost[index]++;
    }

    // Najdeme nejvyšší hodnotu v poli četností
    int nejvyssiCetnost = 0;
    int modus = MIN_TEPLOTA;

    for (int i = 0; i < rozsah; ++i) {
        if (cetnost[i] > nejvyssiCetnost) {
            nejvyssiCetnost = cetnost[i];
            modus = i + MIN_TEPLOTA; // Převod indexu zpět na teplotu
        }
    }

    // --- 4. VÝSTUP DO KONZOLE ---

    std::cout << "=== VYSLEDKY MERENI TEPLOTY ===" << std::endl;
    std::cout << "Pocet mereni:      " << POCET_MERENI << std::endl;
    std::cout << "Prumerna teplota:  " << std::fixed << std::setprecision(2) << prumer << " st. C" << std::endl;
    std::cout << "Minimalni teplota: " << min << " st. C" << std::endl;
    std::cout << "Maximalni teplota: " << max << " st. C" << std::endl;
    std::cout << "Nejcastejsi (modus): " << modus << " st. C (vyskyt: " << nejvyssiCetnost << "x)" << std::endl;

    return 0;
}

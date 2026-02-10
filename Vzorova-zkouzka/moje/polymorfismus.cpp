#include <iostream>
#include <vector>
#include <string>

/**
 * BÁZOVÁ TŘÍDA: Zamestnanec
 * Slouží jako předpis (rozhraní) pro všechny typy zaměstnanců.
 */
class Zamestnanec {
protected:
    std::string jmeno;
    double plat;

public:
    // Konstruktor
    Zamestnanec(std::string jmeno, double plat) : jmeno(jmeno), plat(plat) {}

    /**
     * Virtuální destruktor je KRITICKY DŮLEŽITÝ!
     * Pokud bychom ho neměli, při mazání potomka přes ukazatel na bázovou třídu
     * by se zavolal pouze destruktor Zamestnanec a vznikl by memory leak.
     */
    virtual ~Zamestnanec() {}

    /**
     * Virtuální metoda: Klíč k polymorfismu.
     * Klíčové slovo 'virtual' říká překladači: "Pozor, tuto metodu mohou 
     * potomci přepsat a ty musíš až za běhu programu zjistit, kterou verzi zavolat."
     */
    virtual double vypocitejBonus() const {
        return 0; // Základní bonus je nula
    }

    std::string getJmeno() const { return jmeno; }
};

/**
 * POTOMEK: Programator
 * Dědí od Zamestnance (public inheritance).
 */
class Programator : public Zamestnanec {
public:
    Programator(std::string jmeno, double plat) : Zamestnanec(jmeno, plat) {}

    // Přepsání metody (override)
    // Programátor dostává bonus fixních 10 % z platu za každý odevzdaný projekt
    double vypocitejBonus() const override {
        return plat * 0.10;
    }
};

/**
 * POTOMEK: Manazer
 */
class Manazer : public Zamestnanec {
public:
    Manazer(std::string jmeno, double plat) : Zamestnanec(jmeno, plat) {}

    // Manažer má bonus vyšší, řekněme 25 % z platu
    double vypocitejBonus() const override {
        return plat * 0.25;
    }
};

int main() {
    /**
     * POLYMORFISMUS v praxi:
     * Vytvoříme vektor ukazatelů na bázovou třídu 'Zamestnanec'.
     * Do tohoto vektoru můžeme vložit Programátora i Manažera, 
     * protože oba JSOU (is-a) zaměstnanci.
     */
    std::vector<Zamestnanec*> lidi;

    lidi.push_back(new Programator("Karel", 50000));
    lidi.push_back(new Manazer("Alice", 80000));
    lidi.push_back(new Programator("Jan", 45000));

    std::cout << "--- Prehled bonusu ---" << std::endl;

    // Procházení vektoru pomocí cyklu
    for (const auto* z : lidi) {
        /**
         * Magie: C++ ví, na jaký objekt 'z' skutečně ukazuje,
         * a zavolá správnou verzi metody vypocitejBonus().
         */
        std::cout << "Zamestnanec: " << z->getJmeno() 
                  << " | Bonus: " << z->vypocitejBonus() << " Kc" << std::endl;
    }

    // ÚKLID: Jelikož jsme použili 'new', musíme použít 'delete'
    for (auto* z : lidi) {
        delete z;
    }
    lidi.clear();

    return 0;
}

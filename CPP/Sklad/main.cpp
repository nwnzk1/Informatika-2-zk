#include <iostream>   // Pro standardní vstup a výstup (cout, cin)
#include <string>     // Pro práci s textovými řetězci std::string
#include <fstream>    // Pro práci se soubory (ifstream, ofstream)
#include <sstream>    // Pro rozebírání řetězců (stringstream) - užitečné u načítání
#include <vector>     // Dynamické pole (kontejner) pro ukládání objektů
#include <algorithm>  // Pro algoritmy, konkrétně std::sort

using namespace std;

// --- DEFINICE TŘÍDY ---
class Polozka {
private:
    // Soukromé atributy - přístupné pouze uvnitř třídy
    string nazev_zbozi;
    int kod;
    double cena_za_kus;

public:
    // Implicitní konstruktor (umožňuje vytvořit prázdný objekt: Polozka p;)
    Polozka() = default;
    
    // Parametrický konstruktor pro rychlou inicializaci při vytváření
    Polozka(string nazev_zbozi, int kod, double cena_za_kus) {
        this->nazev_zbozi = nazev_zbozi;
        this->kod = kod;
        this->cena_za_kus = cena_za_kus;
    }

    // Metoda pro dodatečné nastavení dat již existujícího objektu
    void nastavData(string nazev_zbozi, int kod, double cena_za_kus) {
        this->nazev_zbozi = nazev_zbozi;
        this->kod = kod;
        this->cena_za_kus = cena_za_kus;
    }

    // Vypíše informace do konzole. 'const' zaručuje, že metoda objekt nemění.
    void vypisInfo() const { 
        cout << "Nazev zbozi: " << this->nazev_zbozi << " Kod zbozi: " << this->kod << " Cena za kus: " << this->cena_za_kus << endl;
    }

    // Getter pro cenu. 'const' je nutné, aby getter fungoval v třídění a const cyklech.
    double getCena() const {
        return cena_za_kus;
    }

    // Getter pro název, abychom k němu mohli přistupovat i mimo třídu (např. při zápisu)
    string getNazev() const {
        return nazev_zbozi;
    }
};

// --- POMOCNÉ FUNKCE ---

// Funkce pro ruční naplnění souboru daty od uživatele
void vytvorSoubor(string filename) {
    // ios::app znamená 'append' - text se přidává na konec, nepřepisuje soubor
    ofstream outFile(filename, std::ios::app);
    if (!outFile.is_open()) {
        cerr << "Nelze otevrit soubor" << endl;
        return; 
    }

    string zapis_do_souboru;
    cout << "Zapis nove zbozi (Format: Nazev Kod Cena, pro konec napis KONEC): " << endl;

    // Čteme řádky z konzole, dokud uživatel nenapíše KONEC
    while (getline(cin, zapis_do_souboru)) {
        if (zapis_do_souboru == "KONEC") {
            break;
        }
        outFile << zapis_do_souboru << endl; // Zapíšeme řádek do souboru
    }
    outFile.close(); // Soubor musíme vždy zavřít, aby se data uložila
    cout << "Ulozeno" << endl;
}

// Porovnávací funkce pro std::sort. Určuje, že chceme řadit podle ceny vzestupně.
// Parametry jsou konstantní reference (const Polozka&), aby se objekty nekopírovaly a neměnily.
bool porovnejCenu(const Polozka& a, const Polozka& b) {
    return a.getCena() < b.getCena();
}

// --- HLAVNÍ PROGRAM ---
int main() {
    // 1. Fáze: Příprava dat (vytvoření/doplnění souboru)
    vytvorSoubor("sklad.txt");

    // 2. Fáze: Načítání dat ze souboru
    ifstream inFile("sklad.txt"); // Otevření souboru pro čtení
    if (!inFile.is_open()) {
        cerr << "Nelze otevrit soubor pro cteni" << endl;
        return 1;
    }

    vector<Polozka> sklad; // Kontejner, do kterého budeme objekty ukládat
    string radek;

    // Čteme soubor řádek po řádku
    while (getline(inFile, radek)) {
        if (radek.empty()) continue; // Přeskočíme případné prázdné řádky na konci souboru

        stringstream ss(radek); // Převedeme řádek na stream, abychom z něj mohli číst jako z cin
        string nazev_zbozi;
        string sKus;            // Dočasné řetězce pro převod
        string sCena_za_kus;

        // Načítání hodnot oddělených mezerou (operátor >> automaticky dělí podle mezer)
        if (ss >> nazev_zbozi >> sKus >> sCena_za_kus) {
            int kus = stoi(sKus);               // Převod stringu na integer
            double cena_za_kus = stod(sCena_za_kus); // Převod stringu na double (stod = string to double)

            Polozka p;
            p.nastavData(nazev_zbozi, kus, cena_za_kus); // Nastavíme data do objektu
            sklad.push_back(p); // Přidáme objekt na konec vektoru
        }
    }
    inFile.close();

    // 3. Fáze: Algoritmy (Průměr a Třídění)
    double soucet = 0;
    // const auto& p zajistí, že p je reference na objekt ve vektoru (ne kopie) a je jen pro čtení
    for (const auto& p : sklad) {
        soucet += p.getCena();
    }
    
    // Ternární operátor pro ošetření dělení nulou, pokud je sklad prázdný
    double prumer = (sklad.empty()) ? 0 : soucet / sklad.size();
    cout << "Prumerna cena: " << prumer << endl;

    // std::sort seřadí vektor od begin() do end() podle funkce porovnejCenu
    sort(sklad.begin(), sklad.end(), porovnejCenu);

    // 4. Fáze: Zápis výsledků do nového souboru
    ofstream outFile("vysledek.txt"); // Otevře soubor pro zápis (existující přepíše)
    if (!outFile.is_open()) {
        cerr << "Nelze otevrit soubor pro zapis" << endl;
        return 1;
    }

    int pocet = 0;
    for (const auto& p : sklad) {
        // Filtrace: Zapíšeme jen položky s cenou vyšší než průměr
        if (p.getCena() > prumer) {
            outFile << "Nazev: " << p.getNazev() << " Cena: " << p.getCena() << endl;
            pocet++;
        }
    }

    outFile << "Celkovy pocet polozek: " << pocet << endl;
    outFile.close();

    cout << "Vysledek byl ulozen do souboru vysledek.txt" << endl;

    return 0; // Konec programu, vše proběhlo OK
}

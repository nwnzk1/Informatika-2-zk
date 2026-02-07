# Zkoušková úloha: Evidence skladu (C++)

## 📝 Zadání úkolu

Vytvořte program v jazyce C++, který bude spravovat záznamy o položkách na skladě. Program musí splňovat následující specifikace:

### 1. Objektový návrh
Vytvořte třídu `Polozka` s následující strukturou:
- **Atributy (private):** - `nazev_zbozi` (string)
  - `kod` (int)
  - `cena_za_kus` (double)
- **Metody (public):**
  - Parametrický konstruktor pro inicializaci všech hodnot.
  - Gettery pro všechny atributy (označené jako `const`).
  - Metoda `vypisInfo()` pro přehledný výpis dat do konzole.

### 2. Vstup dat (Soubor `sklad.txt`)
- Program implementuje funkci pro zápis dat do souboru uživatelem (vstup končí klíčovým slovem `KONEC`).
- Následně program načte data ze souboru `sklad.txt` do kontejneru `std::vector<Polozka>`.
- Každý řádek souboru reprezentuje jednu položku ve formátu: `Nazev_zbozi Kod Cena`.

### 3. Zpracování a Algoritmy
- **Výpočet průměru:** Program vypočítá průměrnou cenu všech načtených položek.
- **Třídění:** Seřaďte vektor položek podle **ceny vzestupně** s využitím funkce `std::sort` a vlastního komparátoru.
- **Filtrace:** Identifikujte všechny položky, jejichž cena je **vyšší než vypočítaný průměr**.

### 4. Výstup dat (Soubor `vysledek.txt`)
- Seřazené a vyfiltrované položky (dražší než průměr) uložte do souboru `vysledek.txt`.
- Na konec souboru přidejte sumární informaci o celkovém počtu vypsaných položek.
1. Zkompilujte program: `g++ -std=c++11 main.cpp -o program`
2. Spusťte binárku: `./program`
3. Postupujte podle instrukcí v konzoli.

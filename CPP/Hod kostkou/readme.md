# Zkoušková úloha: Simulace a analýza hodů kostkou (C++)

## 📝 Zadání úkolu

Vytvořte program, který simuluje hody šestistěnnou kostkou a provede vyhodnocení získaných dat.

### 1. Generování dat
- Program simuluje `N` hodů (počet definován parametrem funkce).
- Použijte funkci `rand()` s korektní inicializací pomocí `srand(time(0))`.
- Hodnoty musí být v rozmezí **1 až 6**.
- Všechny hody ukládejte do kontejneru `std::vector<int>`.

### 2. Statistická analýza
Program nad získanými daty provede následující výpočty:
- **Četnost:** Zjistí, kolikrát padla každá z hodnot (1–6). Pro efektivní výpočet využijte pole nebo vektor, kde index reprezentuje hodnotu na kostce.
- **Aritmetický průměr:** Vypočítá průměrnou hodnotu všech hodů (výsledek musí být typu `double`).
- **Modus (Nejčastější hodnota):** Určí, které číslo padlo nejvícekrát.

### 3. Výstupy
- **Konzole:** Vypište přehlednou tabulku četností pro jednotlivá čísla.
- **Soubor `statistika.txt`:** Do souboru uložte souhrnné informace:
  - Celkový počet provedených hodů.
  - Vypočítaný průměr.
  - Nejčastější hodnotu a počet jejích výskytů.

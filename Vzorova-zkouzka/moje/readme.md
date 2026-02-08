# 🎓 Příprava na zkoušku Informatika 2 (12. 2. 2026)
---

## 🔵 Část 1: C++ (Systémové programování a OOP)

### 1. Evidence a práce se soubory
**Úkol:** Vytvořte program pro správu knihovny.
- **Třída:** Vytvořte třídu `Kniha` (název, rok). Atributy budou `private`, přístupné přes `const` gettery.
- **Načítání:** Ze souboru `knihy.txt` načtěte data do `std::vector<Kniha>`. Použijte `std::stringstream` pro parsování řádků.
- **Algoritmus:** Seřaďte knihy podle roku vydání od nejstarší pomocí `std::sort`.
- **Výstup:** Uložte do souboru `vyber.txt` pouze knihy vydané po roce 2000.

### 2. Statistická analýza
**Úkol:** Simulace měření venkovní teploty.
- **Generování:** Inicializujte generátor náhody a vytvořte 100 hodnot v rozsahu -10 až 35.
- **Průměr:** Vypočítejte aritmetický průměr všech hodnot jako `double`.
- **Extrémy:** Najděte minimální a maximální teplotu.
- **Četnost:** Zjistěte, která teplota se opakovala nejčastěji (modus) pomocí pomocného pole jako čítače.

### 3. Dynamické matice
**Úkol:** Práce s dvojrozměrným polem pomocí ukazatelů.
- **Alokace:** Požádejte uživatele o rozměry. Dynamicky alokujte paměť (`int**`).
- **Výpočet:** Naplňte matici čísly a vypočítejte součet prvků v každém jednotlivém řádku.
- **Úklid:** Implementujte korektní uvolnění paměti (`delete[]`), aby nedošlo k memory leakům.

### 4. OOP a Polymorfismus
**Úkol:** Hierarchie zaměstnanců ve firmě.
- **Dědičnost:** Vytvořte bázovou třídu `Zamestnanec` s virtuální metodou `vypocitejBonus()`.
- **Specializace:** Vytvořte třídy `Programator` a `Manazer`, které tuto metodu přepíší (`override`).
- **Polymorfismus:** V `main` vytvořte vektor ukazatelů na bázovou třídu a v cyklu zavolejte výpočet bonusu.
---

## 🟡 Část 2: Python (Efektivní zpracování dat)

### 1. Analýza textu
**Úkol:** Počítadlo slov v dokumentu.
- **Preprocessing:** Načtěte text, převeďte jej na malá písmena a odstraňte interpunkci (`. , ! ?`).
- **Slovník:** Použijte `dict` pro spočítání frekvence každého slova.
- **Třídění:** Vypište Top 5 nejčastěji používaných slov seřazených sestupně.

### 2. Strukturovaná data (JSON/CSV)
**Úkol:** Transformace ceníku produktů.
- **Import:** Načtěte data ze souboru `produkty.json`.
- **Transformace:** Pomocí **List Comprehension** vytvořte nový seznam, kde u všech produktů skladem zvýšíte cenu o 15 %.
- **Export:** Výsledek uložte do nového JSON souboru.

### 3. Matematické simulace
**Úkol:** Analýza náhodných hodů kostkou.
- **Simulace:** Pomocí modulu `random` simulujte 1000 hodů dvěma kostkami.
- **Analýza:** Vypočítejte, kolikrát padl součet 7 a kolikrát 12.
- **Formátování:** Výsledky vypište přehledně pomocí funkce `enumerate()`.

### 4. OOP a ošetření chyb
**Úkol:** Simulace bankovního automatu.
- **Třída:** Vytvořte třídu `Ucet` s metodami `vlozit()` a `vybrat()`.
- **Výjimky:** Pomocí `try-except` ošetřete stavy, kdy uživatel zadá nečíselný vstup nebo se pokusí vybrat více, než je zůstatek.

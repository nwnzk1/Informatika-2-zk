import random

# --- SIMULACE ---
# Vygenerujeme 1000 hodů dvěma kostkami a uložíme jejich součty
hody = []
for _ in range(1000):
    kostka1 = random.randint(1, 6) # Náhodné číslo 1-6
    kostka2 = random.randint(1, 6) # Náhodné číslo 1-6
    hody.append(kostka1 + kostka2)

# --- ANALÝZA ---
# Spočítáme konkrétní výsledky pomocí metody .count()
soucet_7 = hody.count(7)
soucet_12 = hody.count(12)

# Připravíme si data pro přehledný výpis
vysledky = [
    ("Součet 7", soucet_7),
    ("Součet 12", soucet_12)
]

# --- FORMÁTOVÁNÍ ---
print(f"--- Výsledky simulace (1000 hodů) ---")

# enumerate(seznam, 1) nám dává index (pořadí) začínající od jedničky
for i, (nazev, hodnota) in enumerate(vysledky, 1):
    procenta = (hodnota / 1000) * 100
    print(f"{i}. {nazev}: padl {hodnota}x ({procenta:.1f} %)")

# 1. Vstupní text (můžeš si sem vložit jakýkoliv dokument)
text = """
Programování v Pythonu je skvělé. Python je jednoduchý, ale velmi mocný! 
Python se učí rychle, a proto je Python tak populární. Je to prostě skvělé? Ano, je!
"""

# --- PREPROCESSING ---

# Převod na malá písmena
text = text.lower()

# Odstranění interpunkce (. , ! ?)
for znak in ".,!?":
    text = text.replace(znak, "")

# Rozdělení textu na jednotlivá slova (podle mezer)
slova = text.split()

# --- SLOVNÍK (FREKVENCE) ---

# Použijeme dict pro spočítání výskytů
frekvence = {}

for slovo in slova:
    if slovo in frekvence:
        frekvence[slovo] += 1  # Pokud slovo už ve slovníku je, přičteme 1
    else:
        frekvence[slovo] = 1   # Pokud tam není, založíme ho s hodnotou 1

# --- TŘÍDĚNÍ ---

# Seřazení slovníku podle hodnot (četnosti) sestupně
# counts.items() nám dá dvojice (slovo, počet), které seřadíme podle druhého prvku (x[1])
serazena_slova = sorted(frekvence.items(), key=lambda x: x[1], reverse=True)

# Výpis Top 5 nejčastějších slov
print("--- Top 5 nejčastějších slov ---")
for i in range(min(5, len(serazena_slova))):
    slovo, pocet = serazena_slova[i]
    print(f"{i+1}. {slovo}: {pocet}x")

import json

# --- IMPORT ---
# Otevřeme soubor pro čtení ('r' jako read)
with open('produkty.json', 'r', encoding='utf-8') as f:
    data = json.load(f)

# --- TRANSFORMACE ---
# List Comprehension:
# Pro každý produkt (p) vytvoříme nový slovník.
# Pokud je skladem, zvýšíme cenu o 15 % (* 1.15) a zaokrouhlíme.
# Pokud není skladem, ponecháme původní data.

upravena_data = [
    {**p, "cena": round(p["cena"] * 1.15, 2)} if p["skladem"] else p 
    for p in data
]

# --- EXPORT ---
# Uložíme výsledek do nového souboru ('w' jako write)
# indent=4 zajistí, že JSON bude hezky čitelný (odsazený)
with open('produkty_aktualizovano.json', 'w', encoding='utf-8') as f:
    json.dump(upravena_data, f, indent=4, ensure_ascii=False)

print("Transformace dokončena. Nový ceník byl uložen.")

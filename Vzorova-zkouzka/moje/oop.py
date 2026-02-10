# Definice vlastní výjimky pro nedostatek peněz
class NedostatekFinanciError(Exception):
    pass

class Ucet:
    def __init__(self, zustatek=0):
        self.zustatek = zustatek

    def vlozit(self, castka):
        """Přidá peníze na účet, pokud je částka kladná."""
        if castka <= 0:
            print("Lze vkládat pouze kladné částky.")
            return
        self.zustatek += castka
        print(f"Úspěšně vloženo: {castka} Kč. Nový zůstatek: {self.zustatek} Kč.")

    def vybrat(self, castka):
        """Odečte peníze, pokud je dostatek financí, jinak vyvolá chybu."""
        if castka > self.zustatek:
            raise NedostatekFinanciError(f"Na účtu nemáte dostatek peněz (chybí {castka - self.zustatek} Kč).")
        if castka <= 0:
            print("Částka k výběru musí být kladná.")
            return
        self.zustatek -= castka
        print(f"Úspěšně vybráno: {castka} Kč. Zbývající zůstatek: {self.zustatek} Kč.")

# --- HLAVNÍ PROGRAM ---

muj_ucet = Ucet(1000)  # Začínáme s tisícovkou

while True:
    print("\n--- MENU ---")
    print("1. Zobrazit zůstatek | 2. Vložit | 3. Vybrat | 4. Konec")
    volba = input("Vyberte akci: ")

    if volba == "4":
        break

    try:
        if volba == "1":
            print(f"Aktuální zůstatek: {muj_ucet.zustatek} Kč")
        
        elif volba == "2":
            hodnota = float(input("Kolik chcete vložit? "))
            muj_ucet.vlozit(hodnota)

        elif volba == "3":
            hodnota = float(input("Kolik chcete vybrat? "))
            muj_ucet.vybrat(hodnota)

    except ValueError:
        # Ošetření případu, kdy uživatel nezadá číslo (např. písmena)
        print("Chyba: Zadejte prosím platné číslo (např. 500 nebo 150.50).")
    
    except NedostatekFinanciError as e:
        # Ošetření případu, kdy je výběr vyšší než zůstatek
        print(f"Chyba při výběru: {e}")

print("Děkujeme, že jste využili náš automat.")

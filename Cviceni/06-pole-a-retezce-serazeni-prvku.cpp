#include <iostream>
#include <algorithm> // Knihovna pro funkci sort
#include <functional> // Knihovna pro pomocné funkce jako greater nebo less

using namespace std;

int main() {
    int pole[] = {5, 2, 9, 1, 5, 6};
    
    // Výpočet počtu prvků v poli: (celková paměť v bajtech) / (paměť jednoho prvku)
    int velikost = sizeof(pole) / sizeof(pole[0]);

    // --- 1. VERZE: OD NEJVĚTŠÍHO PO NEJMENŠÍ (Sestupně) ---
    // Parametry: (začátek pole, konec pole, komparátor 'greater')
    sort(pole, pole + velikost, greater<int>()); // Funkce greater - pro celé čísla int, pro desetinné - double atd, říká že to dělej takto a ne defaultne (vzestupně)

    cout << "Sestupne: ";
    for(int i = 0; i < velikost; i++) {
        cout << pole[i] << " ";
    }
    cout << endl;

    // --- 2. VERZE: OD NEJMENŠÍHO PO NEJVĚTŠÍ (Vzestupně) ---
    // C++ standardně řadí od nejmenšího, takže stačí vynechat třetí parametr,
    // nebo pro přehlednost použít 'less<int>()'
    sort(pole, pole + velikost); // Defaultní chování je vzestupné

    cout << "Vzestupne: ";
    for(int i = 0; i < velikost; i++) {
        cout << pole[i] << " ";
    }
    cout << endl;

    return 0;
}

//První prvek na indexu 0 zůstane nedotčený:
//sort(pole + 1, pole + velikost, greater<int>()); - seřazení třeba od druhého největšího čísla.

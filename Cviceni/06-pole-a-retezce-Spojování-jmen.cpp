#include <iostream>
#include <string>
using namespace std;


int main() {
	string jmeno;
	string prijmeni;
	cout << "Zadej svoje jmeno: "; cin >> jmeno;
	cout << "Zadej svoje prijmeni: "; cin >> prijmeni;

	string celeJmeno = jmeno + " " + prijmeni;
	cout << celeJmeno << endl;
	cout << "Delka jmena je: " << celeJmeno.length() << endl;
}

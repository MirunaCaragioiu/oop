#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Eveniment {
private:
	int nrPers = 0;
	string locatie;
	float pretBilet = 0;

public:
	Eveniment() {}
	Eveniment(int nrPers, string locatie, float pretBilet) {
		this->nrPers = nrPers;
		this->locatie = locatie;
		this->pretBilet = pretBilet;
	}

	Eveniment(const Eveniment& e) {
		this->nrPers = e.nrPers;
		this->locatie = e.locatie;
		this->pretBilet = e.pretBilet;
	}

	Eveniment& operator=(const Eveniment& e) {
		this->nrPers = e.nrPers;
		this->locatie = e.locatie;
		this->pretBilet = e.pretBilet;
		return *this;
	}

	friend ofstream& operator<<(ofstream& fOut, const Eveniment& e) {
		fOut << "\n" << e.nrPers;
		fOut << "\n" << e.locatie;
		fOut << "\n" << e.pretBilet;
		return fOut;
	}

	friend ifstream& operator>>(ifstream& fIn, Eveniment& e) {
		fIn >> e.nrPers;
		fIn >> e.locatie;
		fIn >> e.pretBilet;
		return fIn;
	}

	friend ostream& operator<<(ostream& out, const Eveniment& e) {
		out << "\nNr pers: " << e.nrPers;
		out << "\nLocatie ev: " << e.locatie;
		out << "\nPret bilet: " << e.pretBilet;
		return out;
	}
};

int main() {
	ofstream g("evenimente.txt");

	Eveniment e1(10, "locatie1", 12.5);
	Eveniment e2(20, "locatie2", 25.5);
	Eveniment ve[10];
	ve[0] = e1;
	ve[1] = e2;

	//scriere vector evenimente in fisier
	int nrEvenimente = 2;
	g << nrEvenimente;
	g << e1 << e2;

	//citire vector evenimente din fisier
	int nrE;
	g.close(); //inchidere fisier pentru a-l deschide pentru citire din el
	ifstream f("evenimente.txt");
	//citire nr evenimente din fisier
	f >> nrE;
	//declarare vector alocat dinamic
	Eveniment* vectorEvenimente;
	//alocare zona de memorie in functie de nrE citit din fisier
	vectorEvenimente = new Eveniment[nrE];
	for (int i = 0; i < nrE; i++)
		f >> vectorEvenimente[i];
	cout << "\nAfisare vector evenimente citit din fisier text";
	cout << "\nNr evenimente: " << nrE;
	for (int i = 0; i < nrE; i++)
		cout << vectorEvenimente[i];
}
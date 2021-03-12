#include<iostream>
#include<string>
using namespace std;

class IPayable
{
public:
	virtual float getSalariu() = 0;
};

class Angajat :public IPayable
{
protected:
	string nume = "Anonim";
	float salariu = 0;
public:
	Angajat()
	{
		cout << "\n\nConstructor fara param ANGAJAT";
	}
	Angajat(string n, float s) :nume(n), salariu(s)
	{
		cout << "\n\nConstructor cu param ANGAJAT";
	}
	Angajat(const Angajat& a)
	{
		this->nume = a.nume;
		this->salariu = a.salariu;
	}
	Angajat& operator=(const Angajat& a)
	{
		this->nume = a.nume;
		this->salariu = a.salariu;
		return *this;
	}
	virtual float getSalariu()
	{
		cout << "\nCalcul sal angajati";
		return this->salariu;
	}
};

class Profesor :public Angajat
{
private:
	int nrOre;
public:
	Profesor()
	{
		this->nrOre = 0;
	}
	Profesor(string n, float s, int o) :Angajat(n, s)
	{
		this->nrOre = o;
	}
	Profesor(const Profesor& p) :Angajat(p)
	{
		this->nrOre = p.nrOre;
	}
	Profesor& operator=(const Profesor& p)
	{
		Angajat::operator = (p);
		this->nrOre = p.nrOre;

	}
	float getSalariul()
	{
		cout << "\n\nCalcul sal profesor";
		return this->salariu + this->nrOre * 10;
	}
};

void main()
{
	Angajat a("angajat 1", 1000);
	Profesor p("prof 1", 1200, 10);
	cout << "\n\n" << a.getSalariu();
	cout << "\n\n" << p.getSalariu();

	cout << "\n\n" << p.Angajat::getSalariu();

	//a = p;
	//cout << "\n\n" << a.getSalariu();

	cout << "\n\n\nLUCRU CU VECTORI OBIECTE ANGAJAT";
	Angajat* IAngajati = new Angajat[2];
	IAngajati[0] = a;
	IAngajati[1] = p;
	for (int i = 0; i < 2; i++)
		cout << "\n\n" << IAngajati[i].getSalariu();

	cout << "\n\n\nLUCRU CU VECTORI POINTERI ANGAJAT";
	Angajat** IAngajatiP = new Angajat * [2];
	IAngajatiP[0] = &a;
	IAngajatiP[1] = &p;
	for (int i = 0; i < 2; i++)
		cout << "\n\n" << IAngajatiP[i]->getSalariu();
}
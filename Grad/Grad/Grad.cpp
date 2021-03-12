#include<iostream>
#include<string>
using namespace std;

enum Grad
{
	ASIST = 1, LECT = 2, CONF = 3, PROF = 4
};

ostream& operator<<(ostream& out, Grad g)
{
	if (g == Grad::ASIST)
		out << "Asistent";
	else if (g == Grad::LECT)
		out << "Lector";
	else if (g == Grad::CONF)
		out << "Conferentiar";
	else out << "Profesor";
	return out;
}

class Angajat
{
private:
	string nume;
protected:
	int vechime = 0;
	int nrLocuriMunca = 0;
	string* locuriMunca = NULL;
public:
	Angajat()
	{
		cout << "\n\nApel constr fara param ANGAJAT";
		this->nume = "Anonim";
	}
	Angajat(string nume, int vechime, int nrLocuriMunca, string* locuriMunca)
	{
		cout << "\n\nApel constr cu param ANGAJAT";
		this->nume = nume;
		this->vechime = vechime;
		this->nrLocuriMunca = nrLocuriMunca;
		if (locuriMunca != NULL)
		{
			this->locuriMunca = new string[this->nrLocuriMunca];
			for (int i = 0; i < this->nrLocuriMunca; i++)
				this->locuriMunca[i] = locuriMunca[i];
		}
		else this->locuriMunca = NULL;

	}
	Angajat(const Angajat& a)
	{
		cout << "\n\nApel constr copiere ANGAJAT";
		this->nume = a.nume;
		this->vechime = a.vechime;
		this->nrLocuriMunca = a.nrLocuriMunca;
		if (a.locuriMunca != NULL)
		{
			this->locuriMunca = new string[this->nrLocuriMunca];
			for (int i = 0; i < this->nrLocuriMunca; i++)
				this->locuriMunca[i] = a.locuriMunca[i];
		}
		else this->locuriMunca = NULL;
	}
	Angajat& operator=(const Angajat& a)
	{
		cout << "\n\nOperator= ANGAJAT";
		this->nume = a.nume;
		this->vechime = a.vechime;
		this->nrLocuriMunca = a.nrLocuriMunca;
		if (this->locuriMunca != NULL)
			delete[]this->locuriMunca;
		if (a.locuriMunca != NULL)
		{
			this->locuriMunca = new string[this->nrLocuriMunca];
			for (int i = 0; i < this->nrLocuriMunca; i++)
				this->locuriMunca[i] = a.locuriMunca[i];
		}
		else this->locuriMunca = NULL;
		return *this;
	}
	~Angajat()
	{
		cout << "\n\nDestructor ANGAJAT";
		if (this->locuriMunca != NULL)
			delete[]this->locuriMunca;
	}
	friend ostream& operator << (ostream& out, const Angajat& a)
	{
		out << "\n\nNume:" << a.nume;
		out << "\nVechime:" << a.vechime;
		if (a.locuriMunca != NULL)
		{
			out << "\nLocuri munca:";
			for (int i = 0; i < a.nrLocuriMunca; i++)
				out << a.locuriMunca[i] << ", ";
		}
		return out;
	}
};

class Profesor :public Angajat
{
private:
	float salariuBaza;
	Grad grad;
public:
	Profesor() :Angajat(), salariuBaza(0)
	{
		cout << "\n\nConstructor fara param PROFESOR";
		this->grad = Grad::ASIST;
	}
	Profesor(string nume, int vechime, int nrLocuriMunca, string* locuriMunca, float s, Grad g) :Angajat(nume, vechime, nrLocuriMunca, locuriMunca)
	{
		cout << "\n\nConstructor cu param PROFESOR";
		this->salariuBaza = s;
		this->grad = g;
	}
	Profesor(Angajat& a, float s, Grad g) :Angajat(a)
	{
		cout << "\n\nConstructor de param2 PROFESOR";
		this->salariuBaza = s;
		this->grad = g;
	}
	~Profesor()
	{
		cout << "\n\nDestructor PROFESOR";
	}
	friend ostream& operator<<(ostream& out, const Profesor& p)
	{
		out << (Angajat)p;
		out << "\nSalariu baza:" << p.salariuBaza;
		out << "\nGrad didactic:" << p.grad;
		return out;
	}
};

int main()
{
	string LocuriMunca[] = { "Scoala Centrala","ASE" };
	Angajat a1("Viscol Cristian", 5, 2, LocuriMunca);
	string LocuriMunca2[] = { "Cantemir" };
	//cout << a1;

	Profesor p1("Ger marcel", 2, 1, LocuriMunca2, 1300, Grad::LECT);
	//cout << p1;

	cout << "\n\n**************";
	Profesor p2(a1, 1500, Grad::PROF);
	cout << p2;

	Angajat a2 = p2;
	cout << "\n**************************";
	cout << a1;
	cout << p1;

	return 0;

}
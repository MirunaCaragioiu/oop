#include<iostream>
#include<string>
using namespace std;
template <class T> //pot sa si templetizez mai multe clase in acelasi timp
class Colectie
{
private:
	//vector alocat dinamic de int/float/...
	T* lista;
	int nr;
public:
	Colectie()
	{
		this->lista = NULL;
		this->nr = 0;
	}
	Colectie(T* lista, int nr)
	{
		this->nr = nr;
		this->lista = new T[this->nr];
		for (int i = 0; i < this->nr; i++)
			this->lista[i] = lista[i];
	}
	~Colectie()
	{
		delete[] this->lista;
	}
	friend ostream& operator<<(ostream& out, const Colectie& c)
	{
		out << "\nColectia detine ";
		out << c.nr << "elemente";
		for (int i = 0; i < c.nr; i++)
			out << "\n" << c.lista[i];
		return out;
	}

	void sort()
	{
		T aux;
		for (int i = 0; i < this->nr - 1; i++)
			for (int j = i + 1; j < this->nr; j++)
				if (lista[i] > lista[j])
				{
					aux = lista[i];
					lista[i] = lista[j];
					lista[j] = aux;
				}
	}
};

class Produs
{
private:
	string den;
	float pret;
public:
	Produs()
	{
		this->den = "";
		this->pret = 0;
	}
	Produs(string den, float pret)
	{
		this->den = den;
		this->pret = pret;
	}
	Produs& operator=(Produs& p)
	{
		this->den = p.den;
		this->pret = p.pret;
		return *this;
	}
	friend ostream& operator<<(ostream& out, Produs& p)
	{
		out << p.den;
		out << p.pret;
		return out;
	}
	bool operator>(Produs p)
	{
		if (this->pret > p.pret)
			return 1;
		return 0;
	}


};

void main()
{
	//colectie de int-uri
	int vInt[] = { 10,20,30 };
	Colectie<int> cInt(vInt, 3);
	cout << cInt;
	//colectie de Produse
	//declarare vector cu 3 produse
	//apel constructor cu param ptr cProduse

	//colectie de Produse

	Produs v[] = { Produs("Produs1",3), Produs("Produs2",2) };
	Colectie<Produs> cProduse(v, 2);
	cout << cProduse;
	cProduse.sort();
	cout << cProduse;
}
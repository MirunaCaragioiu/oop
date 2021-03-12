#include<iostream>
#include<string>
#include<fstream>
#include<set>

using namespace std;


class ContBancar {
private:
	const int nrCont;
protected:
	float suma;
	int nrTranzactii;
	float* tranzactii;
public:
	static int nrMaxTrSapt;
	ContBancar():nrCont(0)
	{
		this->suma = 0;
		this->nrTranzactii = 0;
		this->tranzactii = NULL;
	}
	ContBancar(int nrCont, float suma,int nrTranzactii,float*tranzactii):nrCont(nrCont) 
	{
		this -> suma = suma;
		this->nrTranzactii = nrTranzactii;
		if (tranzactii != NULL)
		{
			this->tranzactii = new float[this->nrTranzactii];
			for (int i = 0; i < this->nrTranzactii; i++)
				this->tranzactii[i] = tranzactii[i];
		}
		else
			this->tranzactii = NULL;
	}


	ContBancar(const ContBancar& cb) :nrCont(cb.nrCont)
	{
		this->suma = cb.suma;
		this->nrTranzactii = cb.nrTranzactii;
		if (cb.tranzactii != NULL)
		{
			this->tranzactii = new float[this->nrTranzactii];
			for (int i = 0; i < this->nrTranzactii; i++)
				this->tranzactii[i] = cb.tranzactii[i];
		}
		else
			this->tranzactii = NULL;
	}

	ContBancar& operator=(const ContBancar& cb) 
	{
		this->suma = cb.suma;
		this->nrTranzactii = cb.nrTranzactii;
		if (this->tranzactii != NULL)
			delete[]this->tranzactii;
		if (cb.tranzactii != NULL)
		{
			this->tranzactii = new float[this->nrTranzactii];
			for (int i = 0; i < this->nrTranzactii; i++)
				this->tranzactii[i] = cb.tranzactii[i];
		}
		else
			this->tranzactii = NULL;
		return *this;
	}

	~ContBancar()
	{
		if (this->tranzactii != NULL)
			delete[]this->tranzactii;
	}

	friend ostream& operator<<(ostream &out, const ContBancar& cb)
	{
		out << "\nNr cont: " << cb.nrCont;
		out << " , suma: " << cb.suma;
		out << " , numar tranz: " << cb.nrTranzactii;
		if (cb.tranzactii != NULL)
		{
			out << ", valori: ";
			for (int i = 0; i < cb.nrTranzactii; i++)
				out << cb.tranzactii[i] << " ";
		}
		return out;
	}

	bool operator < (ContBancar cb)
	{
		if (this->nrTranzactii < cb.nrTranzactii)
			return true;
		else return false;
	}

	ContBancar operator+=(int sumaExtra)
	{
		this->suma += sumaExtra;
		return *this;
	}

	float& operator[](int index)
	{
		if (index >= 0 && index < this->nrTranzactii)
			return this->tranzactii[index];
		else
			throw exception("index invalid");
	}

	int getNrTr()
	{
		return this->nrTranzactii;
	}

	float getSuma()
	{
		return this->suma ;
	}

	void setNrTranzactii(int nr)
	{
		this->nrTranzactii = nr;
	}

	void setSuma(int suma)
	{
		this->suma = suma;
	}

	float getMaxim()
	{
		int max = 0;
	    for (int i = 0; i < this->nrTranzactii; i++)
			if (this->tranzactii[i] > max)
				max = this->tranzactii[i];

		return max;
	}

	float getTotal ()
	{
		int sum = 0;
		for (int i = 0; i < this->nrTranzactii; i++)
			sum += this->tranzactii[i];
		return sum;
	}

	void addToFile(fstream& file)
	{
		if (file.is_open())
		{

			file.write((char*)&this->nrCont, sizeof(int));
			file.write((char*)&this->suma, sizeof(float));
			file.write((char*)&this->nrTranzactii, sizeof(int));
		}
		else
			cout << "\nEroare";
	}

	void restoreFromFile(fstream&file)
	{
		if (file.is_open())
		{
			int nrCont;
			float suma;
			int nrTranzactii;
			file.read((char*)&nrCont, sizeof(int));
			file.read((char*)&suma, sizeof(float));
			file.read((char*)&nrTranzactii, sizeof(int));
		}
		else
			cout << "\nEroare la citire";
	}

	friend class Persoana;
};

class Persoana {
private:
	string nume;
	int nrConturi;
	ContBancar** listaConturi;
public:
	Persoana()
	{
		this->nume = " ";
		this->nrConturi = 0;
		this->listaConturi = NULL;
	}
	Persoana(string nume, int nrConturi, ContBancar** listaConturi)
	{
		this->nume = nume;
		this->nrConturi = nrConturi;
		if (listaConturi != NULL)
		{
			this->listaConturi = new ContBancar*[this->nrConturi];
			for (int i = 0; i < this->nrConturi; i++)
				this->listaConturi[i] = new ContBancar(*listaConturi[i]);
		}
		else
			this->listaConturi = NULL;
	}

	Persoana(const Persoana& p)
	{
		this->nume = p.nume;
		this->nrConturi = p.nrConturi;
		if (p.listaConturi != NULL)
		{
			this->listaConturi = new ContBancar*[this->nrConturi];
			for (int i = 0; i < this->nrConturi; i++)
				this->listaConturi[i] = new ContBancar(*p.listaConturi[i]);
		}
		else
			this->listaConturi = NULL;
	}

	Persoana& operator=(const Persoana& p)
	{
		this->nume = p.nume;
		this->nrConturi = p.nrConturi;
		if (this->listaConturi != NULL)
		{
			for (int i = 0; i < this->nrConturi; i++)
				delete this->listaConturi[i];
			delete[]this->listaConturi;
		}
		if (p.listaConturi != NULL)
		{
			this->listaConturi = new ContBancar*[this->nrConturi];
			for (int i = 0; i < this->nrConturi; i++)
				this->listaConturi[i] = new ContBancar(*p.listaConturi[i]);
		}
		else
			this->listaConturi = NULL;

		return*this;
	}

	~Persoana()
	{
		if (this->listaConturi != NULL)
		{
			for (int i = 0; i < this->nrConturi; i++)
				delete this->listaConturi[i];
			delete[]this->listaConturi;
		}
	}

	friend ostream& operator<<(ostream& out, const Persoana &p)
	{
		out << "\nNume: " << p.nume;
		out << " , nr conturi: " << p.nrConturi;
		out << " ,lista conturi: ";
		if (p.listaConturi != NULL)
		{
			for (int i = 0; i < p.nrConturi; i++)
				out << *p.listaConturi[i] << " ";
		}
		return out;
	}

	Persoana& operator+=(ContBancar cont) 
	{
		if (this->listaConturi != NULL) {
			ContBancar** copie = new ContBancar*[this->nrConturi + 1];
			for (int i = 0; i < this->nrConturi; i++)
				copie[i] = new ContBancar(*this->listaConturi[i]);
			for (int i = 0; i < this->nrConturi; i++) 
				delete this->listaConturi[i];
			delete[] this->listaConturi;
			this->nrConturi++;
			this->listaConturi = new ContBancar*[this->nrConturi];
			for (int i = 0; i < this->nrConturi - 1; i++)
				this->listaConturi[i] = new ContBancar(*copie[i]);
			this->listaConturi[this->nrConturi - 1] = new ContBancar(cont);
		}
		return *this;
	}

};

class Banca {
private:
	string nume=" ";
	int nrClienti=0;
public:
	Banca()
	{

	}
	Banca(string n, int nr) 
	{
		this->nume = n;
		this->nrClienti = nr;
	}
	Banca(const Banca& b)
	{
		this->nume = b.nume;
		this->nrClienti = b.nrClienti;
	}
	Banca& operator=(const Banca& b)
	{
		this->nume = b.nume;
		this->nrClienti = b.nrClienti;
		return *this;
	}
	friend ostream& operator<<(ostream& out, const Banca& b)
	{
		out << "\nNume: " << b.nume;
		out << " , nr clienti: " << b.nrClienti;
		return out;
	}

	friend bool operator<(const Banca& b1, const Banca& b2);

};

bool operator<(const Banca& b1, const Banca& b2) {
	if (b1.nrClienti < b2.nrClienti)
		return true;
	else
		return false;
}


int ContBancar::nrMaxTrSapt = 10;

void main()
{
	ContBancar c1 = ContBancar();
	cout << "\nc1: " << c1;
	ContBancar c2 = ContBancar(12, 253, 3, new float[3]{ 20,50,100 });
	cout << "\nc2: " << c2;
	ContBancar c3 = ContBancar(52, 450, 2, new float[2]{ 100,300 });
	cout << "\nc3: " << c3;
	ContBancar c4 = ContBancar(45, 700, 5, new float[5]{ 100,300,20,30,150 });
	cout << "\nc4: " << c4;
	ContBancar c5 = ContBancar(23, 863, 3, new float[3]{ 100,300,250 });
	cout << "\nc5: " << c5;

	ContBancar c6 = c5;
	cout << "\nc6: " << c6;

	c5 = c4;
	cout << "\nc5: " << c5;

	if (c2 < c3)
		cout << "\nContul c3 a avut mai multe tranzactii decat c2";
	else
		cout << "\nContul c2 a avut mai multe tranzactii decat c3";

	c3 += 10;
	cout << "\n\nc3 dupa +=" << c3;

	try {
		cout << "\n\nIndex: " << c3[1];
	}
	catch (exception e)
	{
		cout << "\n\n" << e.what();
	}

	cout << "\n\ncontul4 a avut tr max de: " << c4.getMaxim();
	cout << "\n\ncontul4 a avut tr medie de: " << c4.getTotal();

	int nr = 3;
	fstream file("conturi.bin", ios::in | ios::binary);
	file.write((char*)&nr, sizeof(int));
	c1.addToFile(file);
	c2.addToFile(file);
	c3.addToFile(file);

	ContBancar** listaconturi = new ContBancar*[4];
	listaconturi[0] = &c1;
	listaconturi[1] = &c2;
	listaconturi[2] = &c3;
	listaconturi[3] = &c4;

	Persoana p1 = Persoana("Vasile Marius", 4, listaconturi);
	cout << p1;

	//stl set
	set<Banca> setb;
	Banca b1("bnr", 2000);
	Banca b2("bcr", 3000);
	setb.insert(b1);
	setb.insert(b2);
	cout << "\n\nAfisare set: ";
	set<Banca>::iterator it;
	for (it = setb.begin(); it != setb.end(); it++)
		cout << *it;
}
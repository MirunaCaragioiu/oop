#include<iostream>
#include<string>
#include<fstream>
#include<set>
using namespace std;

class IOpera {
public:
	virtual float getNextVal() = 0;
};

class  Opera:public IOpera {
private :
	const int cod;
protected:
	string denumire;
	string autor;
public:
	int nrLicitatii;
	float* valoare;
	static int contor;
	Opera():cod(contor++)
	{
		this->denumire = " ";
		this->autor = " ";
		this->nrLicitatii = 0;
		this->valoare = NULL;
	}
	Opera(string denumire, string autor, int nrLicitatii, float* valoare) :cod(contor++)
	{
		this->denumire = denumire;
		this->autor = autor;
		this->nrLicitatii=nrLicitatii;
		if (valoare != NULL)
		{
			this->valoare = new float[this->nrLicitatii];
			for (int i = 0; i < this->nrLicitatii; i++)
				this->valoare[i] = valoare[i];
		}
		else
			this->valoare = NULL;
	}
	Opera(const Opera& o):cod(contor++)
	{
		this->denumire = o.denumire;
		this->autor = o.autor;
		this->nrLicitatii = o.nrLicitatii;
		if (o.valoare != NULL)
		{
			this->valoare = new float[this->nrLicitatii];
			for (int i = 0; i < this->nrLicitatii; i++)
				this->valoare[i] = o.valoare[i];
		}
		else
			this->valoare = NULL;
	}
	Opera& operator=(const Opera& o)
	{
		this->denumire = o.denumire;
		this->autor = o.autor;
		this->nrLicitatii = o.nrLicitatii;
		if (this->valoare != NULL)
			delete[]this->valoare;
		if (o.valoare != NULL)
		{
			this->valoare = new float[this->nrLicitatii];
			for (int i = 0; i < this->nrLicitatii; i++)
				this->valoare[i] = o.valoare[i];
		}
		else
			this->valoare = NULL;
		return*this;
	}

	~Opera()
	{
		if (this->valoare != NULL)
			delete[]this->valoare;
	}

	friend ostream& operator<<(ostream& out, const Opera& o)
	{
		out << "\nCod: " << o.cod << " ,denumire: " << o.denumire;
		out << " , autor: " << o.autor << " , nr licitatii: " << o.nrLicitatii;
		if (o.valoare != NULL)
		{
			out << " , cu valorile: ";
			for (int i = 0; i < o.nrLicitatii; i++)
				out << o.valoare[i] << " ";
		}
		return out;
	}

	bool operator<(Opera o)
	{
		if (this->nrLicitatii < o.nrLicitatii)
			return true;
		else
			return false;
	}

	float operator()(float cursValutar)
	{
		float sum = 0;
		sum = this->valoare[this->nrLicitatii] * cursValutar;
		return sum;
	}

	Opera operator += (string numeToAdd)
	{
		this->denumire.append(" ");
		this->denumire.append(numeToAdd);
		return*this;
	}

	string getAutor()
	{
		return this->autor;
	}

	void setAutor(string autor)
	{
		this->autor = autor;
	}

	string getDenumire()
	{
		return this->denumire;
	}

	void setDenumire(string denumire)
	{
		this->denumire = denumire;
	}

	float getMaxim()
	{
		float max = 0;
		for (int i = 0; i < this->nrLicitatii; i++)
			if (this->valoare[i] > max)
				max = this->valoare[i];
		return max;
	}

	float getSumaTotala()
	{
		float sum = 0;
		for (int i = 0; i < this->nrLicitatii; i++)
			sum += this->valoare[i];
		return sum;
	}

	friend ofstream& operator<<(ofstream& fOut, const Opera& o)
	{
		fOut << "\nCod: " << o.cod;
		fOut<< ",denumire: " << o.denumire;
		fOut << ",autor: " << o.autor;
		fOut<< ",nr licitatii: " << o.nrLicitatii;
		if (o.valoare != NULL)
		{
			fOut << "\n\tcu valorile: ";
			for (int i = 0; i < o.nrLicitatii; i++)
				fOut << o.valoare[i] << " ";
		}
		return fOut;
	}

	friend ifstream& operator>>(ifstream& fIn, Opera& o)
	{
		fIn >> o.denumire;
		fIn >> o.autor;
		fIn >> o.nrLicitatii;
		return fIn;
	}

	virtual float getNextVal()
	{
		return this->valoare[this->nrLicitatii-1];
	}

};


class Pictura :public Opera
{
private:
	int vechime;
protected:
	float dimensiune;

public:
	Pictura() :Opera()
	{
		this->vechime = 0;
		this->dimensiune = 0;
	}
	Pictura(string d, string a, int nr, float*val, int v, float dim) :Opera(d, a, nr, val)
	{
		this->vechime = v;
		this->dimensiune = dim;

	}
	Pictura(const Pictura& p) :Opera(p)
	{
		this->vechime = p.vechime;
		this->dimensiune = p.dimensiune;
	}
	Pictura& operator=(const Pictura& p)
	{
		Opera::operator=(p);
		this->vechime = p.vechime;
		this->dimensiune = p.dimensiune;
	}

	float getNextVal()
	{
		return this->valoare[this->nrLicitatii-1] +10;
	}
};

class Muzeu {
private:
	string nume=" ";
	int nrOpere = 0;
public:
	Muzeu() {

	}
	Muzeu(string n, int nr)
	{
		this->nume = n;
		this->nrOpere = nr;
	}
	Muzeu(const Muzeu&m)
	{
		this->nume = m.nume;
		this->nrOpere = m.nrOpere;
	}
	Muzeu& operator=(const Muzeu&m)
	{
		this->nume = m.nume;
		this->nrOpere = m.nrOpere;
		return*this;
	}

	friend ostream& operator<<(ostream& out, const Muzeu& m)
	{
		out << "\nNume muzeu: " << m.nume;
		out << " , numar opere: " << m.nrOpere;
		return out;
	}

	friend bool operator<(const Muzeu&m1, const Muzeu& m2);

};

bool operator<(const Muzeu&m1, const Muzeu& m2)
{
	if (m1.nrOpere < m2.nrOpere)
		return true;
	else
		return false;
}


int Opera::contor = 0;

void main()
{
	//constructor fara param
	Opera o1 = Opera();
	cout << "\no1: "<<o1;  //aici si la toate de genul de mai jos e operatorul <<

	//constructor cu param
	Opera o2 = Opera("MonaLisa", "Da Vinci", 4, new float[4] {12, 52, 10, 45});
	Opera o3 = Opera("Casa", "Van Gogh", 3, new float[3] {12, 52, 10});
	Opera o4 = Opera("Pomul", "Michelangelo", 5, new float[5] {12, 52, 10, 45,63});
	cout << "\no2: " << o2;
	cout << "\no3: " << o3;
	cout << "\no4: " << o4;

	//constructor de copiere
	Opera o5 = o3;
	cout << "\no5: " << o5;

	//operator =
	o4 = o2;
	cout << "\no4: " << o4;

	//operator < compara nr de licitatii ale celor 2 opere
	if (o2 < o3)
		cout << "\n\nOpera 3 a a vut mai multe licitatii decat opera 2";
	else
		cout << "\n\nOpera 2 a a vut mai multe licitatii decat opera 3";


	//operator () inmulteste ultima valoare din vector cu un curs valutar (4.7) a.i. sa rezulte valoarea in lei
	float valoareFinala = o4(4.7f);
	cout << "\n\nValoare in mld lei a operei o4 la ultima vanzare: " << valoareFinala;

	//operator += adauga sec 19 la denumirea operei 3
	o3 += "sec 19";
	cout << "\n\no3 dupa +=: " << o3;

	//apeluri get
	cout<<"\n\n"<<o2.getAutor();
	cout<<"\n\n"<<o3.getDenumire();
	//apeluri set
	o2.setAutor("VG");
	o2.setDenumire("ML");
	cout << "\n\n" << o2;

	//apel metoda getMaxim( metoda specifica clasei care determina maximul din vectorul valoare)
	cout << "\n\nOpera 3 a fost vanduta cu suma maxima de: " << o3.getMaxim();

	//apel metoda getSumaTotala ( metoda specifica clasei care determina suma din vector)
	cout << "\n\nOpera 4 are o valoare totala de vanzare de: " << o4.getSumaTotala();

	//scriere in fisier text
	ofstream g ("opere.txt");
	//int nrOpere = 5;
	//g << nrOpere;
	g << o1;
	g << o2;
	g << o3 << o4 << o5;

	//citire din fisier text (nu merge bine)
	int nrO;
	g.close();
	ifstream f("opere.txt");
	f >> nrO;
	Opera* v;
	v = new Opera[nrO];
	for (int i = 0; i < nrO; i++)
		f >> v[i];
	cout << "\n\nVector opere din fisier text: ";
	cout << "\n\nNumar opere: "<< nrO;
	for (int i = 0; i < nrO; i++)
		cout << v[i];

	Pictura p1 = Pictura("Mona", "Vinci", 3, new float[3]{ 12,14,15 },50,25);
	cout << "\n\nUrmatoarea valoare de licitatie a picturii 1: " << p1.getNextVal();

	//vector de obiecte
	Opera** lo = new Opera*[2];
	lo[0] = &o2;
	lo[1] = &p1;
	for (int i = 0; i < 2; i++)
		cout << "\n" << lo[i]->getNextVal();


	//stl set
	set<Muzeu> setm;
	Muzeu m1("Luvru", 200);
	Muzeu m2("Arta", 230);
	setm.insert(m1);
	setm.insert(m2);
	cout << "\n\nAfisare set: ";
	set<Muzeu>::iterator it;
	for (it = setm.begin(); it != setm.end(); it++)
		cout << *it;
}
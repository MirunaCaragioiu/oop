#include<iostream>
#include<string>
using namespace std;


class Apartament
{
private:
	int nrAp;
	int etaj;
	float* suprafata;
	int nrCamere;
	string proprietar;
	static float pretMp;
public:
	Apartament()
	{
		this->nrAp = 0;
		this->etaj = 0;
		this->suprafata = NULL;
		this->nrCamere = 0;
		this->proprietar = "";
	}

	Apartament(int nrAp, int etaj, int nrCamere, float* suprafata, string proprietar)
	{
		this->nrAp = nrAp;
		this->etaj = etaj;
		this->nrCamere = nrCamere;
		if (suprafata != NULL)
		{
			this->suprafata = new float[this->nrCamere];
			for (int i = 0; i < this->nrCamere; i++)
				this->suprafata[i] = suprafata[i];
		}
		else this->suprafata = NULL;
		this->proprietar = proprietar;
	}

	Apartament(const Apartament& ap)
	{
		this->nrAp = ap.nrAp;
		this->etaj = ap.etaj;
		this->nrCamere = ap.nrCamere;
		if (ap.suprafata != NULL)
		{
			this->suprafata = new float[this->nrCamere];
			for (int i = 0; i < this->nrCamere; i++)
				this->suprafata[i] = ap.suprafata[i];
		}
		else this->suprafata = NULL;
		this->proprietar = ap.proprietar;
	}

	Apartament& operator=(const Apartament& ap)
	{
		this->nrAp = ap.nrAp;
		this->etaj = ap.etaj;
		this->nrCamere = ap.nrCamere;
		if (this->suprafata != NULL)
			delete[] this->suprafata;
		if (ap.suprafata != NULL)
		{
			this->suprafata = new float[this->nrCamere];
			for (int i = 0; i < this->nrCamere; i++)
				this->suprafata[i] = ap.suprafata[i];
		}
		else this->suprafata = NULL;
		this->proprietar = ap.proprietar;
		return *this;
	}

	~Apartament()
	{
		if (this->suprafata != NULL)
			delete[] this->suprafata;
	}

	friend ostream& operator<<(ostream& out, const Apartament& ap)
	{
		out << "\nAp nr. " << ap.nrAp << ", proprietar " << ap.proprietar;
		out << ", etaj " << ap.etaj;
		if (ap.suprafata != NULL)
		{
			out << "\nSuprafete camere: ";
			for (int i = 0; i < ap.nrCamere; i++)
				out << ap.suprafata[i] << " ";
		}
		return out;
	}


	friend istream& operator>>(istream& in, Apartament& ap)
	{
		cout << "\nNr ap";
		in >> ap.nrAp;
		cout << "\nProprietar";
		in.ignore();
		getline(in, ap.proprietar);
		cout << "Etaj:";
		in >> ap.etaj;
		cout << "Nr camere:";
		in >> ap.nrCamere;
		if (ap.suprafata != NULL)
			delete[]ap.suprafata;
		if (ap.suprafata != NULL)
		{
			ap.suprafata = new float[ap.nrCamere];
			for (int i = 0; i < ap.nrCamere; i++)
			{
				cout << "c[" << i << "]=";
				in >> ap.suprafata[i];
			}
		}
		return in;
	}

	Apartament& operator++()
	{
		this->etaj++;
		return*this;
	}

	Apartament operator++(int)
	{
		Apartament copie = *this;
		this->etaj++;
		return copie;
	}

	float getSuprafataTotala()
	{
		float s = 0;
		for (int i = 0; i < this->nrCamere; i++)
			s += this->suprafata[i];
		return s;
	}

	bool operator >=(Apartament ap)
	{
		if (this->getSuprafataTotala() >= ap.getSuprafataTotala())
			return true;
		return false;
	}

	float& operator[](int index)
	{
		if (index >= 0 && index < this->nrCamere)
			return this->suprafata[index];
		else
			throw exception("\nIndex invalid");
	}

	Apartament operator +=(string numeToAdd)
	{
		this->proprietar.append(" ");
		this->proprietar.append(numeToAdd);
		return *this;
	}

	explicit operator float()
	{
		cout << "\n\nApel cast";
		float s = this->getSuprafataTotala();
		if (this->nrCamere > 0)
			return s / this->nrCamere;
		return 0;
	}

	bool operator ==(Apartament ap)
	{
		if (this->nrCamere == ap.nrCamere)
			return true;
		return false;
	}
};

float Apartament::pretMp = 900;

void main()
{
	Apartament ap1(1, 3, 2, new float[2]{ 10,12 }, "Proprietar1");
	Apartament ap2(2, 4, 3, new float[3]{ 10,15,14 }, "Proprietar2");
	cout << ap1;
	cout << ap2;

	cout << "\n\npre incrementare";
	Apartament ap3 = ++ap1;
	cout << ap3 << ap1;

	cout << "\n\npost incrementare";
	Apartament ap4 = ap2++;
	cout << ap4 << ap2;

	cout << "\n\nOperator>=";
	if (ap1 >= ap2)
		cout << "Ap1 are o supraf >= decat ap2";
	else cout << "\nInvers";

	cout << "\n\nOperator[]inedx";
	try
	{
		float suprafataCamera = ap2[0];
		//ap1[1] = 25;
		cout << "\n" << suprafataCamera;
	}
	catch (exception ex)
	{
		cout << "\n" << ex.what();
	}

	cout << "\n\nOperator +=";
	ap1 += "Gigel";
	cout << ap1;

	cout << "\noperator cast";
	float SuprafataMedie = (float)ap1;
	cout << "\nSuprafata medie:" << SuprafataMedie;

	cout << "\n\nOperator ==";
	if (ap1 == ap2)
		cout << "\nAceasi nr de camere";
	else
		cout << "\nNr diferit de camere";
}
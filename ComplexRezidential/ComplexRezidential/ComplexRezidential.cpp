#include<iostream>
using namespace std;

class ComplexRezidential
{
private:
	const int codComplex;
	int nrAp;
	float* suprafeteAp;
public:
	static float pretMetruPatrat;
	ComplexRezidential() :codComplex(0)
	{
		this->nrAp = 0;
		this->suprafeteAp = NULL;
	}
	ComplexRezidential(int codComplex, float* suprafeteAp, int nrAp) :codComplex(codComplex)
	{
		this->nrAp = nrAp;
		if (suprafeteAp != NULL)
		{
			this->suprafeteAp = new float[this->nrAp];
			for (int i = 0; i < this->nrAp; i++)
				this->suprafeteAp[i] = suprafeteAp[i];
		}
		else this->suprafeteAp = NULL;
	}
	ComplexRezidential(int codComplex) :codComplex(codComplex)
	{
		this->nrAp = 0;
		this->suprafeteAp = NULL;
	}

	ComplexRezidential(const ComplexRezidential& cr) :codComplex(cr.codComplex)
	{
		this->nrAp = cr.nrAp;
		if (cr.suprafeteAp != NULL)
		{
			this->suprafeteAp = new float[this->nrAp];
			for (int i = 0; i < this->nrAp; i++)
				this->suprafeteAp[i] = cr.suprafeteAp[i];
		}
		else this->suprafeteAp = NULL;
	}

	ComplexRezidential& operator =(const ComplexRezidential& cr)
	{
		this->nrAp = cr.nrAp;
		if (this->suprafeteAp != NULL)
			delete[]this->suprafeteAp;
		if (cr.suprafeteAp != NULL)
		{
			this->suprafeteAp = new float[this->nrAp];
			for (int i = 0; i < this->nrAp; i++)
				this->suprafeteAp[i] = cr.suprafeteAp[i];
		}
		else this->suprafeteAp = NULL;
		return *this;
	}

	int getNrAp()
	{
		return this->nrAp;
	}

	int getCodComplex()
	{
		return this->codComplex;
	}

	void setSuprafeteAp(float* suprafeteAp, int nrAp)
	{
		if (nrAp > 0)
		{
			this->nrAp = nrAp;
			this->suprafeteAp = new float[this->nrAp];
			for (int i = 0; i < this->nrAp; i++)
				this->suprafeteAp[i] = suprafeteAp[i];
		}
	}

	float getSuprafataMedie()
	{
		float s = 0;
		for (int i = 0; i < this->nrAp; i++)
			s += this->suprafeteAp[i];
		if (this->nrAp != 0)
			return s / this->nrAp;
		return 0;
	}


	friend ostream& operator<<(ostream& out, ComplexRezidential c)
	{
		out << "\nComplexul cu codul ";
		out << c.codComplex << "are" << c.nrAp;
		out << "ap:";
		for (int i = 0; i < c.nrAp; i++)
			out << c.suprafeteAp[i] << " ";
		return out;
	}

	float operator[](int index)
	{
		return this->suprafeteAp[index];
	}

	bool operator<(ComplexRezidential cr)
	{
		if (this->nrAp < cr.nrAp)
			return true;
		return false;

	}

	~ComplexRezidential()
	{
		if (this->suprafeteAp != NULL)
			delete[]this->suprafeteAp;
	}

};

float ComplexRezidential::pretMetruPatrat = 700;

void main()
{
	ComplexRezidential cr1(12);
	cout << "\n" << cr1.getNrAp();
	float suprafeteAp[] = { 65.5,45.5,70.5,85 };
	ComplexRezidential cr2(13, suprafeteAp, 4);
	cout << "\n" << cr2.getCodComplex();
	ComplexRezidential cr3 = cr2;
	cout << "\n" << cr3.getNrAp();
	float suprafeteAp2[] = { 50,60.5,70,80.5,120 };
	cr3.setSuprafeteAp(suprafeteAp2, 5);
	cout << "\n" << cr3.getNrAp();
	cr1 = cr2;
	cout << "\n" << cr1.getSuprafataMedie();
	//ComplexRezidential *pcr = new ComplexRezidential(19, suprafeteAp2, 5);
	//ComplexRezidential cr4 = 50 + *pcr;
	//cout << cr4;
	//ComplexRezidential cr5 = --cr4;
	//cout << cr5;
	//cout << cr4;
	float suprafeteAp3[] = { 50,60.5,70,80.5,120,50 };
	ComplexRezidential cr4(19, suprafeteAp3, 6);
	ComplexRezidential::pretMetruPatrat = 800;
	cout << "\n" << cr4[2] * ComplexRezidential::pretMetruPatrat;
	if (cr1 < cr2)
		cout << "\ncr1 are o suprafata totala mai mica ca cr2";
	else
		cout << "\ncr2 are o suprafata totala mai mica ca cr1";
}
#include<iostream>
using namespace std;

class Produs
{
private:
	const int codProd;
	int nrPreturi;
	int* istoricPreturi;
public:
	Produs() :codProd(0)
	{
		this->nrPreturi = 0;
		this->istoricPreturi = NULL;
	}

	Produs(int codProd, int* istoricPreturi, int nrPreturi) :codProd(codProd)
	{
		this->nrPreturi = nrPreturi;
		if (istoricPreturi != NULL)
		{
			this->istoricPreturi = new int[this->nrPreturi];
			for (int i = 0; i < this->nrPreturi; i++)
				this->istoricPreturi[i] = istoricPreturi[i];
		}
		else this->istoricPreturi = NULL;
	}

	Produs(int codProd) :codProd(codProd)
	{
		this->nrPreturi = 0;
		this->istoricPreturi = NULL;
	}

	Produs(const Produs& p) :codProd(p.codProd)
	{
		this->nrPreturi = p.nrPreturi;
		if (p.istoricPreturi != NULL)
		{
			this->istoricPreturi = new int[this->nrPreturi];
			for (int i = 0; i < this->nrPreturi; i++)
				this->istoricPreturi[i] = p.istoricPreturi[i];
		}
		else this->istoricPreturi = NULL;
	}

	Produs& operator=(const Produs& p)
	{
		this->nrPreturi = p.nrPreturi;
		if (this->istoricPreturi != NULL)
			delete[]this->istoricPreturi;
		if (p.istoricPreturi != NULL)
		{
			this->istoricPreturi = new int[this->nrPreturi];
			for (int i = 0; i < this->nrPreturi; i++)
				this->istoricPreturi[i] = p.istoricPreturi[i];
		}
		else this->istoricPreturi = NULL;
		return *this;
	}

	int getNrPreturi()
	{
		return this->nrPreturi;
	}

	int getCodProd()
	{
		return this->codProd;
	}

	void setPreturi(int* istoricPreturi, int nrPreturi)
	{
		if (this->istoricPreturi != NULL)
			delete[]this->istoricPreturi;
		this->nrPreturi = nrPreturi;
		if (istoricPreturi != NULL)
		{
			this->istoricPreturi = new int[this->nrPreturi];
			for (int i = 0; i < this->nrPreturi; i++)
				this->istoricPreturi[i] = istoricPreturi[i];
		}
		else this->istoricPreturi = NULL;

	}

	int getPretMaxim()
	{
		int max = 0;
		if (istoricPreturi != NULL)
			for (int i = 0; i < this->nrPreturi; i++)
				if (this->istoricPreturi[i] > max)
					max = this->istoricPreturi[i];
		return max;
	}

	friend ostream& operator<<(ostream& out, const Produs& p)
	{
		out << "\nProdusul cu codul:" << p.codProd;
		out << " are " << p.nrPreturi << " preturi in istoric:";
		if (p.istoricPreturi != NULL)
			for (int i = 0; i < p.nrPreturi; i++)
				out << p.istoricPreturi[i] << " ";
		else out << "-";
		return out;
	}

	Produs& operator++()
	{
		if (this->istoricPreturi != NULL)
			this->istoricPreturi[this->nrPreturi - 1] += 1;
		return *this;
	}

	float getPretMediu()
	{
		float s = 0;
		if (this->istoricPreturi != NULL)
		{
			for (int i = 0; i < this->nrPreturi; i++)
				s += this->istoricPreturi[i];
			return s / this->nrPreturi;
		}
		return 0;
	}

	bool operator==(Produs p)
	{
		if (this->getPretMediu() == p.getPretMediu())
			return true;
		return false;
	}

	~Produs()
	{
		if (this->istoricPreturi != NULL)
			delete[]this->istoricPreturi;
	}
};

void main()
{
	Produs p1(102);
	cout << p1.getNrPreturi();
	int preturi[]{ 100,150,125,150,130 };
	Produs p2(104, preturi, 5);
	cout << "\n" << p2.getNrPreturi();
	Produs p3 = p2;
	cout << "\n" << p3.getCodProd();
	int preturi2[]{ 500,525,400,450 };
	p1.setPreturi(preturi2, 4);
	cout << "\n" << p1.getNrPreturi();
	p3 = p1;
	int pretMax = p3.getPretMaxim();
	cout << "\n" << pretMax;
	Produs p4(110);
	cout << "\n" << p4.getPretMaxim();
	Produs* pp1 = new Produs(109);
	*pp1 = p1;
	cout << *pp1;
	delete pp1;
	//int pretUltim = (int)p1;
	//cout << "\n" << pretUltim;
	p1 = ++p3;
	cout << p1;
	cout << p3;
	p4.setPreturi(preturi, 5);
	if (p1 == p4)
		cout << "\nPretul mediu al produsului p1 este acelasi cu cel al produsului p4";
	else
		cout << "\nPretul mediu al produsului p1 nu este acelasi cu cel al produsului p4";
}
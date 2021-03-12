#include<iostream>
using namespace std;

class Prajitura
{
private:
	const int codPrajitura;
	char* denumirePrajitura;
	int nrIngrediente;
	int* cantIngrediente;
	bool contineZahar;
	//int vanzari[7];  // cate buc de prajitura se vand zilnic timp de o saptamnana
public:
	static float pretPrajitura;
	Prajitura() :codPrajitura(0)
	{
		this->nrIngrediente = 0;
		this->cantIngrediente = NULL;
		this->contineZahar = NULL;
		this->denumirePrajitura = NULL;
	}
	Prajitura(int codPrajitura, const char* denumirePrajitura, int nrIngrediente, int* cantIngrediente) :codPrajitura(codPrajitura)
	{
		this->nrIngrediente = nrIngrediente;
		if (cantIngrediente != NULL)
		{
			this->cantIngrediente = new int[this->nrIngrediente];
			for (int i = 0; i < this->nrIngrediente; i++)
				this->cantIngrediente[i] = cantIngrediente[i];
		}
		if (denumirePrajitura != NULL)
		{
			this->denumirePrajitura = new char[strlen(denumirePrajitura) + 1];
			strcpy(this->denumirePrajitura, denumirePrajitura);
		}
		else this->denumirePrajitura = NULL;
	}

	Prajitura(int codPrajitura) :codPrajitura(codPrajitura)
	{
		this->nrIngrediente = 0;
		this->cantIngrediente = NULL;
		this->contineZahar = NULL;
		this->denumirePrajitura = NULL;
	}

	Prajitura(const Prajitura& p) :codPrajitura(p.codPrajitura)
	{
		this->nrIngrediente = p.nrIngrediente;
		if (p.cantIngrediente != NULL)
		{
			this->cantIngrediente = new int[this->nrIngrediente];
			for (int i = 0; i < this->nrIngrediente; i++)
				this->cantIngrediente[i] = p.cantIngrediente[i];
		}
		this->contineZahar = p.contineZahar;
		if (p.denumirePrajitura != NULL)
		{
			this->denumirePrajitura = new char[strlen(p.denumirePrajitura) + 1];
			strcpy(this->denumirePrajitura, p.denumirePrajitura);
		}
		else this->denumirePrajitura = NULL;
	}

	Prajitura& operator =(const Prajitura& p)
	{
		this->nrIngrediente = p.nrIngrediente;
		if (cantIngrediente != NULL)
			delete[]this->cantIngrediente;
		if (p.cantIngrediente != NULL)
		{
			this->cantIngrediente = new int[this->nrIngrediente];
			for (int i = 0; i < this->nrIngrediente; i++)
				this->cantIngrediente[i] = p.cantIngrediente[i];
		}
		this->contineZahar = p.contineZahar;
		if (denumirePrajitura != NULL)
			delete[]this->denumirePrajitura;
		if (p.denumirePrajitura != NULL)
		{
			this->denumirePrajitura = new char[strlen(p.denumirePrajitura) + 1];
			strcpy(this->denumirePrajitura, p.denumirePrajitura);
		}
		else this->denumirePrajitura = NULL;
		return *this;
	}

	~Prajitura()
	{
		if (cantIngrediente != NULL)
			delete[]this->cantIngrediente;
		if (denumirePrajitura != NULL)
			delete[]this->denumirePrajitura;
	}

	friend ostream& operator <<(ostream& out, const Prajitura& p)
	{
		out << "\nCodul prajiturii este " << p.codPrajitura;
		if (p.denumirePrajitura != NULL)
			out << " , denumirea prajiturii: " << p.denumirePrajitura;
		out << " \nNumarul de ingrediente este " << p.nrIngrediente;
		if (p.nrIngrediente != NULL)
		{
			out << " cantitatea din fiecare ingredient este: ";
			for (int i = 0; i < p.nrIngrediente; i++)
				out << p.cantIngrediente[i] << "  grame ";
		}
		return out;
	}

	int getCodPrajitura()
	{
		return this->codPrajitura;
	}

	char* getDenumirePrajitura()
	{
		if (this->denumirePrajitura != NULL)
			return this->denumirePrajitura;
		else
			return NULL;
	}
	void setDenumirePrajitura(const char* denumireNoua)
	{
		if (this->denumirePrajitura != NULL)
			delete[] this->denumirePrajitura;
		if (denumireNoua != NULL)
		{
			this->denumirePrajitura = new char[strlen(denumireNoua) + 1];
			strcpy(this->denumirePrajitura, denumireNoua);
		}
		else this->denumirePrajitura = NULL;
	}
	int getNrIngrediente()
	{
		return this->nrIngrediente;
	}

	void setNrIngrediente(int nrIngrediente)
	{
		if (nrIngrediente >= 10)
			this->nrIngrediente = nrIngrediente;
	}

	int getcantIngredinte()
	{
		return *this->cantIngrediente;
	}

	void setcantIngrediente(int nrIngrediente, int* cantIngrediente)
	{
		if (nrIngrediente > 0)
		{
			this->nrIngrediente = nrIngrediente;
			this->cantIngrediente = new int[this->nrIngrediente];
			for (int i = 0; i <= this->nrIngrediente; i++)
				this->cantIngrediente[i] = cantIngrediente[i];
		}
	}

	friend istream& operator>>(istream& in, Prajitura& p)
	{
		cout << "Denumire prajitura: ";
		in >> p.denumirePrajitura;
		cout << "Nr ingrediente: ";
		in >> p.nrIngrediente;
		if (p.cantIngrediente != NULL)
			delete[] p.cantIngrediente;
		if (p.nrIngrediente > 0)
		{
			p.cantIngrediente = new int[p.nrIngrediente];
			for (int i = 0; i < p.nrIngrediente; i++)
			{
				cout << "c[" << i << "]= ";
				in >> p.cantIngrediente[i];
			}
		}
		return in;
	}

	int getCelMaiFolositIngredient()
	{
		int max = 0;
		if (this->cantIngrediente != NULL)
		{
			for (int i = 0; i < this->nrIngrediente; i++)
				if (this->cantIngrediente[i] > max)
					max = this->cantIngrediente[i];
		}
		return max;
	}

	float getCantitatiMedii()
	{
		int s = 0;
		if (this->cantIngrediente != NULL)
		{
			for (int i = 0; i < this->nrIngrediente; i++)
				s += this->cantIngrediente[i];
			return (float)s / this->nrIngrediente;
		}
		return 0;
	}

	Prajitura& operator++()
	{
		this->nrIngrediente++;
		return *this;
	}

	Prajitura operator++(int)
	{
		Prajitura copie = *this;
		this->nrIngrediente++;
		return copie;
	}

	bool operator <=(Prajitura p)
	{
		if (this->getCantitatiMedii() >= p.getCantitatiMedii())
			return true;
		return false;
	}

	int& operator [](int index)
	{
		if (index >= 0 && index < this->nrIngrediente)
			return this->cantIngrediente[index];
	}

	explicit operator float()
	{
		float s = this->getCantitatiMedii();
		if (this->nrIngrediente > 0)
			return s / this->nrIngrediente;
		return 0;
	}

	bool operator!()
	{
		if (this->nrIngrediente == 0)
			return true;
		return false;
	}

	float operator()()
	{
		return 5 * Prajitura::pretPrajitura;
	}

	Prajitura operator+(int nrIngredienteadaugate)
	{
		Prajitura copie = *this;
		copie.nrIngrediente += nrIngredienteadaugate;
		return copie;
	}

};

float Prajitura::pretPrajitura = 6;

void main()
{
	Prajitura p1;
	cout << "\n\nParjitura1:" << p1;

	int cantIngrediente1[]{ 3,200,15,47,1,56 };
	Prajitura p2(14, "Ecler", 6, cantIngrediente1);
	cout << "\n\nParjitura2:" << p2;

	Prajitura p3 = p2;
	cout << "\n\nDenumire prajitura 3: " << p3.getDenumirePrajitura();
	p3.setDenumirePrajitura("Amandina");
	cout << p3;

	int cantIngrediente2[]{ 3,200,15,47,56 };
	Prajitura p4(18, "Savarina", 5, cantIngrediente2);
	cout << "\n\nNr ingrediente prajitura 4: " << p4.getNrIngrediente();
	p4.setNrIngrediente(5);
	cout << p4;

	int cantIngrediente3[]{ 3,200,15,47,56 };
	Prajitura p5(3, "Tiramisu", 5, cantIngrediente3);
	cout << "\n\nCantitati ingrediente prajitura 5: " << p5.getcantIngredinte();
	p5.setcantIngrediente(5, cantIngrediente3);
	cout << p5;

	cout << "\n\nCel mai folosit ingredient din prajitura 4 are " << p3.getCelMaiFolositIngredient() << " grame";

	cout << "\n\nPrajitura 5 are " << p3.getCantitatiMedii() << " grame de ingrediente.";

	//p3 = ++p2;
	//cout << "\n\n" << p3 << p2;

	//p5 = p4++;
	//cout << "\n\n" << p5 << p4;

	if (p2 <= p3)
		cout << "\n\nPrajitura p2 are o cantitate de ingrediente <= decat prajitura p3";
	else
		cout << "\n\nPrajitura p3 are o cantitate de ingrediente <= decat prajitura p2";

	cout << "\n\nCantitatea ingredientului 1 este: ";
	cout << p3[1];

	float cantMedie = (float)p4;
	cout << "\n\nCantitatea medie a prajiturii 4 este:: " << cantMedie;

	if (!p2)
		cout << "\n\nPrajitura 2 nu are ingrediente cunoscute";
	else
		cout << "\n\nPrajitura 2 are cel putin un ingredient cunoscut";

	float pretPrajituri = p3();
	cout << "\n\nO persoana care cumpara 5 prajitura plateste" << pretPrajituri;

	//p4 = p4 + 100;
	//cout << "\n\nNoua reteta a prajiturii p4 contine " << p4 << " ingrediente";

}
#include<iostream>
#include<string>
#include<fstream>
#include<set>

using namespace std;

class Videoclip {
private:
	const int id;
	string subiect;
	int numar;
	float* durata;
public:
	Videoclip() :id(0)
	{
		this->subiect = "";
		this->numar = 0;
		this->durata = NULL;
	}
	Videoclip(int id, string subiect, int numar, float* durata) :id(id)
	{
		this->subiect = subiect;
		this->numar = numar;
		if (durata != NULL)
		{
			this->durata = new float[this->numar];
			for (int i = 0; i < this->numar; i++)
				this->durata[i] = durata[i];
		}
	}
	Videoclip(const Videoclip& v) :id(v.id)
	{
		this->subiect = v.subiect;
		this->numar = v.numar;
		if (v.durata != NULL)
		{
			this->durata = new float[this->numar];
			for (int i = 0; i < this->numar; i++)
				this->durata[i] = v.durata[i];
		}
	}
	Videoclip& operator=(const Videoclip& v)
	{
		this->subiect = v.subiect;
		this->numar = v.numar;
		if (this->durata != NULL)
			delete[]durata;
		if (v.durata != NULL)
		{
			this->durata = new float[this->numar];
			for (int i = 0; i < this->numar; i++)
				this->durata[i] = v.durata[i];
		}
		return*this;
	}

	friend ostream& operator<<(ostream&out, const Videoclip& v)
	{
		out << "\nId: " << v.id;
		out << " ,subiect: " << v.subiect;
		out << " ,numar: " << v.numar;
		out << " ,durata: ";
		for (int i = 0; i < v.numar; i++)
			out << v.durata[i] << " ";
		return out;
	}

	string getSubiect()
	{
		return this->subiect;
	}

	int getNumar()
	{
		return this->numar;
	}

	void setSubiect(string subiect)
	{
		if (this->subiect != subiect)
			this->subiect = subiect;
		else
			throw exception("\nAi introdus acelasi subiect!");
	}

	void setNumar(int numar)
	{
		if (numar > 3)
			this->numar = numar;
		else
			throw exception("\nNumar invalid!");
	}

	float getMediaAritmetica()
	{
		float sum = 0;
		if (this->durata != NULL)
		{
			for (int i = 0; i < this->numar; i++)
				sum += this->durata[i];
		}
		return sum / this->numar;
	}

	float getMaxim()
	{
		float max = 0;
		for (int i = 0; i < this->numar; i++)
			if (this->durata[i] > max)
				max = this->durata[i];
		return max;
	}

	float operator()(float num)
	{
		return this->durata[this->numar - 1] + num;
	}

	bool operator!()
	{
		if (this->numar == 0)
			return true;
		else return false;
	}
	
	friend istream& operator>>(istream& in, Videoclip& v)
	{
		//cout << "\nId: ";
		//in >> v.id;
		cout << "\nSubiect: ";
		in.ignore();
		getline(in, v.subiect);
		cout << "\nNumar: ";
		in >> v.numar;
		if (v.numar != NULL)
			delete[]v.durata;
		cout << "\nDurata: \n";
		if (v.numar > 0)
		{
			v.durata = new float[v.numar];
			for (int i = 0; i < v.numar; i++)
			{
				cout << "v[" << i << "]=";
				in >> v.durata[i];
			}
		}
		return in;
	}

	friend ofstream& operator<<(ofstream& fOut, const Videoclip& v)
	{
		fOut << "\nId: " << v.id;
		fOut << " ,subiect: " << v.subiect;
		fOut << " ,numar: " << v.numar;
		fOut << " ,durata: ";
		for (int i = 0; i < v.numar; i++)
			fOut << v.durata[i] << " ";
		return fOut;
	}


	~Videoclip()
	{
		if (this->durata != NULL)
			delete[]durata;
	}
};

class Reclama :public Videoclip
{
private:
	int minute;
	string produs;
public:
	Reclama():Videoclip()
	{
		this->minute = 0;
		this->produs = "";
	}
	Reclama(int c, string s,int n,float*d,int minute, string produs):Videoclip(c,s,n,d)
	{
		this->minute = minute;
		this->produs = produs;
	}
	Reclama(Videoclip&v, int minute, string produs) :Videoclip(v)
	{
		this->minute = minute;
		this->produs = produs;
	}
	Reclama(const Reclama&r):Videoclip(r)
	{
		this->minute = r.minute;
		this->produs = r.produs;
	}
	Reclama& operator =(const Reclama&r)
	{
		Videoclip::operator=(r);
		this->minute = r.minute;
		this->produs = r.produs;
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Reclama& r)
	{
		out << Videoclip(r);
		out << " ,minute: " << r.minute;
		out << " ,produs: " << r.produs;
		return out;
	}
	~Reclama()
	{

	}
};

class Documentar {
private:
	string nume = "";
	int minute = 0;
public:
	Documentar()
	{
	}
	Documentar(string nume, int minute)
	{
		this->nume = nume;
		this->minute = minute;
	}
	Documentar(const Documentar& d)
	{
		this->nume = d.nume;
		this->minute = d.minute;
	}
	Documentar& operator=(const Documentar& d)
	{
		this->nume = d.nume;
		this->minute = d.minute;
		return*this;
	}

	friend ostream& operator<<(ostream& out, const Documentar& d)
	{
		out << "\nNume documentar: " << d.nume;
		out << " ,minute: " << d.minute;
		return out;
	}
	~Documentar()
	{

	}

	friend bool operator<(const Documentar& d1, const Documentar& d2);
};

bool operator<(const Documentar& d1, const Documentar& d2)
{
	if (d1.minute < d2.minute)
		return true;
	else return false;
}

void main()
{
	Videoclip v1=Videoclip();
	cout << "\nVideo 1: " << v1;
	Videoclip v2 = Videoclip(13, "school", 3, new float[3]{ 45,20,13 });
	cout << "\nVideo 2: " << v2;
	Videoclip v3 = Videoclip(32, "skin care", 2, new float[2]{ 12,30 });
	cout << "\nVideo 3: " << v3;
	Videoclip v4 = Videoclip(45, "make up", 4, new float[4]{ 12,32,52,26 });
	cout << "\nVideo 4: " << v4;

	Videoclip v5 = v4;
	cout << "\nVideo 5: " << v5;

	v4 = v3;
	cout << "\nVideo 4: " << v4;

	cout<<"\n\n"<<v2.getNumar();
	cout << "\n" << v2.getSubiect();

	try {
		v3.setNumar(2);
	}
	catch (exception e)
	{
		cout << "\n" << e.what();
	}

	try {
		v3.setSubiect("skin care");
	}
	catch (exception e)
	{
		cout << "\n" << e.what();
	}

	cout<<"\n\nMedia aritmetica a duratelor: "<<v4.getMediaAritmetica();
	cout << "\n\nValoarea maxima a duratelor: " << v4.getMaxim();

	cout << "\n\nOperator functie: " << v3(10);
	cout << v3;

	if (!v2)
		cout << "\n\nVideo 2 nu are nr de filmulete";
	else
		cout << "\n\nVideo 2 are nr de filmulete";

	//Videoclip v6;
	//cin >> v6;
	//cout << v6;

	ofstream g("video.txt");
	Videoclip * video = new Videoclip[5];
	video[0] = v1;
	video[1] = v2;
	video[2] = v3;
	video[3] = v4;
	video[4] = v5;
	for(int i=0;i<5;i++)
		g << video[i];
	
	Reclama r1 = Reclama(v2, 23, "carte");
	cout << r1;
	Videoclip v7 = r1;
	cout << "\n\n\n" << v7;

	set<Documentar> setD;
	Documentar d1("blue planet", 120);
	Documentar d2("orcas", 130);
	setD.insert(d1);
	setD.insert(d2);
	set<Documentar>::iterator it;
	cout << "\nSET: ";
	for(it = setD.begin(); it != setD.end(); it++)
		cout << *it;

}
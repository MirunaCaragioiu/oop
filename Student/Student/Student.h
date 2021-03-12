#include<iostream>
using namespace std;

class Student
{
private:
	const int codStud;
	int nrNote;
	int* note;

public:
	static int nrPctCredit;
	Student() :codStud(0)
	{
		this->nrNote = 0;
		this->note = NULL;
	}

	Student(int codStud, int* note, int nrNote) :codStud(codStud)
	{
		this->nrNote = nrNote;
		if (note != NULL)
		{
			this->note = new int[this->nrNote];
			for (int i = 0; i < this->nrNote; i++)
				this->note[i] = note[i];
		}
		else this->note = NULL;
	}

	Student(int codStud) :codStud(codStud)
	{
		this->nrNote = 0;
		this->note = NULL;
	}

	Student(const Student& s) :codStud(s.codStud)
	{
		this->nrNote = s.nrNote;
		if (s.note != NULL)
		{
			this->note = new int[this->nrNote];
			for (int i = 0; i < this->nrNote; i++)
				this->note[i] = s.note[i];
		}
		else this->note = NULL;
	}

	Student& operator=(const Student& s)
	{
		this->nrNote = s.nrNote;
		if (this->note != NULL)
			delete[]this->note;
		if (s.note != NULL)
		{
			this->note = new int[this->nrNote];
			for (int i = 0; i < this->nrNote; i++)
				this->note[i] = s.note[i];
		}
		else this->note = NULL;
		return *this;
	}

	int getNrNote()
	{
		return this->nrNote;
	}

	int getCod()
	{
		return this->codStud;
	}

	void setNote(int* note, int nrNote)
	{
		if (nrNote > 0)
		{
			this->nrNote = nrNote;
			this->note = new int[this->nrNote];
			for (int i = 0; i < nrNote; i++)
				this->note[i] = note[i];
		}
	}
	bool estePromovat(int Credit)
	{
		int s = 0;
		for (int i = 0; i < this->nrNote; i++)
		{
			if (this->note[i] >= 5)
				s += s + Student::nrPctCredit;
		}
		if (s >= Credit)
			return true;
		return false;
	}

	friend ostream& operator <<(ostream& out, const Student& s)
	{
		out << "\nCod student" << s.codStud << " , numar note" << s.nrNote;
		if (s.note != NULL)
		{
			out << "\nNote:";
			for (int i = 0; i < s.nrNote; i++)
				out << s.note[i] << " ";
		}
		return out;
	}
	int getMedie()
	{
		float s = 0;
		for (int i = 0; i < this->nrNote; i++)
			s += this->note[i];
		return s;
	}

	explicit operator float()
	{
		float m = this->getMedie();
		if (this->nrNote > 0)
			return m / this->nrNote;
		return 0;
	}

	bool operator==(Student s)
	{
		if (this->nrNote == s.nrNote)
			return true;
		return false;
	}

	~Student()
	{
		if (this->note != NULL)
			delete[]this->note;
	}
};

int Student::nrPctCredit = 3;

void main()
{
	Student s1(102);
	cout << s1.getNrNote();
	int note[]{ 10,7,8,10,4 };
	Student s2(104, note, 5);
	cout << "\n" << s2.getNrNote();
	Student s3 = s2;
	cout << "\n" << s3.getCod();
	int note2[]{ 5,5,4,10 };
	s1.setNote(note2, 4);
	cout << "\n" << s1.getNrNote();
	Student::nrPctCredit = 4;
	s3 = s1;
	bool promovat = s3.estePromovat(15);
	if (promovat)
		cout << "\nStudentul s3 are un numar suficient de puncte credit";
	else
		cout << "\nStudentul s3 nu are un numar suficient de puncte credit";
	Student* ps1 = new Student(109);
	*ps1 = s1;
	cout << *ps1;
	delete ps1;
	float medie = (float)s1;
	cout << "\n" << medie;
	//s1 = s3++;
	if (s1 == s3)
		cout << "\ns4 are acelasi numar de note de trecere cu s3";
	else
		cout << "\ns4 nu are acelasi numar de note de trecere cu s3";








}

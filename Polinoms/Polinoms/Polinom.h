#pragma once
#include "Spisok.h";
#include "Zveno.h"
class Polinom
{
private:
	int maxst;
	int n;
	CSpisok cs;
public:

	Polinom(void)
	{
	}
	CSpisok StrToPol(string str)
	{
		string* mas = new string(str.length/2+1);
		int n;
		CSpisok tmp;
		for(int i=0;i<n;i++)
		{

		}

	}
	Polinom(string str,int _maxst,int _n)
	{
		maxst=_maxst;
		n=_n;
		cs=StrToPol(str);
	}
	Polinom(const Polinom &tmp)
	{
		maxst=tmp.maxst;
		n=tmp.n;
		cs=tmp.cs;
	}
	~Polinom(void)
	{
	}
	Polinom &operator = (const Polinom &tmp)
	{
		maxst=tmp.maxst;
		n=tmp.n;
		cs=tmp.cs;
		return *this;
	}
	void AddZveno(string str)
	{
		cs.AddZveno();
	}
	Polinom StrToPol(string str)
	{
		return Polinom(str,maxst,n);
	}
	string GetString()
	{
		return cs.SpToStr(maxst,n);
	}
	Polinom &operator + (const Polinom &tmp)
	{
		Polinom res("",maxst,n);
		res.cs=cs+tmp.cs;
	}
};


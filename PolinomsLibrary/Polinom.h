#pragma once
#include "Spisok.h"
#include "Zveno.h"
class Polinom
{
private:
	int maxst;
	int n;
	CSpisok cs;
public:
	int GetMaxst()
	{
		return maxst;
	}
	int GetN()
	{
		return n;
	}
	CSpisok GetCs()
	{
		return cs;
	}
	Polinom(int maxst_,int n_,CSpisok tmp_)
	{
		maxst = maxst_;
		n = n_;
		cs = tmp_;
	}
	Polinom(int maxst_, int n_, string st)
	{
		maxst = maxst_;
		n = n_;
		cs = StrToPol(st);
	}
	CSpisok StrToPol(string str)
	{
		string *mas = new string[str.length() / 4 + 1];
		CSpisok tmp;
		int k = 0;
		if(str.length()==0)
		return tmp;
		else
		{
			while (str.length() != 0)
			{
				int posp = str.find('+');
				int poso = str.find('-');
				if (posp == 0)
				{
					string copy = str;
					copy.erase(0, 1);
					posp = copy.find('+');
						if(posp!=-1)
							posp++;
				}
				if (poso == 0)
				{
					string copy = str;
					copy.erase(0, 1);
					poso = copy.find('-') + 1;
					if (poso != -1)
						poso++;
				}
				int pos = -1;
				if ((poso == -1) && (posp != -1))
					pos = posp;
				else if ((posp == -1) && (poso != -1))
					pos = poso;
				else if (posp < poso)
					pos = posp;
				else if (poso < posp)
					pos = poso;
				if (pos != -1)
				{
					string strc = str;
					strc.erase(pos, str.length());
					mas[k] = strc;
					k++;
					str.erase(0, pos);
				}
				else
				{
					mas[k] = str;
					str.erase(0, str.length());
					k++;
				}
			}
			Zveno A;
			Zveno *B;
			for (int i = 0;i < k;i++)
			{
				A = A.StringToZveno(maxst, mas[i]);
				int kof = A.GetA();
				int svr = A.GetSv();
				B = new Zveno(kof, svr);
				tmp.AddMonom(B);
			}
			return tmp;
		}
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
	Polinom operator = (const Polinom &tmp)
	{
		maxst=tmp.maxst;
		n=tmp.n;
		cs=tmp.cs;
		return *this;
	}
	string GetString()
	{
		return cs.SpToStr(maxst,n);
	}
	Polinom operator + (const Polinom &tmp)
	{
		Polinom frst = tmp;
		Polinom sec = *this;
		frst.Balance(sec);
		sec.Balance(frst);
		CSpisok rescs = frst.GetCs()+sec.GetCs();
		Polinom res(frst.GetMaxst(), frst.GetN(), rescs);
		return res;
	}
	Polinom operator - (const Polinom &tmp)
	{
		Polinom frst = tmp;
		Polinom sec = *this;
		frst.Balance(sec);
		sec.Balance(frst);
		CSpisok rescs = frst.GetCs() - sec.GetCs();
		Polinom res(frst.GetMaxst(), frst.GetN(), rescs);
		return res;
	}
	Polinom operator *(int num)
	{
		Polinom frs = *this;
		CSpisok csp = frs.GetCs();
		csp = csp*num;
		Polinom res(maxst, n, csp);
		return res;
	}
	Polinom operator *(const Polinom &tmp)
	{
		Polinom frst = tmp;
		Polinom sec = *this;
		frst.Balance(sec);
		sec.Balance(frst);
		CSpisok rescs = frst.GetCs().Mull(sec.GetCs(),frst.GetMaxst(),frst.GetN());
		Polinom res(frst.GetMaxst(), frst.GetN(), rescs);
		return res;
	}
	Polinom Balance(Polinom tmp)
	{
		string strs = this->GetString();
		int maxstt = maxst;
		if (tmp.GetMaxst() > maxst)
			maxstt = tmp.GetMaxst();
		int nt = n;
		if (tmp.GetN() > n)
			nt = tmp.GetN();
		Polinom res(maxstt, nt, strs);
		return res;
	}
	CSpisok StrToPol(string str,int maxst_,int n_)
	{
		string *mas = new string[str.length()- 1];
		CSpisok tmp;
		int k = 0;
		str="+"+str;
		if (str.length() == 0)
			return tmp;
		else
		{
			while (str.length() != 0)
			{
				int posp = str.find('+');
				int poso = str.find('-');
				if (posp == 0)
				{
					string copy = str;
					copy.erase(0, 1);
					posp = copy.find('+');
					if (posp != -1)
						posp++;
				}
				if (poso == 0)
				{
					string copy = str;
					copy.erase(0, 1);
					poso = copy.find('-') + 1;
					if (poso != -1)
						poso++;
				}
				int pos = -1;
				if ((poso == -1) && (posp != -1))
					pos = posp;
				else if ((posp == -1) && (poso != -1))
					pos = poso;
				else if (posp < poso)
					pos = posp;
				else if (poso < posp)
					pos = poso;
				if (pos != -1)
				{
					string strc = str;
					strc.erase(pos, str.length());
					mas[k] = strc;
					k++;
					str.erase(0, pos);
				}
				else
				{
					mas[k] = str;
					str.erase(0, str.length());
					k++;
				}
			}
			Zveno A;
			Zveno *B;
			for (int i = 0;i < k;i++)
			{
				A = A.StringToZveno(maxst_, mas[i]);
				int kof = A.GetA();
				int svr = A.GetSv();
				B = new Zveno(kof, svr);
				tmp.AddMonom(B);
			}
			return tmp;
		}
	}
};

#pragma once
#include <iostream>
#include <string> 
using namespace std;
class Zveno
{
private:
	int A;
	int Sv;
	Zveno * Next;
public:
	Zveno(int A_= 0 ,int Sv_=0)
	{
		A=A_;
		Sv=Sv_;
		Next=NULL;
	}
	Zveno(const Zveno &tmp)
	{
		A=tmp.A;
		Sv=tmp.Sv;
		Next=NULL;
	}
	Zveno &operator = (Zveno tmp)
	{
		A=tmp.A;
		Sv=tmp.Sv;
		Next=tmp.Next;
		return *this;
	}
	~Zveno(void)
	{
		Next=NULL;
		delete Next;
	}
	int GetA()
	{
		return A;
	}
	void SetA(int A_)
	{
		A=A_;
	}
	int GetSv()
	{
		return Sv;
	}
	void SetSv(int Sv_)
	{
		Sv=Sv_;
	}
	Zveno*GetNext()
	{
		return Next;
	}
	void SetNext(Zveno* Next_)
	{
		Next=Next_;
	}
	int FindN(string str)
	{
		int max = 0;
		while (str.find('x') != -1)
		{
			int k = str.find('x');
			k++;
			string copy="";
			while ((str[k] != '^') && (str[k] != 'x')&&(k!=str.length()))
			{
				copy = copy + str[k];
				k++;

			}
			str.erase(0, k);
			k=atoi(copy.c_str());
			if (k > max)
				max = k;
		}
		return max;
		
	}
	string ZvenoToString(int maxSt,int n)
	{
	int* pw=new int[n];
	for(int i=0;i<n;i++)
	{
		pw[i]=0;
	}
	int cSv=Sv;
	string monom="";
	int i = 0;
	while (cSv!=0)
	{
		pw[i++]=cSv%maxSt;
		cSv=cSv/maxSt;
	}
	for(int i=0;i<n;i++)
	{
		if(pw[i]==1)
		{
			monom="x"+to_string(i+1)+monom;
		}
		if(pw[i]>1)
		{
			monom="x"+to_string(i+1)+"^"+to_string(pw[i])+monom;
		}
	}
	monom=to_string(A)+monom;
	return monom;
	}
	void SvToMas(int maxst,int n,int*mas)
	{
		for(int i=0;i<n;i++)
		{
			mas[i]=0;
		}
		int k=Sv;
		int i=0;
		while(k!=0)
		{
			mas[n-i-1]=k%maxst;
			k=k/maxst;
			i++;
		}
	}
	int MasToSv(int maxst,int n,int *mas)
	{
		int k=0;
		for(int i=0;i<n;i++)
		{
			k=k*maxst+mas[i];
		}
		return k;
	}
	Zveno Mul(Zveno &tmp,int maxst,int n)
	{
		int*masthis=new int[n];
		int* mastmp=new int[n];
		int* masres=new int[n];
		SvToMas(maxst,n,masthis);
		tmp.SvToMas(maxst,n,mastmp);
		int l=0;
		for(int i=0;i<n;i++)
		{
			masres[i]=masthis[i]+mastmp[i];
			if(maxst<=masres[i])
			{
				l=-1;
			}
		}
		Zveno res;
		if(l==0)
		{
			res.SetA(A*tmp.GetA());
			res.SetSv(MasToSv(maxst,n,masres));
		}
		return res;
	}
	int GetA(string str)
	{
		string cstr=str;
		int n=str.find('x');
		cstr.erase(n,str.length()-n);
		n=atoi(cstr.c_str());
		return n;
	}
	int GetSv(int maxst,string str)
	{
		string copy = str;
		int k = copy.find("x");
		copy=copy.erase(0, k);
		k = FindN(copy);
		int *mas = new int [k];
		for (int i = 0;i<k;i++)
		{
			int l = copy.find("x" + to_string(i + 1));
			if (l == -1)
			{
				mas[i] = 0;
			}
			else
			{
				l = copy.find("x" + to_string(i + 1)+"^");
				if (l == -1)
				{
					mas[i] = 1;
				}
				else
				{
					string copyc = copy;
					copyc.erase(0, l);
					l = copyc.find("^");
					l++;
					string buf = "";
					while ((copyc[l] != 'x') && (l != copyc.length()))
					{
						buf = buf + copyc[l];
						l++;
					}
					mas[i]= atoi(buf.c_str());
				}
			}
		}
		int Sv = 0;
		for (int i = k-1;i>=0;i--)
		{
			Sv = Sv*maxst + mas[i];
		}
		return Sv;

	}
	Zveno StringToZveno(int maxst, string str)
	{
		int A_ = GetA(str);
		int Sv_ = GetSv(maxst, str);
		Zveno res(A_, Sv_);
		return res;

	}

};
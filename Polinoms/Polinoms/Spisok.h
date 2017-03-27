#pragma once
#include"Zveno.h"
class CSpisok
{
private:
	Zveno*pFirst;
public:
	CSpisok()
	{
		pFirst=new Zveno();
		pFirst->SetNext(pFirst);
	}
	~CSpisok()
	{
		Zveno*pCur=pFirst->GetNext();
		while(pCur!=pFirst)
		{
			pFirst->SetNext(pCur->GetNext());
			delete pCur;
			pCur=pFirst->GetNext();
		}
		delete pFirst;
	}
	void AddMonom(Zveno* tmp)
	{
		Zveno* prew=pFirst;
		Zveno* cur=pFirst->GetNext();
		while(cur->GetSv()>tmp->GetSv())
		{
			prew=cur;
			cur=cur->GetNext();
			if(cur->GetSv()<tmp->GetSv())
			{
				prew->SetNext(tmp);
				tmp->SetNext(cur);
			}
			else
			{
				if(cur->GetA()==-tmp->GetA)
				{
					delete tmp;
					prew->SetNext(cur->GetNext());
					delete cur;
				}
				else
				{
					cur->SetA(tmp->GetA()+cur->GetA());
					delete tmp;
				}
			}
		}
	}
	CSpisok(const CSpisok &tmp)
	{
		pFirst=new Zveno();
		pFirst->SetNext(pFirst);
		Zveno* pCur= tmp.pFirst->GetNext();
		while(pCur!=tmp.pFirst)
		{
			Zveno* copy;
			copy=new Zveno(*pCur);
			this->AddMonom(copy);
			pCur->SetNext(pCur->GetNext());
		}
	}
	CSpisok &operator=(const CSpisok&tmp)
	{
		Zveno* pCur=pFirst->GetNext();
		while(pCur!=pFirst)
		{
			pFirst->SetNext(pCur->GetNext());
			delete pCur;
			pCur=pFirst->GetNext();
		}
		pCur=tmp.pFirst->GetNext();
		while(pCur!=tmp.pFirst)
		{
			Zveno* copy = new Zveno(*pCur);
			this->AddMonom(copy);
			pCur=pCur->GetNext();
		}
		return *this;
	}
	void AddMonom(int Sv_,int A_)
	{
		Zveno* tmp=new Zveno(A_,Sv_);
		AddMonom(tmp);
	}
	string SpToStr(int maxst, int n)
	{
		string st="";
		{
			Zveno* pCur=pFirst->GetNext();
			while(pCur!=pFirst)
			{
				string stc=pCur->ZvenoToString(maxst,n);
				if(stc[0]!='-')
				{
					st=st+"+"+stc;
				}
				else
				{
					st=st+stc;
				}
				pCur=pCur->GetNext();
			}
			if(st[0]='+')
			{
				st.erase(0,1);
			}
			return st;
		}

	}
	CSpisok &operator+(const CSpisok &tmp)
	{
		CSpisok res(tmp);
		Zveno *pCurrent=pFirst->GetNext();
		while (pCurrent!=pFirst)
		{
			Zveno* pCopy= new Zveno(*pCurrent);
			res.AddMonom(pCopy);
			pCurrent=pCurrent->GetNext();
		}
		return res;
	}
	CSpisok operator*(int num)
	{
		CSpisok res(*this);
		if(num!=0)
		{
			Zveno* pCurrent=res.pFirst->GetNext();
			while (pCurrent!=res.pFirst)
			{
				pCurrent->SetA(pCurrent->GetA()*num);
				pCurrent=pCurrent->GetNext();
				return res;
			}
		}
		else
		{
			res.~CSpisok();
			CSpisok res;
			return res;
		}

	}
	CSpisok operator-(const CSpisok&tmp)
	{
		CSpisok res(tmp);
		res=res*(-1);
		res=res+(*this);
		return res;
	}
	
	
};

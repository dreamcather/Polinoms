#pragma once
#include "Zveno.h"
class CSpisok
{
private:
	Zveno*pFirst;
public:
	CSpisok()
	{
		pFirst=new Zveno(0,-1);
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
	void AddMonom(Zveno *tmp)
	{
		Zveno* prew=pFirst;
		Zveno* cur=pFirst->GetNext();
		if (cur->GetSv() <= tmp->GetSv())
		{
			if (cur->GetSv() < tmp->GetSv())
			{
				tmp->SetNext(cur);
				pFirst->SetNext(tmp);
			}
			else
			{
				if (cur->GetA() == -tmp->GetA())
				{
					prew->SetNext(cur->GetNext());
					cur->~Zveno();
				}
				else
					cur->SetA(cur->GetA()+tmp->GetA());

			}
		}
		else
		{
			while (cur->GetSv() > tmp->GetSv())
			{
				prew = cur;
				cur = cur->GetNext();
				if (cur->GetSv() < tmp->GetSv())
				{
					prew->SetNext(tmp);
					tmp->SetNext(cur);
				}
				else
				{
					if (cur->GetSv() == tmp->GetSv())
					{
						if (cur->GetA() == -tmp->GetA())
						{
							tmp->~Zveno();
							prew->SetNext(cur->GetNext());
							cur->~Zveno();
						}
						else
						{
							cur->SetA(tmp->GetA() + cur->GetA());
							tmp->~Zveno();;
						}
					}
				}
			}
		}
	}
	Zveno*GetFirst()
	{
		return pFirst;
	}
	CSpisok(const CSpisok &tmp)
	{
		pFirst=new Zveno(0,-1);
		pFirst->SetNext(pFirst);
		Zveno* pCur= tmp.pFirst->GetNext();
		while(pCur!=tmp.pFirst)
		{
			Zveno* copy;
			copy=new Zveno(*pCur);
			this->AddMonom(copy);
			pCur=pCur->GetNext();
		}
	}
	CSpisok &operator=(const CSpisok tmp)
	{
		Zveno* pCur=pFirst->GetNext();
		while(pCur!=pFirst)
		{
			pFirst->SetNext(pCur->GetNext());
			delete pCur;
			pCur=pFirst->GetNext();
		}
		CSpisok tmpc(tmp);
		pCur=tmpc.pFirst->GetNext();
		while(pCur!=tmpc.pFirst)
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
				if(stc[0]=='-')
				{
					st=st+stc;
				}
				else
				{
					if (stc[0] == '+')
					{
						st = st + stc;
					}
					else
						st = st + '+' + stc;
				}
				pCur=pCur->GetNext();
			}
			if(st[0]=='+')
			{
				st.erase(0,1);
			}
			return st;
		}

	}
	CSpisok operator+(CSpisok tmp)
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
			}
			return res;
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
	CSpisok Mull(CSpisok tmp, int maxst,int n)
	{
		CSpisok res;
		CSpisok frs = tmp;
		CSpisok sec = *this;
		Zveno *pprew = frs.GetFirst();
		Zveno *pcur = frs.GetFirst()->GetNext();
		while (pcur != pprew)
		{
			Zveno *tprew = sec.GetFirst();
			Zveno *tcur = sec.GetFirst()->GetNext();
			while (tcur != tprew)
			{
				Zveno* fcopy = new Zveno(*pcur);
				Zveno* scopy = new Zveno(*tcur);
				Zveno *resz =new Zveno(fcopy->Mul(*scopy, maxst, n));
				res.AddMonom(resz);
				tcur = tcur->GetNext();
			}
			pcur = pcur->GetNext();
		}
		return res;
	}
	
	
};


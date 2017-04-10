#include "stdafx.h"
#include "CppUnitTest.h"
#include "Zveno.h"
#include "Spisok.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PolinomTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestZvenoConstructor)
		{
			Zveno A;
		}
		TEST_METHOD(TestZvenoConstructorCopy)
		{
			Zveno A(10,125);
			Zveno B(A);
			bool flag =false;
			if((A.GetA()==B.GetA())&&(A.GetSv()==B.GetSv()))
			{
				flag=true;
			}
			Assert::IsTrue(flag);
		}
		TEST_METHOD(TestZvenoOperatorPrisvaivaniya)
		{
			Zveno A(10,125);
			Zveno B(12,134);
			B=A;
			bool flag =false;
			if((A.GetA()==B.GetA())&&(A.GetSv()==B.GetSv()))
			{
				flag=true;
			}
			Assert::IsTrue(flag);
		}
		TEST_METHOD(TestZvenoGetAStringInt1)
		{
			Zveno A;
			string str ="123";
			int res=A.GetA(str);
			Assert::AreEqual(res,123);
		}
		TEST_METHOD(TestZvenoGetAStringInt2)
		{
			Zveno A;
			string str ="123x5^8";
			int res=A.GetA(str);
			Assert::AreEqual(res,123);
		}
		TEST_METHOD(TestZvenoGetAStringInt3)
		{
			Zveno A;
			string str ="x5^8";
			int res=A.GetA(str);
			Assert::AreEqual(res,1);
		}
		TEST_METHOD(TestZvenoGetAStringInt4)
		{
			Zveno A;
			string str ="";
			int res=A.GetA(str);
			Assert::AreEqual(res,0);
		}
		TEST_METHOD(TestZvenoGetAStringInt5)
		{
			Zveno A;
			string str ="23x4^8";
			int res=A.GetA(str);
			Assert::AreEqual(res,23);
		}
		TEST_METHOD(TestZvenoGetAStringInt6)
		{
			Zveno A;
			string str ="-23x4^8";
			int res=A.GetA(str);
			Assert::AreEqual(res,-23);
		}
		TEST_METHOD(TestZvenoGetAStringInt7)
		{
			Zveno A;
			string str ="-12";
			int res=A.GetA(str);
			Assert::AreEqual(res,-12);
		}
		TEST_METHOD(TestZvenoGetAStringInt8)
		{
			Zveno A;
			string str ="-x2^3x1";
			int res=A.GetA(str);
			Assert::AreEqual(res,-1);
		}
		TEST_METHOD(TestZvenoGetSvStringInt1)
		{
			Zveno A;
			string str ="23x4^8x3^8";
			int res=A.GetSv(10,str);
			Assert::AreEqual(res,8800);
		}
		TEST_METHOD(TestZvenoGetSvStringInt2)
		{
			Zveno A;
			string str ="23x4^8x3^8";
			int res=A.GetSv(9,str);
			Assert::AreEqual(res,6480);
		}
		TEST_METHOD(TestZvenoStringToZveno1)
		{
			Zveno A;
			string str ="23x4^8x3^8";
			A=A.StringToZveno(10,str);
			string scopy=A.ZvenoToString(10,4);
			bool flag =false;
			if(str==scopy)
				flag=true;
			Assert::IsTrue(flag);
		}
		TEST_METHOD(TestZvenoStringToZveno2)
		{
			Zveno A;
			string str ="x4^8x3^8";
			A=A.StringToZveno(10,str);
			string scopy=A.ZvenoToString(10,5);
			bool flag =false;
			if(str==scopy)
				flag=true;
			Assert::IsTrue(flag);
		}
		TEST_METHOD(TestZvenoStringToZveno3)
		{
			Zveno A;
			string str ="15";
			A=A.StringToZveno(10,str);
			string scopy=A.ZvenoToString(10,4);
			bool flag =false;
			if(str==scopy)
				flag=true;
			Assert::AreEqual(str,scopy);
		}
		TEST_METHOD(TestZvenoStringToZveno4)
		{
			Zveno A;
			string str ="";
			A=A.StringToZveno(10,str);
			string scopy=A.ZvenoToString(10,4);
			bool flag =false;
			if(str=="0")//Спорный момент
				flag=true;
		}
		TEST_METHOD(TestZvenoGetSvStringInt3)
		{
			Zveno A;
			string str ="15";
			A=A.StringToZveno(10,str);
			int res =A.GetSv();
			Assert::AreEqual(res,0);
		}
		TEST_METHOD(TestZvenoMul1)
		{
			Zveno A;
			Zveno B;
			string stra ="15x2";
			string strb ="7x3";
			A=A.StringToZveno(10,stra);
			B=B.StringToZveno(10,strb);
			A=A.Mul(B,10,4);
			string str=A.ZvenoToString(10,4);
			bool flag=false;
			if(str=="105x3x2")
				flag=true;
			Assert::IsTrue(flag);		
		}
		TEST_METHOD(TestZvenoToString1)
		{
			Zveno A(-1,1010);
			string res=A.ZvenoToString(10,5);
			string expected="-x4x2";
			bool flag =false;
			if(res==expected)
				flag=true;
			Assert::IsTrue(flag);
		}
		TEST_METHOD(TestSpisoc1)
		{
			CSpisok sp;
			Zveno*A=new Zveno(1,1100);
			Zveno*B=new Zveno(1,11);
			sp.AddMonom(A);
			sp.AddMonom(B);
			string str=sp.SpToStr(10,5);
			bool flag=false;
			if(str=="x4x3+x2x1")
				flag=true;
			Assert::IsTrue(flag);
		}
		TEST_METHOD(TestSpisoc2)
		{
			CSpisok sp;
			Zveno*A=new Zveno(1,1100);
			Zveno*B=new Zveno(-1,11);
			sp.AddMonom(A);
			sp.AddMonom(B);
			string str=sp.SpToStr(10,5);
			bool flag=false;
			string res ="x4x3-x2x1";
			if(str==res)
				flag=true;
			Assert::IsTrue(flag);
		}
		TEST_METHOD(TestSpisoc3)
		{
			CSpisok sp;
			Zveno*A=new Zveno(-1,1100);
			Zveno*B=new Zveno(-1,11);
			sp.AddMonom(A);
			sp.AddMonom(B);
			string str=sp.SpToStr(10,5);
			bool flag=false;
			string res ="-x4x3-x2x1";
			if(str==res)
				flag=true;
			Assert::IsTrue(flag);
		}
		TEST_METHOD(TestSpisoc4)
		{
			CSpisok sp;
			Zveno*A=new Zveno(-1,1100);
			Zveno*B=new Zveno(-1,11);
			Zveno*C=new Zveno(-1,11);
			sp.AddMonom(A);
			sp.AddMonom(B);
			sp.AddMonom(C);
			string str=sp.SpToStr(10,5);
			bool flag=false;
			string res ="-x4x3-2x2x1";
			if(str==res)
				flag=true;
			Assert::IsTrue(flag);
		}
		TEST_METHOD(TestSpisoc5)
		{
			CSpisok sp;
			Zveno*A=new Zveno(1,1100);
			Zveno*B=new Zveno(-1,11);
			Zveno*C=new Zveno(8,0);
			sp.AddMonom(A);
			sp.AddMonom(B);
			sp.AddMonom(C);
			string str=sp.SpToStr(10,5);
			bool flag=false;
			string res ="x4x3-x2x1+8";
			if(str==res)
				flag=true;
			Assert::IsTrue(flag);
		}
		TEST_METHOD(TestSpisoc6)
		{
			CSpisok sp;
			Zveno*A=new Zveno(1,1100);
			Zveno*B=new Zveno(-1,11);
			Zveno*C=new Zveno(-7,0);
			sp.AddMonom(A);
			sp.AddMonom(B);
			sp.AddMonom(C);
			string str=sp.SpToStr(10,5);
			bool flag=false;
			string res ="x4x3-x2x1-7";
			if(str==res)
				flag=true;
			Assert::IsTrue(flag);
		}
		TEST_METHOD(TestSpisoc7)
		{
			CSpisok sp;
			Zveno*A=new Zveno(1,1100);
			Zveno*B=new Zveno(-1,11);
			Zveno*C=new Zveno(-7,0);
			sp.AddMonom(C);
			sp.AddMonom(A);
			sp.AddMonom(B);
			CSpisok spc(sp);
			string str=spc.SpToStr(10,5);
			bool flag=false;
			string res ="x4x3-x2x1-7";
			if(str==res)
				flag=true;
			Assert::IsTrue(flag);
		}
		TEST_METHOD(TestSpisoc8)
		{
			CSpisok sp;
			CSpisok spc;
			Zveno*A=new Zveno(1,1100);
			Zveno*B=new Zveno(-1,11);
			Zveno*C=new Zveno(-7,0);
			sp.AddMonom(C);
			spc.AddMonom(A);
			sp.AddMonom(B);
			spc=spc+sp;
			string str=spc.SpToStr(10,5);
			bool flag=false;
			string res ="x4x3-x2x1-7";
			if(str==res)
				flag=true;
			Assert::IsTrue(flag);
		}
		TEST_METHOD(TestSpisoc9)
		{
			CSpisok sp;
			CSpisok spc;
			Zveno*A=new Zveno(1,1000);
			Zveno*B=new Zveno(1,100);
			Zveno*C=new Zveno(1,1000);
			Zveno*D=new Zveno(1,100);
			sp.AddMonom(A);
			sp.AddMonom(B);
			spc.AddMonom(C);
			spc.AddMonom(D);
			spc=spc+sp;
			string str=spc.SpToStr(10,5);
			bool flag=false;
			string res ="2x4+2x3";
			if(str==res)
				flag=true;
			Assert::IsTrue(flag);
		}

	};
}
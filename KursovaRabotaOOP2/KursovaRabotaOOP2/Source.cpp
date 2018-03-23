#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <vector>
#include <iterator>
#include <numeric>
#include <algorithm>
#include <math.h>

using namespace std;

class CShape {
	private:
		string m_strType;

	public:
		//CShape(const string &name);

		CShape()
		{
			m_strType = "None";
		}

		CShape(string t)
		{
			m_strType = t;
		}

		string GetName()const
		{
			return m_strType;
		}
		
		void SetName(string t)
		{
			m_strType = t;
		}

};

class CRectangle:public CShape {
	private:   
		int m_intW;
		int m_intH;

	public:
		CRectangle()
		{
			m_intW = 1;
			m_intH = 1;
		}
		CRectangle(const string & name, int W, int H) :CShape(name) {
			m_intW = W;
			m_intH = H;
		}

		void SetW(int w)
		{
			m_intW = w;
		}
		void SetH(int h)
		{
			m_intH = h;
		}

		int GetW()const
		{
			return m_intW;
		}
		int GetH()const
		{
			return m_intH;
		}

		double GetPerimeter()const {
			return 2 * GetW() + 2 * GetH();
		}
		double GetArea()const {
			return GetH()*GetW();
		}

		

		friend ostream& operator << (ostream & toStream, const CRectangle & A)
		{
		//toStream << "Perimeter is " << A.m_intR << endl;
		toStream << "The area of the rectangle is " << A.GetArea() << endl;
		toStream << "The Perimeter is " << A.GetPerimeter() << endl;
		return toStream;
		}

};

class CCircle : public CShape
{
private:
	int m_intR;

public:
	CCircle() 
	{
		m_intR = 1;
	}
	double GetPerimeter()const 
	{
		return 2 * 3.14 * m_intR;
	}
	double GetArea()const 
	{
		return 3.14 * m_intR*m_intR;
	}

	CCircle(const string & name, int R) : CShape(name)
	{
		m_intR = R;
	}

	friend ostream& operator << (ostream & toStream, const CCircle & A)
	{
		//toStream << "Radius of circle is " << A.m_intR << endl;
		toStream << "The area of the circle is " << A.GetArea() << endl;
		toStream << "The Perimeter is " << A.GetPerimeter() << endl;
		return toStream;
	}

};

class CTriangle : public CShape {

private:
	int m_intA;
	int m_intB;
	int m_intC;

public:
	CTriangle()
	{
		m_intA = 1;
		m_intB = 1;
		m_intC = 1;
	}
	double GetPerimeter()const
	{
		return m_intA + m_intB + m_intC;
	}
	double GetArea()const
	{
		int a = m_intA;
		int b = m_intB;
		int c = m_intC;

		int p = (a + b + c) / 2;
		return sqrt(p*(p - a)*(p - b)*(p - c));
	}

	CTriangle(const string & name, int a, int b, int c) : CShape(name)
	{
		m_intA = a;
		m_intB = b;
		m_intC = c;

	}

	friend ostream& operator << (ostream & toStream, const CTriangle & A)
	{
		//toStream << "Radius of circle is " << A.m_intR << endl;
		toStream << "The area of the triangle is " << A.GetArea() << endl;
		toStream << "The Perimeter is " << A.GetPerimeter() << endl;
		return toStream;
	}

};

int main()
{
	CRectangle A("R", 20, 10);
	cout << A;
	CCircle B("C", 10);
	cout << B;
	CTriangle C("T", 20, 30, 40);
	cout << C;

}
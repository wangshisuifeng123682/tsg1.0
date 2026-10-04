#pragma once
#include<iostream>
#include<string>
using namespace std;
class TriangleItem
{
public:
	TriangleItem();
	void set(int a, int b, int c);
	void printTriangle();
	bool isTriangle();
	int calperimeter();
	double calarea();
	void flow();//Á÷³Ì
	bool isRight();
	double getArea() {return m_area;};
	double getUArea() { return m_uarea; };
	int geta() { return m_a; };
	int getb() { return m_b; };
	int getc() { return m_c; };
	int getPerimeter() { return m_perimeter; };
	int getUPerimeter() { return m_uperimeter; };
	int getId() { return m_Id; };
	void showquestion();
	void setId(int id) { m_Id = id; }; 
	int getScore() { return m_score; };
private:
	double m_area;
	double m_uarea;
	int m_a;
	int m_b;
	int m_c;
	int  m_perimeter;
	int m_uperimeter;
	int m_score;
	int m_Id;
};

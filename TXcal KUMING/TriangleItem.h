#pragma once
class TriangleItem
{
public:
	TriangleItem();
	void set(int a, int b, int c);
	void printTriangle();
	bool isTriangle();
	int calperimeter();
	double calarea();
	void flow();//流程
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
private:
	double m_area;
	double m_uarea;a
	int m_a;
	int m_b;
	int m_c;
	int  m_perimeter;
	int m_uperimeter;
	int m_score;
	int m_Id;
};
TriangleItem::TriangleItem()
{
	m_a = 0;
	m_b = 0;
	m_c = 0;
	m_area = 0;
	m_uarea = 0;
	m_perimeter = 0;
	m_uperimeter = 0;
	m_score = 0;
	m_Id = 0;
}//构造函数
void TriangleItem::showquestion()
{
	cout << "题目编号：" << m_Id << endl;
	cout << "三角形的三条边为：" << m_a << " " << m_b << " " << m_c << endl;
	cout << "请计算该三角形的周长和面积" << endl;
}//显示题目	
void TriangleItem::calarea()
{
	double p = (m_a + m_b + m_c) / 2.0;
	m_area = sqrt(p * (p - m_a) * (p - m_b) * (p - m_c));
}//计算面积
void TriangleItem::set(int a, int b, int c)
{
	m_a = a;
	m_b = b;
	m_c = c;
}//修改三角形三条边
bool TriangleItem::isTriangle()
{
	if (m_a + m_b > m_c && m_a + m_c > m_b && m_b + m_c > m_a)
		return true;
	else
		return false;
}//判断是否为三角形	
int TriangleItem::calperimeter()
{
	m_perimeter = m_a + m_b + m_c;
	return m_perimeter;
}//计算周长
void TriangleItem::printTriangle()
{
	cout << m_perimeter << " " << m_area << endl;
}//输出答案	
bool TriangleItem::isRight()
{
	if(m_uperimeter == m_perimeter && m_uarea == m_area)
		m_score+= 10;
		return true;
	else
		return false;
}//判断用户答案是否正确
void TriangleItem::flow()
{
	cout << "请输入三角形的三条边：" << endl;
	cin >> m_a >> m_b >> m_c;
	if (isTriangle())
	{
		calperimeter();
		calarea();
		cout << "请输入三角形的周长和面积：" << endl;
		cin >> m_uperimeter >> m_uarea;
		if (isRight())
			cout << "恭喜你获得10分，回答正确！" << endl;
		else
			cout << "很遗憾，回答错误！" << endl;
	}
	else
		cout << "输入的三条边不能构成三角形，请重新输入！" << endl;
}//流程	

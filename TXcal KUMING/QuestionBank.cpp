#include "QuestionBank.h"


QuestionBank::QuestionBank(string name)
{
	BankName = name;
	count = 0;
	currentcount = 0;
	donecount = 0;
	correctnum = 0;
	totalScore = 0;
	capcity = 10;
	triangleItem = new TriangleItem[capcity];
}//初始化

void QuestionBank::expandCapacity()
{
	capcity *= 2;
	TriangleItem* newTriangleItem = new TriangleItem[capcity];
	for (int i = 0; i < currentcount; i++)
	{
		newTriangleItem[i] = triangleItem[i];
	}
	delete[] triangleItem;
	triangleItem = newTriangleItem;
}//扩容

void QuestionBank::addTriangleItem(TriangleItem item)
{
	if (currentcount >= capcity)
	{
		expandCapacity();
	}
	triangleItem[currentcount] = item;
	currentcount++;
	count++;
}//添加三角形题目

void QuestionBank::deleteTriangleItem(int id)
{
	for (int i = 0; i < currentcount; i++)
	{
		if (triangleItem[i].getId() == id)
		{
			for (int j = i; j < currentcount - 1; j++)
			{
				triangleItem[j] = triangleItem[j + 1];
			}
			currentcount--;
			count--;
			cout << "题目编号为" << id << "的题目已删除" << endl;
			return;
		}
	}
	cout << "未找到题目编号为" << id << "的题目" << endl;
}//删除题目

void QuestionBank::queryTriangleItem(int id)
{
	for (int i = 0; i < currentcount; i++)
	{
		if (triangleItem[i].getId() == id)
		{
			triangleItem[i].showquestion();
			return;
		}
	}
	cout << "未找到题目编号为" << id << "的题目" << endl;
}//查询题目

void QuestionBank::showAllTriangleItems()
{
	if (currentcount == 0)
	{
		cout << "题库为空" << endl;
		return;
	}
	for (int i = 0; i < currentcount; i++)
	{
		triangleItem[i].showquestion();
	}
}//显示所有题目

void QuestionBank::answerTriangleItem(int id, int perimeter, double area)
{
	for (int i = 0; i < currentcount; i++)
	{
		if (triangleItem[i].getId() == id)
		{
			if (triangleItem[i].calperimeter() == perimeter && triangleItem[i].getArea() == area)
			{
				cout << "回答正确" << endl;
				correctnum++;
				totalScore += triangleItem[i].getScore();
			}
			else
			{
				cout << "回答错误" << endl;
			}
			donecount++;
			return;
		}
	}
	cout << "题目编号不存在" << endl;
}//回答题目

QuestionBank::~QuestionBank()
{
	delete[] triangleItem;
}//释放内存

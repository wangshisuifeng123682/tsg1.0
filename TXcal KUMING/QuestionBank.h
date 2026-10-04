#pragma once
class QuestionBank
{
private:
	string BankName;//题库名称
	int count;//题目数量
	TriangleItem* triangleItems;
	int currentcount;//当前题目数量
	int donecount;//已完成题目数量
	int correctnum//正确题目数量
	int totalScore;//总分数
	int capcity;//容量

public:
	QuestionBank(string name);
	string getBankName() { return BankName; };//获取题库名称
	int AverageScore() { return totalScore / donecount; };//平均分数
	int getdonecount() { return donecount; };//已完成题目数量
	void setBankName(string name) { BankName = name; };//设置题库名称
	int gettotalScore() { return totalScore; };//获取总分数
	int getcorrectnum() { return correctnum; };//获取正确题目数量
	void expandCapacity();//扩容
	void addTriangleItem(TriangleItem item);//添加三角形题目
	void deleteTriangleItem(int id);//删除题目
	void queryTriangleItem(int id);//查询题目
	void showAllTriangleItems();//显示所有题目
	void answerTriangleItem(int id, int perimeter, double area);//回答题目
};

QuestionBank::QusestionBank(string name)：bankName(name), count(0), currentcount(0), maxsize(10), donecount(0), correctcount(0), totalScore(0)
{
	triangleItems = new TriangleItem[capcity];
}//初始化

QuestionBank::~QuestionBank()
{
	delete[] triangleItems;
	triangleItems = NULL;
}

void QuestionBank::expandCapacity()
{
	capcity *= 2;
	TriangleItem* newItems = new TriangleItem[capcity];
	for (int i = 0; i < currentcount; i++)
	{
		newItems[i] = triangleItems[i];
	}
	delete[] triangleItems;
	triangleItems = newItems;
}//扩容

void QuestionBank::addTriangleItem(TriangleItem item)
{
	if (currentcount >= capcity)
	{
		expandCapacity();
	}
	triangleItems[currentcount] = item;
	currentcount++;
	count++;
}//添加题目

void QuestionBank::deleteTriangleItem(int id)
{
	for (int i = 0; i < currentcount; i++)
	{
		if (triangleItems[i].getId() == id)
		{
			for (int j = i; j < currentcount - 1; j++)
			{
				triangleItems[j] = triangleItems[j + 1];
			}
			currentcount--;
			count--;
			return;
		}
	}
	cout << "题目编号不存在" << endl;
}//删除题目	

void QuestionBank::queryTriangleItem(int id)
{
	for (int i = 0; i < currentcount; i++)
	{
		if (triangleItems[i].getId() == id)
		{
			triangleItems[i].showquestion();
			return;
		}
	}
	cout << "题目编号不存在" << endl;
}//查询题目

void QuestionBank::showAllTriangleItems()
{
	for (int i = 0; i < currentcount; i++)
	{
		triangleItems[i].showquestion();
	}
}//显示所有题目

void QuestionBank::answerTriangleItem(int id, int perimeter, double area)
{
	for (int i = 0; i < currentcount; i++)
	{
		if (triangleItems[i].getId() == id)
		{
			if (triangleItems[i].calperimeter() == perimeter && triangleItems[i].getUPerimeter() == area)
			{
				cout << "回答正确" << endl;
				correctnum++;
				totalScore += triangleItems[i].getScore();
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
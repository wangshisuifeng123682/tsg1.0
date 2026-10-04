#pragma once
#include <iostream> 
#include <string>
#include "TriangleItem.h" 
using namespace std;
class QuestionBank
{
private:
	string BankName;//题库名称
	int count;//题目数量
	TriangleItem* triangleItem;//运用指针来体现类之间的组合关系
	int currentcount;//当前题目数量
	int donecount;//已完成题目数量
	int correctnum;//正确题目数量
	int totalScore;//总分数
	int capcity;//容量

public:
	QuestionBank(string name);
	string getBankName() { return BankName; };//获取题库名称
	int AverageScore() { if (donecount == 0) return 0;else return  totalScore / donecount; };//平均分数
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
	~QuestionBank();
};



#include<iostream>
#include<cmath>

#include "QuestionBank.h"
#include <string>
#include<vector>
using namespace std;
int main()
{   
	 QuestionBank bank("三角形计算题题库");

    // 构造第1题：3 4 5 直角三角形，id=1
    TriangleItem t1;
    t1.setId(1);
    t1.set(3,4,5);
    t1.calperimeter();
    t1.calarea();
    bank.addTriangleItem(t1);

    // 第2题：5 5 6，id=2
    TriangleItem t2;
    t2.setId(2);
    t2.set(5,5,6);
    t2.calperimeter();
    t2.calarea();
    bank.addTriangleItem(t2);

    // 第3题：6 8 10，id=3
    TriangleItem t3;
    t3.setId(3);
    t3.set(6,8,10);
    t3.calperimeter();
    t3.calarea();
    bank.addTriangleItem(t3);


    cout << "===== 1. 显示题库所有题目 =====" << endl;
    bank.showAllTriangleItems();

    cout << "\n===== 2. 查询id=2的题目 =====" << endl;
    bank.queryTriangleItem(2);

    cout << "\n===== 3. 答题：id=1，正确答案周长12，面积6 =====" << endl;
    bank.answerTriangleItem(1, 12, 6.0);

    cout << "\n===== 4. 答题：id=3，故意答错，周长24，面积23 =====" << endl;
    bank.answerTriangleItem(3, 24, 23.0);

    cout << "\n===== 5. 删除id=2题目 =====" << endl;
    bank.deleteTriangleItem(2);

    cout << "\n===== 6. 删除后，显示全部题目 =====" << endl;
    bank.showAllTriangleItems();

    cout << "\n===== 统计信息 =====" << endl;
    cout << "已完成题目数量：" << bank.getdonecount() << endl;
    cout << "答对题目数量：" << bank.getcorrectnum() << endl;
    cout << "总得分：" << bank.gettotalScore() << endl;
    cout << "平均得分：" << bank.AverageScore() << endl;
	return 0;
}
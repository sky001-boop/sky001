#pragma once
#include <iostream>
using namespace std;
#include<string>
class worker{
public:
	//显示职工信息
	virtual void showInfo() = 0;


	//获取岗位信息
	virtual string getDeptname() = 0;
	int m_id;
	string m_name;
	int m_Dept_id;

};
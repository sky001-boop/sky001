#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

//class boss :public worker { //继承
//public:
//	boss(int id, string name, int did);
//	//显示职工信息
//	virtual void showInfo();
//
//
//	//获取岗位信息
//	virtual string getDeptname();
//};
class boss :public worker {
public:
	boss(int id, string name, int did);
	virtual void showInfo();
	virtual string getDeptname();
};
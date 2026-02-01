#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

class employee:public worker { //继承
public:
	employee(int id, string name,int did);
	//显示职工信息
	virtual void showInfo();


	//获取岗位信息
	virtual string getDeptname() ;
};
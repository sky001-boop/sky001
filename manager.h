#pragma once
#include <iostream>
#include "worker.h"
using namespace std;

class manager :public worker { //继承
public:
	manager(int id, string name, int did);
	//显示职工信息
	virtual void showInfo();


	//获取岗位信息
	virtual string getDeptname();
};
#pragma once
#include <iostream>
using namespace std;
#include "worker.h"
#include "boss.h";
#include"employee.h"
#include"manager.h"
#include <fstream>
#define FILENAME "emFile.txt"
class Workermanager 
{
public:
	Workermanager();
	void show_menu();
	void ExitSystem();
	~Workermanager();
	int m_EmpNum;

	worker** m_EmpArray;//职工数组指针
	void addEmp();//添加成员
	void save();//保存文件
	bool m_FileIsempty;//文件是否为空
	int get_Empnum();//统计文件中人数
	void init_Emp();//初始化员工
	void show_Emp();//显示员工
	void Del_Emp();//删除职工
	int IsExist(int id);//判断职工是否存在,返回数组索引
	void Mod_Emp();//修改信息
	void Find_Emp();//查找信息
	void Clean_File();//清空
	void Sort_Emp();
};
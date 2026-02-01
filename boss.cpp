#include "boss.h"

//构造函数
boss::boss(int id, string name, int did) {
	this->m_id = id;
	this->m_name = name;
	this->m_Dept_id = did;

}
//显示职工信息
void boss::showInfo() {
	cout << "职工编号:" << this->m_id
		<< "\t职工姓名:" << this->m_name
		<< "\t\t岗位:" << this->getDeptname()
		<< "\t岗位职责：管理公司所有事务" << endl;

}


//获取岗位信息
string boss::getDeptname() {
	return string("总裁");

}



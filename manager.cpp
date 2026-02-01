#include "manager.h"

//构造函数
manager::manager(int id, string name, int did) {
	this->m_id = id;
	this->m_name = name;
	this->m_Dept_id = did;

}
//显示职工信息
void manager::showInfo() {
	cout << "职工编号:" << this->m_id
		<< "\t职工姓名:" << this->m_name
		<< "\t\t岗位:" << this->getDeptname()
		<< "\t岗位职责：完成老板交给的任务，并且下发任务给员工" << endl;

}


//获取岗位信息
string manager::getDeptname() {
	return string("经理");

}



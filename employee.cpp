#include"employee.h"

//构造函数
	employee::employee(int id, string name, int did) {
		this->m_id = id;
		this->m_name = name;
		this->m_Dept_id = did;

	}
	//显示职工信息
	void employee::showInfo() {
		cout << "职工编号:" << this->m_id
			<< "\t职工姓名:" << this->m_name
			<< "\t\t岗位:" << this->getDeptname()
			<< "\t岗位职责：完成经理给的任务" << endl;

	}


	//获取岗位信息
	string employee::getDeptname() {
		return string("员工");

	}



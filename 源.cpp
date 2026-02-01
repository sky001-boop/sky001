#include<iostream>
using namespace std;
#include "Workermanager.h"
#include"worker.h"
#include"employee.h"
#include "manager.h"
#include "boss.h"
int main() {
	////测试代码
	//worker* worker = NULL;
	//worker = new employee(1, "张三", 1);
	//worker->showInfo();
	//delete worker;
	//
	//worker = new manager(2, "李四",2);
	//worker->showInfo();
	//delete worker;

	//worker = new boss(3, "王五", 3);
	//worker->showInfo();
	//delete worker;
	//实例化管理对象
	Workermanager wm;
	int choice=0;
	while (true) {
		wm.show_menu();
		cout << "请输入你的选择:" << endl;
		cin >> choice;
		switch (choice) {
		case 0://退出系统
			wm.ExitSystem();

			break;
		case 1://增加职工
			wm.addEmp();
			break;
		case 2://显示职工
			wm.show_Emp();
			break;
			
		case 3://删除职工
			wm.Del_Emp();
			break;
		case 4://修改职工
			wm.Mod_Emp();
			break;
		case 5://查找职工
			wm.Find_Emp();
			break;
		case 6://排序职工
			wm.Sort_Emp();
			break;
		case 7://清空文档
			wm.Clean_File();
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");

	return 0;
}
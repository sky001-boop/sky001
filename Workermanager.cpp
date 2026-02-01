#include "Workermanager.h"

Workermanager::Workermanager() {
	//文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读文件
		if (!ifs.is_open() ){//文件不存在
			//cout << "文件不存在"<<endl;可开关
			this->m_EmpNum = 0;
			this->m_EmpArray = NULL;
			this->m_FileIsempty = true;
			ifs.close();
			return;
	}
		char ch;
		ifs >> ch;
		if (ifs.eof() ){//文件存在，为空
			//cout<<"文件为空"<<endl;可开关
			this->m_EmpNum = 0;
			this->m_EmpArray = NULL;
			this->m_FileIsempty = true;
			ifs.close();
			return;

		}
		//文件存在，不为空
		int num = this->get_Empnum();
		//cout << "职工人数为：" << num << endl;
		this->m_EmpNum = num;
		this->m_EmpArray = new worker * [this->m_EmpNum];//开辟空间
		this->init_Emp();//文件内容存到数组
		//for (int i = 0; i < this->m_EmpNum; i++) {
		//	cout << "职工编号：" << this->m_EmpArray[i]->m_id
		//		<< " 姓名：" << this->m_EmpArray[i]->m_name
		//		<< " 部门：" << this->m_EmpArray[i]->m_Dept_id << endl;

		//}

}

Workermanager::~Workermanager() {
	if (this->m_EmpArray != NULL) {

		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}
void Workermanager::show_menu() {
	cout << "**************************************************" << endl;
	cout << "***************欢迎使用职工管理系统***************" << endl;
	cout << "******************0.退出管理程序******************" << endl;
	cout << "******************1.增加职工信息******************" << endl;
	cout << "******************2.显示职工信息******************" << endl;
	cout << "******************3.删除离职职工******************" << endl;
	cout << "******************4.修改职工信息******************" << endl;
	cout << "******************5.查找职工信息******************" << endl;
	cout << "******************6.按照编号排序******************" << endl;
	cout << "******************7.清空所有文档******************" << endl;
	cout << "**************************************************" << endl;
}
void Workermanager::ExitSystem() {
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}
void Workermanager:: save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//用输出的方式打开文件----写文件
	for (int i = 0; i < this->m_EmpNum;i++) {
		ofs << this->m_EmpArray[i]->m_id << " "
			<< this->m_EmpArray[i]->m_name << " "
			<< this->m_EmpArray[i]->m_Dept_id << endl;

	}
	ofs.close();
}

	void Workermanager::addEmp() {
		cout << "请输入添加职工的数量" << endl;
		int addNum = 0;
		cin >> addNum;
		if (addNum > 0) {
			//添加
			//计算新空间大小
			int newsize = this->m_EmpNum + addNum;//新空间人数=原来的+新增的
			//开辟
			worker** newspace = new worker * [newsize];//二级指针数组存放一级指针
			//将原来的空间下数据，拷贝到新空间下
			if (this->m_EmpNum != NULL) {

				for (int i = 0; i < this->m_EmpNum; i++) {
					newspace[i] = this->m_EmpArray[i];
				}
			}
				for (int i = 0; i < addNum; i++) {
					//批量添加新数据
					int id;
					string name;
					int dSelect;
					cout << "请输入第" << i + 1 << "个职工的编号：";
					cin >> id;
					cout << "请输入第" << i + 1 << "个职工的姓名：";
					cin >> name;
					cout << "请选择该职工的岗位：" << endl;
					cout << "1.普通员工"<<endl;
					cout << "2.经理" << endl;
					cout << "3.总裁" << endl;
					cin >> dSelect;

					worker* worker = NULL;
					switch (dSelect)
					{
					case 1:
						worker = new employee(id, name, 1);
						break;
					case 2:
						worker = new manager(id, name, 2);
						break;
					case 3:
						worker = new boss(id, name, 3);
						break;
					default:
						break;
					}
					//将创建的职工职责，保存到数组中
					newspace[this->m_EmpNum+i] = worker;
				}
			
			delete[]this->m_EmpArray;//释放数组加[]
			this->m_EmpArray = newspace;//更新
			this->m_EmpNum = newsize;//更新
			//保存到文件中
			this->m_FileIsempty = false;
			cout << "成功添加" << addNum << "名员工" << endl;
			this->save();

		}
		else
		{
			cout << "输入有误" << endl;
		}
		system("pause");
		system("cls");
	}
	int Workermanager::get_Empnum() {
		ifstream ifs;
		ifs.open(FILENAME,ios::in);//读文件
		int id;
		string name;
		int did;
		int num = 0;
		while (ifs>>id&&ifs>>name&&ifs>>did) {
			num++;
		}
		return num;//为了读取完开辟空间
	}
	void Workermanager::init_Emp() {
		int id;
		string name;
		int did;
		int index = 0;
		ifstream ifs;
		ifs.open(FILENAME, ios::in);

		while (ifs>>id&&ifs>>name&&ifs>>did) {//ifs读取文件内容，忽略空格，直到遇到下一个字符
			worker* worker = NULL;
			if (did == 1) {//员工
				worker = new employee(id, name, did);
			}
			else if (did == 2) {//经理
					worker = new manager(id, name, did);
			}
			else{//老板
				worker = new boss(id, name, did);
			}
			this->m_EmpArray[index] = worker;
			index++;
		}
		ifs.close();
	}

	void Workermanager::show_Emp() {
		if (this->m_FileIsempty) {
			cout << "文件不存在或者记录为空" << endl;
		}
		else {
			for (int i = 0; i < this->m_EmpNum; i++) {
				//利用多态调用程序接口
				this->m_EmpArray[i]->showInfo();//不同的对象打印出来的结果不同
			}
		}
		system("pause");//按任意键
		system("cls");//清屏
	}
	void Workermanager::Del_Emp() {
		if (this->m_FileIsempty) {
			cout << "文件不存在或记录为空" << endl;
		}
		else {
			cout << "请输入你想要删除的职工编号：" << endl;
			int id = 0;
			cin >> id;
			int index = this->IsExist(id);//判断是否存在这个员工
			if (index != -1) {
				for (int i = index; i < this->m_EmpNum - 1; i++) {//数组数据前移
					this->m_EmpArray[i] = this->m_EmpArray[i + 1];
				}
				this->m_EmpNum--;//更新记录人数
				//同步文件
				this->save();
				cout << "删除成功" << endl;
			}
			else {
				cout << "删除失败，未找到该员工" << endl;
			}
		}
		system("pause");
		system("cls");
	}
	int Workermanager::IsExist(int id) {
		int index = -1;
		for (int i = 0; i < m_EmpNum; i++) {
			if (this->m_EmpArray[i]->m_id==id) {
				index = i;
				break;
			}
			
		}

		return index;//返回索引
	}

	void Workermanager::Mod_Emp() {
		if (this->m_FileIsempty) {
			cout << "文件不存在或文件为空" << endl;
		}
		else {
			cout << "请输入修改职工的编号" << endl;
			int id;
			cin >> id;
			int ret = this->IsExist(id);
			if (ret != -1) {
				delete this->m_EmpArray[ret];
				int newId = 0;
				string newName = "";
				int dSelect = 0;
				cout << "查找到：" << id << "号职工，请输入新职工号" << endl;
				cin >> newId;
				cout << "请输入新姓名：" << newName;
				cin >> newName;
				cout << "请输入新岗位：" << endl;
				cout<< "1.普通职工" << endl;
				cout << "2.经理" << endl;
				cout << "3.总裁" << endl;
				cin >> dSelect;
				worker* worker = NULL;//父类指针
				switch(dSelect){
					case 1:
						worker = new employee(newId, newName, dSelect);
						break;
					case 2:
						worker = new manager(newId, newName, dSelect);
						break;
					case 3:
						worker = new boss(newId, newName, dSelect);
						break;
					default:
						break;
				}
				this->m_EmpArray[ret] = worker;
				cout << "修改成功" << endl;
				this->save();

			}
			else {
				cout << "修改失败，查无此人！" << endl;
			}
		}
		system("pause");
		system("cls");
	}
	void Workermanager::Find_Emp() {/////////////////////编号冲突？只允许有一个编号，添加的时候判断////////////////////
		if (this->m_FileIsempty) {
			cout << "文件不存在或记录为空！" << endl;
		}
		else {
			cout << "1.按职工编号查找" << endl;
			cout << "2.按职工姓名查找" << endl;
			int select = 0;
			cin >> select;
			if (select == 1) {
				int id;
				cout << "请输入要查找的编号：" << endl;
				cin >> id;
				int ret = this->IsExist(id);
				if (ret != -1) {
					cout << "查找成功！该职工的信息如下：" << endl;//先判断职工是否存在
					this->m_EmpArray[ret]->showInfo();//利用多态
				}
				else {
					cout << "查找失败！查无此人" << endl;
				}
			}
			else if (select == 2) {
				string name;
				bool flag = false;
				cout << "请输入你要查找的姓名：" << endl;
				cin >> name;

				for (int i = 0; i < this->m_EmpNum; i++) {
					if (this->m_EmpArray[i]->m_name == name) {
						cout <<endl<< "查找成功！职工编号为：" << this->m_EmpArray[i]->m_id<< "号"<<endl<<"该职工信息如下：" << endl<<endl;
						flag = true;
						this->m_EmpArray[i]->showInfo();

					}
				}
				if (flag == false) {
					cout << "查找失败！查无此人" << endl;
				}
			}
			else {
				cout << "输入的选项有误！" << endl;
			}

		}
		system("pause");
		system("cls");
	}


	void Workermanager::Clean_File(){
		cout << "确认清空？" << endl;
		cout << "1.确定" << endl;
		cout << "2.返回" << endl;

		int select = 0;
		cin >> select;
		if (select == 1) {
			ofstream ofs;
			ofs.open(FILENAME, ios::trunc);//删除文件后重新创建
			ofs.close();
		}
		//删除堆区每个对象
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				delete this->m_EmpArray[i];//清空数组中对象占用的内容空间
				this->m_EmpArray[i] = NULL;//清除对象指针，防止成为野指针
			}
			delete[] this->m_EmpArray;//数组存放的是指针，需要清除两次，这次清除数组占用的内存
			this->m_EmpArray = NULL;

			this->m_EmpNum = 0;
			this->m_FileIsempty = true;

		}
		cout << "清空成功！"<<endl;

		system("pause");
		system("cls");
	}
	void Workermanager::Sort_Emp() {
		//首先判断文件是否为空
		if (this->m_FileIsempty) {
			cout << "文件不存在或记录为空！" << endl;
			system("pause");
			system("cls");
		}
		else {
			cout << "请选择排序方式：" << endl;
			cout << "1.按职工号进行升序" << endl;
			cout << "2.按职工号进行降序" << endl;
			int choice = 0;////////选择排序，选一个最小值，同向遍历所有，交换，共num-1轮/////////
			cin >> choice;
			if (choice != 1 && choice != 2) {
				cout << "输入有误！" << endl;
				system("pause");
				system("cls");
			}
			else {
				for (int i = 0; i < this->m_EmpNum; i++)
				{
					int x = i;
					if (choice == 1) {
						for (int j = i + 1; j < this->m_EmpNum; j++) {
							if (this->m_EmpArray[j]->m_id < this->m_EmpArray[x]->m_id) {
								x = j;
							}
						}

					}

					else if (choice == 2) {
						for (int j = i + 1; j < this->m_EmpNum; j++) {
							if (this->m_EmpArray[j]->m_id > this->m_EmpArray[x]->m_id) {
								x = j;
							}
						}
					}
					if (i != x) {
						worker* temp = this->m_EmpArray[i];
						this->m_EmpArray[i] = this->m_EmpArray[x];
						this->m_EmpArray[x] = temp;
					}
				}
				cout << "排序完成！排序后的结果为：" << endl;
				this->save();
				this->show_Emp();
			}
		}
	}
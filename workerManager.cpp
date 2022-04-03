#include "workerManager.h"
#include "worker.h"
#include <fstream>
workerManager::workerManager()
{
	std::ifstream ifs;
	
	ifs.open("d://workerData.txt", std::ios::in);
	//如果不存在，打开失败
	if (!ifs)
	{
		workerSize = 0;
		pArray = nullptr;
		isFileEmpty = true;
		ifs.close();
		return;
	}
	//存在但是为空
	char get;
	ifs.get(get);
	//文件为空->eof（true）
	if (ifs.eof())
	{
		workerSize = 0;
		pArray = nullptr;
		isFileEmpty = true;
		ifs.close();
		return;
	}
	//存在文件且文件不为空
	//workerSize获得文件中的数据个数
	workerSize = getFileNum();
	//创建指针数组
	pArray = new worker * [workerSize];
	//创建指针中的数据
	initArray();
	isFileEmpty = false;
}
workerManager::~workerManager()
{

}

void workerManager::showConsle()
{
	std::cout << "*********************************" << std::endl;
	std::cout << "***   欢迎使用职工管理系统  *****" << std::endl;
	std::cout << "*****   0、退出管理程序   *******" << std::endl;
	std::cout << "*****   1、增加职工信息   *******" << std::endl;
	std::cout << "*****   2、显示职工信息   *******" << std::endl;
	std::cout << "*****   3、删除离职职工   *******" <<std:: endl;
	std::cout << "*****   4、修改职工信息   *******" << std::endl;
	std::cout << "*****   5、查找职工信息   *******" << std::endl;
	std::cout << "*****   6、按照编号排序   *******" << std::endl;
	std::cout << "*****   7、清空所有文档   *******" << std::endl;
	std::cout << "*********************************" << std::endl;
	return;
}
//增加职工	
void workerManager::addWorker()
{
	int inputNum(0);
	std::cout << "请输入增加的职工的数量" << std::endl;
	std::cin >> inputNum;
	if (inputNum > 0)
	{
		int newN(this->workerSize + inputNum);
		worker** newData = new worker * [newN];
		//录入之前数据 ,创建边长的数组
		if (this->pArray != nullptr)
		{
			for (int i(0); i < workerSize; i++)
			{
				newData[i] = this->pArray[i];
			}
		}
		//需要录入的数据 
		for (int i(0); i < inputNum; i++)
		{
			int id;
			int did;
			std::string name;
			//录入新数据
			std::cout << "请输入第 " << i + 1 << " 个新职工编号" << std::endl;
			std::cin >> id;
			std::cout << "请输入第 " << i + 1 << " 个新职工姓名" << std::endl;
			std::cin >> name;
			std::cout << "请选择该职工岗位：" << std::endl;
			std::cout << "1、普通职工" << std::endl;
			std::cout << "2、经理" << std::endl;
			std::cout << "3、老板" << std::endl;
			std::cin >> did;
			worker* midData = nullptr;
			//通过did确定子类的实例化对象
			if(!i)
			{
				delete[]this->pArray;//删除了指向数组的指针
				pArray = newData;
			}
			switch (did)
			{
				//普通员工
			case 1:
			{
				//数组还没有变长
				midData = new person(id, name, did);
				pArray[this->workerSize + i] = midData;
				break;
			}
			//经理
			case 2:
			{
				midData = new manager(id, name, did);
				pArray[this->workerSize + i] = midData;
				break;
			}
			//老板
			case 3:
			{
				midData = new boss(id, name, did);
				pArray[this->workerSize + i] = midData;
				break;
			}
			default:
			{
				break;
			}
			}
		}
			//录入数据
			this->workerSize = newN;
			isFileEmpty = false;
	}
	//录入文件
	std::ofstream ofs;
	ofs.open("d://workerData.txt", std::ios::out);
	if (!ofs)
	{
		std::cerr << "文件打开失败" << std::endl;
	}
	for (int i(0);i<workerSize;i++)
	{
		ofs<<pArray[i]->name<<std::endl;
		ofs << pArray[i]->id<< std::endl;
		ofs << pArray[i]->did << std::endl;
	}
	ofs.close();
}
//显示职工信息
void workerManager::showWorker()
{
	for (int i(0);i<workerSize;i++)
	{
		std::cout << "员工姓名:" << pArray[i]->name << std::endl;
		std::cout << "员工编号:" << pArray[i]->id<< std::endl;
		std::cout << "员工职位:" << pArray[i]->did << std::endl << std::endl;
	}
	return;
}
//删除职工
void workerManager::delWorker()
{
	if (!isFileEmpty)
	{
		std::cout << "数据为空" << std::endl;
		return;
	}
	int id,i(0);
	std::cout << "请输入员工编号:" << std::endl;
	std::cin >> id;
	//如果找到就跳出
	for (;i<workerSize;i++)
	{
		if (pArray[i]->id==id)
		{
			break;
		}
	}
	//没找到数据
	if (i==workerSize)
	{
		std::cout << "未找到数据" << std::endl;
		return;
	}
	//找到数据
	//删除最后一位PArray[workerSize-1]
	if (i==workerSize-1)
	{
		worker** newOne = new worker * [workerSize - 1];
		for (int i(0);i<workerSize-1;i++)
		{
			//拷贝数据 
			newOne[i] = pArray[i];
		}
		delete []pArray;
		 //指向newOne内存，通过delete [] pArray来释放
		pArray = newOne;
		//减数据方便之后录文件
		workerSize--;
	}
	else
	{
		//不是最后一位
		for (; i < workerSize - 1; i++)
		{
			//向前移动一位，覆盖数据 
			pArray[i] = pArray[i + 1];
		}
		workerSize--;
	}
	//写入数据
	std::ofstream ofs;
	ofs.open("d://workerData.txt", std::ios::out);
	if (!ofs)
	{
		std::cerr << "void workerManager::showWorker() ofs file error" << std::endl;
	}
	for (int i(0);i<workerSize;i++)
	{
		ofs << pArray[i]->name << std::endl;
		ofs << pArray[i]->id << std::endl;
		ofs << pArray[i]->did << std::endl;
	}
	ofs.close();
}

int workerManager::getFileNum()
{
	std::ifstream ifs;
	ifs.open("d://workerData.txt", std::ios::in);
	if (!ifs)
	{
		std::cerr << "void workerManager::getFileNum() file open error" << std::endl;
	}
	int id;
	int did;
	char name[20];
	int re(0);
	while (!ifs.eof())
	{
		ifs >> name;
		ifs >> did;
		ifs >> id;
		if (!ifs.eof())
		{
			re++;
		}
	}
	return re;
}

void workerManager::modifyWorker()
{
	//文件为空时
	if (isFileEmpty)
	{
		std::cout << "数据为空" << std::endl;
		return;
	}
	int id;
	int i(0);
	std::cin >> id;
	for (;i<workerSize;i++)
	{
		if (pArray[i]->id==id)
		{
			//数据的重新输入
			std::cout << "已查到 " << this->pArray[i]->id << " 号职工，请输入新职工号" << std::endl;
			std::cin >> this->pArray[i]->id;
			std::cout << "请输入新姓名：" << std::endl;
			std::cin >> this->pArray[i]->name;
			std::cout << "请输入新岗位：" << std::endl;
			std::cout << "1、普通职工" << std::endl;
			std::cout << "2、经理" << std::endl;
			std::cout << "3、老板" << std::endl;
			std::cin >> this->pArray[i]->did;
			//录入文件 
			std::ofstream ofs;
			ofs.open("d://workerData.txt", std::ios::out);
			if (!ofs)
			{
				std::cerr << "workerManager::modifyWorker() ofs open error" << std::endl;
			}
			for (int i(0);i<workerSize;i++)
			{
				ofs << pArray[i]->name << std::endl;
				ofs << pArray[i]->id << std::endl;
				ofs << pArray[i]->did << std::endl;
			}
			ofs.close();
			//这个时刻的i值
			break;
		}
	}
	if (i==workerSize)
	{
		std::cout << "未找到数据" << std::endl;
	}
}
//查找职工信息
void workerManager::seletWorker()
{
	//判断文件是否为空
	if (isFileEmpty)
	{
		std::cout << "数据为空" << std::endl;
	} 
	int i(0),id;
	std::cin >> id;
	for (;i<workerSize;i++)
	{
		if (pArray[i]->id==id)
		{
			std::cout << pArray[i]->name<<std::endl;
			std::cout << pArray[i]->id << std::endl;
			std::cout << pArray[i]->did << std::endl;
			break;
		}
	}
	if (i==workerSize)
	{
		std::cout << "未找到数据" << std::endl;
	}
}
//从文件录入数据
void workerManager::initArray()
{
	std::ifstream ifs;
	int id, did;
	std::string name;
	ifs.open("d://workerData.txt", std::ios::in);
	if (!ifs)
	{
		std::cout << "workerManager::initArray() ifs open error" << std::endl;
	}
	for (int i(0);i<workerSize;i++)
	{
		ifs >> name;
		ifs >> id;
		ifs >> did;
		switch (did)
		{
		case 1:
		{
			pArray[i] = new person(id, name, did);
			break;
		}
		case 2:
		{
			pArray[i] = new manager(id, name, did);
			break;
		}
		case 3:
		{
			pArray[i] = new boss(id, name, did);
			break;
		}
		default:
		{
			std::cerr << "workerManager::initArray() ifs>> did error" << std::endl;
			break;
		}
		}
	}
}
//数组排序
void workerManager::sortArray()
{
	//文件为空
	if (isFileEmpty)
	{
		std::cout << "数据为空" << std::endl;
		return;
	}
	int num(0);
	std::cout << "请选择排序类型：" << std::endl;
	std::cout << "1、按职工编号升序" << std::endl;
	std::cout << "2、按职工编号降序" << std::endl;
	//交换值
	worker* mid = nullptr;
	//获取最大的
	int getk(0);
	int max_id(0);
	std::cin >> num;
	switch (num)
	{	
	//升序
	case 1:
	{
		//在线处理
		//到worksize-2时后就只有一个workersize-1了。
		for ( int i(0);i<workerSize-1;i++)
		{
			//把max_id设置为当前i的id。
			max_id = pArray[i]->id;
			//处理后面的数，故从i起
			for (int k(i);k<workerSize;k++)
			{
				//数据小于等于max_id
				if (pArray[k]->id <= max_id)
				{
					max_id = pArray[k]->id;
					//记录数据
					getk = k;
				}
			}
			mid = pArray[getk];
			pArray[getk] = pArray[i];
			pArray[i] = mid;
		}
		break;
	}
	//降序
	case 2:
	{
		for (int i(0); i < workerSize - 1; i++)
		{
			max_id = pArray[i]->id;
			for (int k(i); k < workerSize; k++)
			{
				if (pArray[k]->id >= max_id)
				{
					max_id = pArray[k]->id;
					getk = k;
				}
			}
			mid = pArray[getk];
			pArray[getk] = pArray[i];
			pArray[i] = mid;
		}
		break;
	}
	default:
	{
		break;
	}
	}
	showWorker();
	//此处不进行文件的存储
}
//清空所有数据(文件、数组)
void workerManager::clearWorker()
{
	//数组不为空
	if (!pArray)
	{
		workerSize = 0;
		delete[]pArray;
		pArray = nullptr;
	}
	//清空文件
	std::fstream fs;
	fs.open("d://workerData.txt", std::ios::trunc);
	if (!fs)
	{
		std::cerr << "清除失败" << std::endl;
	}
	fs.close();
	//文件为空标准为真。
	isFileEmpty = true;
}


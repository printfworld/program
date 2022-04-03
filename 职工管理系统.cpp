#include<iostream>
#include"workerManager.h"

int main()
{
	int controlNum(0);
	workerManager Consle;
	while (true)
	{
		//显示控制台
		Consle.showConsle();
		std::cin >> controlNum;
		switch (controlNum)
		{
		//退出管理系统
		case 0:
		{
			return 0;
			break;
		}
		//增加职工信息
		case 1:
		{
			Consle.addWorker();
			break;
		}
		//显示职工信息
		case 2:
		{
			Consle.showWorker();
			break;
		}
		//删除职工信息
		case 3:
		{
			Consle.delWorker();
			break;
		}
		//修改职工信息
		case 4: 
		{
			Consle.modifyWorker();
			break;
		}
		//查找职工信息
		case 5:
		{
			Consle.seletWorker();
			break;
		}
		//按照编号排序
		case 6:
		{
			Consle.sortArray();
			break;
		}
		//清空所有文档
		case 7:
		{
			Consle.clearWorker();
			break;
		}
		//请输入正确的数字
		default:
		{
			std::cerr << "请输入正确的数字" << std::endl;
			break;
		}
		}
	}
	return 0;
}
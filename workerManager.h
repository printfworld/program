#pragma once
#include "worker.h"
#include <iostream>
class workerManager
{
public:
	workerManager();
	~workerManager();
	int workerSize;
	bool isFileEmpty;
	worker** pArray;
	//显示控制台
	void showConsle();
	//增加职工(录入文件)
	void addWorker();
	//显示职工信息
	void showWorker();
	//删除职工信息（录入文件）
	void delWorker();
	//获得文件中的数据个数
	int getFileNum();
	//修改职工信息
	void modifyWorker();
	//查找职工信息 
	void seletWorker();
	//初始化数组
	void initArray();
	//按编号排序
	void sortArray();
	//清空所有文档
	void clearWorker();
};


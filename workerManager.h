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
	//��ʾ����̨
	void showConsle();
	//����ְ��(¼���ļ�)
	void addWorker();
	//��ʾְ����Ϣ
	void showWorker();
	//ɾ��ְ����Ϣ��¼���ļ���
	void delWorker();
	//����ļ��е����ݸ���
	int getFileNum();
	//�޸�ְ����Ϣ
	void modifyWorker();
	//����ְ����Ϣ 
	void seletWorker();
	//��ʼ������
	void initArray();
	//���������
	void sortArray();
	//��������ĵ�
	void clearWorker();
};


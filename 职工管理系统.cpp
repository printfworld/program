#include<iostream>
#include"workerManager.h"

int main()
{
	int controlNum(0);
	workerManager Consle;
	while (true)
	{
		//��ʾ����̨
		Consle.showConsle();
		std::cin >> controlNum;
		switch (controlNum)
		{
		//�˳�����ϵͳ
		case 0:
		{
			return 0;
			break;
		}
		//����ְ����Ϣ
		case 1:
		{
			Consle.addWorker();
			break;
		}
		//��ʾְ����Ϣ
		case 2:
		{
			Consle.showWorker();
			break;
		}
		//ɾ��ְ����Ϣ
		case 3:
		{
			Consle.delWorker();
			break;
		}
		//�޸�ְ����Ϣ
		case 4: 
		{
			Consle.modifyWorker();
			break;
		}
		//����ְ����Ϣ
		case 5:
		{
			Consle.seletWorker();
			break;
		}
		//���ձ������
		case 6:
		{
			Consle.sortArray();
			break;
		}
		//��������ĵ�
		case 7:
		{
			Consle.clearWorker();
			break;
		}
		//��������ȷ������
		default:
		{
			std::cerr << "��������ȷ������" << std::endl;
			break;
		}
		}
	}
	return 0;
}
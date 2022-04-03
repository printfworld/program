#include "workerManager.h"
#include "worker.h"
#include <fstream>
workerManager::workerManager()
{
	std::ifstream ifs;
	
	ifs.open("d://workerData.txt", std::ios::in);
	//��������ڣ���ʧ��
	if (!ifs)
	{
		workerSize = 0;
		pArray = nullptr;
		isFileEmpty = true;
		ifs.close();
		return;
	}
	//���ڵ���Ϊ��
	char get;
	ifs.get(get);
	//�ļ�Ϊ��->eof��true��
	if (ifs.eof())
	{
		workerSize = 0;
		pArray = nullptr;
		isFileEmpty = true;
		ifs.close();
		return;
	}
	//�����ļ����ļ���Ϊ��
	//workerSize����ļ��е����ݸ���
	workerSize = getFileNum();
	//����ָ������
	pArray = new worker * [workerSize];
	//����ָ���е�����
	initArray();
	isFileEmpty = false;
}
workerManager::~workerManager()
{

}

void workerManager::showConsle()
{
	std::cout << "*********************************" << std::endl;
	std::cout << "***   ��ӭʹ��ְ������ϵͳ  *****" << std::endl;
	std::cout << "*****   0���˳��������   *******" << std::endl;
	std::cout << "*****   1������ְ����Ϣ   *******" << std::endl;
	std::cout << "*****   2����ʾְ����Ϣ   *******" << std::endl;
	std::cout << "*****   3��ɾ����ְְ��   *******" <<std:: endl;
	std::cout << "*****   4���޸�ְ����Ϣ   *******" << std::endl;
	std::cout << "*****   5������ְ����Ϣ   *******" << std::endl;
	std::cout << "*****   6�����ձ������   *******" << std::endl;
	std::cout << "*****   7����������ĵ�   *******" << std::endl;
	std::cout << "*********************************" << std::endl;
	return;
}
//����ְ��	
void workerManager::addWorker()
{
	int inputNum(0);
	std::cout << "���������ӵ�ְ��������" << std::endl;
	std::cin >> inputNum;
	if (inputNum > 0)
	{
		int newN(this->workerSize + inputNum);
		worker** newData = new worker * [newN];
		//¼��֮ǰ���� ,�����߳�������
		if (this->pArray != nullptr)
		{
			for (int i(0); i < workerSize; i++)
			{
				newData[i] = this->pArray[i];
			}
		}
		//��Ҫ¼������� 
		for (int i(0); i < inputNum; i++)
		{
			int id;
			int did;
			std::string name;
			//¼��������
			std::cout << "������� " << i + 1 << " ����ְ�����" << std::endl;
			std::cin >> id;
			std::cout << "������� " << i + 1 << " ����ְ������" << std::endl;
			std::cin >> name;
			std::cout << "��ѡ���ְ����λ��" << std::endl;
			std::cout << "1����ְͨ��" << std::endl;
			std::cout << "2������" << std::endl;
			std::cout << "3���ϰ�" << std::endl;
			std::cin >> did;
			worker* midData = nullptr;
			//ͨ��didȷ�������ʵ��������
			if(!i)
			{
				delete[]this->pArray;//ɾ����ָ�������ָ��
				pArray = newData;
			}
			switch (did)
			{
				//��ͨԱ��
			case 1:
			{
				//���黹û�б䳤
				midData = new person(id, name, did);
				pArray[this->workerSize + i] = midData;
				break;
			}
			//����
			case 2:
			{
				midData = new manager(id, name, did);
				pArray[this->workerSize + i] = midData;
				break;
			}
			//�ϰ�
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
			//¼������
			this->workerSize = newN;
			isFileEmpty = false;
	}
	//¼���ļ�
	std::ofstream ofs;
	ofs.open("d://workerData.txt", std::ios::out);
	if (!ofs)
	{
		std::cerr << "�ļ���ʧ��" << std::endl;
	}
	for (int i(0);i<workerSize;i++)
	{
		ofs<<pArray[i]->name<<std::endl;
		ofs << pArray[i]->id<< std::endl;
		ofs << pArray[i]->did << std::endl;
	}
	ofs.close();
}
//��ʾְ����Ϣ
void workerManager::showWorker()
{
	for (int i(0);i<workerSize;i++)
	{
		std::cout << "Ա������:" << pArray[i]->name << std::endl;
		std::cout << "Ա�����:" << pArray[i]->id<< std::endl;
		std::cout << "Ա��ְλ:" << pArray[i]->did << std::endl << std::endl;
	}
	return;
}
//ɾ��ְ��
void workerManager::delWorker()
{
	if (!isFileEmpty)
	{
		std::cout << "����Ϊ��" << std::endl;
		return;
	}
	int id,i(0);
	std::cout << "������Ա�����:" << std::endl;
	std::cin >> id;
	//����ҵ�������
	for (;i<workerSize;i++)
	{
		if (pArray[i]->id==id)
		{
			break;
		}
	}
	//û�ҵ�����
	if (i==workerSize)
	{
		std::cout << "δ�ҵ�����" << std::endl;
		return;
	}
	//�ҵ�����
	//ɾ�����һλPArray[workerSize-1]
	if (i==workerSize-1)
	{
		worker** newOne = new worker * [workerSize - 1];
		for (int i(0);i<workerSize-1;i++)
		{
			//�������� 
			newOne[i] = pArray[i];
		}
		delete []pArray;
		 //ָ��newOne�ڴ棬ͨ��delete [] pArray���ͷ�
		pArray = newOne;
		//�����ݷ���֮��¼�ļ�
		workerSize--;
	}
	else
	{
		//�������һλ
		for (; i < workerSize - 1; i++)
		{
			//��ǰ�ƶ�һλ���������� 
			pArray[i] = pArray[i + 1];
		}
		workerSize--;
	}
	//д������
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
	//�ļ�Ϊ��ʱ
	if (isFileEmpty)
	{
		std::cout << "����Ϊ��" << std::endl;
		return;
	}
	int id;
	int i(0);
	std::cin >> id;
	for (;i<workerSize;i++)
	{
		if (pArray[i]->id==id)
		{
			//���ݵ���������
			std::cout << "�Ѳ鵽 " << this->pArray[i]->id << " ��ְ������������ְ����" << std::endl;
			std::cin >> this->pArray[i]->id;
			std::cout << "��������������" << std::endl;
			std::cin >> this->pArray[i]->name;
			std::cout << "�������¸�λ��" << std::endl;
			std::cout << "1����ְͨ��" << std::endl;
			std::cout << "2������" << std::endl;
			std::cout << "3���ϰ�" << std::endl;
			std::cin >> this->pArray[i]->did;
			//¼���ļ� 
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
			//���ʱ�̵�iֵ
			break;
		}
	}
	if (i==workerSize)
	{
		std::cout << "δ�ҵ�����" << std::endl;
	}
}
//����ְ����Ϣ
void workerManager::seletWorker()
{
	//�ж��ļ��Ƿ�Ϊ��
	if (isFileEmpty)
	{
		std::cout << "����Ϊ��" << std::endl;
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
		std::cout << "δ�ҵ�����" << std::endl;
	}
}
//���ļ�¼������
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
//��������
void workerManager::sortArray()
{
	//�ļ�Ϊ��
	if (isFileEmpty)
	{
		std::cout << "����Ϊ��" << std::endl;
		return;
	}
	int num(0);
	std::cout << "��ѡ���������ͣ�" << std::endl;
	std::cout << "1����ְ���������" << std::endl;
	std::cout << "2����ְ����Ž���" << std::endl;
	//����ֵ
	worker* mid = nullptr;
	//��ȡ����
	int getk(0);
	int max_id(0);
	std::cin >> num;
	switch (num)
	{	
	//����
	case 1:
	{
		//���ߴ���
		//��worksize-2ʱ���ֻ��һ��workersize-1�ˡ�
		for ( int i(0);i<workerSize-1;i++)
		{
			//��max_id����Ϊ��ǰi��id��
			max_id = pArray[i]->id;
			//�������������ʴ�i��
			for (int k(i);k<workerSize;k++)
			{
				//����С�ڵ���max_id
				if (pArray[k]->id <= max_id)
				{
					max_id = pArray[k]->id;
					//��¼����
					getk = k;
				}
			}
			mid = pArray[getk];
			pArray[getk] = pArray[i];
			pArray[i] = mid;
		}
		break;
	}
	//����
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
	//�˴��������ļ��Ĵ洢
}
//�����������(�ļ�������)
void workerManager::clearWorker()
{
	//���鲻Ϊ��
	if (!pArray)
	{
		workerSize = 0;
		delete[]pArray;
		pArray = nullptr;
	}
	//����ļ�
	std::fstream fs;
	fs.open("d://workerData.txt", std::ios::trunc);
	if (!fs)
	{
		std::cerr << "���ʧ��" << std::endl;
	}
	fs.close();
	//�ļ�Ϊ�ձ�׼Ϊ�档
	isFileEmpty = true;
}


#include "worker.h"

person::person(int id, std::string name, int did)
{
	this->id = id;
	this->name = name;
	this->did = did;
}
//˵��λ
std::string person::sayPost()
{
	return (std::string)"��ͨԱ��";
}
//˵����
void person::sayWork()
{
	std::cout << this->id << " " << this->name << " " << this->sayPost() << std::endl;
}

manager::manager(int id, std::string name, int did)
{
	this->id = id;
	this->name = name;
	this->did = did;
}
std::string manager::sayPost()
{
	return (std::string)"����";
}
void manager::sayWork()
{
	std::cout << this->id << " " << this->name << " " << this->sayPost() << std::endl;
}

boss::boss(int id, std::string name, int did)
{
	this->id = id;
	this->name = name;
	this->did = did;
}
std::string boss::sayPost()
{
	return (std::string)"�ϰ�";
}
void boss::sayWork()
{
	std::cout << this->id << " " << this->name << " " << this->sayPost() << std::endl;
}

#include "worker.h"

person::person(int id, std::string name, int did)
{
	this->id = id;
	this->name = name;
	this->did = did;
}
//说岗位
std::string person::sayPost()
{
	return (std::string)"普通员工";
}
//说工作
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
	return (std::string)"经理";
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
	return (std::string)"老板";
}
void boss::sayWork()
{
	std::cout << this->id << " " << this->name << " " << this->sayPost() << std::endl;
}

#pragma once
#include<iostream>
#include <string>
class worker
{
public:
	//说工作
	virtual void sayWork()=0;
	//说岗位
	virtual std::string  sayPost()=0;
	int id;
	std::string name;
	int did;
};
//person继承worker
class person:public worker
{
public:
	person(int id,std::string name,int did);
	std::string sayPost();
	void sayWork();
};
class manager:public worker
{
public:
	manager(int id, std::string name, int did);
	std::string sayPost();
	void sayWork();
};
class boss:public worker
{
public:
	boss(int id,std::string name,int did);
	std::string sayPost();
	void sayWork();
};

#pragma once
#include<iostream>
#include <string>
class worker
{
public:
	//˵����
	virtual void sayWork()=0;
	//˵��λ
	virtual std::string  sayPost()=0;
	int id;
	std::string name;
	int did;
};
//person�̳�worker
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

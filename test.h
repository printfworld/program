#pragma once
//测试，获取文件数据个数的函数。
void testGetFileNum()
{
	workerManager a;
	int getNum=a.getFileNum();
	std::cout << "a.getFileNum()=" << getNum << std::endl;
}
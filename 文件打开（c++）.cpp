#include"stdafx.h"
#include<iostream>
#include<fstream>
using namespace std;
int main() {
	ifstream in;
	in.open("test.txt");
	if (!in) {
		cerr << " 打开文件失败 " << endl;
		return 0;
	}
	char x;
	while (in>>x)
	{
		cout << x;
	}
	cout << endl;
	in.close();
	system("PAUSE");
	return 0;
}

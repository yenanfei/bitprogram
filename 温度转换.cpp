#include<iostream>
int main() {
	const unsigned short ADD_SUBTRACT = 32;
	const double RATIO = 9.0 / 5.0;
	double tempin, tempout;
	char typein, typeout;
	bool flag = true;
	std::cout << "输入需要转换的温度:" << "\n";//xx.xF或者xx.xC
	std::cin >> tempin >> typein;
	switch (typein)
	{
	case'c':
	case'C':
		tempout = tempin*RATIO + ADD_SUBTRACT;
		typeout = 'F';
		break;
	case'F':
	case'f':
		tempout = (tempin - ADD_SUBTRACT) / RATIO;
		typeout = 'C';
		break;
	default:
		flag = false;
		std::cout << "ERROR";
		break;
	}
	if (flag) {
		std::cout <<tempout << typeout<<std::endl;
	}
	system("PAUSE");
}

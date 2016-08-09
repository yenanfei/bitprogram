#include"stdafx.h"
#include<iostream>
template <class T> T min(T a, T b) {
	return (a < b) ? a : b;
}
int main() {
	int a = 0, b = 0;
	std::cin >> a >> b;
	std::cout << "min:" << min(a, b)<<std::endl;//此处如果输入浮点型则不能输出正确的结果，因为输入限制为int
	double c = 0, d = 0;
	std::cin >> c >> d;
	std::cout << "min:" << min(c, d) << std::endl;
	system("PAUSE");
}
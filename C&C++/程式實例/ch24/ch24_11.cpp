//   ch24_11.cpp        /
#include <cstdlib>
#include <iostream>
using namespace std;
int larger_value(int, int);
int main()
{
	int i, j;
	
	cout << "�п�J��ƭ�" << endl << "==> ";
	cin >> i >> j;
	larger_value(i, j);
	system("pause");
	return 0;	
} 
int larger_value(int a, int b)
{
	if (a < b)
		cout << "���j�ȬO = " << b << endl;
	else if (a > b)
		cout << "���j�ȬO = " << a << endl; 
	else
		cout << "��ƭȬ۵�" << endl; 
}




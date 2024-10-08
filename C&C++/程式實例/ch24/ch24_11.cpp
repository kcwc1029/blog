//   ch24_11.cpp        /
#include <cstdlib>
#include <iostream>
using namespace std;
int larger_value(int, int);
int main()
{
	int i, j;
	
	cout << "請輸入兩數值" << endl << "==> ";
	cin >> i >> j;
	larger_value(i, j);
	system("pause");
	return 0;	
} 
int larger_value(int a, int b)
{
	if (a < b)
		cout << "較大值是 = " << b << endl;
	else if (a > b)
		cout << "較大值是 = " << a << endl; 
	else
		cout << "兩數值相等" << endl; 
}




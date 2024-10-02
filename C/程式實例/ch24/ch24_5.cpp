//   ch24_5.cpp        /
#include <cstdlib>
#include <iostream>
using namespace std;
int main()
{
	int i, j, k, sum;
	char ch1, ch2;
	float x1, x2, ave;
	
	cout << "請輸入 2 個字元" << endl;
	cin >> ch1 >> ch2;
	cout << "這兩個字元的相反輸出是" << endl << "===> "
	     << ch2 << ch1 << endl;
	cout << "請輸入 3 個整數" << endl << "==> ";
	cin >> i
	    >> j
		>> k;
	sum = i + j + k;
	cout << "總和是" << endl << "==> "
	     << sum << "\n";
	cout << "請輸入 2 個浮點數" << endl << "==> ";
	cin >> x1 >> x2;
	ave = (x1 + x2) / 2.0;
	cout << "平均是 ==>  " << ave << endl;  
	system("pause");
	return 0;	
} 



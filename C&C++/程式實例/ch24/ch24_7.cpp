//   ch24_7.cpp        /
#include <cstdlib>
#include <iostream>
using namespace std;
int main()
{
	int i, j, k;
	
	cout << "請輸入 3 個整數" << endl << "==> ";
	cin >> i
	    >> j
		>> k;
	int sum = i + j + k;
	cout << "總和是" << endl << "==> "
	     << sum << "\n"; 
	system("pause");
	return 0;	
} 



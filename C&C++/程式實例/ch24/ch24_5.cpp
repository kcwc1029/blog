//   ch24_5.cpp        /
#include <cstdlib>
#include <iostream>
using namespace std;
int main()
{
	int i, j, k, sum;
	char ch1, ch2;
	float x1, x2, ave;
	
	cout << "�п�J 2 �Ӧr��" << endl;
	cin >> ch1 >> ch2;
	cout << "�o��Ӧr�����ۤϿ�X�O" << endl << "===> "
	     << ch2 << ch1 << endl;
	cout << "�п�J 3 �Ӿ��" << endl << "==> ";
	cin >> i
	    >> j
		>> k;
	sum = i + j + k;
	cout << "�`�M�O" << endl << "==> "
	     << sum << "\n";
	cout << "�п�J 2 �ӯB�I��" << endl << "==> ";
	cin >> x1 >> x2;
	ave = (x1 + x2) / 2.0;
	cout << "�����O ==>  " << ave << endl;  
	system("pause");
	return 0;	
} 



//   ch24_14.cpp        /
#include <cstdlib>
#include <iostream>
using namespace std;
// �^�ǵ���� 
inline int abs(int i)
{
	return (i < 0 ? -i : i);
}
// �^�Ǹ��p�� 
inline int min(int v1, int v2)
{
	return (v1 <= v2 ? v1 : v2);
}
int main()
{
	int i, j;
	
	cout << "�п�J�� 1 �ӭ� : ==> ";
	cin >> i;
	cout << "�п�J�� 2 �ӭ� : ==> ";
	cin >> j;
	cout << endl << "�̤p�� = " << min(i,j) << endl;
	i = abs(i);
	j = abs(j);
	cout << endl << "����� abs(i) = " << i << endl;
	cout << endl << "����� abs(j) = " << j << endl;
	system("pause");
	return 0;	
} 





//   ch24_13.cpp        /
#include <cstdlib>
#include <iostream>
using namespace std;
// ��ܦr�� 
int display(char str[])
{
	cout << "�r��O : " << str << endl;
}
// ��ܾ�� 
int display(int i)
{
	cout << "��ƬO : " << i << endl;
}
int main()
{
	int i = 3;
	char str[] = "Deepmind";
	
	display(str);
	display(i);
	system("pause");
	return 0;	
} 





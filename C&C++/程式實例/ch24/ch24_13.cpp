//   ch24_13.cpp        /
#include <cstdlib>
#include <iostream>
using namespace std;
// 顯示字串 
int display(char str[])
{
	cout << "字串是 : " << str << endl;
}
// 顯示整數 
int display(int i)
{
	cout << "整數是 : " << i << endl;
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





//   ch24_15.cpp        /
#include <cstdlib>
#include <iostream>
using namespace std; 
int swap(int& x, int& y)
{
	int tmp;
	
	tmp = x;
	x = y;
	y = tmp;
}
int main()
{
	int i, j;
	
	i = 10;
	j = 20;
	cout << "©I¥s swap «e" << endl
	     << "i = " << i << ",   j = " << j << endl; 
	swap(i, j);
	cout << "©I¥s swap «e" << endl
	     << "i = " << i << ",   j = " << j << endl; 
	system("pause");
	return 0;	
} 





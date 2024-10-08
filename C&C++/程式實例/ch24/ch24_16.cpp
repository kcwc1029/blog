//   ch24_16.cpp        /
#include <cstdlib>
#include <iostream>
using namespace std; 
int main()
{
	int *i;
	
	i = new int; 		// 配置記憶體 
	*i = 10;
	cout << "i = " << *i << endl;
	delete i; 			// 收回記憶體 
	system("pause");
	return 0;	
} 





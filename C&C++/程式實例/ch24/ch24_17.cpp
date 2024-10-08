//   ch24_17.cpp        /
#include <cstdlib>
#include <iostream>
using namespace std; 
int main()
{
	int *i;
	
	i = new int(10); 	// 配置記憶體 
	cout << "i = " << *i << endl;
	delete i; 			// 收回記憶體 
	system("pause");
	return 0;	
} 





//   ch24_16.cpp        /
#include <cstdlib>
#include <iostream>
using namespace std; 
int main()
{
	int *i;
	
	i = new int; 		// �t�m�O���� 
	*i = 10;
	cout << "i = " << *i << endl;
	delete i; 			// ���^�O���� 
	system("pause");
	return 0;	
} 





//   ch24_17.cpp        /
#include <cstdlib>
#include <iostream>
using namespace std; 
int main()
{
	int *i;
	
	i = new int(10); 	// �t�m�O���� 
	cout << "i = " << *i << endl;
	delete i; 			// ���^�O���� 
	system("pause");
	return 0;	
} 





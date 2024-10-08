//   ch24_9.cpp        /
#include <cstdlib>
#include <iostream>
using namespace std;
char ch = 'D';
void modify()
{
	char ch;
	ch = 's';
	cout << "ch = " << ch << endl;
	::ch = 'T';
	cout << "ch = " << ch << endl;
}
int main()
{
	cout << "©I¥s modify «e" << endl;
	cout << ch << endl;
	modify();
	cout << "©I¥s modify «á" << endl;
	cout << ch << endl; 
	system("pause");
	return 0;	
} 



//   ch24_14.cpp        /
#include <cstdlib>
#include <iostream>
using namespace std;
// 回傳絕對值 
inline int abs(int i)
{
	return (i < 0 ? -i : i);
}
// 回傳較小值 
inline int min(int v1, int v2)
{
	return (v1 <= v2 ? v1 : v2);
}
int main()
{
	int i, j;
	
	cout << "請輸入第 1 個值 : ==> ";
	cin >> i;
	cout << "請輸入第 2 個值 : ==> ";
	cin >> j;
	cout << endl << "最小值 = " << min(i,j) << endl;
	i = abs(i);
	j = abs(j);
	cout << endl << "絕對值 abs(i) = " << i << endl;
	cout << endl << "絕對值 abs(j) = " << j << endl;
	system("pause");
	return 0;	
} 





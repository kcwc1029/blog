#include <iostream>
// #include <stack>

using namespace std;
int main(){
    int columnNumber = 1;
    string s;
    while(columnNumber > 0){
        columnNumber--;
        ans+=columnNumber%26 + 'A';
        columnNumber/=26;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}


// g++ test.cpp -o test.exe



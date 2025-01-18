#include <iostream>

using namespace std;
int main(){
    int n = 11100;
    int ans = 0;
    
    // 第一次
    cout<<"-----第一次-----"<<"\n";
    cout<<"n&1 "<<(n&1)<<"\n";
    cout<<"ans<<1 "<<(ans<<1)<<"\n";
    ans = (n&1)+(ans<<1)
    cout<<"(n&1)+(ans<<1) "<<ans<<"\n";

    cout<<"n>>1 "<<(n>>1)<<"\n";
    // 第二次
    cout<<"-----第二次-----"<<"\n";
    cout<<"n&1 "<<(n&1)<<"\n";
    cout<<"ans<<1 "<<(ans<<1)<<"\n";
    cout<<"(n&1)+(ans<<1) "<<(n&1)+(ans<<1)<<"\n";
    cout<<"n>>1 "<<(n>>1)<<"\n";

}


// g++ test.cpp -o test.exe



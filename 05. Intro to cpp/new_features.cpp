// here i will demonstrate new features of c++
// those doesn't exist in c

#include <iostream>
using namespace :: std;

long long fact(int n){
    long long f = 1; 
    for(int i=1; i<=n; i++) f*=i;
    return f;
}

int main(void){
    cout <<"This program uses some feature not in C\n";
            // like auto
    for(auto i=0; i<16; i++){
        cout<<"factorial of "<<i<<" is "<<fact(i)<<endl;
    }
    cout << "That's all folks!" << endl;
}
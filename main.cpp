#include <iostream>
#include <set>
using namespace std;
int foo(int n){
    if(n==1) return n;
else return foo(n-1)-n;
return 0;
}
int main(){
    cout<<foo(5)<<endl;
    //cout<<A[0];
return 0;
}

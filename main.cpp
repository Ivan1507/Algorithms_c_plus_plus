#include <iostream>
#include <math.h>
using namespace std;

auto F(int n){
 if(n==1) return 70.0;
else return (0.7*(100+2*(F(n-1))));
}
auto M(int n){
if(n==1) return 40.0;
else return (0.3*(100+2*F(n-1))+10.0);
}

int main()
{

	double n;
    cin>>n;
    cout<<int64_t(M(n));
	return 0;
}

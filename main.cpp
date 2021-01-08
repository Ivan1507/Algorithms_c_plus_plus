#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
int n;
cin>>n;
int C[n];
for(int i=0;i<n;i++)
    cin>>C[i];
int K[n];
for(int i=0;i<n;i++)
    cin>>K[i];
int *A=new int[n];
A[0]=1;
if(C[1]==C[0]||C[1]==K[0]) A[1]=1;
else A[1]=0;
for(int i=2;i<n;i++){
     if((C[i]==C[i-2]||C[i]==K[i-2])&&(C[i]==C[i-1]||C[i]==K[i-1])) A[i]=(A[i-1]+A[i-2])%947;
     else if(C[i]==C[i-2]||C[i]==K[i-2]) A[i]=A[i-2]%947;
     else if(C[i]==C[i-1]||C[i]==K[i-1]) A[i]=A[i-1]%947;
     else A[i]=0;
}
cout<<A[n-1];
delete[] A;
}

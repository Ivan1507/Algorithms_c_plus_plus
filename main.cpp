#include <iostream>
#include <stack>
#include <math.h>
#include <map>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    int A[n];
    int B[n];
    bool truth[n];
    for(int i=0;i<n;i++){
            truth[i]=false;
        cin>>A[i]>>B[i];
    }
    int ans=0;
    for(int i=0;i<n;i++){
         if(A[i]>=n||B[i]>=n) ans+=1;
         else{
            if(!B[i]){
                    if(truth[n-A[i]-1])
                ans+=1;
                else truth[n-A[i]-1]=true;
            }
            else if(!A[i]){
                if(truth[B[i]])
                    ans+=1;
                else truth[B[i]]=true;
            }
            else{
                 int k=n-A[i]-1;
                 if(B[i]!=k) ans+=1;
                else if(truth[k]) ans+=1;
                   else truth[k]=true;
            }
         }
    }
    cout<<n-ans;
}

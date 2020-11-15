#include <iostream>
using namespace std;

int main()
{
 int n;
 cin>>n;
 int A[n];
 for(int i=0;i<n;i++){
    cin>>A[i];
 }
 int ans1=0,ans2=0;
 int r=0;
 for(int i=0;i<n;i++){
    if(A[i]==1){
            for(int j=i+1;j<n;j++){
                if(A[j]==2) {
                        ans1=j-i;
                        break;
                }
            }
            for(int k=i-1;k>=0;k--){
                if(A[k]==2){
                        ans2=i-k;
                        break;
                }
            }
            if(!ans1 or !ans2){
                    if(max(ans1,ans2)>r)
                r=max(ans1,ans2);
            }
            else if(min(ans1,ans2)>r)
                r=min(ans1,ans2);
       //cout<<ans1<<'\t'<<ans2<<'\t';
       ans1=0;
       ans2=0;
    }

    }
    cout<<r;
}



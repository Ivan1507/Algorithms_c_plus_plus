#include <iostream>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;
void print(int *A,int n){
for(int i=0;i<n;i++)
    cout<<A[i]<<" ";
    cout<<endl;
}
void print(vector<int> A,int n){
for(int i=0;i<n;i++)
    cout<<A[i]<<" ";
    cout<<endl;
}
void radix_sort(vector<int> A,int *cop,int N){
    int *a0 = new int[N];
    int *a1 = new int[N];
    int max=-1;
    for(int i=0;i<N;i++){
        if(A[i]>max)
            max=A[i];
    }
    int c=0;
    while(max>0){
        c+=1;
        max/=10;
    }
    for(int radix = 0; radix < c; radix++) {
        int a0_size = 0;
        int a1_size = 0;
        for(int i = 0; i < N; i++) {
            if (cop[i]%2==0)
                a0[a0_size++] = A[i];
            else
                a1[a1_size++] = A[i];

        }
        for(int i = 0; i < a0_size; i++){
            A[i] = a0[i];
            if(a0[i]==10&&radix>0)
              cop[i]=0;
            else if(a0[i]==10)
                cop[i]=1;
            else cop[i]=a0[i]/pow(10,radix+1);
            //a0[i]/=ceil(pow(10,radix+1));
        }
        for(int i = 0; i < a1_size; i++){
            A[a0_size + i] = a1[i];
            if(a1[i]==10&&radix>0)
                cop[a0_size+i]=0;
            else if(a1[i]==10)
                cop[a0_size+i]=1;
            else cop[a0_size+i]=a1[i]/pow(10,radix+1);
         //a1[i]/=pow(10,radix+1);
        }
        print(A,N);
        //cout<<"our tmp array"<<endl;
        //print(cop,N);
    }
    delete[] a0;
    delete[] a1;
}

int main()
{
    int n;
    int top=0;
    vector<int> A;
    while(cin>>n){
            A.resize(top+1);
        A[top++]=n;
    }
    int cop[top+1];
    //cout<<top;

    for(int i=0;i<top;i++)
        cop[i]=A[i];
    radix_sort(A,cop,top);
    return 0;
}

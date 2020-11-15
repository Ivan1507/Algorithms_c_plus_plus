#include <iostream>
#include <vector>
using namespace std;
void generate_subarr(vector<int> A,int len_A,int pos_of_arr){
    if(pos_of_arr==0){
        cout<<A[pos_of_arr]<<'\n';
        pos_of_arr+=1;
        for(int i=0;i<pos_of_arr+1;i++){
            cout<<A[i]<<" ";
        }
        cout<<endl;
        generate_subarr(A,len_A,pos_of_arr);
    }
    else if(pos_of_arr<len_A-1){
            cout<<A[pos_of_arr]<<'\n';
            pos_of_arr+=1;
        int i=0;
        while(i!=pos_of_arr){
            for(int j=i;j<pos_of_arr+1;j++){
                cout<<A[j]<<" ";
            }
             cout<<endl;
        i++;
        }
        generate_subarr(A,len_A,pos_of_arr);
    }
    else cout<<A[pos_of_arr]<<endl;
}

int main(){
    int top=0;
    int n;
    vector<int> A;
    A.resize(top+1);
    while(cin>>n){
        A[top++]=n;
        A.resize(top+1);
    }
    int index=0;
    cout<<A.size()<<"";
    if(A.size()>2) generate_subarr(A,top,0);
    else cout<<A[0];
}

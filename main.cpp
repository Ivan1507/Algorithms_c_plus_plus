#include <iostream>
#include <math.h>
#include <utility>
#include <memory>
#include <cassert>
using std::unique_ptr;
struct Move{
    int num;
    int from;
    int to;
};

void print_Move(const Move *m,int size_moves){
for(int i=0;i<size_moves;i++){
    std::cout<<m[i].num<<" "<<m[i].from<<" "<<m[i].to<<"\n";
}
}

void hanoi_recunstraction(int A,int B,int C,int n){
if(n==1){
   std::cout<<"move 1 from "<<A<<" to "<<B<<'\n';
   std::cout<<"move 1 from "<<B<<" to "<<C<<'\n';
}
else{
        hanoi_recunstraction(A,B,C,n-1);
        std::cout<<"disk "<<n<<" from "<<A<<" to "<<B<<'\n';
        hanoi_recunstraction(C,B,A,n-1);
        std::cout<<"disk "<<n<<" from "<<B<<" to "<<C<<"\n";
        hanoi_recunstraction(A,B,C,n-1);

}
}
void generate(int top,int n,int *A){
	if(n==top){
		for(int i=0;i<top;i++)
			std::cout<<A[i];
		std::cout<<'\n';
			}
	else{
		A[top++]=0;
		top--;
		generate(top,n,A);
		A[top++]=1;
		top--;
		generate(top,n,A);
		top-=1;
	}
}
void hanoi(int A,int B,int C,int n){
if(n==1){
    std::cout<<A<<" "<<B<<"\n";
}
else{
    hanoi(A,C,B,n-1);
    std::cout<<A<<" "<<B<<'\n';
    hanoi(C,B,A,n-1);
}
}

void print2D(int A[][8],int n,int k){
for(int i=0;i<n;i++){
    for(int j=0;j<k;j++){
        std::cout<<A[i][j]<<" ";
    }
    std::cout<<'\n';
}
}


 int main()
{
	int n;
	std::cin>>n;
	int *A=new int[n];
	generate(0,n,A);
	delete[] A;
}

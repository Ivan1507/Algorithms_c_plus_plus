 #include <iostream>
#include <queue>
#include <deque>
using namespace std;
int main()
{
    int n;
    cin>>n;
    deque<int> deque1;

char F[n];
    for(int i=0;i<n;i++){
        cin>>F[i];
        if(F[i]=='+'){
           int x;
           cin>>x;
          deque1.push_back(x);
        }
        if(F[i]=='*'){
                int m;
                cin>>m;
                auto it=deque1.begin();
                int s=deque1.size();
                if(s==0) deque1.push_back(m);
                else if(s%2==0)
                    deque1.insert(it+s/2,m);
                else deque1.insert(it+s/2+1,m);
                }
        if(F[i]=='-'){
                cout<<deque1.front()<<endl;
                deque1.pop_front();
        }
    }


    return 0;
}

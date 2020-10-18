#include <iostream>
using std::cin;
using std::cout;
using std::endl;

   void my_slightly_less_dumb_reallocation(int** source, unsigned int n_old, unsigned int n_new){
    if(n_old==0&&n_new==1){
        int *ns=new int[n_new];
            delete *source;
            *source=ns;
    }
    else if(*source==nullptr&&n_old==0&&n_new>0){
            int *ns=new int[n_new];
            delete *source;
            *source=ns;
    }
    else if(n_old!=0&&n_new>n_old){
           int *ns=new int[n_new];
        for(int i=0;i<n_old;i++){
            ns[i]=source[0][i];
        }
        delete[] *source;
       *source=ns;
    }
    else if(n_old==1&&n_new==0){
    delete[] *source;
}
else if(n_old>n_new&&n_new!=0){
    delete[] *source;
}
}
int main() {
    unsigned int n, i;
    cin >> n;
    int *a = NULL;
    my_slightly_less_dumb_reallocation(&a, 0, n / 2);
    for (i = 0; i < n / 2; i++)
        cin >> a[i];
    my_slightly_less_dumb_reallocation(&a, n / 2, n);
    for (; i < n; i++)
        cin >> a[i];
    int sum = 0;
    for (i = 0; i < n; i++)
        sum += a[i];
    cout << sum << endl;
    my_slightly_less_dumb_reallocation(&a, n, n / 2);
    my_slightly_less_dumb_reallocation(&a, n / 2, 0);
    my_slightly_less_dumb_reallocation(&a, 0, 0);
    return 0;
}

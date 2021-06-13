#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

void permute(string a,int top,int size_of_str,vector<string> buffer,bool *is_used,set<string> &ans){
if(top==size_of_str){
	string tmp="";
	for(int i=0;i<top;i++)
		tmp+=buffer[i];
ans.insert(tmp);
}
else{
for(int i=0;i<size_of_str;i++){
	if(not is_used[i]){
		buffer[top]=a[i];
		is_used[i]=true;
		permute(a,top+1,size_of_str,buffer,is_used,ans);
		is_used[i]=false;
	}
}

}

}

int main()
{
string s;
cin>>s;
sort(s.begin(),s.end());
int len=s.length();
vector<string> buffer;
bool used[len]{0};
set<string> ans;
buffer.resize(len+1);
permute(s,0,len,buffer,used,ans);
cout<<ans.size()<<endl;
for(auto &i:ans)
	cout<<i<<endl;
	return 0;
}

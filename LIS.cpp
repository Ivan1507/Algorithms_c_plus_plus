#include <bits/stdc++.h>

int main(){
	int n;
	std::cin>>n;
	std::vector<int> ans;
	for(int i=0;i<n;++i){
		int x;
		std::cin>>x;
		int p=upper_bound(ans.begin(),ans.end(),x)-ans.begin();//Find out position of x 
		if(p<ans.size())
			ans[p]=x;//If it is not max num of our sequence just improve it
		else 
			ans.push_back(x);//Otherwise add that x in our sequence
	}
	std::cout<<ans.size();
}

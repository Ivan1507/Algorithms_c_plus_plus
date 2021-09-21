#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
const int len=6;// Длина наших чисел
void thirteen_gen(int len,int top,std::vector<char>& notation,std::string buff,uint64_t& ans){//Функция генерации всех чисел длины len
	if(top==len){
		//std::cout<<buff<<'\n'; Распечатка всех наших чисел
		ans+=1;
	}
	else{
		for(int i=0;i<notation.size();i++){
			thirteen_gen(len,top+1,notation,buff+notation[i],ans);
		}
	}
}
int main(){
	std::string s="aba";
	std::vector<char> notation={'0','1','2','3','4','5','6','7','8','9','A','B','C'};//Это наша система исчиcления из 13 чисел
	uint64_t all_num=0;
	const int k=notation.size();//Количество таких чисел, что при перестановке они не меняюся
	std::vector<char> bin_not={'0','1'};
	const int k1=bin_not.size();
	thirteen_gen(len,0,notation,"",all_num);//Считаем все возможные числа длины 6 в 13-ой системе счисления
	uint64_t ans=(all_num-k)*len+k;// Формула для ответа, которую вывел на бумажке, выводилась на примере двоичных чисел
	std::cout<<all_num<<"\n"<<ans<<'\n';
	return 0;
}

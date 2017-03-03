#include <iostream>
#include <string>

using namespace std;

string cal(string input){
	int carry = 0;
	string res = "";
	int temp;
	for(int i=input.size()-1;i>=0;i--){
		temp = stoi(string(1,input[i]))*2 +carry;
		res = to_string(temp%10) + res;
		// res.push_front(to_string(temp%10));
		carry = temp/10;
	}
	if(carry!=0)
		res = to_string(carry) + res;
	// return res;
	// cout<<res<<endl;
	int borrow = 2;
	
	for(int i = res.size()-1;borrow!=0;i--){
		temp = stoi(string(1,res[i]));
		// cout<<"temp = "<<temp<<endl;
		if(temp<borrow){
			temp = 10 + temp - borrow;
			res[i] = (char)(temp+48);
			borrow = 1;
		}
		else{
			temp -= borrow;
			// cout<<(char)(temp+48)<<endl;
			res[i] = (char)(temp+48);
			borrow = 0;
		}

	}
	if(res[0]=='0')
		res.erase(res.begin());
	return res;



}
		
int main(){
    ios::sync_with_stdio(false);

 	string input;
 	while(getline(cin,input)){
 		if(input=="0"||input=="1")
 			cout<<stoi(input)<<endl;
 		else
 			cout<<cal(input)<<endl;
 		// cout<<stoi(string(1,cpy[cpy.size()-1]))+1<<endl;
 	}

 	return 0;
 }
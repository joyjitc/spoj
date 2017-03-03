#include <iostream>
#include <cmath>
// #include <>
typedef unsigned long long ull;
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	ull input;
	cin>>input;
	// ull log_2 = log(input)/log(2);
	// // cout<<log_2<<endl; 
	// if(pow(2,log_2)==input)
	// 	cout<<"TAK"<<endl;
	// else
	// 	cout<<"NIE"<<endl;
	//older solution
	/*while(!(input&1))
		input>>=1;
	input>>=1;
	if(!input)
		cout<<"TAK"<<endl;
	else
		cout<<"NIE"<<endl;*/
	//Latest Solution
	if(input!=0&&((input&(input-1))==0))
		cout<<"TAK"<<endl;
	else
		cout<<"NIE"<<endl;



	return 0;
}
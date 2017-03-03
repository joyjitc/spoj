#include <iostream>
#include <cmath>

typedef unsigned long long ull;

using namespace std;

int main(){
	ios::sync_with_stdio(false);

	ull input;

	while(cin>>input){
		if(input==-1)
			break;
		if(input%6!=1){
			cout<<"N"<<endl;
			continue;
		}
		ull Q = input/6;
		double temp = (sqrt(1+8*Q)-1)/2;
		if(temp - int(temp)==0)
			cout<<"Y"<<endl;
		else
			cout<<"N"<<endl;
	}

	return 0;
}
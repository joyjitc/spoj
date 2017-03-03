#include <iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int N;
	cin>>N;
	int result = 0;
	int temp;
	for(int i=0;i<N;i++){
		cin>>temp;
		result = result^(temp);
	}
	cout<<result<<endl;
	return 0;
}
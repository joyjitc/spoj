#include <iostream>
#include <vector>
#include <cmath>
#include <tr1/unordered_set>

#define MAX 1000000

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	vector<int> array(MAX+1,1);
	array[1]=0;
	int sqrootMAX = sqrt(MAX);

	for(int i = 2;i<=sqrootMAX;i++){
		if(array[i]==0)
			continue;
		int j = i*2;
		while(j<=MAX){
			array[j] = 0;
			j = j+i;
		}
	}
	vector<int> prime;
	for(int i = 1;i<=MAX/2;i++)
		if(array[i]==1)
			prime.push_back(i);
	// for(auto it = prime.begin();it!=prime.end();++it){
	// 	cout<<(*it)<<" ";
	// }
	int t;
	cin>>t;
	int N;
	while(t--){
		cin>>N;
		double res = N;
		tr1::unordered_set<int> factor;

		for(vector<int>::iterator it=prime.begin();it!=prime.end();){
			if(array[N]==1){
				factor.insert(N);
				break;
			}
			if(N%(*it)!=0)
				++it;
			else{
				N = N/(*it);
				factor.insert(*it);
			}
		}
		for(tr1::unordered_set<int>::iterator it=factor.begin();it!=factor.end();++it)
			res*=(1.0-(1.0/(*it)));
		
		cout<<(int)res<<endl;
	}
	return 0;
}
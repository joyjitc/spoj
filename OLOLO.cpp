#include <iostream>
#include <tr1/unordered_set>

typedef unsigned long long ull;

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	
	// vector<int> input;
	// input.resize(1000000001,0);
	tr1::unordered_set<ull> mySet;

	int N;
	cin>>N;

	ull temp;

	for(int i=0;i<N;i++){
		cin>>temp;
		if(mySet.find(temp)==mySet.end())
			mySet.insert(temp);
		else
			mySet.erase(temp);
	}
	cout<<*(mySet.begin())<<endl;
	return 0;
}
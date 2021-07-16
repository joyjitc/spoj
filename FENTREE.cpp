#include <iostream>
using namespace std;

void fillBIT (int index, vector<int>& a, int val, int size){
	while(index<=size){
		a[index] += val;
		index = getChild(index);
	}
}

int getChild(int index){
	return index + (index & -index);
}

int getParent(int index){
	return index - (index & -index);
}

int getPrefixSum(int index, vector<int>& a){
	int sum = 0;
	while(index > 0){
		sum += a[index];
		index = getParent(index);
	}
}

int main(){
	int n;
	cin>>n;
	vector<int> a(n+1,0);
	int val;
	for (int i = 0;i<n;i++){
		cin>>val;
		fillBIT(i+1, a, val, n);
	}
	int q;
	cin>>q;
	char ops;
	int x, y;

	while(q--){
		cin>>ops>>x>>y;
		if(ops == 'q'){
			cout<<getPrefixSum(y, a) - getPrefixSum(x-1, a)<<"\n";
		} else if (ops == 'u'){
			fillBIT(x, a, y, n);
		}
	}
}
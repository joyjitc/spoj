#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool length_cut (vector<int>& sorted_input, int cut, int target){
	auto it = upper_bound(sorted_input.begin(),sorted_input.end(),cut);
	long long length_cut = 0;

	while(it!=sorted_input.end()){
		length_cut += (*it) - cut;
		it++;
	}

	// return length_cut;
	if(length_cut>=target)
		return 1;
	else
		return 0;
}

int main(){
	ios::sync_with_stdio(0);

	int n,m;
	int temp;
	vector<int> v;

	cin>>n>>m;

	for(int i=0;i<n;i++)
	{
		cin>>temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end());

	int l=0,r=v.back();
	int mid;

	while(l<r){
		mid = l + (r-l+1)/2;
		if(length_cut(v,mid,m))
			l=mid;
		else
			r=mid-1;
	}

	cout<<l<<"\n";
}
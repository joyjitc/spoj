#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
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
	int a=0,b=n-1,mid,tot_cut;
	while(a<b){
		mid=a+(b-a)/2;
		tot_cut = 0;
		for(int i=mid+1;i<n;i++){
			tot_cut+=v[i]-v[mid];
		}
		if(tot_cut<m)
			b=mid;
		else
			a=mid;
	}
	// for(auto x:v){
	// 	cout<<"Value : "<<x<<"\n";
	// }
	
}
#include <bits/stdc++.h>
using namespace std;

class Mix{
public: 
	int val;
	int smoke;
	Mix(){
		val=-1;
		smoke=0;
	}
};

Mix mixtures (vector<vector<Mix> >& memo, int i, int j ) {
	if (memo[i][j].val!=-1)
		return memo[i][j];

	else{
		int min_smoke = INT_MAX;
		int min_color;
		for(int k=i;k<j;k++){
			Mix a = mixtures (memo,i,k);
			Mix b = mixtures (memo,k+1,j);
			int smoke = a.smoke + b.smoke + a.val*b.val;
			if(smoke<min_smoke){
				min_smoke = smoke;
				min_color = (a.val + b.val)%100;
			}
		}
		memo[i][j].val = min_color;
		memo[i][j].smoke = min_smoke;
		return memo[i][j];
	}
}


int main(){
	ios::sync_with_stdio(false);
	int n;
	// vector<int> mix;
	// mix.reserve(100);
	vector<vector<Mix> > memo;
	int inp;

	while(cin>>n){
		memo.resize(n,vector<Mix>(n));
		for(int i=0;i<n;i++){
			cin>>inp;
			memo[i][i].val = inp;
		}
		mixtures (memo, 0, n-1);
		cout<<memo[0][n-1].smoke<<endl;
		memo.clear();
	}
}
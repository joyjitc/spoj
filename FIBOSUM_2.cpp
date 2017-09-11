#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

typedef unsigned long long ull;

vector<vector<ull> > matMul(vector<vector<ull> > mat1, vector<vector<ull> > mat2){
	int m,n,p;
	m=mat1.size();
	n=mat2.size();
	p=mat2[0].size();
	vector<vector<ull> > mat_res;
	mat_res.resize(m,vector<ull>(p,0));
	for(int i=0;i<m;i++){
		for(int j=0;j<p;j++){
			for(int k=0;k<n;k++){
				mat_res[i][j] = (mat_res[i][j]+(mat1[i][k]*mat2[k][j])%MOD)%MOD;
			}
		}
	}
	return mat_res;
}
vector<vector<ull> > fastExpo(vector<vector<ull> > mat, int n){
	if(n==1) return mat;
	if(n&1) return matMul(fastExpo(mat,n-1),mat);
	else{
		auto temp_mat = fastExpo(mat,n/2);
		return matMul(temp_mat,temp_mat);
	}
}

ull fibMod (int n){
	if(n==0) return 0;
	vector<vector<ull> > mat_base = {{1},{0}};
	vector<vector<ull> > mat_res = {{1,1},{1,0}};	
	mat_res = fastExpo(mat_res,n);
	mat_res = matMul(mat_res,mat_base);
	return mat_res[1][0];
}

int main(){
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	int m,n;
	while(t--){
		cin>>m>>n;
		ull res = ((fibMod(n+2)-1)-(fibMod(m+1)-1)+MOD)%MOD; 
		cout<<res<<"\n";
	}
}
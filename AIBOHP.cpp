#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
 
using namespace std;
// vector<vector<int> > memo;
 
int LCS(string a,string b);
// int LCS(string a,string b,int i, int j);
// int LCS_memo(string a, string b);
 
int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	string a,b;
	while(t--){
		cin>>a;
		b = a;
		std::reverse(b.begin(),b.end());
		int ans = a.size();
		ans = ans-LCS(a,b);
		cout<<ans<<endl;
	}
	return 0;
}
 
int LCS(string a,string b){//Tabular,bottom-up approach
	int size_a = a.size();
	int size_b = b.size();
	vector<vector<int> > matrix;
	matrix.resize(size_b+1,vector<int>(size_a+1,0));
	for(int i = 1;i<=size_b;i++){
		for(int j=1;j<=size_a;j++){
			if(a[j-1]==b[i-1])
				matrix[i][j]=matrix[i-1][j-1]+1;
			else
				matrix[i][j]=max(matrix[i-1][j],matrix[i][j-1]);
		}
	}
	return matrix[size_b][size_a];
}
// int LCS(string a,string b,int i, int j){//recursion+memoisation, Top-Down Approach
// 	if(i<0||j<0)
// 		return 0;
// 	if(memo[i][j]!=-1)
// 		return memo[i][j];
// 	if(a[i]==b[j]){
// 		memo[i][j] = (1+LCS(a,b,i-1,j-1));
// 		return memo[i][j];
// 	}
// 	else{
// 		memo[i][j] = (max(LCS(a,b,i-1,j),LCS(a,b,i,j-1)));
// 		return memo[i][j];
// 	}
// }
// int LCS_memo(string a, string b){
// 	memo.resize(a.size(),vector<int>(b.size(),-1));
// 	int lcs = LCS(a,b,a.size()-1,b.size()-1);
// 	memo.clear();
// 	return lcs;
// }
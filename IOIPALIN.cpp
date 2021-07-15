#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
	ios::sync_with_stdio(0);

	int n;
	string input;
	cin>>n;
	cin>>input;

	vector<vector<int> > dp;
	dp.resize(n+1,vector<int>(n+1));
	string rev_input = input;
	reverse(rev_input.begin(),rev_input.end());

	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(i==0||j==0)
				dp[i][j]=0;
			else if(input[i-1]==rev_input[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}

		}
	}

	int lcs = dp[n][n];
	cout<<n-lcs<<"\n";

}




// int lcs(string &X, string &Y) 
// { 
      
//     // Find lengths of two strings 
//     int m = X.length(), n = Y.length(); 
  
//     int L[2][n + 1]; 
  
//     // Binary index, used to 
//     // index current row and 
//     // previous row. 
//     bool bi; 
  
//     for (int i = 0; i <= m; i++) 
//     { 
          
//         // Compute current  
//         // binary index 
//         bi = i & 1; 
  
//         for (int j = 0; j <= n; j++) 
//         { 
//             if (i == 0 || j == 0) 
//                 L[bi][j] = 0; 
  
//             else if (X[i-1] == Y[j-1]) 
//                  L[bi][j] = L[1 - bi][j - 1] + 1; 
  
//             else
//                 L[bi][j] = max(L[1 - bi][j],  
//                                L[bi][j - 1]); 
//         } 
//     } 
  
//     // Last filled entry contains 
//     // length of LCS 
//     // for X[0..n-1] and Y[0..m-1]  
//     return L[bi][n]; 
// } 
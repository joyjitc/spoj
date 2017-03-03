#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Party{
public:
	int cost,fun;
	// double score;
	Party(int c, int f){
		cost = c;
		fun = f;
		// score = (double)f/(double)c;
	}		
};

Party calParty(int budget, int n,vector<Party> input){
	vector<vector<Party> > DP;
	DP.resize(n+1,vector<Party>(budget+1,Party(0,0)));

	// for(int i=0;i<=n;i++)
	// 	DP[i][0].cost = DP[i][0].fun =0;
	// for(int j=0;j<=budget;j++)
	// 	DP[0][j].cost = DP[0][j].fun =0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=budget;j++){
			if(j<input[i].cost){
				DP[i][j].fun=DP[i-1][j].fun;
				DP[i][j].cost = DP[i-1][j].cost;
			}
			else{
				DP[i][j].fun=max(DP[i-1][j].fun,DP[i-1][j-input[i].cost].fun+input[i].fun);
				if(DP[i-1][j-input[i].cost].fun+input[i].fun>DP[i-1][j].fun)
					DP[i][j].cost = DP[i-1][j-input[i].cost].cost + input[i].cost;
				else if(DP[i-1][j-input[i].cost].fun+input[i].fun==DP[i-1][j].fun)
					DP[i][j].cost = min(DP[i-1][j].cost,DP[i-1][j-input[i].cost].cost + input[i].cost);
				else
					DP[i][j].cost = DP[i-1][j].cost;
			}
		}
	}
	// Party ans = Party(used_budget,DP[n][budget]);
	// return ans;
	return DP[n][budget];

}

// bool sortByScore(const party &lhs, const party &rhs){ return lhs.score>rhs.score; }
int main(){
	ios::sync_with_stdio(false);
	int budget,n;
	while(cin>>budget>>n){
		if(budget==0&&n==0)
			break;
		vector<Party> array;
		int cost, fun;
		// array.resize(n+1,NULL);
		array.push_back(Party(0,0));
		for(int i=1;i<=n;i++){
			cin>>cost>>fun;
			// array[i]=Party(cost,fun);
			array.push_back(Party(cost,fun));
		}
		Party sol = calParty(budget,n,array);
		cout<<sol.cost<<" "<<sol.fun<<endl;

		// cout<<calParty(size,n,&array)<<endl;
		// sort(array.begin(),array.end(),sortByScore);
		// cost = fun = 0;
		// for(int i=0;i<b;i++){
		// 	if(a>=array[i].cost){
		// 		cost+=array[i].cost;
		// 		fun+=array[i].fun;
		// 		a-=array[i].cost;
		// 	}
		// }
		// cout<<cost<<" "<<fun<<endl;

	}
	return 0;
}

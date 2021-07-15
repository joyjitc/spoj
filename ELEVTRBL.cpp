#include <iostream>
#include <utility>
#include <unordered_set>
#include <queue>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	int f,s,g,u,d;
	int ans;
	cin>>f>>s>>g>>u>>d;
	string notFoundMsg = "use the stairs";
	bool found = false;
	unordered_set<int> visited;
	queue<pair<int,int> > q;

	visited.insert(s);
	q.push(make_pair(s,0));

	while(!q.empty()){
		int cur = q.front().first;
		int cur_state =  q.front().second;
		if(cur==g){
			ans = cur_state;
			found = true;
			break;
		}
		else{
			int new_up = cur+u;
			int new_down  = cur-d;
			if(visited.count(new_up)==0&&new_up<=f){
				q.push(make_pair(new_up,cur_state+1));
				visited.insert(new_up);
			}
			if(visited.count(new_down)==0&&new_down>=1){
				q.push(make_pair(new_down,cur_state+1));
				visited.insert(new_down);
			}

		}
		q.pop();
	}
	if(found)
		cout<<ans<<"\n";
	else 
		cout<<notFoundMsg<<"\n";
}
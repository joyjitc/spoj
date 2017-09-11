#include <bits/stdc++.h>

using namespace std;


struct state{
	string src;
	string des;
	int dis;
};
int string_to_int (string input){
	int out = 0;
	for(int i=0;i<4;i++)
		out = out*10 + (input[i]-'0');
	return out;
}

string int_to_4string (int input){
	string out;
	out.resize(4);
	int i = 3;
	while(input!=0){
		out[i] = input%10 + '0';
		input = input/10;
		i--;
	}
	return out;
}
int main(){
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	
	vector<bool> prime(10000,1);	
	int inx,mul;
	for(int i=2;i<10000;i++){
		if(prime[i]==1){
			inx = 2;
			while(i*inx<10000){
				prime[i*inx]=0;
				inx++;
			}
		}
	}

	int src, des;
	bool found;
	int ans;
	vector<bool> visited;

	while(t--){
		cin>>src>>des;
		visited.resize(10000,0);
		queue<state> q;
		found = 0;
		
		
		state temp;
		temp.dis = 0;
		temp.src = int_to_4string(src);
		temp.des = int_to_4string(des);
		visited[src]=1;
		q.push(temp);

		state cur;
		string source;

		while(!q.empty()){
			cur = q.front();
			q.pop();
			if(cur.src == cur.des){
				found = 1;
				ans = cur.dis;
				break;
			}
			source = cur.src;
			for(int i='1';i<='9';i++){
				source[0] = i;
				if(prime[string_to_int(source)]&&!visited[string_to_int(source)]){
					temp = cur;
					temp.src = source;
					temp.dis++;
					visited[string_to_int(source)] = 1;
					q.push(temp);
				}
			}
			for(int j=1;j<=3;j++){
				source = cur.src;
				for(int i='0';i<='9';i++){
					source[j] = i;
					if(prime[string_to_int(source)]&&!visited[string_to_int(source)]){
						temp = cur;
						temp.src = source;
						temp.dis++;
						visited[string_to_int(source)] = 1;
						q.push(temp);
					}
				}
			}
		}

		if(!found) cout<<"Impossible\n";
		else cout<<ans<<"\n";
		visited.clear();
	}
}
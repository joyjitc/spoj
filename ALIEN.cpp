#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	int n,lim;
	vector<int> x;
	int temp,ans,sta;
	while(t--){
		cin>>n>>lim;
		for(int i=0;i<n;i++){
			cin>>temp;
			x.push_back(temp);
		}
		ans=0;
		temp=0;
		sta=0;
		int i=0;
		int j;
		while(i<n){
			if(x[i]<=lim){
				j=i;
				while(j<n&&i<=j){
					if(temp+x[j]<=lim){
						temp+=x[j];
						// if(temp>ans){
						// 	ans=temp;
						// 	sta=j-i+1;
						// }
						if(j-i+1>sta){
							ans=temp;
							sta=j-i+1;
						}
						else if(j-i+1==sta){
							if(temp<ans){
								ans=temp;
							}
						}
						j++;
					}
					else{
						temp-=x[i];
						i++;
						if(i==j)
							break;
					}
				}
				i=j;
			}				
			else
				i++;
		}
		cout<<ans<<" "<<sta<<"\n";
		x.clear();
	}
}



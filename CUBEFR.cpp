#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	int t,n;
	int lim=1000000,x,j;
	vector<int> tab(lim+1,0);
	for(int i=2;i<=lim;i++){
		if(tab[i]==0&&i<=100){
			x=i*i*i;
			if(x>0&&x<=lim)
				if(tab[x]==0)
					tab[x]=1;
		}
		else if(tab[i]==1){
			j=2;
			while(i*j<=lim){
				tab[i*j]=2;
				j++;
			}

		}
	}
	cin>>t;
	vector<int> ind(lim+1);
	j=1;
	for(int i=1;i<=lim;i++){
		if(tab[i]==0){
			ind[i]=j;
			j++;
		}
		else
			ind[i]=0;
	}
	for(int index=1;index<=t;index++){
		cin>>n;
		cout<<"Case "<<index<<": ";
		if(ind[n]==0)
			cout<<"Not Cube Free\n";
		else
			cout<<ind[n]<<"\n";
	}
}

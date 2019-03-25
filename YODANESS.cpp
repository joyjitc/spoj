#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int yodaness;
unordered_map <string,int> should_be_spoken;
vector<string> as_spoken;

void yoda_sort(int l,int h){
	if(l==h)
		return;

	int mid = l + (h-l)/2;
	yoda_sort(l,mid);
	yoda_sort(mid+1,h);

	vector<string> temp;
	int i=l,j=mid+1;
	while(i<=mid&&j<=h){
		if(should_be_spoken[as_spoken[i]]<should_be_spoken[as_spoken[j]]){
			temp.push_back(as_spoken[i]);
			i++;
		}
		else{
			temp.push_back(as_spoken[j]);
			yodaness += mid-i+1;
			j++;
		}
	}
	while(j<=h){
		temp.push_back(as_spoken[j++]);
	}
	while(i<=mid)
		temp.push_back(as_spoken[i++]);
	
	int x=0,y=l;
	while(y<=h){
		as_spoken[y] = temp[x];
		y++;x++;
	}

	return;
}


int main(){
	ios::sync_with_stdio(0);

	int t,n;
	string word;

	cin>>t;

	while(t--){
		cin>>n;

		as_spoken.clear();
		as_spoken.resize(n);
		for(int i=0;i<n;i++)
			cin>>as_spoken[i];

		should_be_spoken.clear();
		for(int i=0;i<n;i++){
			cin>>word;
			should_be_spoken.insert({word,i});
		}
		
		yodaness = 0;

		yoda_sort(0,n-1);
		cout<<yodaness<<"\n";
	}

}

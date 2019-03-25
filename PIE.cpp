#include<iostream>
#include <algorithm>
#include <vector>
#include<cmath>
#include<iomanip>
using namespace std;

vector<double> pie;

bool pie_eval(double mid, int friends){
	double r = sqrt(mid/acos(-1));
	int rad = (double)ceil(r);
	int f = 0;
	auto it = lower_bound (pie.begin(),pie.end(),rad);
	while(it!=pie.end()){
		f += (int) (acos(-1) * (*it) * (*it)/mid);
		it++;
	}
	if(f>=friends)
		return 1;
	else return 0;
}

int main(){
	ios::sync_with_stdio(0);

	int t;
	cin>>t;

	int n,f;


	while(t--){
		cin>>n>>f;
		f++;

		pie.clear();
		pie.resize(n);

		for(int i=0;i<n;i++)
			cin>>pie[i];

		sort(pie.begin(),pie.end());

		double l = 0, r = acos(-1) * pie.back() * pie.back(), mid;
		while(r-l>0.0001){
			double mid = l+ (r-l)/2.0;

			if(pie_eval(mid,f))
				l = mid;
			else
				r = mid;
		}

		cout<<setprecision(4)<<fixed<<l<<"\n";
	}
}
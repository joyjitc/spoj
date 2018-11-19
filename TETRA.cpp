#include <bits/stdc++.h>
using namespace std;
double triArea(double a, double b, double c){
	double s = (a+b+c)/2;
	double area = sqrt(s*(s-a)*(s-b)*(s-c));
	return area;
}
int main(){
	ios::sync_with_stdio(0);
	// cin.tie(0);
	int t;
	cin>>t;
	long u,v,w,U,V,W,u_,v_,w_;
	double vol;
	double r,a1,a2,a3,a4;
	cout<<fixed;
	cout.precision(4);
	while(t--){
		cin>>u>>v>>w>>W>>V>>U;
		if(u==0||v==0||w==0||W==0||V==0||U==0)
			cout<<"0.0000\n";
		u_ = v*v + w*w - U*U;
		v_ = w*w + u*u - V*V;
		w_ = u*u + v*v - W*W;
		vol = (4*u*u*v*v*w*w) - (u*u*u_*u_) - (v*v*v_*v_) - (w*w*w_*w_) + (u_*v_*w_);
		vol = sqrt(vol);
		vol = vol/12.0;
		a1=triArea(u,w,V);a2=triArea(v,w,U);a3=triArea(u,v,W);a4=triArea(U,V,W);
		r=3*vol/(a1+a2+a3+a4);
		cout<<r<<"\n";
	}
}
#include <iostream>
using namespace std;

int main(){
        ios::sync_with_stdio(false);
        unsigned long long input;
        int t;
        cin>>t;
        while(t--){
                cin>>input;
                cout<<((3*input*(input+1)/2)-input)%1000007<<endl;
        }
        return 0;
}

//SOLVED USING BITree(works for negative numbers)

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;


class BITree{
    int N;
    vector<ull> array;
public:
    BITree(int N){
        this->N = N;
        array.resize(N+1,0);
    }
    BITree(vector<ull> input){
        array.resize(input.size()+1,0);
        this->N = input.size();
        int i = 0;
        // for(int it = 0; it<=N;++it)
        //  cout<<array[it]<<" ";
        for(vector<ull>::iterator it=input.begin();it!=input.end();++it,i++)
            this->updateBIT(i,(*it));
            // cout<<i<<" "<<(*it)<<endl;

    }
    void updateBIT(int index, ull value){
        while(index<=this->N){
            this->array[index] += value;
            index += index&(-index);
        }
    }
    ull getSum(int index){
        ull sum = 0;
        while(index>0){
            // cout<<"debug :: index = "<<index<<" "<<array[index]<<endl;
            sum+=this->array[index];
            index -= index&(-index);
        }
        return sum;
    }
    void print(){
        for(int i = 0;i<=N;i++)
            cout<<this->array[i]<<" ";
        cout<<endl;
    }

};

int main()
{
	ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int size;
    while(t--){
        // int max_val = INT_MIN;
        cin>>size;
        int a;
        vector<int> inp;
        vector<int> temp;
        for(int i = 0;i<size;i++){
            cin>>a;
            // max_val=max(max_val,a);
            inp.push_back(a);
            temp.push_back(a);
        }
        sort(temp.begin(),temp.end());
        for(int i = 0;i<size;i++){
        	inp[i]=lower_bound(temp.begin(),temp.end(),inp[i]) - temp.begin() + 1;
        }
        // cout<<"debug :: max_val = "<<max_val<<endl;
        BITree b(size);
        ull inv_cnt = 0;
        for(vector<int>::reverse_iterator rit = inp.rbegin();rit!=inp.rend(); ++rit){
            inv_cnt += b.getSum(*rit);
            // b.print();
            // cout<<"debug :: (*rit) = "<<(*rit)<<endl;
            // cout<<"debug :: getsum = "<<b.getSum(*rit)<<endl;
            // cout<<"debug :: inv_cnt = "<<inv_cnt<<endl;
            b.updateBIT((*rit),1);
        }
        cout<<inv_cnt<<endl;
    }

    return 0;
}
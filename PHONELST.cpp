#include <bits/stdc++.h>

using namespace std;

struct TrieNode{
	TrieNode* edges[10] = {NULL};
	bool is_leaf = false;
};
void insertWord(TrieNode* node, string& word, int index){
	if(index<word.size()){
		if(node->edges[word[index]-'0']==NULL)
			node->edges[word[index]-'0'] = new TrieNode;
		insertWord(node->edges[word[index]-'0'],word,index+1);
	}
	else
		node->is_leaf = true;
}
bool checkWord(TrieNode* node, string& word, int index){
	if(index<word.size()){
		if(node->edges[word[index]-'0']==NULL)
			return false;
		else
			return checkWord(node->edges[word[index]-'0'],word,index+1);
	}
	else
		return node->is_leaf;
}
bool prefixExist(TrieNode* node, string& word, int index){
	if(index<word.size()){
		if(node->is_leaf){
			// cout<<word[index-1]<<"\n";
			return true;
		}
		else return prefixExist(node->edges[word[index]-'0'],word,index+1); 
	}
	else return false;
}
void clearTrie(TrieNode* node){
	for(int i=0;i<10;i++){
		if(node->edges[i]!=NULL){
			clearTrie(node->edges[i]);
			delete node->edges[i];
			// node->edges[i] = NULL;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	int n;
	string input;
	vector<string> list;
	TrieNode* trie;
	bool consis;
	while(t--){
		consis = true;
		cin>>n;
		trie = new TrieNode;
		for(int i=0;i<n;i++){
			cin>>input;
			list.push_back(input);
			insertWord(trie,input,0);
		}
		for(auto x:list){
			if(prefixExist(trie,x,0)){
				consis = false;
				// cout<<"Fuck:: "<<x<<"\n";
				break;
			}
		}
		if(consis) cout<<"YES\n";
		else cout<<"NO\n";
		list.clear();
		clearTrie(trie);
		delete trie;
	}
}
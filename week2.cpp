#include <iostream>
using namespace std;

class Trie{
public:
	int count;
	Trie* next[26];
	Trie():count(0){
		for(unsigned i(0); i<26; ++i){
			next[i] = NULL;
		}
	}

	void insert(const string& str){
		Trie *ptr = this;
		for(unsigned int i(0); i < str.size(); ++i){
			int index = str[i] - 'a';
			if(ptr->next[index] != NULL){ // if already a node here.
				(ptr->next[index]->count)++;
			}
			else{	// if no node here.
				ptr->next[index] = new Trie;
				ptr->next[index]->count = 1;
			}

			ptr = ptr->next[index];
		}
	}

	unsigned int find_count(const string& str){
		Trie *ptr = this;
		for(unsigned int i(0); i < str.size(); ++i){
			int index = str[i] - 'a';
			if(ptr->next[index]){ // if already a node here.
				ptr = ptr->next[index];
			}
			else{	// if no node here.
				return 0;
			}
		}
		return ptr->count;
	}
};

int main()
{
	int N,M;
	string word, query;
	Trie* root = new Trie;

	cin >> N; // get inputed words
	while(N--){
		cin >> word;
		root->insert(word);
	}

	cin >> M;
	while(M--){	// get inputed queries.
		cin>>query;
		cout << root->find_count(query) << endl;
	}
	return 0;
}
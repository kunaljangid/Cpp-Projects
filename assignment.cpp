#include<string>
#include<iostream>
#include<string>
#include<stdbool.h>

using namespace std;

class trienode {
private:
public:

    trienode *children[26];
    bool endofword = false;

    trienode() {
        for(int i =0;i<26;i++){
        	children[i]=NULL;
        }
    }
};


class Trie {
private:
public:
    trienode *root;

    //trienode * end;
    //bool first=true;
    //int i=0;
    void inserttrie(string word, int len) {
        inserttriee(word, len, root, 0);
    }

    void inserttriee(string word, int len, trienode *current, int i) {
        int index = word[i] - 'a';
        //trienode *cur = new trienode();
        // trienode *temp = new trienode();
        //cur=current;
        if(i==len-1){
        	current->endofword=true;
        	}

        if (current->children[index] == NULL) {
            trienode *x = new trienode();
            current->children[index] = x;
            current = x;
        } else
            current = current->children[index];
        if (i == len - 1)
            return;
        inserttriee(word, len, current, i + 1);
    }

    void searchword(string word,int len){
        searchwords(word,root,len,0);
    }

    void searchwords(string word,trienode *current,int len,int j){
    	if(j==len-1&& current->endofword==true){
    		cout<<"yes there is a word "<<word<<"\n";
            return;
    	}
    	int index = word[j] - 'a';
    	if(current->children[index]==NULL){
    		cout<<"no there is no such word \n";
    	}
    	else{
    		current=current->children[index];
    		searchwords( word,current,len,j+1);
    	}
    }

    Trie() {
        root = new trienode();
    };


};

int main() {
    int t, x = 1;
    string word;
    cout << "enter the number of names you want to add" << endl;
    cin >> t;
    Trie *list = new Trie;
    //cout << "thishjd";
    for (int i = 0; i < t; i++) {
        cout << "enter the word" << endl;
        cin >> word;
       // cout << word;
        //cout << word.length();

        int len = word.length();
        list->inserttrie(word, len);
	}
	cout<<"enter the number of words to be searched"<<"\n";
	cin>>t;
    for(int i=0;i<t;i++){
     cout << "enter the word" << endl;
    cin >> word;   
	int len = word.length();
	list->searchword(word,len);
}
}
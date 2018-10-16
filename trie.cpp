#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

const int N = 26;

struct Trie{
    int words;
    int prefixes;
    Trie* edges[26];
    Trie(){
        words = 0;
        prefixes = 0;
        for(int i = 0; i < N; i++)
            edges[i] = NULL;
    }
};

Trie root;

void addWord(Trie* vertex, int idx, string &word){
    if(idx == word.size()){
        vertex->prefixes++;
        vertex->words++;
        return;
    }
    vertex->prefixes++;
    if(vertex->edges[word[idx]-'a'] == NULL)
        vertex->edges[word[idx]-'a'] = new Trie;
    addWord(vertex->edges[word[idx]-'a'], idx+1, word);
}

int countWords(Trie* vertex, int idx, string &word){
    if(idx == word.size())
        return vertex->words;
    if(vertex->edges[word[idx]-'a'] == NULL)
        return 0;
    return countWords(vertex->edges[word[idx]-'a'], idx+1, word);
}

int countPrefixes(Trie* vertex, int idx, string &word){
    if(idx == word.size())
        return vertex->prefixes;
    if(vertex->edges[word[idx]-'a'] == NULL)
        return 0;
    return countPrefixes(vertex->edges[word[idx]-'a'], idx+1, word);
}

void init(){
    root.words = 0;
    root.prefixes = 0;
    for(int i = 0;i < N; i++)
        root.edges[i] = NULL;
}

int main(){
    io;
    init();
    string str = "karan";
    string str2 = "ka";
    addWord(&root, 0, str);
    cout << countPrefixes(&root, 0, str2) << endl;
    return 0;
}
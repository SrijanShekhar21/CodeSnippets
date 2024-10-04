/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

class TrieNode{
public:
    TrieNode* child[26];
    bool isEnd;
    TrieNode(){
        isEnd = false;
        for(int i=0; i<26; i++){
            child[i] = NULL;
        }
    }
};

class Trie {
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
    void insert(string word){
        TrieNode* curr = root;
        for(char w: word){
            if(curr->child[w-'a'] == NULL){
                curr->child[w - 'a'] = new TrieNode();
            }
            curr = curr->child[w - 'a'];
        }
        curr->isEnd = true;
    }
    bool search(string word){
        TrieNode* curr = root;
        for(char w: word){
            if(curr->child[w - 'a'] == NULL)return false;
            curr = curr->child[w - 'a'];
        }
        return curr->isEnd;
    }
    bool startsWith(string prefix){
        TrieNode* curr = root;
        for(char w: prefix){
            if(curr->child[w - 'a'] == NULL)return false;
            curr = curr->child[w - 'a'];
        }
        return true;
    }
};
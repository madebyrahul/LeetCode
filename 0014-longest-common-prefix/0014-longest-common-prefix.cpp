class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    int childCount;
    TrieNode(char ch){
        data = ch;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie{
    public:
    TrieNode* root;
    Trie(char ch){
        root = new TrieNode(ch);
    }

    void insertWord(TrieNode* root,string word){
        if(word.length() == 0){
            root->isTerminal = true;
            return ;
        }
        int index = word[0] - 'a';
        TrieNode* child;
        if(root->children[index] != NULL){
            child = root->children[index];
        }else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }
        insertWord(child,word.substr(1));
    }
    
    void insert(string word){
        insertWord(root,word);
    }

    void LCP(string word,string &ans){
        TrieNode* temp = root; 
        for(int i=0;i<word.length();i++){
            char ch = word[i];
            if(temp->isTerminal){
                break;
            }
            if(temp->childCount == 1){
                ans.push_back(ch);
                int index = word[i] - 'a';
                temp = temp->children[index];
            }else{
                break;
            }
        }
    }

};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie* t = new Trie('\0'); // t initialised with null root value
        for(int i=0;i<strs.size();i++){
            t->insert(strs[i]);
        }
        string first = strs[0];
        string ans = "";
        t->LCP(first,ans);
        return ans;
    }
};
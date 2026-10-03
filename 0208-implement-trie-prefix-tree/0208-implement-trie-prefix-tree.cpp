class TrieNode{
    public:
        char data;
        unordered_map<char,TrieNode*>childern;
        bool isTerminal;

        TrieNode(char val){
            data = val;
            isTerminal = false;
        }
};
void InsertWord(TrieNode* root, string word){
    if(word.length() == 0){
        root->isTerminal = true;
        return;
    }
    char ch = word[0];
    TrieNode*child;
    if(root->childern.find(ch)!= root->childern.end()){
        child = root->childern[ch];
    }
    else{
        child = new TrieNode(ch);
        root->childern[ch] = child;
    }
    InsertWord(child,word.substr(1));
}

bool SearchWord(TrieNode* root, string word){
    if(word.length() == 0){
       return  root->isTerminal;
    }
    char ch = word[0];
    TrieNode*child;
    if(root->childern.find(ch) != root->childern.end()){
        child = root->childern[ch];
    }
    else{
        return false;
    }
    bool recursionkaans = SearchWord(child,word.substr(1));
    return recursionkaans;
}
bool SearchPrefix(TrieNode* root, string word){
    if(word.length() == 0){
       return  true;
    }
    char ch = word[0];
    TrieNode*child;
    if(root->childern.find(ch) != root->childern.end()){
        child = root->childern[ch];
    }
    else{
        return false;
    }
    bool recursionkaans = SearchPrefix(child,word.substr(1));
    return recursionkaans;
}
class Trie {
public:
    TrieNode*root;
    Trie() {
        root = new TrieNode('-');
        
    }
    
    void insert(string word) {
        InsertWord(root,word);
        
    }
    
    bool search(string word) {
        return SearchWord(root,word);
        
    }
    
    bool startsWith(string prefix) {
        return SearchPrefix(root,prefix);
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
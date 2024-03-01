class TrieNode{
public:
    char data;
    TrieNode ** child;
    bool isTerminal;
    
    TrieNode(char data){
        this->data = data;
        child = new TrieNode*[26];
        for(int i=0;i<26;++i){
            child[i] = NULL;
        }
        isTerminal = false;
    }
};

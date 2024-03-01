#include<string>
#include"TrieNode.h"

class Trie{
    TrieNode* root;
    
public:
    Trie(){
        root = new TrieNode('\0');
    }
    
    void insertWord(TrieNode* root, string data){
        //Base Case
        if(data.length() == 0){
            root -> isTerminal = true;
            return;
        }
        
        //Small calulation
        char firstChar = data[0];
        int index = data[0] - 'a';
        if(root->child[index] == NULL){
            TrieNode* childNode = new TrieNode(firstChar);
            root->child[index] = childNode;
        }
       
        //Recursive Call
        insertWord(root->child[index],data.substr(1));
        
        
    }
    
    void insertWord(string data){
        insertWord(root,data);
    }
    
    bool search(TrieNode* root ,string word){
        if(word.length()==0){
            if(root->isTerminal == true){
                return true;
            }
            return false;
        }
        
        
        char firstChar = word[0];
        int index = firstChar - 'a';
        if(root->child[index] == NULL){
            return false;
        }
        else{
            return search(root->child[index],word.substr(1));
        }
    }
    
    bool search(string word){
        return search(root,word);
    }
    
    void deleteData(TrieNode* root,string word){
        if(word.length() == 0){
            root->isTerminal = false;
            return;
            
        }
        TrieNode* childe;
        int index = word[0] - 'a';
        if(root->child[index] != NULL){
            childe = root->child[index];
        }
        else{
            return;
        }
        deleteData(childe,word.substr(1));
        
        if(childe->isTerminal == false){
            for(int i=0;i<26;++i){
                if(childe->child[i] != NULL){
                    return;
                }
            }
            delete childe;
            root->child[index] = NULL;
        }
        
        
        
        
        
        
//        char firstChar = word[0] ;
//        int index = word[0] - 'a';
//        if(root->child[index] != NULL){
//            deleteData(root->child[index],word.substr(1));
//        }
//        else{
//            cout<<"word doesn't exits"<<endl;
//            return;
//        }
    }
    
    void deleteData(string word){
        return deleteData(root,word);
    }
    
};

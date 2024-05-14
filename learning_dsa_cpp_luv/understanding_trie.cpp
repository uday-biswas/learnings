#include <bits/stdc++.h>
using namespace std;

//declaring the node structure for the trie
class trieNode{
    public:
   char ch;                  //data
   trieNode* children[26];   //child nodes
   bool isTerminal;          //to check if the node is terminal node or not, true for terminal otherwise false
   int childCount;           //number of children nodes
   vector<int> childIndex;   //vector storing the indexes of the child nodes
   trieNode(char ch){         //constructor for the node initialising the values
      this->ch = ch;
      for(int i=0; i<26; i++){
         children[i] = NULL;
      }
      isTerminal = false;
      childCount = 0;
   }
};

//declaring the structure of the trie 
class trie{
   public:
   trieNode* root;          //the root node for the trie
   trie(){     
     root = new trieNode('\0');      //initialising and putting the null character in the root node of the trie
   }

   //function for inserting strings in the trie
   //approach - we will recursively add each character of the string into the trie and if it is the last character of the string 
   // ,then we will make the 'isTerminal' variable as true for that character's node.
   void insertWord(trieNode* root, string word){
      //base case
        if(word.size() == 0){           //if its the last character of the string , then put isTerminal as true;
            root->isTerminal = true;
            return;
        }
        
        trieNode* child;
        int index = word[0] - 'a';         //getting the index in which the node has to be inserted
        if(root->children[index] != NULL){  //if that character's index is already filled , then nothing to do , just traverse
             child = root->children[index];
        }
        else{                               //if that character's index is empty, then create a node with that character and insert into the trie, increase the childcount
            child = new trieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
            root->childIndex.push_back(index);
        }
        insertWord(child, word.substr(1));      //inserting the next characters of the string to the trie
   }

   //function to search the given the word in the trie
   //approach - just traverse the trie for the letters of the word, if for any of the letter ,the trie node is null then return false.
   bool search(trieNode* root, string word){
      //base case
       if(word.size() == 0){           //if its the last character to be find, then return true only if the isTerminal is true, otherwise false;
           return root->isTerminal;
       }

       int index = word[0] - 'a';         //finding the index of the character to find in the trie
       trieNode* child;        
       if(root->children[index] != NULL){    //if that index is not null means the letter is there, so we will search for the next letters in the word
          child = root->children[index];
       }
       else{                                //if that node in that index is null, means the letter is not there , so word doesn't exist in the trie , so return false.
          return false;
       }
       return search(child, word.substr(1));   //finding for the next letters
   }

};

int main() {
trie* t = new trie();         //creating a trie

t->insertWord(t->root,"abc");    //insertion in trie
t->insertWord(t->root,"abcd");
cout<<t->search(t->root,"abc");   //searching in that trie.
return 0;
}
#include <bits/stdc++.h> 
using namespace std;

struct Node {
    public:
    Node* links[26];
    int cntEndWith = 0;
    int cntPrefix = 0; 

    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL); 
    }
    Node* get(char ch) {
        return links[ch - 'a']; 
    }
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
    void increaseEnd() {
        cntEndWith++; 
    }
    void increasePrefix() {
        cntPrefix++;
    }
    void deleteEnd() {
        cntEndWith--; 
    }
    void reducePrefix() {
        cntPrefix--; 
    }
};


class Trie {
private:
    Node* root; 

public:
    
    Trie() {
       
        root = new Node(); 
    }

    void insert(string word) {
        
        Node* node = root; 
     
        for (int i = 0; i < word.size(); i++) { 
             
            if (!node->containsKey(word[i])) {
               
                node->put(word[i], new Node()); 
            }
            node = node->get(word[i]);
            node->increasePrefix(); 
        }
        node->increaseEnd(); 
    }


    int countWordsEqualTo(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) { 
            if (node->containsKey(word[i])) { 
                node = node->get(word[i]); 
            } else {
                return 0;
            }
        }
        return node->cntEndWith; 
    }

    // Function to count the number of
    // words starting with a given prefix
    int countWordsStartingWith(string word) {
         // Start from the root node
        Node* node = root;
        // Iterate over each character in the prefix
        for (int i = 0; i < word.size(); i++) { 
            // If the character is found in the trie
            if (node->containsKey(word[i])) { 
                // Move to the child node
                // corresponding to the character
                node = node->get(word[i]); 
            } else {
                // Return 0 if the
                // character is not found
                return 0; 
            }
        }
        // Return the count of
        // words with the prefix
        return node->cntPrefix; 
    }

    // Function to erase a
    // word from the trie
    void erase(string word) {
         // Start from the root node
        Node* node = root;
        // Iterate over each
        // character in the word
        for (int i = 0; i < word.size(); i++) { 
            // If the character is
            // found in the trie
            if (node->containsKey(word[i])) { 
                 // Move to the child node
                 // corresponding to the character
                node = node->get(word[i]);
                // Decrement the prefix
                // count for the node
                node->reducePrefix(); 
            } else {
                // Return if the
                // character is not found
                return; 
            }
        }
        // Decrement the end count
        // for the last node of the word
        node->deleteEnd(); 
    }
};


int main() {
    Trie trie; 
    trie.insert("apple"); 
    trie.insert("app"); 
    cout << "Inserting strings 'apple', 'app' into Trie"<< endl;
    cout << "Count Words Equal to 'apple': ";
    cout << trie.countWordsEqualTo("apple") << endl; 
    cout << "Count Words Starting With 'app': ";
    cout << trie.countWordsStartingWith("app") << endl; 
    cout << "Erasing word 'app' from trie"<< endl;
    trie.erase("app"); 
    cout << "Count Words Equal to 'apple': ";
    cout << trie.countWordsEqualTo("apple") << endl; 
    cout << "Count Words Starting With 'apple': ";
    cout << trie.countWordsStartingWith("app") << endl; 
    return 0; 
}
                            
                        
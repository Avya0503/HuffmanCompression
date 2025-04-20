#include <iostream>
#include <fstream>
#include <queue>
#include <unordered_map>
using namespace std;

// A Huffman Tree node
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char ch, int freq, Node* left = nullptr, Node* right = nullptr)
        : ch(ch), freq(freq), left(left), right(right) {}
};

// Comparison function for the priority queue
struct Compare {
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq;
    }
};

// Traverse the Huffman Tree and store Huffman codes
void encode(Node* root, string str, unordered_map<char, string>& huffmanCode) {
    if (root == nullptr)
        return;

    // If the node is a leaf
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

// Decode a Huffman encoded string
string decode(Node* root, string str) {
    string result = "";
    Node* current = root;
    for (char bit : str) {
        current = (bit == '0') ? current->left : current->right;
        if (!current->left && !current->right) {
            result += current->ch;
            current = root;
        }
    }
    return result;
}

// Build the Huffman Tree and return the root
Node* buildHuffmanTree(const string& text) {
    // Count frequency of each character
    unordered_map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    // Create a priority queue
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Create a leaf node for each character
    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    // Merge nodes until the tree is complete
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        pq.push(new Node('\0', left->freq + right->freq, left, right));
    }

    return pq.top();
}

int main() {
    string text;
    cout << "Enter text to compress: ";
    getline(cin, text);

    Node* root = buildHuffmanTree(text);

    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);

    cout << "\nHuffman Codes:\n";
    for (auto pair : huffmanCode) {
        cout << pair.first << " " << pair.second << endl;
    }

    string encoded = "";
    for (char ch : text) {
        encoded += huffmanCode[ch];
    }

    cout << "\nEncoded string:\n" << encoded << endl;

    string decoded = decode(root, encoded);
    cout << "\nDecoded string:\n" << decoded << endl;

    return 0;
}

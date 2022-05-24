#include <bits/stdc++.h>
using namespace std;
struct Node {
  int freq;
  char data;
  Node* left;
  Node* right;
  Node(char c,int f,Node* l=NULL,Node* r=NULL)
  {
      data=c;freq=f;
      left=l;right=r;
  }
};
struct compare {
	bool operator()(Node* l, Node* r){
		return (l->freq > r->freq);
	}
};
void printCodes(struct Node* root, string str){
	if (!root)
		return;
	if (root->data != '$')
		cout << root->data << ": " << str << "\n";
	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
}
void printHcodes(char arr[], int freq[], int size){
	priority_queue<Node*, vector<Node*>, compare> h;
	for (int i = 0; i < size; ++i)
		h.push(new Node(arr[i], freq[i]));
	while (h.size() > 1) {
		Node *l = h.top();h.pop();
		Node *r = h.top();h.pop();
		Node *top = new Node('$', l->freq + r->freq, l, r);
		h.push(top);
	}
	printCodes(h.top(), "");
}
int main(){
	char arr[] = { 'a', 'd', 'e', 'f' };
	int freq[] = { 30, 40, 80, 60 };
	int size = sizeof(arr);
	printHcodes(arr, freq, size);
}
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
//** FUNCS */
// to build tree -> init();
// level order traversal -> levelOrderTraversal();
// reverse order traversal -> reverseOrderTraversal();
// inorder traversal -> inorder();
// pre order traversal -> preorder();
// post order traversal -> postorder();
// to count leaf nodes -> countLeaf();
class Node {
public:
  int data;
  Node *left;
  Node *right;
  Node(int data) {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};

class Tree {
private:
  Node *root;

public:
  //** CONS AND DES */
  Tree() { root = NULL; }
  ~Tree() { deleteTree(root); }
  void deleteTree(Node *root) {
    if (!root) {
      return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
  }
  //** BUILD TREE */
  void buildTree(Node *&root) {
    int data;
    cin >> data;
    if (data == -1) {
      root = NULL;
      return;
    }
    root = new Node(data);
    buildTree(root->left);
    buildTree(root->right);
  };
  void init() { buildTree(root); };
  //** LEVEL ORDER TRAVERSAL */
  void levelOrderTraversal() {
    if (!root) {
      return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
      Node *front = q.front();
      q.pop();
      cout << front->data << " ";
      if (front->left) {
        q.push(front->left);
      }
      if (front->right) {
        q.push(front->right);
      }
    }
  };
  //** REVERSE ORDER TRAVERSAL */
  void reverseOrderTraversal() {
    if (!root) {
      return;
    }
    queue<Node *> q;
    stack<Node *> s;
    q.push(root);
    while (!q.empty()) {
      Node *front = q.front();
      q.pop();
      s.push(front);
      if (front->right) {
        q.push(front->right);
      }
      if (front->left) {
        q.push(front->left);
      }
    }
    while (!s.empty()) {
      Node *curr = s.top();
      s.pop();
      cout << curr->data << " ";
    }
  };
  //** IN ORDER TRAVERSAL */
  void inOrderTraversal(Node *root) {
    if (!root) {
      return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
  };
  void inorder() { inOrderTraversal(root); };
  //** PRE ORDER TRAVERSAL */
  void preOrderTraversal(Node *root) {
    if (!root) {
      return;
    }
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
  };
  void preorder() { preOrderTraversal(root); };
  //** POST ORDER TRAVERSAL */
  void postOrderTraversal(Node *root) {
    if (!root) {
      return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
  };
  void postorder() { postOrderTraversal(root); };
  //** COUNT LEAF NODES */
  void countLeafNodes(Node *root, int &count) {
    if (!root) {
      return;
    }
    countLeafNodes(root->left, count);
    if (!root->left && !root->right) {
      count++;
    }
    countLeafNodes(root->right, count);
  };
  int countLeaf() {
    int count = 0;
    countLeafNodes(root, count);
    return count;
  };
};

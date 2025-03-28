#include <iostream>
using namespace std;

//** NODE */
class Node {
public:
  int data;
  Node *next;
  Node(int data) {
    this->data = data;
    this->next = NULL;
  }
};

//** LINKED LIST */
class LinkedList {
private:
  Node *head;

public:
  //** CONS AND DES */
  LinkedList() { head = NULL; };
  ~LinkedList() {
    Node *curr = head;
    while (curr) {
      Node *temp = curr;
      curr = curr->next;
      delete temp;
    }
    head = NULL;
  };
  //** INSERT AT FIRST POSITION */
  void insertAtHead(int data) {
    Node *temp = new Node(data);
    if (head == NULL) {
      head = temp;
      return;
    } else {
      temp->next = head;
      head = temp;
    }
  };
  //** INSERT AT LAST POSITION */
  void insertAtTail(int data) {
    Node *temp = new Node(data);
    if (head == NULL) {
      head = temp;
      return;
    } else {
      Node *curr = head;
      while (curr->next) {
        curr = curr->next;
      }
      curr->next = temp;
    }
  };
  //** SIZE OF LINKED LIST */
  int size() {
    Node *curr = head;
    int count = 0;
    while (curr) {
      curr = curr->next;
      count++;
    }
    return count;
  };
  //** CHECK EMPTY LINKED LIST */
  bool isEmpty() { return head == NULL; };

  //** INSERT AT ANY POSITION */
  void insertAtPosition(int data, int position) {
    Node *temp = new Node(data);
    if (position <= 1 || !head) {
      insertAtHead(data);
      return;
    }
    Node *curr = head;
    int count = 1;
    while (curr->next && count < position - 1) {
      curr = curr->next;
      count++;
    }
    temp->next = curr->next;
    curr->next = temp;
  };
  //** DELETE AT AN POSITION */
  void deleteAtPosition(int position) {
    if (!head) {
      return;
    }
    Node *curr = head;
    Node *prev = NULL;
    if (position <= 1) {
      head = head->next;
      delete curr;
      return;
    }
    int count = 1;
    while (curr && count < position) {
      prev = curr;
      curr = curr->next;
      count++;
    }
    if (!curr) {
      return;
    }
    prev->next = curr->next;
    delete curr;
  };
  //** PRINT LINKED LIST */
  void print() {
    Node *curr = head;
    while (curr) {
      cout << curr->data << " ";
      curr = curr->next;
    }
  };
};
#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node(int data) {
    this->data = data;
    this->next = NULL;
  }
};

class LinkedList {
private:
  Node *head;

public:
  LinkedList() { head = NULL; };
  ~LinkedList() {
    Node *curr = head;
    while (curr) {
      Node *temp = curr;
      curr = curr->next;
      delete temp;
    }
  };
  void insertAtHead(int data) {
    Node *temp = new Node(data);
    if (head == NULL) {
      head = temp;
    } else {
      temp->next = head;
      head = temp;
    }
  };
  void insertAtTail(int data) {
    Node *temp = new Node(data);
    if (head == NULL) {
      head = temp;
    } else {
      Node *curr = head;
      while (curr->next) {
        curr = curr->next;
      }
      curr->next = temp;
    }
  };
  int size() {
    Node *curr = head;
    int count = 0;
    while (curr) {
      curr = curr->next;
      count++;
    }
    return count;
  };
  bool isEmpty() {
    if (!head) {
      return true;
    }
    return false;
  };
  void insertAtPosition(int data, int position) {
    Node *temp = new Node(data);
    if (position <= 1) {
      insertAtHead(data);
      return;
    }
    Node *curr = head;
    int count = 1;
    while (curr && count < position - 1) {
      curr = curr->next;
      count++;
    }
    if (!curr) {
      insertAtTail(data);
      return;
    }
    temp->next = curr->next;
    curr->next = temp;
  };
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
  void print() {
    Node *curr = head;
    while (curr) {
      cout << curr->data << " ";
      curr = curr->next;
    }
  };
};
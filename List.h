#ifndef LIST_H
#define LIST_H

#include <string>

template<class T>
class List
{
  class Node
  {
    public:
      T* data;
      Node* next;
      Node* prev; // added for doubly linked list

      // Constructor initializing prev to nullptr
      Node() : data(nullptr), next(nullptr), prev(nullptr) { }
  };

  public:
    List();
    ~List();
    void add(T*);
    void del(std::string, T**);
    void print() const;

  private:
    Node* head;
    Node* tail; // added for doubly linked list
};

template<class T>
List<T>::List() : head(nullptr), tail(nullptr) { } // initialize tail

template<class T>
List<T>::~List()
{
  Node* currNode = head;
  Node* nextNode;

  while (currNode != nullptr) {
    nextNode = currNode->next;
    delete currNode->data;
    delete currNode;
    currNode = nextNode;
  }
}

template<class T>
void List<T>::del(std::string n, T** stu)
{
  Node* currNode = head;

  while (currNode != nullptr) {
    if (currNode->data->getName() == n)
      break;

    currNode = currNode->next;
  }

  if (currNode == nullptr) {
    *stu = nullptr;
    return;
  }

  // Update the links of the surrounding nodes
  if (currNode->prev != nullptr) {
    currNode->prev->next = currNode->next;
  }
  else {
    head = currNode->next; // Update head if necessary
  }
  
  if (currNode->next != nullptr) {
    currNode->next->prev = currNode->prev;
  }
  else {
    tail = currNode->prev; // Update tail if necessary
  }

  *stu = currNode->data;
  delete currNode;
}

template<class T>
void List<T>::add(T* stu)
{
  Node* newNode = new Node;
  newNode->data = stu;

  Node* currNode = head;
  Node* prevNode = nullptr;

  while (currNode != nullptr && currNode->data->getName() < stu->getName()) {
    prevNode = currNode;
    currNode = currNode->next;
  }

  newNode->next = currNode;
  newNode->prev = prevNode;

  if (currNode != nullptr) {
    currNode->prev = newNode;
  }
  else {
    tail = newNode; // New node is now the last node
  }
  
  if (prevNode != nullptr) {
    prevNode->next = newNode;
  }
  else {
    head = newNode; // New node is now the first node
  }
}

template<class T>
void List<T>::print() const
{
  Node* currNode = head;

  // Forward direction
  std::cout << "Forward:" << std::endl;
  while (currNode != nullptr) {
    currNode->data->print();
    currNode = currNode->next;
  }

  // Backward direction
  currNode = tail;
  std::cout << "Backward:" << std::endl;
  while (currNode != nullptr) {
    currNode->data->print();
    currNode = currNode->prev;
  }
}

#endif

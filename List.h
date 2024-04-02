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
      Node* prev; 
  };

  public:
    List();
    ~List();
    void add(T*);
    void del(std::string, T**);
    void print() const;
    void addFront(T*);
    void addBack(T*);

  private:
    Node* head;
    Node* tail; 
};

template<class T>
List<T>::List() : head(nullptr), tail(nullptr) { } 

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

  if (currNode->prev != nullptr) {
    currNode->prev->next = currNode->next;
  }
  else {
    head = currNode->next; 
  }
  
  if (currNode->next != nullptr) {
    currNode->next->prev = currNode->prev;
  }
  else {
    tail = currNode->prev; 
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
    tail = newNode; 
  }
  
  if (prevNode != nullptr) {
    prevNode->next = newNode;
  }
  else {
    head = newNode;
  }
}

template<class T>
void List<T>::print() const
{
  Node* currNode = head;

  std::cout << "Forward:" << std::endl;
  while (currNode != nullptr) {
    currNode->data->print();
    currNode = currNode->next;
  }

  currNode = tail;
  std::cout << "Backward:" << std::endl;
  while (currNode != nullptr) {
    currNode->data->print();
    currNode = currNode->prev;
  }
}

template<class T>
void List<T>::addFront(T* stu){
    Node* newNode = new Node;
    newNode->data = stu;
    newNode->next = head;
    newNode->prev = nullptr;
    if (head != nullptr) {
        head->prev = newNode;
    } else {
        tail = newNode;
    }

    head = newNode; 
}

template<class T>
void List<T>::addBack(T* stu){
    Node* newNode = new Node;
    newNode->data = stu;
    newNode->next = nullptr; 
    if (tail != nullptr) {
        tail->next = newNode;
        newNode->prev = tail;
    } else {
        head = newNode;
    }

    tail = newNode; 
}



#endif

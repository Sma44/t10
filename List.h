#ifndef LIST_H
#define LIST_H


template<class T>
class List
{
  class Node
  {
    public:
      T* data;
      Node*    next;
  };

  public:
    List();
    ~List();
    void add(T*);
    void del(string, T**);
    void print() const;

  private:
    Node* head;
};

template<class T>
List<T>::List() : head(nullptr) { }

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
void List<T>::del(string n, T** stu)
{
  Node* prevNode = nullptr;
  Node* currNode = head;

  while (currNode != nullptr) {
    if (currNode->data->getName() == n)
      break;

    prevNode = currNode;
    currNode = currNode->next;
  }

  if (currNode == nullptr) {
    *stu = nullptr;
    return;
  }

  if (prevNode == nullptr) {
    head = currNode->next;
  }
  else {
    prevNode->next = currNode->next;
  }

  *stu = currNode->data;
  delete currNode;

}

template<class T>
void List<T>::add(T* stu)
{
  Node* newNode;
  Node* prevNode;
  Node* currNode;

  newNode = new Node;
  newNode->data = stu;
  newNode->next = nullptr;

  currNode = head;
  prevNode = nullptr;

  while (currNode != nullptr) {
    if (currNode->data->getName() > stu->getName())
      break;

    prevNode = currNode;
    currNode = currNode->next;
  }

  if (prevNode == nullptr) {
    head = newNode;
  }
  else {
    prevNode->next = newNode;
  }

  newNode->next  = currNode;
}

template<class T>
void List<T>::print() const
{
  Node* currNode = head;

  while (currNode != nullptr) {
    currNode->data->print();
    currNode = currNode->next;
  }
}





#endif


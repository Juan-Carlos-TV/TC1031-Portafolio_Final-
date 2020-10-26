#ifndef Node_h
#define Node_h

#include <iostream>
using namespace std;

//Estructura Bitacora
struct Bitacora{
    string mes;
    int dia;
    long long IpKey;
    string hora;
    string IP;
    string concepto;
};

class Node{
  public:
    Node(Bitacora data);
    Node(Bitacora data, Node *next, Node *prev);
    Bitacora getData();
    Node* getNext();
    Node* getPrev();
    void setData(Bitacora data);
    void setNext(Node *next);
    void setPrev(Node *prev);
    
  private:
    Bitacora data;
    Node *next;
    Node *prev;
};

//Constructor
//Complejidad: O(1)
Node::Node(Bitacora data){
  this->data = data;
  this->next = nullptr;
  this->prev = nullptr;
}

//Constructor
//Complejidad: O(1)
Node::Node(Bitacora data, Node *next, Node*prev){
  this->data = data;
  this->next = next;
  this->prev = prev;
}

//Complejidad: O(1)
Bitacora Node::getData(){
  return data;
}

//Complejidad: O(1)
Node* Node::getNext(){
  return next;
}

//Complejidad: O(1)
Node* Node::getPrev(){
  return prev;
}

//Complejidad: O(1)
void Node::setData(Bitacora data){
  this-> data = data;
}

//Complejidad: O(1)
void Node::setNext(Node *next){
  this-> next = next;
}

//Complejidad: O(1)
void Node::setPrev(Node *prev){
  this-> prev = prev;
}


#endif
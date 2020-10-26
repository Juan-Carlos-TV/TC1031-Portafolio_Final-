#ifndef BST_h
#define BST_h

#include <iostream>

using namespace std;

#include "NodeT.h"
#include <queue>

class BST{
    public:
        BST();
        ~BST();
        void add(Bitacora data);
        void printAcc();

    private:
        NodeT *root;
        void destruye(NodeT *r);
        void reverseInOrden(NodeT *r, queue<Bitacora> &datos);
};

BST::BST(){
    root = nullptr;
}

//Nombre: destruye
//Descripción: borra/destruye los datos a partir de un nodo dado
//Entrada: un Nodo de árbol
//Salida: ninguna
//Complejidad: O(n)
void BST::destruye(NodeT *r){
    if (r != nullptr){
        destruye(r->getLeft());
        destruye(r->getRight());
        delete r;
    }
}

BST::~BST(){
    destruye(root);
}

//Nombre: add
//Descripción: agrega un nuevo nodo en el árbol por número de accesos. Si hay 2 con accesos iguales
//  ordena en base a la IP
//Entrada: un dato Bitacora que se desee agrega al arbol
//Salida: ninguna
//Complejidad: O(n)
void BST::add(Bitacora data){
    NodeT *curr = root;
    NodeT *father = nullptr;

    while (curr != nullptr){
        if (curr->getData().accesos == data.accesos){
            father = curr;
            curr = (curr->getData().IpKey < data.IpKey) ?  curr->getLeft() : curr->getRight(); 
        }
        else {
            father = curr;
            curr = (curr->getData().accesos > data.accesos) ? curr->getLeft() : curr ->getRight() ; 
        }
    }

    if (father == nullptr){
        root = new NodeT(data);
    }
    else{
        if (father->getData().accesos == data.accesos){
            (father->getData().IpKey < data.IpKey) ? father->setLeft(new NodeT(data)) : father->setRight(new NodeT(data));
        }
        else{
            (father->getData().accesos > data.accesos) ? father->setLeft(new NodeT(data)) : father->setRight(new NodeT(data));
        }
    }
}

//Nombre: reverseInOrden
//Descripción: hace un recorrido inorder reverso que guarda en una queue los registros de la bitacora 
//  A partir de un nodo dado 
//Entrada: El nodo del cual se va a empezar, la queue para almacenar por referencia
//Salida: ninguna
//Complejidad: O(n)
void BST::reverseInOrden(NodeT *r, queue<Bitacora> &datos){
  if (r != nullptr){
    reverseInOrden(r->getRight(), datos);
    datos.push(r->getData());
    reverseInOrden(r->getLeft(), datos);
  }
}

//Nombre: printAcc
//Descripción: imprime las 5 iP con más accesos 
//Entrada: ninguna
//Salida: ninguna
//Complejidad: O(n)
void BST::printAcc(){  
  queue<Bitacora> datos;
  reverseInOrden(root, datos); //Se guardan los registros desde el root en inorder reverso
  for (int i=1; i<=5; i++){    //Recorre los primeros 5 registros
    cout << "IP: " << datos.front().IP << " ";
    cout << "Accesos: " << datos.front().accesos << endl;
    datos.pop();
  }
}

#endif
#ifndef DoubleLinkedL_h
#define DoubleLinkedL_h

#include <iostream>
using namespace std;

#include "Node.h"
#include <fstream>


class DoubleLinkedL{
  public:
    DoubleLinkedL();
    ~DoubleLinkedL();
    void addFirst(Bitacora data);
    void addLast(Bitacora data);
    void add(Bitacora data, int pos);
    int getSize();
    Bitacora getDato(int pos);
    void setDato(Bitacora data, int pos);
    int searchMen(long long key);
    int searchMay(long long key);
    Bitacora getFirst();
    Bitacora getLast();
    void ordenaBurbuja();
    void print();
    void printLast();
    void printFirst();
    void printPos(int pos1, int pos2);
    void archivoSalida(string fileName);
    
    
  private:
    Node *head;
    Node *tail;
    int size;
};

//Constructor
//Complejidad: O(1)
DoubleLinkedL::DoubleLinkedL(){
    head = nullptr;
    tail = nullptr;
    size = 0;
}

//Destructor
//Complejidad: O(n)
DoubleLinkedL::~DoubleLinkedL(){
    Node *curr = head;
    while(head != nullptr){
        head = head->getNext();
        delete curr;
        curr = head;
    }
    size = 0;

}

//Nombre: addFirst
//Decripción: añade un nuevo registro al principio de la Lista
//Entrada: una estructura bitacora
//Salida: ninguna
//Complejidad: O(1)
void DoubleLinkedL::addFirst(Bitacora data){
    if (size == 0){
        head = new Node(data,tail,nullptr);
        tail = head;
    }
    else{
        head = new Node(data,head,nullptr);
        head->getNext()->setPrev(head);
    }
    size++;
}

//Nombre: addLast
//Descipción: añade un nuevo registro al final de la lista
//Entrada: una estructura bitacora
//Salida: ninguna
//Complejidad: O(1)
void DoubleLinkedL::addLast(Bitacora data){
    if(size == 0){
        addFirst(data);
    }
    else{
        tail->setNext(new Node(data,nullptr,tail));
        tail = tail->getNext();
        size++;
    }
}

//Nombre: add
//Descripción: añade un nuevo registro a la lista en una posición dada
//Entrada: una estructura bitacora y una posición
//Salida: ninguna
//Precondición: que sea una posicón válida
//Complejidad: O(n)
void DoubleLinkedL::add(Bitacora data,int pos){
    if (pos == 0){
        addFirst(data);
    }
    else if (pos == size-1){
        addLast(data);
    }
    else{
        Node *curr = head;
        for(int i=1; i<pos; i++){
            curr = curr->getNext();
        }
        curr->setNext(new Node(data,curr->getNext(),curr));
    }
    size++;
}

//Nombre: setDato
//Descripción: cambia el registro dentro de la lista dada una posición
//Entrada: una estructura bitacora y una posición
//Salida: ninguna
//Precondición: que se ingrese una posición válidad
//Complejidad: O(n)
void DoubleLinkedL::setDato(Bitacora data, int pos){
    if (pos == 0){
        head->setData(data);
    }
    else if(pos == size-1){
        tail->setData(data);
    }
    else{
        Node *curr = head;
        for (int i=1; i<=pos; i++){
            curr = curr->getNext();
        }
        curr->setData(data);
    }
}

//Nombre: getSize
//Descripción: retorna el valor del tamaño de la lista
//Entrada: ninguna
//Salida: el tamaño de la lista
//Complejidad: O(1)
int DoubleLinkedL::getSize(){
    return size;
}

//Nombre: getFirst
//Descripción: retorna el primer registro en la lista
//Entrada: ninguna
//Salida: El primer dato de tipo bitacora en la lista
//Precondición: que la lista contenga ya un valor
//Complejidad: O(1)
Bitacora DoubleLinkedL::getFirst(){
    return head->getData();
}

//Nombre: getLast
//Descripción: retorna el último registro en la lista
//Entrada: ninguna
//Salida: El último dato de tipo bitacora en la lista
//Precondición: que la lista contenga ya un valor
//Complejidad: O(1)
Bitacora DoubleLinkedL::getLast(){
    return tail->getData();
}

//Nombre: getDato
//Descripción: retorna un registro cualquiera de la lista dada una posición
//Entrada: ninguna
//Salida: El dato en determinada posición
//Precondición: que la lista tenga ya un dato, que se trate de una posición válida
//Complejidad: O(n)
Bitacora DoubleLinkedL::getDato(int pos){
    if (pos == 0){
        getFirst();
    }
    else if(pos == size-1){
        getLast();
    }
    else{
        Node *curr = head;
        for (int i=0; i<=pos; i++){
            curr = curr->getNext();
        }
        return curr->getData();
    }   
}

//Nombre: ordenaBurbuja
//Descripción: ordena el contenido de la lista en base a las ip por el método burbuja
//Entrada: ninguna
//Salida: ninguna
//Precondición: que la lista tenga varios registros
//Complejidad: mejor caso O(n)....peor O(n^2)
void DoubleLinkedL::ordenaBurbuja(){
    bool interruptor = true;
    Bitacora aux;

    for (int i=0; i<size-1 && interruptor; i++){
        interruptor = false;
        Node *curr = head;
        for (int j=0; j<size-1-i; j++){
            if ((curr->getNext()->getData().IpKey) < curr->getData().IpKey){ //Compara la IpKey del Nodo actual y el siguiente
                aux = curr->getNext()->getData();                    
                curr->getNext()->setData(curr->getData());      //Si el dato siguiente es mayor se intercambian los registros
                curr->setData(aux);
                interruptor = true;
                
            }
            curr = curr->getNext();
        }
    }
}

//Nombre: searchMen
//Descripción: encuentra el primer registro dentro de la lista con una key igual o la más cercana a la dada
//Entrada: la key a ser buscada
//Salida: la posición del registro con la key dada o la más cercana a este
//Precondición: que la lista ya esté ordenada
//Complejidad: O(n)
int DoubleLinkedL::searchMen(long long key){
    int pos = 0;
    Node *curr = head;
    if (key <= head->getData().IpKey){
        return 0;
    }
    curr = curr->getNext();
    pos++;
    while (curr != nullptr){
        if ((curr->getData().IpKey >= key)){
            return pos;
        }
        pos++;
        curr = curr->getNext();
    }

    return pos;
}

//Nombre: searchMay
//Descripción: encuentra el último registro dentro de la lista con una key igual o la más cercana a la dada
//Entrada: la key a ser buscada
//Salida: la última posición con la key dada o la más cercana este
//Precondición: que la lista ya esté ordenada
//Complejidad: O(n)
int DoubleLinkedL::searchMay(long long key){
    int pos = 0;
    Node *curr = head;
    if (key <= head->getData().IpKey){
        return 0;
    }
    else if (key >= tail->getData().IpKey){
        return size-1;
    }
    else{
        while (curr != nullptr){
        if ((curr->getData().IpKey <= key) && (key < curr->getNext()->getData().IpKey)){
            return pos;
        }
        pos++;
        curr = curr->getNext();
        }
    }
    return pos;
}

//Nombre: printFirst
//Descripción: imprime el primer registro de la lista
//Entrada: ninguna
//Salida: ninguna
//Precondición: que la lista contenga registros
//Complejidad: O(1)
void DoubleLinkedL::printFirst(){
    cout << "No. " << 0 << endl;
    cout << "IP: " << head->getData().IP << endl;
    cout << "Mes: " << head->getData().mes << endl;
    cout << "Dia: " << head->getData().dia << endl;
    cout << "Hora: " << head->getData().hora << endl;
    cout << "Concepto: " << head->getData().concepto << endl;
    cout << endl;    
}

//Nombre: printLast
//Descripción: imprime el último registro de la lista
//Entrada: ninguna
//Salida: ninguna 
//Precondición: que la lista contenga registros
//Complejidad: O(1)
void DoubleLinkedL::printLast(){
    cout << "No. " << size-1 << endl;
    cout << "IP: " << tail->getData().IP << endl;
    cout << "Mes: " << tail->getData().mes << endl;
    cout << "Dia: " << tail->getData().dia << endl;
    cout << "Hora: " << tail->getData().hora << endl;
    cout << "Concepto: " << tail->getData().concepto << endl;
    cout << endl;
}

//Nombre: print
//Descripción: imprime todos los registros dentro de la lista
//Entrada: ninguna
//Salida: ninguna
//Precondición: que la lista contenga registros
//Complejidad: O(1)
void DoubleLinkedL::print(){
    Node *curr = head;
    int i=0;
    while(curr != nullptr){ //Cicla hasta que curr sea null
        cout << "No. " << i << endl;
        cout << "IP: " << curr->getData().IP << endl;
        cout << "Mes: " << curr->getData().mes << endl;
        cout << "Dia: " << curr->getData().dia << endl;
        cout << "Hora: " << curr->getData().hora << endl;
        cout << "Concepto: " << curr->getData().concepto << endl;
        cout << endl;
        i++;
        curr = curr->getNext();
    }
}

//Nombre: printPos
//Descripción: imprimir los registros desde la posición uno a la posición dos
//Entrada: 2 posiciones
//Salida: ninguna
//Precondición: que las posiciones sean válidas y posición uno sea menor a la 2
//Complejidad: O(n) 
void DoubleLinkedL::printPos(int pos1, int pos2){
    Node *curr = head;
    for (int i=0; i<pos1; i++){
        curr = curr->getNext(); //Curr llega hasta posición 1
    }

    for(int i=pos1; i<=pos2; i++){ //Se imprime desde la posición 1 a posición 2
        if(i != size-1){
            cout << "No. " << i << endl;
            cout << "IP: " << curr->getData().IP << endl;
            cout << "Mes: " << curr->getData().mes << endl;
            cout << "Dia: " << curr->getData().dia << endl;
            cout << "Hora: " << curr->getData().hora << endl;
            cout << "Concepto: " << curr->getData().concepto << endl;
            cout << "IPkey: " << curr->getData().IpKey << endl;
            cout << endl;
            curr = curr->getNext();
        }
        else{
            printLast();
        }
    }
}

//Nombre: archivoSalida
//Descripción: genera un archivo de salida con el contenido de la lista 
//Entrada: el nombre del archivo que se creará/sobrescribirá
//Salida: ninguna
//Complejidad: O(n)
void DoubleLinkedL::archivoSalida(string fileName){
    //Escritura del archivo
    ofstream archivo2;
    archivo2.open(fileName,ios::out); //Se crea el archivo. Si ya existe, lo reemplaza

    if (archivo2.fail()){ //En caso de error al crear el archivo
       cout << "No se pudo abrir el archivo" << endl;
       archivo2.close();
    }
    else{
        Node *curr = head;
        while(curr != nullptr){ //Cicla hasta que curr sea null
            archivo2 << curr->getData().mes << " ";
            archivo2 << curr->getData().dia << " ";
            archivo2 << curr->getData().hora << " ";
            archivo2 << curr->getData().IP << " ";
            archivo2 << curr->getData().concepto << endl;
            curr = curr->getNext();
        }
    }
    archivo2.close();
}


#endif
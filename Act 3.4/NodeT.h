#ifndef NodeT_h
#define NodeT_h

struct Bitacora{
    long long IpKey;
    string IP;
    int accesos;
};

class NodeT{
    public:
        NodeT(Bitacora data);
        NodeT(Bitacora data, NodeT *left, NodeT *right);
        Bitacora getData();
        void setData(Bitacora data);
        NodeT* getLeft();
        void setLeft(NodeT *left);
        NodeT* getRight();
        void setRight(NodeT *right);

    private:
        Bitacora data;
        NodeT *left;
        NodeT *right;
};

NodeT::NodeT(Bitacora data){
    this->data = data;
    this->right = nullptr;
    this->left = nullptr;
}

NodeT::NodeT(Bitacora data, NodeT *left, NodeT *right){
    this->data = data;
    this->left = left;
    this->right = right;
}

Bitacora NodeT::getData(){
    return data;
}

void NodeT::setData(Bitacora data){
    this->data = data;
}

NodeT* NodeT::getLeft(){
    return left;
}

void NodeT::setLeft(NodeT *left){
    this->left = left;
}

NodeT* NodeT::getRight(){
    return right;
}

void NodeT::setRight(NodeT *right){
    this->right = right;
}

#endif
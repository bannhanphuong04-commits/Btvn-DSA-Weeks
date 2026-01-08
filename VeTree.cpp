#include <iostream>
using namespace std;

struct Node {
    int data;       
    Node* left;     
    Node* right;  
};

Node* makeNode(int x) {
    Node* p = new Node;
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void duyetTruoc(Node* t) {
    if (t != NULL) {
        cout << t->data << " "; 
        duyetTruoc(t->left);    
        duyetTruoc(t->right);   
    }
}
void duyetGiua(Node* t) {
    if (t != NULL) {
        duyetGiua(t->left);     
        cout << t->data << " "; 
        duyetGiua(t->right);    
    }
}
void duyetSau(Node* t) {
    if (t != NULL) {
        duyetSau(t->left);      
        duyetSau(t->right);     
        cout << t->data << " "; 
    }
}
bool kiemTraGiongNhau(Node* cay1, Node* cay2) {
  
    if (cay1 == NULL && cay2 == NULL) return true;

    if (cay1 == NULL || cay2 == NULL) return false;

    if (cay1->data != cay2->data) return false;

    return kiemTraGiongNhau(cay1->left, cay2->left) &&
        kiemTraGiongNhau(cay1->right, cay2->right);
}

int main() {
    
    Node* n1 = makeNode(4);  
    Node* n2 = makeNode(1); 
    Node* n3 = makeNode(3);  
    Node* n4 = makeNode(2);  
    Node* n5 = makeNode(16); 
    Node* n6 = makeNode(9); 
    Node* n7 = makeNode(10); 
    Node* n8 = makeNode(14); 
    Node* n9 = makeNode(8);  
    Node* n10 = makeNode(7); 

    n1->left = n2; n1->right = n3;      
    n2->left = n4; n2->right = n5;      
    n3->left = n6; n3->right = n7;      
    n4->left = n8; n4->right = n9;     
    n5->left = n10;                    

    cout << "Duyet Truoc (NLR): ";
    duyetTruoc(n1);
    cout << "\n";

    cout << "Duyet Giua (LNR):  ";
    duyetGiua(n1);
    cout << "\n";

    cout << "Duyet Sau (LRN):   ";
    duyetSau(n1);
    cout << "\n";

    return 0;
}
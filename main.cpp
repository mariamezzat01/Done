#include <iostream>
#include "my_tree.h"

using namespace std;

struct Node
{
    int info;
    Node* left;
    Node* right;
};

int main(int argc, char** argv){

    int size,operations,k,n;
    cin>>size>>operations;

    MyTree<int> T;
    for (int i = 1; i <= size; ++i) {
        cin>>k;
        T.insert(k);
    }

    for (int i = 0; i < operations; ++i) {
        cin>>k;
        if(k==1) {
            cin>>n; T.insert(n);
        }

        if(k==2){
            cin>>n;
            if(T.search(n)) cout<<"Element found";
            else cout<<"Element not found";
        }

        if(k==3){
            cin>>n;
            if(n==1) T.inorder_rec(T.root);
            if(n==2) T.inorder_it();
        }

        if(k==4){
            cin>>n;
            if(n==1) T.preorder_rec(T.root);
            if(n==2) T.preorder_it();
        }

        if(k==5){
            cin>>n;
            if(n==1) T.postorder_rec(T.root);
            if(n==2) T.postorder_it();
        }

        if(k==6){
            T.breadth_traversal();
        }

        if(k==7){
            cout<<T.size;

        }
    }
}
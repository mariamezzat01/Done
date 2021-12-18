#ifndef MARIAM_EZZAT_MY_TREE_H
#define MARIAM_EZZAT_MY_TREE_H
#include <iostream>
#include <cassert>
#include <vector>
#include <stack>
#include "queue"
using namespace std;
template <class T>
class MyTree {

private:

    struct node {
        T item;
        node* left;
        node* right;
    };



public:
    node* root;
    int size;

    MyTree() {
        root = NULL;
        size = NULL;
    }

    MyTree(vector<T> elements) {
    }

    bool search(T key) {
        node* p = root;
        if (p == NULL) return false;

        while (p != NULL) {
            if (key == p->item)
                return true;
            if (key > p->item) {
                p = p->right;
            }
            else
                p = p->left;
        }
        return false;
    }

    void insert(T item) {
        node* current;
        node* trailCurrent;
        node* newNode;

        newNode= new node;
        assert(newNode != NULL);
        newNode->item = item;
        newNode->right = NULL;
        newNode->left = NULL;

        if(root == NULL) {
            root = newNode;
            size++;
        }
        else{

            current=root;
            while(current != NULL){
                trailCurrent=current;

                if(item > current->item){
                    current = current->right;
                }
                else current = current->left;
            }
            if(item > trailCurrent->item) {
                trailCurrent->right = newNode;
                size++;
            }
            else {
                trailCurrent->left = newNode;
                size++;
            }
        }
        }

    void inorder_rec(node* p) {
        if (p != NULL)
        {
            inorder_rec(p->left);
            cout << p->item << " ";
            inorder_rec(p->right);
        }
    }

    void preorder_rec(node* p) {
        if (p != NULL)
        {
            cout << p->item << " ";
            preorder_rec(p->left);
            preorder_rec(p->right);
        }
    }

    void postorder_rec(node* p) {
        if (p != NULL)
        {
            postorder_rec(p->left);
            postorder_rec(p->right);
            cout << p->item << " ";
        }
    }

    void inorder_it() {
        stack<node*> s;
        node* curr = root;

        while (curr != NULL || s.empty() == false)
        {
            while (curr != NULL)
            {
                s.push(curr);
                curr = curr->left;
            }

            curr = s.top();
            s.pop();

            cout << curr->item << " ";
            curr = curr->right;

        }
    }

    void preorder_it()
        {
            node* p = root;
            if (p == NULL)
                return;

            stack<node*> nodeStack;
            nodeStack.push(p);

            while (nodeStack.empty() == false) {
                struct node* node = nodeStack.top();
                cout << node->item << " ";
                nodeStack.pop();


                if (node->right)
                    nodeStack.push(node->right);
                if (node->left)
                    nodeStack.push(node->left);
            }
        }

        void postorder_it() {
            node* p = root;
            if (p == NULL)
                return;
            stack<node*> s1, s2;

            s1.push(root);
            node* node;

            while (!s1.empty()) {

                node = s1.top();
                s1.pop();
                s2.push(node);

                if (node->left)
                    s1.push(node->left);
                if (node->right)
                    s1.push(node->right);
            }

            while (!s2.empty()) {
                node = s2.top();
                s2.pop();
                cout << node->item << " ";
            }


        }

        void breadth_traversal( ) {
            node* p = root;
            if (p == NULL)
                return;
            queue<node*> q;
            q.push(p);
            while (q.empty() == false) {
                node* temp = q.front();
                cout << temp->item << " ";
                q.pop();

                if (temp->left != NULL)
                    q.push(temp->left);

                if (temp->right != NULL)
                    q.push(temp->right);
            }

        }

        int Size() {
            node* p = root;
            if (p == NULL)
                return 0;
            return 1 + size(p->left) + size(p->right);
        }
    };


#endif //MARIAM_EZZAT_MY_TREE_H

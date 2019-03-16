
#include "Tree.hpp"
#include <stdexcept>
#include <iostream>

using namespace std;
using namespace ariel;



Node::Node(int data){
  this->_data = data;
  this->left = NULL;
  this->right = NULL;
}

int Node::getData(){
  return _data;
}


Tree::Tree(){
  _root = NULL;
  _size = 0;
}

Tree& Tree::insert(int n){
  if(contains(n)){
    throw invalid_argument("already in");
  }
   if(_size==0){
     _root = new Node(n);
     _size++;
   }else{
   Node* newNode = new Node(n);
   Node* curr = _root;

     while(true){
     if((*newNode).getData()<(*curr).getData()){
       if(curr->left == NULL){
         curr->left = newNode;
         _size++;
         break;
       }else{
         curr = curr->left;
       }
     }else{
       if(curr->right == NULL){
         curr->right = newNode;
         _size++;
         break;
       }else{
         curr = curr->right;
       }
     }
   }
 }
 return *this;
}


void Tree::remove(int i){
  if(contains(i)){
    _size--;
    cout << "in contains" << endl;
    Node* toRemove = find(i);
    if(parent(i)==NULL){
      _root = NULL;
      delete _root;
      return;
    }
    Node* parentof = find(parent(i));
    if(toRemove->left == NULL && toRemove->right == NULL){
      cout << "no chils" << endl;
      if(parentof->left->getData() == toRemove->getData()){
        cout << "left child" << endl;
        parentof->left = NULL;
      }else{
        parentof->right = NULL;
      }
    }else if(toRemove->left != NULL && toRemove->right == NULL){
      if(parentof->left->getData() == i){
        parentof->left = toRemove->left;
      }else{
        parentof->right = NULL;
      }
    }else if(toRemove->left == NULL && toRemove->right != NULL){
      if(parentof->left->getData() == i){
        parentof->left = toRemove->right;
      }else{
        parentof->right = toRemove->right;
      }

    }
    else{
      if(parentof->left->getData() == i){
          Node* toMove = toRemove->right->left;
          toRemove->right->left = toRemove->left;
          Node* addTo = toRemove->left;
          while(addTo->right != NULL){
            addTo = addTo->right;
          }
          addTo->right = toMove;
          parentof->left = toRemove->right;
        }else{
          Node* toMove = toRemove->left->right;
          toRemove->left->right = toRemove->right;
          Node* addTo = toRemove->right;
          while(addTo->left != NULL){
            addTo = addTo->left;
          }
          addTo->left = toMove;
          parentof->right = toRemove->left;
        }
    }
      free(toRemove);
  }else{
    throw invalid_argument("has have this number");
  }

}
int Tree::size(){
  return _size;
}
bool Tree::contains(int i){
  Node* isIn = find(i);
  if(isIn == NULL){
    return false;
  }
  return true;
}
int Tree::root(){
  if(_size>0){
    return _root->getData();
  }else{
    throw invalid_argument("no root has been init..");
  }
}
int Tree::parent(int i){
  if(!contains(i) || find(i) == _root){
    if(find(i) != _root){
      return NULL;
    }
    throw invalid_argument("non contains or has no parent");
  }else{
    Node* par = _root;
    Node* curr = find(i);
    while(par->right->getData() != curr->getData() && par->left->getData() != curr->getData()){
      if(i<par->getData()){
        par = par->left;
      }else{
        par = par->right;
      }
    }
    return par->getData();
  }
}
int Tree::left(int i){
  Node* locate = find(i);
  return locate->left->getData();
}
int Tree::right(int i){
  Node* locate = find(i);
  return locate->right->getData();
}

void Tree::print(){
  printRecursive(_root);
}

void Tree::printRecursive(Node* curr){
  if(curr==NULL){
    return;
  }
  printRecursive(curr->left);
  cout << curr->getData() << " ";
  printRecursive(curr->right);
}

int Tree::getSize(){
  return _size;
}

Node* Tree::find(int i){
  if(getSize() > 0 ){
  return find(_root,i);
  }else{
  cout << "an empty tree" << endl;
  return NULL;
  }
}

Node* Tree::find(Node* curr,int i){
  if(curr == NULL){
      return NULL;
  }
  if(curr->getData()==i){
      return curr;
  }else if(i<curr->getData()){
    return find(curr->left,i);
  }else{
    return find(curr->right,i);
  }
}

Node& Tree::getRoot(){
  Node* node = this->_root;
  return *node;
}

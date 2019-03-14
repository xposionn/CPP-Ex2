#include <iostream>

#pragma one


class Node{
public:
  int data;
  Node* left;
  Node* right;

  Node(){
  }
  Node(int n){
    data = n;
  }
};


class Tree{
public:
    Node* _root;
    int _size;

public:
  Tree(){
    _size = 0;
  }
  int size(){
    return _size;
  }



  int root(){
    return _root->data;
  }

  int print(){
    return 1;
  }

  void insert(int n){
    if(_size==0){
      _root = new Node(n);
      _size++;
    }else{
    Node* newNode = new Node(n);
    Node* curr = _root;

      while(true){
      if(newNode->data<curr->data){
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
      }

      int left(int i){
        return i;
      }

    int right(int i){
      return i;
    }

    int parent(int i){
      return i;
    }

  private:
    Node* find(Node* node,int data){
      if()
      Node* curr = node;
      if(curr->data == data){
        return curr;
      }else{
        if(data<curr->data){
          find(curr->left,data);
        }else{
          find(curr->right,data);
        }
      }
      }


      return curr;

    }

};

#include<iostream>
using namespace std;
template <class T>
struct BiNode{
  T data;
  BiNode* left;
  BiNode* right;
};
template<class T>
class BiTree{
private:
  void Create(BiNode<T>*&r,T data[],int i,int n);
  void Release(BiNode<T> *r);
public:
  BiNode<T>* root;
  BiTree(T data[],int n);
  // ~BiTree();
  void PreOrder(BiNode<T> *r);
  void InOrder(BiNode<T> *r);
  void PostOrder(BiNode<T> *r);
  void LevelOrder(BiNode<T> *r);
};
template<class T>
void BiTree<T>::Create(BiNode<T>* &r,T data[],int i,int n){
  if(i<n && data[i-1]){
    r=new BiNode<T>;
    r->data=data[i-1];
    Create(r,data,2*i,n);
    Create(r,data,2*i+1,n);
  }
  else{
    r=nullptr;
  }
}
template <class T>
BiTree<T>::BiTree(T data[],int n){
  Create(root,data,1,n);
}
template<class T>
void BiTree<T>::PreOrder(BiNode<T> *r){
  if(r!=nullptr){
    cout<<r->data;
    PreOrder(r->left);
    PreOrder(r->right);
  }
}
int main(int argc, char const *argv[]) {
  int data[11]={1,2,3,4,5,6,7,0,9,0,10};
  BiTree<int> btree(data,11);
  btree.PreOrder(btree.root);
  return 0;
}

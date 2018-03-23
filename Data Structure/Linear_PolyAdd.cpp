#include<iostream>
using namespace std;
template <class T>
struct Node{
  T data;
  Node<T> * next;
};
template <class T>
class Linklist{
private:
  Node<T>* front;
public:
  Linklist(){front=new Node<T>;front->next=NULL;};
  Linklist(T a[],int n);
  void Insert(T a,int i);
  void Delete(int i);
  Node<T>* Get(int i);
  void PrintList();
};
template<class T>
Linklist<T>::Linklist(T a[],int n){
  front=new Node<T>;
  Node<T>*p=front;
  for(int i=0;i<n;i++){

  }
}

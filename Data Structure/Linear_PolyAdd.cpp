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
  ~Linklist();
  void Insert(T a,int i);
  T Delete(int i);
  Node<T>* Get(int i);
  void PrintList();
};
template<class T>
Linklist<T>::Linklist(T a[],int n){
  front=new Node<T>;
  Node<T>*p=front;
  for(int i=0;i<n;i++){
    Node<T>* s=new Node<T>;
    s->data=a[i];
    p->next=s;
    p=s;
  }
  p->next=NULL;
}
template<class T>
void Linklist<T>::PrintList(){
  Node<T>*p=front;
  cout<<"Linklist contains:"<<endl;
  while (p) {
    cout<<p->data<<"   ";
    p=p->next;
  }
  cout<<endl;
}
template<class T>
Node<T>* Linklist<T>::Get(int i){
  if (i<0)throw "index invalid";
  Node<T>*p=front;
  // for(int j=0;j<i;j++){
  //   p=p->next;
  // }
  int j=0;
  while (p & j!=i) {
    p=p->next;
    j++;
    // if (i==j)return p;
  }
  return p;
}
template<class T>
Linklist<T>::~Linklist(){
  Node<T>*p=front;
  while (p) {
    front=p;
    p=p->next;
    delete front;
  }
}
template<class T>
void Linklist<T>::Insert(T a,int i){
  if(i>0){
    Node<T>*p=Get(i-1);
    if(p){
      Node<T>*s=new Node<T>;
      s->data=a;
      s->next=p->next;
      p-next=s;
    }
    else{
      throw"index invalid";
    }
  }
}
template<class T>
T Linklist<T>::Delete(int i){
  if (i>0) {
    Node<T>*p=Get(i-1);
    Node<T>*q=Get(i);

    if (p&&q){
      T tmp=q->data;
      p->next=q->next;
      delete q;
      return  tmp;
    }
  }
  return NULL;
}
int main(int argc, char const *argv[]) {
  int a[10]={1,2,3,4,5,6,7,8,9,0};
  Linklist<int> llist(a,100);
  cout<<"list construction complete."<<endl;
  llist.PrintList();
  system("pause");
  return 0;
}

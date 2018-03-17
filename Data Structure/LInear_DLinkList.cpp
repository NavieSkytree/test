#include<iostream>
using namespace std;

template<class T>
struct Node{
  T data;
  Node<T> *prior;
  Node<T> *next;
};
template<class T>
class DLinkList{
public:
  DLinkList(){front=new Node<T>;front->next=front;front->prior=front;}
  DLinkList(T a[],int n);
  ~DLinkList();
  void PrintList();
  void Insert(int i,T x);
  T Delete(int i);
private:
  Node<T>*front;
};
template<class T>
void DLinkList<T>::Insert(int i,T x){
  Node<T>*p=front->next;
  for (int j = 1; j <i-1 ; j++) p=p->next;
  Node<T>*s=new Node<T>;
  Node<T>*q=p->next;
  s->data=x;
  s->next=q;
  q->prior=s;
  p->next=s;
  s->prior=p;
}
template <class T>
T DLinkList<T>::Delete(int i){
  Node<T>*p=front->next;
  for (int j = 1; j < i-1; j++) p=p->next;
  Node<T>*q=p->next;
  p->next=q->next;
  q->next->prior=p;
  T tmp=q->data;
  delete q;
  return tmp;
}
template<class T>
DLinkList<T>::DLinkList(T a[],int n){
  front=new Node<T>;
  Node<T> * p=front;
  for (int i = 0; i < n; i++) {
    Node<T>*s=new Node<T>;
    s->data=a[i];
    p->next=s;
    s->prior=p;
    p=s;
  }
  p->next=front;
  front->prior=p;
}
template<class T>
DLinkList<T>::~DLinkList(){
  Node<T>*p=front->next;
  Node<T>*s=p;
  while (p!=front) {
    s=p;
    p=p->next;
    delete s;
  }
}
template<class T>
void DLinkList<T>::PrintList(){
  // Node<T> *rear=front->prior;
  Node<T>*p=front->next;
  std::cout << "DLinkList contains:" << '\n';
  while(p!=front){
    std::cout << p->data << "   ";
    p=p->next;
  }
}
int main(int argc, char const *argv[]) {
  DLinkList<int> ccl_empty();
  int a[10]={1,2,3,4,5,6,7,8,9,0};
  DLinkList<int> ccl(a,10);
  ccl.PrintList();
  std::cout  << '\n';
  ccl.Insert(2,100);
  std::cout  << '\n';
  ccl.PrintList();
  cout<<ccl.Delete(2)<<endl;
  ccl.PrintList();

  system("pause");
  return 0;
}

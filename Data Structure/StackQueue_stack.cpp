#include<iostream>
using namespace std;
const int MAXSIZE=100;
template<class T>
class SeqStack{
private:
  int top;
  T SeqSta[MAXSIZE];
public:
  SeqStack(){top=-1;}
  void Push(T x);
  T Pop();
  bool Empty(){return (-1==top)?true:false;}
  T GetTop();
  void Print(){
    int p=top;
    cout<<"Stack contains";
    while (p>=0) {
      cout<<SeqSta[p]<<"   ";
      p--;
    }
    cout<<endl;
  }
};
template<class T>
void SeqStack<T>::Push(T x){
  if(top>=MAXSIZE-1)throw "position overflow";
  top++;
  SeqSta[top]=x;
}
template<class T>
T SeqStack<T>::Pop(){
  if(Empty())throw "position underflow";
  T tmp=SeqSta[top];
  top--;
  return tmp;
}
template<class T>
T SeqStack<T>::GetTop(){
  if(Empty())throw"position ubderflow";
  return SeqSta[top];
}


template<class T>
struct Node{
  T data;
  Node<T> * next;
};
template<class T>
class LinkStack{
private:
  Node<T>* top;
  // Node<T>* front;
public:
  LinkStack(){
    top=new Node<T>;
    top->next=NULL;
  }
  void Push(T x){
    Node<T>*p=new Node<T>;
    p->data=x;
    p->next=top->next;
    top->next=p;
  }
  T Pop(){
    if (Empty()) throw "index underflow";
    Node<T>* p=top->next;
    T tmp=p->data;
    top=p->next;
    delete p;
    return tmp;
  }
  bool Empty(){
    return top->next?false:true;
  };
  T GetTop(){
    if (Empty())throw "index underflow";
    return top->next->data;
  }
  void PrintStack() {
    Node<T>*p=top->next;
    cout<<"Stack contains:";
    while (p) {
      cout<<p->data<<"  ";
    }
    cout<<endl;
  }
};
int main(int argc, char const *argv[]) {
  // SeqStack<int> sstack;
  // sstack.Push(2);
  // sstack.Push(1);
  // sstack.Push(1);
  // sstack.Push(4);
  // sstack.Print();
  // sstack.Pop();
  // sstack.Print();
  // cout<<sstack.GetTop();


  LinkStack<int> stack;
  stack.Push(2);
  stack.Push(1);
  stack.Push(1);
  stack.Push(4);
  stack.PrintStack();
  stack.Pop();
  stack.PrintStack();
  cout<<stack.GetTop();
  system("pause");
  return 0;
}

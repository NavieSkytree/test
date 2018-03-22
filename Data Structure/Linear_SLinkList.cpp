#include<iostream>
using namespace std;
const int MAXSIZE=100;
template<class T>
struct StaticNode{
  T data;
  int next;
};
template<class T>
class SLinkList{
public:
  SLinkList();
  SLinkList(T a[],int n);
  void Insert(int i,T a);
  T Delete(int i);
  int Get(int i);
  int Locate(T x);
  int NewNode();
  T DeleteNode(int i);
  void PrintList();
private:
  int front;
  int tail;
  StaticNode<T> SArray[MAXSIZE];
};

template<class T>
SLinkList<T>::SLinkList(){
  front=-1;
  for(int i=0;i<MAXSIZE-1;i++){
    SArray[i].next=i+1;
  }
  SArray[MAXSIZE-1]=-1;
  tail=0;
}

template<class T>
SLinkList<T>::SLinkList(T a[],int n){
  for(int i=0;i<MAXSIZE-1;i++){
    SArray[i].next=i+1;
  }
  SArray[MAXSIZE-1].next=-1;
  front=0;
  for(int i=0;i<n;i++){
    SArray[i].data=a[i];
  }
  tail=SArray[n-1].next;
  SArray[n-1].next=-1;
}

template<class T>
void SLinkList<T>::PrintList(){
    if(front==-1)return;
    int p=front;
    cout<<"SLinkList contains:"<<endl;
    while (SArray[p].next!=-1){
      cout<<SArray[p].data<<"  ";
      p=SArray[p].next;
    }
    cout<<SArray[p].data;
}

// void Insert(int i,T a);
// T Delete(int i);
// int Get(int i);
// int Locate(T x);
// int NewNode();
// void DeleteNode(int i);
template<class T>
int SLinkList<T>::NewNode(){
    if(tail==-1)return tail;
    int pos=tail;
    tail=SArray[tail].next;
    return pos;
}

template<class T>
void SLinkList<T>::Insert(int i,T a){
  if (i<1 || i>MAXSIZE) throw "invalid position";
  int p=Get(i);
  // cout<<p<<"!!!";
  // cout<<SArray[p].next;
  if(SArray[p].next == -1){
    int pos=NewNode();
    SArray[pos].data=SArray[p].data;
    SArray[p].data=a;
    SArray[p].next=pos;
    SArray[pos].next=-1;
  }
  else{
    int pos=NewNode();
    SArray[pos].data=SArray[p].data;
    SArray[p].data=a;
    SArray[pos].next=SArray[p].next;
    SArray[p].next=pos;
  }
}
template<class T>
T SLinkList<T>::DeleteNode(int i) {
  if (i<1 || i>MAXSIZE)throw "invalid position";
  int p=Get(i-1);
  int q=SArray[p].next;
  T tmp=SArray[q].data;
  if (SArray[q].next==-1) {
    SArray[p].next=-1;
    SArray[q].next=tail;
    tail=q;
  }
  else{
    SArray[p].next=SArray[q].next;
    SArray[q].next=tail;
    tail=q;
  }
  return tmp;
}
template<class T>
int SLinkList<T>::Get(int i){
  if (i<1 || i>MAXSIZE) throw"invalid position";
  int p=front;
  for(int j=0;j<i-1;j++){
    p=SArray[p].next;
    if(p==-1)return p;
  }
  return p;
}
int main(int argc, char const *argv[]) {
  int a[10]={1,2,3,4,5,6,7,8,9,0};
  SLinkList<int> slist(a,10);
  slist.PrintList();
  std::cout << '\n';
  slist.Insert(10,100);
  slist.PrintList();
  cout<<endl;
  cout<<slist.DeleteNode(2);
  slist.PrintList();
  
  system("pause");
  return 0;
}

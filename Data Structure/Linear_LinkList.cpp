/***
Mar 7th 2018
线性表->单链表
***/
#include<iostream>
using namespace std;
template <class T>
struct Node {
	T data;
	struct Node<T> *next;
};

template <class T>
class LinkList {
private:
	Node<T> * front;
public:
	LinkList() { front = new Node<T>;front->next = NULL; }
	LinkList(T a[],int n,int mode);
	~LinkList();
	void PrintList();
	int GetLength();
	Node<T> *Get(int i);
	int Locate(T x);
	void Insert(int i, T x);
	T Delete(int i);

};

template <class T>
LinkList<T>::LinkList(T a[], int n, int mode) {
//0 头插法，~0尾插法
	if (0 == mode) {
		front = new Node<T>;
		front->next = NULL;
		for (int i = n - 1;i >= 0;--i) {
			Node<T> *s = new Node<T>;
			s->data = a[i];
			s->next = front->next;
			front->next = s;
		}
	}
	else {
		front = new Node<T>;
		Node<T> * r = front;
		for (int i=0;i<n;++i){
			Node<T> * s = new Node<T>;
			s->data = a[i];
			r->next = s;
			r = s;
		}
		r->next = NULL;
	}
}


template<class T>
LinkList<T>::~LinkList() {
	Node<T> *p = front;
	while (p)
	{
		front = p;
		p = p->next;
		delete front;
	}
}

template<class T>
void LinkList<T>::PrintList() {
	Node<T> *p = front->next;
	cout << "链表中存储的数据为："<< endl;
	while (p)
	{
		cout << p->data << "  ";
		p = p->next;
	}
}

int main() {
	int a[10] = { 3,2,1,4,5,6,9,8,7,0 };
	LinkList<int> ll(a, 10,1);
	ll.PrintList();
	system("pause");
	return 0;
}

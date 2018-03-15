#include<iostream>
using namespace std;
template<class T>
struct Node
{
	T data;
	Node<T> * next;
};
template <class T>
class CLinkList
{
public:
	CLinkList() { rear = new Node<T>;rear->next = rear; };
	CLinkList(T a[], int n);
	~CLinkList();
	int GetLength();
	T * Get(int i);
	int Locate(T x);
	void Insert(int i, T x);
	T Delete(int i);
	void PrintList();
private:
	Node<T> * rear;
};
template<class T>
CLinkList<T>::CLinkList(T a[], int n) {
	rear = new Node<T>;
	Node<T>*p = rear;
	for (int i = n - 1;i >=0;--i) {
		Node<T>* s = new Node<T>;
		s->data = a[i];
		s->next = p;
		p = s;
	}
	rear->next = p;
}
template<class T>
void CLinkList<T>::PrintList() {
	Node<T> *p = rear->next;
	cout << "链表的输出结果为：" << endl;
	while (p!=rear)
	{
		cout << p->data<<"   ";
		p = p->next;
	}
}
int main()
{
	return 0;
}

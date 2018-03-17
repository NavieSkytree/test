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
	T Get(int i);
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
CLinkList<T>::~CLinkList() {
	Node < T >* p= rear->next;
	Node<T> *s = p;
	while (p!=rear)
	{
		s = p;
		p = p->next;
		delete s;
	}
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
template<class T>
int CLinkList<T>::GetLength() {
	Node<T> *p = rear->next;
	int total = 0;
	while (p!=rear)
	{
		p = p->next;
		total++;
	}
	return total;
}
template<class T>
T CLinkList<T>::Get(int i) {
	if (i<1 || i>GetLength())throw"位置异常";
	Node<T> *p = rear->next;
	int j = 1;
	while (j!=i)
	{
		p = p->next;
		j++;
	}
	return p->data;
}
template<class T>
int CLinkList<T>::Locate(T x) {
	int loc = 1;
	Node<T>* p = rear->next;
	while (p!=rear)
	{
		if (p->data==x)
		{
			return loc;
		}
		p = p->next;
		loc++;
	}
	if (loc>GetLength())
	{
		return 0;
	}

}
template<class T>
void CLinkList<T>::Insert(int i, T x) {
	if (i<1 || i>GetLength())throw"位置异常";
	Node<T> * p = rear -> next;
	for (int j = 1;j < i;j++)p = p->next;
	Node <T>*s = new Node<T>;
	s->data = p->data;
	s->next = p->next;
	p->data = x;
	p->next = s;
}
template<class T>
T CLinkList<T>::Delete(int i) {
	if (i<1 || i>GetLength())throw"位置异常";
	//int total = 1;
	T tmp;
	Node<T> *p = rear->next;
	for (int j = 1;j < i - 1;j++)p = p->next;
	Node<T>*s = p->next;
	tmp = s->data;
	p->next = s->next;
	delete s;
	return tmp;
}
int main()
{
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	CLinkList<int> cll_empty();
	CLinkList<int> cll(a, 10);
	cll.PrintList();
	cout << endl << "链表长度为:" << cll.GetLength() << endl;
	cout << cll.GetLength() << endl;
	cout << cll.Get(int(10)) << endl;
	cout << cll.Locate(int(22));
	try {
	cll.Insert(10, int(100));
	}
	catch(...){
		cout << "发生异常";
	}
	cll.PrintList();
	cout << "删除的结果为：" << cll.Delete(int(10)) << endl;
	cll.PrintList();
	system("pause");
	return 0;
}

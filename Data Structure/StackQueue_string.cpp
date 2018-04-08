#include<iostream>
using namespace std;
template <class T>
struct Node {
	T data;
	struct Node<T> *next;
};

template <class T>
class LinkList {
public:
	Node<T> * front;
	LinkList() { front = new Node<T>;front->next = NULL; }
	LinkList(T a[], int n, int mode);
	~LinkList();
	void PrintList();
	int GetLength();
	Node<T>* Get(int i);
	int Locate(T x);
	void Insert(int i, T x);
	T Delete(int i);

};
template<class T>
int LinkList<T>::GetLength() {
	int tmp = 0;
	Node<T>*p = front->next;
	while (p)
	{
		p = p->next;
		tmp++;
	}
	return tmp;
}
template <class T>
Node<T>* LinkList<T>::Get(int i) {
	Node<T> *p = front->next;
	int j = 1;
	while (p && j != i) {
		p = p->next;
		j++;
	}
	return p;
}

template <class T>
int LinkList<T>::Locate(T x) {
	Node<T> *p = front->next;
	int j = 1;
	while (p)
	{
		if (p->data == x) return j;
		p = p->next;
		j++;
	}
}

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
		for (int i = 0;i<n;++i) {
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
	cout << "链表中存储的数据为：" << endl;
	while (p)
	{
		cout << p->data << "  ";
		p = p->next;
	}
	cout << endl;
}

template<class T>
void LinkList<T>::Insert(int i, T x) {
	Node<T> *p = front;
	if (i != 1)p = Get(i - 1);
	if (p) {
		Node<T> *s = new Node<T>;
		s->data = x;
		s->next = p->next;
		p->next = s;
	}
	else
	{
		throw "插入位置错误";
	}
}

template<class T>
T LinkList<T>::Delete(int i) {
	Node<T> *p = front;
	if (i != 1)
	{
		p = Get(i - 1);
	}
	if (!p && !p->next)throw "位置错误";
	Node<T> *q = p->next;
	p->next = q->next;
	T x = q->data;
	delete q;
	return x;
}
class LinkString :public LinkList<char> {
public:
	LinkString() :LinkList<char>() {};
	LinkString(char tmp[], int n) : LinkList(tmp, n, 1) {};
	void Strcat(LinkString &s);
	LinkString* Substr(int i, int j);
	int Strcmp(LinkString &s);
	void Insert(int i, LinkString &);
	int Index_BF(LinkString &s);
	int Index_KMP(LinkString &s);
	bool Replace(LinkString &t, LinkString &v);
	void GenNextArray(LinkString &t, int *next);

};
int LinkString::Index_KMP(LinkString &s) {
	int i = 1, j = 1;
	int *next = new int[s.GetLength() + 1];
	GenNextArray(s, next);
	while (i<GetLength() && j<s.GetLength())
	{
		if (Get(i) == s.Get(j)) { i++;j++;}
		else if (!next[j]) { i++;j = 1; }
		else j = next[j];
	}
	if (j > s.GetLength())return i+1-j;
	else return -1;
}
void LinkString::GenNextArray(LinkString &t, int *next) {
	next[1] = 0;
	next[2] = 1;
	int p = next[2];
	//p storage next[j-1]
	for(int j=3;j<t.GetLength();++j){
		while (p>1 && t.Get(p)!=t.Get(j-1))
		{
			p = next[p];
		}
		if (t.Get(p) == t.Get(j - 1))
			p++;
		next[j] = p;
	}
}

bool LinkString::Replace(LinkString &t, LinkString &v) {
	int out = Index_BF(t);
	if (out != -1) {
		Substr(out, t.GetLength());
		Insert(out, v);
		return true;
	}
	else return false;
}
void LinkString::Insert(int i, LinkString &s) {
	Node<char>*p = Get(i - 1);
	Node<char>*rear = s.front->next;
	while (rear->next)rear = rear->next;
	rear->next = p->next;
	p->next = s.front->next;
	s.front->next = NULL;
}
void LinkString::Strcat(LinkString &s) {
	Node<char>*p = this->front;
	while (p->next)p = p->next;
	Node<char> *tmp = s.front;
	p->next = tmp->next;
	tmp->next = NULL;
}
int LinkString::Index_BF(LinkString &s) {
	//i-k=j-1 describe relation of target string and pattern string
	int i = 1, j = 1;
	while (i<=GetLength() && j<=s.GetLength())
	{
		if (Get(i)->data == s.Get(j)->data) { i++;j++; }
		else { i = i - j + 2;j = 1; }

	}
	if (j > s.GetLength()) { return i + 1 - j; }
	else return -1;
}
LinkString* LinkString::Substr(int i, int j) {
	Node<char>*tmp = Get(i - 1);
	Node<char>*p = tmp->next;
	for (int t = 0;t<j - 1;++t) {
		if (!p->next) {
			break;
		}
		p = p->next;
	}
	LinkString *tmpls = new LinkString();
	tmpls->front->next = tmp->next;

	tmp->next = p->next;
	PrintList();
	p->next = NULL;
	//tmpls.PrintList();
	return tmpls;

}
int LinkString::Strcmp(LinkString &s) {
	int i = 1, j = 1;
	while (i <= GetLength() && j < s.GetLength()) {
		if (Get(i)->data > s.Get(j)->data) return 1;
		else if (Get(i)->data < s.Get(j)->data) return -1;
		i++;
		j++;
	}
	if (GetLength() == s.GetLength())return 0;
	else if (GetLength() > s.GetLength())return 1;
	else return -1;
}
int main(int argc, char const *argv[]) {
	//int a[5] = { 1,2,3,4,54 };
	//LinkList<int> ll = LinkList<int>(a, 5,1);
	//ll.PrintList();
	//cout << ll.Get(5);
	char *a = "cabcdeacfabcdxd";
	char *b = "abc";
	char *c = "123";
	LinkString aa = LinkString(a, 15);
	LinkString bb = LinkString(b, 3);
	LinkString cc = LinkString(c, 3);
	/*aa.PrintList();
	aa.Strcat(bb);
	LinkString* ret= aa.Substr(3, 2);
	ret->PrintList();*/

	/*aa.Insert(2, bb);
	aa.PrintList();*/
	aa.PrintList();
	aa.Replace(bb, cc);
	aa.PrintList();
	cout << aa.Index_KMP(bb);
	system("pause");
	return 0;
}

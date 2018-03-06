/***
Mar 6th 2018
线性表->顺序表
***/
#include<iostream>
using namespace std;
const int MAXSIZE = 1000;
template<class T>
class SeqList {
private:
	T data[MAXSIZE];
	int length;
public:
	SeqList() { length = 0; }
	SeqList(const T a[], int n);
	int GetLength() { return length; }
	void PrintList();
	void Insert(int i, T x);
	T Delete(int i);
	T Get(int i);
	int Locate(T x);
};


template <class T>
SeqList<T>::SeqList(const T a[], int n) {
	if (n > MAXSIZE) throw "数组长度超过顺序表最大长度";
	for (int i = 0;i < n;++i)
		data[i] = a[i];
	length = n;
}

template<class T>
void SeqList<T>::PrintList() {
	cout << "顺序表依照序号顺序显示结果："<< endl;
	for (int i = 0;i < length;++i)
		cout << data[i] << "  ";
		cout << endl;
}


template<class T>
void SeqList<T>::Insert(int i,T x) {
	if (length > MAXSIZE)throw"上溢异常";
	if (i<1 || i>length + 1) throw"位置异常";
	for (int j = length;j >= i;j--)
		data[j] = data[j - 1];
	data[i - 1] = x;
	length++;
}

template<class T>
T SeqList<T>::Delete(int i) {
	if (0 == length)throw"下溢异常";
	if (i<1 || i>length)throw"位置异常";
	T x = data[i - 1];
	for (int j = i;j <length;++j)
		data[j - 1] = data[j];
	length--;
	return x;
}

template<class T>
T SeqList<T>::Get(int i) {
	if (i < length || i>length)throw "位置异常";
	return data[i - 1];
}

template<class T>
int SeqList<T>::Locate(T x){
	for (int i = 0;i < length;++i)
		if (data[i] == x)return i + 1;
	return 0;
}

int main() {
	int num[10] = { 1,2,3,6,5,4,7,8,9,0 };
	SeqList <int> sl(num, 10);
	sl.PrintList();
	sl.Insert(3, -1);
	sl.Delete(2);
	sl.PrintList();
	cout<<sl.Locate(1);
	system("pause");
	return 0;
}

#include<iostream>
#include<queue>
using namespace std;
template<class T>
class Ele {
public:
	//Ele();
	Ele(int i, T d) :data(d), p(i) {};
	inline friend bool operator < (const Ele<T>  &a,const Ele<T> &b) {
		return a.p<b.p ? true : false;
	}
	void print() const{
		cout << "data" << data << "p" << p << endl;
	}
private:
	T data;
	int p;
};

int main(int argc, char const *argv[]) {
	priority_queue< Ele<int> > pqueue;
	pqueue.push(Ele<int>(2, 10));
	pqueue.push(Ele<int>(3, 1));
	pqueue.push(Ele<int>(1, 100));
	int size = (int)pqueue.size();
	for (int i = 0;i<size; i++)
	{
		pqueue.top().print();
		pqueue.pop();
	}
	system("pause");
	return 0;
}

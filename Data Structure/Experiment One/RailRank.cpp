#include<iostream>
#include<queue>
#include<deque>
#include<vector>
using namespace std;
int train[10] = { 2,0,1,5,8,9,7,3,4,6 };
vector< queue<int> > bufferarray;
void check_input(int i) {
	for (auto it=bufferarray.begin();it<bufferarray.end();it++) {
		if (i>it->back()) {
			it->push(i);
			return;
		}
	}
	queue<int> tmp;
	tmp.push(i);
	bufferarray.push_back(tmp);
}
void print(){
  int tmp=-1,minPos=-1;
  for (int i = 0; i < 10; i++) {
    minPos=0;
    tmp=1000;//一个极大值保证正常运行
    for(int j=0;j<bufferarray.size();++j){
      if(bufferarray[j].empty())
        continue;
      // tmp=bufferarray[j].front();
      if(bufferarray[j].front()<tmp){
        tmp=bufferarray[j].front();
        minPos=j;
      }
    }
    cout << tmp<<" ";
    bufferarray[minPos].pop();
  }
}
int main(int argc, char const *argv[]) {
	for (auto i : train) {
		check_input(i);
	}
  // for(auto k:bufferarray)cout<<k.size();
	print();
	system("pause");
	return 0;
}

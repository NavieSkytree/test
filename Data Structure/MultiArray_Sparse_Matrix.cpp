#include <iostream>
using namespace std;
const int MAXSIZE=10;
template<class T>
struct TripEle{
  int col,row;
  T data;
};
template<class T>
class TripMatrix{
public:
  TripMatrix(int i,int j):mat_row(i),mat_col(j),total(0){};
  void addEle(int i,int j,T data){
    triData[total].row=i;
    triData[total].col=j;
    triData[total].data=data;
    total++;
  }
  void scanMat(T data[5][5]){
    for(int i=0;i<mat_row;++i){
      for(int j=0;j<mat_col;++j){
        if(data[i][j]!=0){
          addEle(i,j,data[i][j]);
        }
      }
    }
  }
  void print(){
    for(int i=0;i<total;++i){
      cout<<triData[i].row<<"  "<<triData[i].col<<"  "<<triData[i].data<<endl;
    }
  }

  void tranpose(T data[5][5],TripEle<int> newd[9]){
    int number[5];
    int pos[5];
    int tmp;
    for(int j=0;j<5;++j){
      tmp=0;
      for(int i=0;i<5;++i){
        if(data[i][j]!=0)tmp++;
      }
      number[j]=tmp;
    }
    pos[0]=0;
    int i=0;
    for(i=1;i<5;++i)
      pos[i]=pos[i-1]+number[i-1];

    for(i=0;i<9;++i){
      newd[pos[triData[i].col]].row=triData[i].col;
      newd[pos[triData[i].col]].col=triData[i].row;
      newd[pos[triData[i].col]].data=triData[i].data;
      pos[triData[i].col]+=1;
    }
    for(i=0;i<9;++i){
      cout<<newd[i].row<<"  "<<newd[i].col<<"  "<<newd[i].data<<endl;
    }
  }
private:
  int mat_row,mat_col;
  int total;
  TripEle<T> triData[MAXSIZE];
};


int main(int argc, char const *argv[]) {
  int mat[5][5]={0,0,1,2,0,
                 4,0,0,2,0,
                 7,0,0,0,0,
                 0,0,10,0,1,
                 2,1,0,0,0};
  for(int i=0;i<5;++i){
   for(int j=0;j<5;++j){
     cout<<mat[i][j]<<" ";
   }
   cout<<endl;
 }
  TripMatrix<int> trimat(5,5);
  trimat.scanMat(mat);
  trimat.print();
  cout<<endl;
  TripEle<int> newd[9];
  trimat.tranpose(mat,newd);
  return 0;
}

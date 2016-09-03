#include <iostream>
#include <algorithm>
using namespace std;

int A[16];
int counter=0;
//int node;

void build_rec(int node,int begin,int end, int a[]){
  int mid;
  if(begin==end){
    A[node]=a[begin];
    counter++;
    return;
  }else{
    mid=(begin+end)/2;
    build_rec(2*node,begin,mid,a);
    build_rec(2*node+1,mid+1,end,a);
    A[node]=min(A[2*node],A[2*node+1]);
    counter++;
    //cout<<A[2*node]<<A[2*node+1]<<min(A[2*node],A[2*node+1])<<endl;
  }
}

int main(){
    int a[9]={0,9,2,6,3,1,5,8,7};
    int n=8;
    build_rec(1,1,n,a);
    cout<<counter<<endl;
    for(int i=1;i<counter+1;i++){
      cout<<A[i];
    }
    return 0;
}

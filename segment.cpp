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

int query_rec(int node,int t_begin,int t_end,int a_begin,int a_end){
  int res;
  if(t_begin>=a_begin && t_end<=a_end){
    return A[node];
  }else{
    res=99999;
    int mid=(t_begin+t_end)/2;
    if(mid>=a_begin && t_begin<=a_end){
      res=min(res,query_rec(2*node,t_begin,mid,a_begin,a_end));
    }
    if(t_end>=a_begin && mid+1<=a_end){
      res = min(res,query_rec(2*node+1,mid+1,t_end,a_begin,a_end));
    }
    return res;
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
    cout<<endl;
    int result=query_rec(1,1,8,1,6);
    cout<<result;
    return 0;

}

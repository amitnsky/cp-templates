#include <bits/stdc++.h>
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,n) fr(i,0,n-1)
#define MXN 1000001
using namespace std;

void print(int a[], int n){
    rep(i, n) cout << a[i] << " ";
    cout << '\n';
}

void heapify(int a[], int ind, int n){
    while((ind*2+1) < n){
        int mxind = ind*2 + 1;
        if((mxind+1)<n && a[mxind+1] > a[mxind]) mxind++;
        if(a[mxind] < a[ind]) break;
        swap(a[mxind], a[ind]);
        ind = mxind;
    }
}

void build_heap(int a[], int n){
    for(int i=(n/2-1); i>=0; i--)
        heapify(a, i, n);
}

void heap_sort(int a[], int n){
    build_heap(a, n);
    
    for(int i=n-1; i>0; i--){
        swap(a[i], a[0]);
        heapify(a, 0, i);
    }
}
int main() {
    int n;
    int a[MXN] = {0};
    
    cin>>n;
    rep(i,n){
        
    }
}

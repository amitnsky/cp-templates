#include <bits/stdc++.h>

#define fr(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,n) fr(i,0,n-1)
#define fd(i,a,b) for(i=a;i>=b;i--)

using namespace std;

void print(int a[], int n){
    rep(i, n) printf("%d ", a[i]);
    cout << '\n';
}

void count_sort(int a[], int n, int place){
    int range = 10;
    int f[range] = {0};
    int out[n] = {0};
    
    rep(i,n) f[(a[i]/place)%range]++; //freq
    rep(i, (range-1)) f[i+1] += f[i]; //PS
    
    for(int i=n-1; i>=0; i--){
        // collect from buckets
        out[f[(a[i]/place)%range]-1] = a[i];
        f[(a[i]/place)%range]--;
    }
    
    rep(i, n) a[i] = out[i];
    print(a, n);
}

void radix_sort(int a[], int n){
    int place = 1;
    int maxx = *max_element(a, a+n);
    while(maxx){
        count_sort(a, n, place);
        place *= 10;
        maxx/=10;
    }
}

int main(){
    int n, t;
    int a[1001];
    cin>>n;
    rep(i, n) cin>>a[i];
    radix_sort(a, n);
}
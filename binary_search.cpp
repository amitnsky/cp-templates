#include <bits/stdc++.h>

#define fr(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,n) fr(i,0,n-1)
#define fd(i,a,b) for(i=a;i>=b;i--)

#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) (a).size()
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define ll long long
#define ALL(x) (x).begin(), (x).end()

#define vi vector< int >
#define vl vector< ll >
#define vpii vector<pii>
#define vpll vector<pll>

#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
#define flush fflush(stdout)
#define endl '\n'

#define MOD (1000*1000*1000+7)
#define MXN 300010
#define sq(a) ((a)*(a))

using namespace std;

int partition(int a[], int s, int e){
    int piv = a[s];
    int i = s+1, j = s+1;
    for(int j=s+1; j<=e; j++){
        if(a[j]<piv){
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[s], a[i-1]);
    return i-1;
}

int rand_partition(int a[], int s, int e){
    int r = rand();
    swap(a[s], a[r]);
    return partition(a, s, e);
}

void qs(int a[], int s, int e){
    if(s==e) return;
    int m = rand_partition(a, s, e);
    qs(a, s, m);
    qs(a, m+1, e);
}

int main(){
	
}
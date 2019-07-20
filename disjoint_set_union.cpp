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

int par[MXN];
int size[MXN];

void make_set(int v) {
    par[v] = v;
    size[v] = 1;
}

int find_set(int v){
    while(v != par[v]) 
        v = par[par[v]];
    return v;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        par[b] = a;
        size[a] += size[b];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // cout << flush;
    // fflush(stdout);
}

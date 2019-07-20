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

// x, y and d satisfy below equation.
// a.x + b.y = gcd(a, b) = d
int x,y,d;

void extend_euclid(int a, int b){
	if(b==0){
		x = 1;
		y = 0;
		d = a;
		return;
	}
	extend_euclid(b, a % b);
	int temp = x;
	x = y;
	y = temp - (a/b)*y;
}

int gcd(int a, int b) {
    if(b==0)
        return a;
    return gcd(b, a % b);
}

int mod_expo(int x,int n,int mod){
    int res=1;
    while(n>0)
    {
        if(n&1)
            res=(res * x)%mod;
        x=(x*x)%mod;
        n=n/2;
    }
    return res;
}

//  a's inverse mod for m exist only if a and mod are co-prime.
int inverse_mod(int a, int mod){
	// if mod is prime
	return mod_expo(a, mod-2, mod);

	// use this if mod is non-prime, however this will work even though 
	// mod is prime.
	// extend_euclid(int a, int m);
	// return (x % mod + mod) % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // cout << flush;
    // fflush(stdout);
}

#include <bits/stdc++.h>
using namespace std;

#define MXN 100001
int T[MXN];
int counter;

// T[i] denotes longest length of prefix which 
// is also suffix in substring upto T[i-1]
// or we can also say index of next possible match if
// P[j] does not match, goto j = T[j].
void build_table(string& pat){
    int i=0, j=-1; T[0]=-1;
    while(i<pat.size()){
        while(j>=0 && pat[i] != pat[j]) j = T[j];
        i++; j++;
        T[i] = j;
    }x
}

void kmp_match(string& pat, string& text){
    build_table(pat);
    int i=0, j=0;
    while(i<text.size()){
        while(j>0 && pat[j]!=text[i]) j = T[j];
        i++; j++;
        if(j==pat.size()){
            //match found
            counter++;
        }
    }
}
int main(){
    string p,t;
    cin>>p>>t;
    kmp_match(p, t);
    cout << counter << '\n';
}
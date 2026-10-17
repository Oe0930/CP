#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll,ll>;
#define rep(i,n) for(ll i=0; i<n; i++)
#define Yes cout<<"Yes"<<endl;
#define No cout<<"No"<<endl;
int main(void){
    ll n,m,k;
    cin>>n>>m>>k;
    vector<pair<bitset<15>,bool>> v(m);
    rep(i,m)
    {
        bitset<15> y;
        ll c;
        cin>>c;
        rep(j,c){
            ll a;
            cin>>a;
            y.set(a-1);
        }
        char s;
        cin>>s;
        bool r;
        if(s=='o'){
            r=true;
        }else{
            r=false;
        }
        pair p=make_pair(y,r);
        v[i]=p;
    }
    bitset<15> x2;
    ll ans=0;
    bool bo;
    rep(x10,1<<n)
    {
        bo = true;
        rep(j,m)
        {
            pair p=v[j];
            //bo=true;
            bitset<15> bi;
            bitset<15> x2(x10);
            rep(l,n){
                if((x2[l] && p.first[l])/*==1*/){
                    bi.set(l);
                }
            }
            ll num=bi.count();
            //cout<<num<<endl;
            if(p.second/*=='o'*/ && num<k){
                //cout<<10<<endl;
                bo=false;
            }else if(!p.second/*=='x'*/ && num>=k){
                //cout<<10<<endl;
                bo=false;
            }
        }
        if(bo)ans++;
        //x10++;
    }
    cout<<ans;
}

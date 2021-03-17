
// C++ (GCC9.2.1) AtCoder
/*
Ctrl+Option+N で　実行

*/

#include <bits/stdc++.h>
#define INF 100000000000
#define MOD 1000000007
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define print(x) cout << (x) << endl;

typedef long long ll;

using namespace std;

ll digit(ll x){
  ll rep = 0;
  while(x){
    x /= 10;
    rep++;
  }
  return rep;
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr); 
  ll N,M; cin>>N>>M;
  vector < pair <ll,ll> > ans(M+1); // p,x
  vector < set <pair <ll,ll> > > pref(N+1); // y,i

  REP(i,M){
    ll p,y;
    cin>>p>>y;
    ans[i+1].first = p;
    pref[p].insert(make_pair(y,i+1));
  }

  for(int p = 1; p<=N; p++){
    auto nowpref = pref[p];
    //int num = 1;

    if(nowpref.empty()) continue;

    for( auto itr = nowpref.begin(); itr != nowpref.end();itr++){
      ll index = (*itr).second;
      //ll x = ll(distance(nowpref.begin(), itr ) ) + 1;
    //  cout<<index << " "<<x<<endl;
    ll x = ll(itr - nowpref.begin() )
      ans[index].second = x;
     // num++;
    }
  }

  for(int i=1;i<=M;i++){
    auto out = ans[i];
    ll zeros = 6 - digit(out.first);
    REP(a,zeros) cout<<0;
    cout<<out.first;
    zeros = 6 -digit( out.second );
    REP(a,zeros) cout<<0;
    cout<<out.second;
    cout<<endl;

  }
  




  return 0;
}
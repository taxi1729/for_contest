
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


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr); 
  ll N;
  cin>>N;
  /*
 
 1

 10

 100




  */

 ll digit = 1000;
 ll ans = 0;

 
 while(1){

   if(digit > N) break;

   ans += (N - (digit-1));

   digit *= 1000;


 }

 print(ans);





  return 0;
}
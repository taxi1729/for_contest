/*
デバッグについて
competitive_programming のフォルダ内ではデバッグができる模様
*/


// よく使う便利関数
#include <vector>
#define ll long long int
using namespace std;

#include <iostream>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <bitset>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iomanip>
#define INF 100000000000
#define MOD 1000000007
#define ll long long int
#define REP(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;


int main(){
  // speeding up cin
ios::sync_with_stdio(false);
cin.tie(nullptr);
  
  return 0;
}


//桁の和
int getDigitSum(int n){
  int object=n;
  int ans=0;
  for(;;){
    if(object == 0) break;
    ans += object%10;
    object=object/10;
  }
  return ans;
}

//ケタ数取得
unsigned GetDigit(unsigned num){
    return log10(num)+1;
}

//ユークリッドの互除法
int gcd(int a,int b)
{
	if (a%b==0)
	{
		return(b);
    }
	else
	{
		return(gcd(b,a%b));
    }
}

//累乗を高速に（MODとってないよ！！！！！！）
ll my_pow(ll a,ll b){
  ll res;
  if(b==1) return a;
  if(b % 2 == 0){
    res = my_pow(a,b/2);
    return res * res;
  } else {
    res = my_pow(a,b/2);
    return res * res * a;
  }
}

//累乗を高速に（MOD 指定可能）
int powMod(int x, int k, int m) {
  if (k == 0)     return 1;
  if (k % 2 == 0) return powMod(x*x % m, k/2, m);
  else            return x*powMod(x, k-1, m) % m;
}

//約数列挙アルゴリズム　O（√N）
vector <ll > divisor(ll n) {
  vector <ll> ret;
  for(int i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}
// 素因数分解　O(√N)
template <typename T> 
vector < pair<T,T> > prime_factor(T n){
    vector  < pair <T,T> > ret;
    for(T i=2; i*i <= n; i++){
        if(n % i != 0) continue;
        T tmp = 0;
        while(n % i == 0) {
            tmp++;
            n /= i;
        }
        ret.push_back(make_pair(i,tmp));
    }
    if(n != 1) ret.push_back(make_pair(n,1));
    return ret;
}


struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};
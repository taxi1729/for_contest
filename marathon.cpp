// C++ (GCC9.2.1) AtCoder
//x axisで切っていく
// size調整してない...


#include <bits/stdc++.h>
#include<fstream>
#include <random>
#define INF 100000000000
#define MOD 1000000007
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define print(x) cout << (x) << endl;

typedef long long ll;

using namespace std;

double calc_score(int square, int r){
  // double(square),double(r)
  return 1-(1-(min(double(square),double(r))/max(double(square),double(r)))) * (1-(min(double(square),double(r))/max(double(square),double(r))));
};

class rectangle{
  int X0,Y0;
  int X1,Y1;
};

int main() {

// dbbug mode change
 bool debbug = true;
 const int cnt_cut = 1000000;


  ios::sync_with_stdio(false);
  cin.tie(nullptr); 
  ll N;
  cin>>N;

  vector < tuple<int,int,int,int> > ans(N); //x,y,x,y
  vector < tuple<int,int,int,int> > candidate(N);

  // 入力をidつきで収納
  vector < tuple<int,int,int,int> > qx(N); // x,y,r,i
  vector < tuple<int,int,int,int> > qy(N); // y,x,r,i

   double pred_score = 0;
   double best_score = -1;

   vector <double> scores;
   vector <int> Xs;
   vector <int> Ys;
   Xs.push_back(10000);
   Ys.push_back(10000);


  
  REP(i,N){
      ll a,b,c; cin>>a>>b>>c;
      qx[i] = make_tuple(a,b,c,i);
      qy[i] = make_tuple(b,a,c,i);
      Xs.push_back(a);
      Ys.push_back(b);
  }

  sort(qx.begin(),qx.end());
  sort(all(Xs));
  sort(qy.begin(),qy.end());
  sort(all(Ys));


int xcnt = 0;

while(xcnt<cnt_cut){
  xcnt++;



{
// x-axis 
 
  int nowx = 0;

  for(int i=0;i<N;i++){
    //  cout<<nowx<<endl;

      int& x1 = get<0> (qx[i]);
      int& y1 = get<1> (qx[i]);
      int &i1 = get<3>(qx[i]);
      int &r1 = get<2>(qx[i]);
      
      if(nowx == x1 + 1){
          candidate[i1] = make_tuple(x1,y1,x1+1,y1+1);
          pred_score += calc_score(1,r1);
          nowx = x1+1;
          continue;
      }

      if(Xs[i] == Xs[i+1]){
        candidate[i1] = make_tuple(x1,y1,x1+1,y1+1);
        pred_score += calc_score(1,r1);
        nowx = x1+1;
        continue;
      }

      int nextX = Xs[i+1];

      //左端と右端を乱数で決定
      
      int leftx = nowx + (int)(rand()*( x1-1  - nowx + 1.0)/(1.0 + RAND_MAX));
      int rightx = x1+1 + (int)(rand()*(nextX - (x1+1) + 1.0)/(1.0+RAND_MAX));

      
      int hight = r1/abs(rightx-leftx);
  

     if(hight > 10000) hight = 10000;
     if(hight == 0) hight = 1;

     int ay = 0;
     int by = hight;

     if(y1 >= hight + 1){
       by = y1 + 1;
       ay += by - hight;
     }

      candidate[i1] = make_tuple(leftx,ay,rightx,by);
      pred_score += calc_score((rightx - leftx)*(by-ay),r1);

      nowx = rightx;

  }

}

if(pred_score > best_score){
  best_score = pred_score;
  ans = candidate;
}
 scores.push_back(pred_score);

pred_score = 0;

/*
x axis asceding order finished
*/
}


{
// y-axis ascending order 
  sort(qy.begin(),qy.end());

// 最初の要素
  int& id = get<3>(qy[0]);
  int& x0 = get<1>(qy[0]);
  int& y0 = get<0>(qy[0]);
  int& r0 = get<2>(qy[0]);

  candidate[id] = make_tuple(x0,y0,x0+1,y0+1);
  pred_score += calc_score(1,r0);

  int nowy = y0+1;

  for(int i=1;i<N;i++){
    //  cout<<nowx<<endl;

      int& y1 = get<0> (qy[i-1]);
      int& y2 = get<0> (qy[i]);
      int& x1 = get<1> (qy[i-1]);
      int& x2 = get<1>(qy[i]);
      int &i1 = get<3>(qy[i-1]);
      int &i2 = get<3>(qy[i]);

      int &r2 = get<2>(qy[i]);
      assert(y2 >= y1);
      if(y1 == y2){
          candidate[i1] = make_tuple(x1,y1,x1+1,y1+1);
          candidate[i2]= make_tuple(x2,y2,x2+1,y2+1);
          pred_score += calc_score(1,r2);
          nowy = y2+1;
          pred_score -= 0.7;
          continue;
      }
      
      int& r = get<2>(qy[i]);

      int hight = r/abs(y2+1-nowy);
  

     if(hight > 10000) hight = 10000;
     if(hight == 0) hight = 1;

     int ax = 0;
     int bx = hight;

     if(x2 >= hight + 1){
       bx = x2 + 1;
       ax += bx - hight;
     }

      candidate[i2] = make_tuple(ax,nowy,bx,y2+1);
      pred_score += calc_score((y2+1-nowy)*(bx-ax),r2);

      nowy = y2+1;

  }

}

if(pred_score > best_score){
  best_score = pred_score;
  ans = candidate;
}
 scores.push_back(pred_score);

pred_score = 0;

/*
y axis asceding order finished
*/


  REP(i,N){
      /*
      x+0.5 y+0.5

      x y x+1 y+1
      */
     int& x = get<0>(ans[i]);
     int& y = get<1>(ans[i]);
     int& xx = get<2>(ans[i]);
     int& yy = get<3>(ans[i]);
     cout<<x<<" "<<y<<" "<<xx<<" "<<yy<<endl;
  }

 
// debug

   if(debbug){
     ofstream outputfile("test.txt");

    REP(i,N){
       int& x = get<0>(ans[i]);
      int& y = get<1>(ans[i]);
      int& xx = get<2>(ans[i]);
      int& yy = get<3>(ans[i]);

      outputfile<<x<<" "<<y<<" "<<xx<<" "<<yy<<endl;
    } 

    for(auto s : scores){
      // cout<<s*1000000000/double(N)<<" ";
    }
     cout<<endl;

     cout<<best_score*1000000000/double(N)<<endl;

    outputfile.close();
   }


  return 0;
}

/*
作りかけ

// C++ (GCC9.2.1) AtCoder
//x axisで切っていく
// size調整してない...


#include <bits/stdc++.h>
//#include<fstream>
#include <random>
#define INF 100000000000
#define MOD 1000000007
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define print(x) cout << (x) << endl;

typedef long long ll;

using namespace std;


//これだけの情報があれば衝突判定　点の包含を調べられる
// https://yttm-work.jp/collision/collision_0005.html#head_line_02
class rectangle{
  // 実際の長方形
  pair <double,double> center;
  int width;
  int hight;
  // adの位置
  pair <double,double> pos;

  int r;
};

// 全ての長方形を走査すれば計算可能 O(N)
//　ただしダブリはないことが前提。
double calc_score();

int main() {

// dbbug mode change
 bool debbug = 1;


  ios::sync_with_stdio(false);
  cin.tie(nullptr); 
  ll N;
  cin>>N;
  vector < tuple<int,int,int,int> > ans(N); //x,y
  vector < tuple<int,int,int,int> > candidate(N);

  // 入力をidつきで収納
  vector < tuple<int,int,int,int> > qx(N); // x,y,r,i
  vector < tuple<int,int,int,int> > qy(N); // y,x,r,i
  vector < tuple <int,int,int,int> > qid(N); // id,x,y,r
  vector < rectangle > rects(N); 
 
  REP(i,N){
      ll a,b,c; cin>>a>>b>>c;
      qx[i] = make_tuple(a,b,c,i);
      qy[i] = make_tuple(b,a,c,i);
      qid[i] = make_tuple(i,a,b,c);
      double x = double(a)+0.5;
      double y = double(b)+0.5;
      rects[i].pos = make_pair(x,y);
      rects[i].r = c;
  }

  sort(all(qx));
  sort(all(qy));
  sort(all(qid));

// 全ての広告について暫定的な境界を定めその中で出来る限りの最適化をする。
  REP(i,N){
    auto q = qid[i];

    int left = 0;
    int right = 10000;
    int bottom = 0;
    int top = 10000;

  }

//山登り的に更新



  return 0;
}


*/
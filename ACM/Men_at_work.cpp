#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <map>
#include <queue>
using namespace std;
bool estPasse[50][50];
list <pair<int,int>> save;
bool wall[50][50];
int periode[50][50];
int N;

long long mini( long long a , long long b){
  if(a<b)return a;
  return b;
}
long long maxi(long long a , long long b){
  if(a<b)return b;
  return a;
}

void initialise(){
  char x;
  for(int i = 0; i < N ; i++){
    for(int j = 0; j < N ;j++){
        cin >> x ;
        if( x == '*')wall[i][j] = true;
        else wall[i][j] = false;
    }
  }
  string y;
  for(int i = 0; i < N ; i++){
    cin >> y;
    for(int j = 0 ; j < N ; j++){
      periode[i][j] = y[j] - 48;
    }
  }
}
int modulo(long long a ,long long b){
  return a%b;
}
void displaylist(list<pair<int,int>> *next){
  for(auto it = next->begin(); it != next->end();it++){
    cout << "(" << it->first << ","<< it->second << ") ";
  }
  cout <<endl;
}
int uneEtape(list <pair<int,int>> next, long long t){
  int i,j;
  for(int i = 0; i < N ;i++){
    for(int j = 0 ; j <N ;j++){
      estPasse[i][j] = false;
    }
  }
  while(next.size() != 0){
    i = next.front().first;
    j = next.front().second;
    next.pop_front();
    bool c11 = false;
    bool c12 = false;

    if(periode[i + 1][j] != 0){
      c11 = (t + 1) % (2*periode[i + 1][j]) <  periode[i + 1][j];
      c12 = (t + 1) % (2*periode[i + 1][j]) >= periode[i + 1][j];
    }

    bool c21 = false;
    bool c22 = false;

    if(periode[i][j + 1] != 0){
    c21 = (t + 1) % (2*periode[i][j + 1]) <  periode[i][j + 1];
    c22 = (t + 1) % (2*periode[i][j + 1]) >= periode[i][j + 1];
    }

    bool c31 = false;
    bool c32 = false;

    if(periode[i - 1][j] != 0){
      c31 = (t + 1) % (2*periode[i - 1][j]) <  periode[i - 1][j];
      c32 = (t + 1) % (2*periode[i - 1][j]) >= periode[i - 1][j];
    }
    bool c41 = false;
    bool c42 = false;
    if(periode[i][j - 1] != 0){
      c41 = (t + 1) % (2*periode[i][j - 1]) <  periode[i][j - 1];
      c42 = (t + 1) % (2*periode[i][j - 1]) >= periode[i][j - 1];
    }
    bool c51 = false;
    bool c52 = false;
    if(periode[i][j] != 0){
      c51 = (t + 1) % (2*periode[i][j])     <  periode[i][j];
      c52 = (t + 1) % (2*periode[i][j])     >= periode[i][j];
    }
    if( (i + 1) < N && estPasse[i + 1][j] == false){
      if(periode[i + 1][j] == 0 && wall[i + 1][j] == false){
        estPasse[i + 1][j] = true;
        save.push_back(make_pair(i + 1,j));
        //cout <<"ici 11" << endl;
      }
      else if( c11 && wall[i + 1][j] == false){
        //cout << "test = " << (t + 1)% (2 * periode[i + 1][j]) <<" "<< periode[i + 1][j] << endl;
        estPasse[i + 1][j] = true;
        save.push_back(make_pair(i + 1,j));
        //cout <<"ici 12" << endl;
      }
      else if( c12 && wall[i + 1][j] == true){
        //cout << "test = " << (t + 1)% (2 * periode[i + 1][j]) <<" "<< periode[i + 1][j] << endl;
        estPasse[i + 1][j] = true;
        save.push_back(make_pair(i + 1,j));
        //cout <<"ici 12" << endl;
      }

    }

    if( (j + 1) < N && estPasse[i][j + 1] == false){
      if(periode[i][j + 1] == 0 && wall[i][j + 1] == false){
        estPasse[i][j + 1] = true;
        save.push_back(make_pair(i,j + 1));

      }
      else if( c21 && wall[i][j + 1] == false){
        //cout << "test = " << (t + 1)% (2 * periode[i][j + 1]) <<" "<< periode[i][j + 1] << endl;
        estPasse[i][j + 1] = true;
        save.push_back(make_pair(i,j + 1));

      }
      else if( c22 && wall[i][j + 1] == true){
        //cout << "test = " << (t + 1)% (2 * periode[i][j + 1]) <<" "<< periode[i][j + 1] << endl;
        estPasse[i][j + 1] = true;
        save.push_back(make_pair(i,j + 1));

      }

    }

    if( (i - 1) >= 0 && estPasse[i - 1][j] == false){
      if(periode[i - 1][j] == 0 && wall[i - 1][j] == false ){
        estPasse[i - 1][j] = true;
        save.push_back(make_pair(i - 1,j));

      }
      else if( c31 && wall[i - 1][j] == false){
        //cout << "test = " << (t + 1)% (2 * periode[i - 1][j])<<" "<< periode[i -1][j]<< endl;
        estPasse[i - 1][j] = true;
        save.push_back(make_pair(i - 1,j));

      }
      else if( c32 && wall[i - 1][j] == true){
        //cout << "test = " << (t + 1)% (2 * periode[i - 1][j])<<" "<< periode[i -1][j]<< endl;
        estPasse[i - 1][j] = true;
        save.push_back(make_pair(i - 1,j));

      }

    }

    if( (j - 1) >= 0 && estPasse[i][j - 1] == false){
      if(periode[i][j - 1] == 0 && wall[i][j - 1] == false){
        estPasse[i][j - 1] = true;
        save.push_back(make_pair(i,j - 1));

      }
      else if( c41 && wall[i][j - 1] == false){
        //cout << "test = " << (t + 1)% (2 * periode[i][j - 1]) <<" "<< periode[i][j-1]<< endl;
        estPasse[i][j - 1] = true;
        save.push_back(make_pair(i,j - 1));

      }
      else if( c42 && wall[i][j - 1] == true){
        //cout << "test = " << (t + 1)% (2 * periode[i][j - 1]) <<" "<< periode[i][j-1]<< endl;
        estPasse[i][j - 1] = true;
        save.push_back(make_pair(i,j - 1));

      }

    }
    if(estPasse[i][j] == false){
      if(periode[i][j] == 0 && wall[i][j] == false){
        estPasse[i][j] = true;
        save.push_back(make_pair(i,j));

      }
      else if( c51 && wall[i][j] == false){
        estPasse[i][j] = true;
        save.push_back(make_pair(i,j));
      }
      else if( c52 && wall[i][j] == true){
        estPasse[i][j] = true;
        save.push_back(make_pair(i,j));
      }

    }

  }
  if(estPasse[N-1][N-1] == true){
    cout<<t + 1 <<endl;
    return -1;
  }
return save.size();

}

void solver(){
  initialise();
  long long t = 0;
  list <pair<int,int>> next;
  next.push_front(make_pair(0,0));
  int out_etape;
  while(t < 10000 ){
    //displaylist(&next);
    out_etape = uneEtape(next,t);
    if(out_etape == -1)return;
    t++;
    next = save;
    save.clear();
    //cout << "next size = " << next.size() << endl;
  }
//cout << t << endl;
cout << "NO" <<endl;



}
int main(){
  cin >> N;
  while(true){
    solver();
    save.clear();
    if(cin >> N)cout <<endl;
    else break;
  }


  return 0;

}

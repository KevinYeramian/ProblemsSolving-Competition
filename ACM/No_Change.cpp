#include <iostream>
#include <vector>
#include <list>
using namespace std;

bool solver(int x, int k, int * v){
  int i1,i2,i3,i4,i5;
  float x1,x2,x3,x4,x5;
  for(i1 = (int)(x/v[0]); i1>=0;i1--){
    //cout << "i1 = " << i1 << endl;
    x1 = x - i1*v[0];
    if(x1 == 0)return true;

    for(i2 = min((int)(x1/v[1]),i1); i2>=0;i2--){
      //cout << "i2 = " << i2 << endl;
      x2 = x1 -i2*v[1];
      if(x2 == 0)return true;
      for(i3 = min((int)(x2/v[2]),i2); i3>=0;i3--){
        x3 = x2 -i3*v[2];
        if(x3 == 0)return true;
        for(i4 = min((int)(x3/v[3]),i3); i4>=0;i4--){
          x4 = x3 -i4*v[3];
          if(x4 == 0) return true;
          for(i5 = min((int)(x4/v[4]),i4); i5>=0;i5--){
            x5 = x4 -i5*v[4];
            if(x5 == 0) return true;
          }
        }
      }
    }
  }
  return false;
}

int main(){
  int n;
  int x;
  int k;
  int v[5];
  cin >> n;
  for(int j = 0 ; j < n ; j++){
    for(int i = 0; i < 5; i++){
      v[i] = -1;
    }
    cin >>x;
    cin >>k;
    for(int i = 0 ; i < k ; i++){
      cin>>v[i];
    }
    //cout << x << " " << k <<endl;
    if(solver(x,k,v))cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    if(j != n-1) cout <<endl;

  }



  return 0;

}

#include <iostream>
#include <queue>
using namespace std;
#include <list>

int main(){
  long long int P = 0, C = 0; int etape = 1; char state = 0; list<long long> queue; long long toprint; long long lim = 1000;
  cin >> P >> C;

  while(P != 0 && C != 0){
    cout<<"Case "<<etape<<":"<<endl;
    etape++;
    for(long long i = 1 ; i <= min(C,P) ; i++){
              queue.push_back(i);
    }
    for(long long i = 1 ; i <= C ; i++){
      cin >> state;
      if( state == 'N'){
        toprint = queue.front(); queue.pop_front();
        cout<< toprint <<endl;
        if(toprint<=min(C,P))queue.push_back(toprint);

      }
      else{
        cin >> toprint;
        queue.remove(toprint);
        queue.push_front(toprint);
      }
    }
    queue.clear();
    cin >> P >> C;

  }

  return 0;

}

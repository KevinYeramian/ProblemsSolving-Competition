#include <iostream>
#include <vector>
#include <list>
using namespace std;
bool solver(int n,float taille, float w){
  list<float> position;
  float x;
  for(int i = 0 ; i < n ; i++){
    cin >> x;
    position.push_back(x);
  }
  position.sort();

  unsigned j;
  auto actual = position.begin();
  auto next = position.begin();
  next++;
  float f1;
  float f2;
  for(j = 0 ; j < position.size()-1;j++){
      f1 = *actual;
      f2 = *next;
      //cout << f2 <<" "<<f1<< endl;
      if( f2 -f1 > w){
        //cout << "erreur "<< *next <<" " << *actual << endl;
        return false;
      }
      next++;
      actual++;
  }
  if((taille - *actual) > w/2){
    //cout << "erreur fin"<< *actual << endl;
   return false;
 }
  if( *position.begin() > w/2){
    //cout << "erreur debut "<< *position.begin() << endl;
     return false;}

  return true;
}

int main(){
  int nx,ny;
  float w;
  cin >> nx >> ny >>w;
  while(nx != 0 && ny != 0 && w != 0){
    bool x = solver(nx,75,w);
    bool y = solver(ny,100,w);
    if(x == true && y == true)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    cin >> nx >> ny >>w;
  }
  return 0;

}

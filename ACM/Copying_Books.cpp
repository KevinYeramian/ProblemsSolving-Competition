#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;

long long int books[500];
long long int minbooks[500][501];
int backtrack[500][501];
long long mini( long long a , long long b){
  if(a<b)return a;
  return b;
}
long long maxi(long long a , long long b){
  if(a<b)return b;
  return a;
}
void initialise(long long number_books){

  for(long long int i = 0 ; i < number_books ; i++){
    cin >> books[i];
  }
  minbooks[number_books - 1][1] = books[number_books -1];
  for(long long i = number_books - 2 ; i >= 0;i--){
    minbooks[i][1] = minbooks[i + 1][1] + books[i];
    backtrack[i][1] = number_books - i - 1;
  }
}

int new_borne(int actual_pos,long long max, long long number_scribes,long long scribe_left , long long number_books){
  int out =  -1;
   //cout << "postion = " << actual_pos << " scribe_left = " << scribe_left << " ma borne " << number_books  - scribe_left <<endl;
  long long aux;
  for(long long book_take_i = 1 ; (book_take_i  + actual_pos) <= (number_books  - scribe_left + 1) ; book_take_i++){
    aux = minbooks[actual_pos + book_take_i][scribe_left - 1];
    //cout << aux << endl;
    if(aux <= max){
      out = book_take_i;
      break;
    }
  }
if(out == -1)cout <<"ici" << endl;
return out;
}

void backtrackingminlast(long long number_scribes, long long number_books){
  long long max = minbooks[0][number_scribes];
  int scribe_left = number_scribes;
  int i = 0;
  int borne_package;
  while(scribe_left != 0){
    borne_package = backtrack[i][scribe_left];
    if(scribe_left != 1){
      borne_package = new_borne(i,max,number_scribes,scribe_left,number_books);
    }
    else{
      borne_package = number_books - i;
    }
    for(int j = 0 ; j < borne_package; j++){
      cout << books[i + j];

      if(j != borne_package - 1)cout <<" ";
    }

    i += borne_package;
    scribe_left--;
    if(scribe_left != 0)cout << " / ";

  }

}
void solver(long long number_books ,long long number_scribes){
  initialise(number_books);

  long long sum_total;
  long long sum_in;
  long long min;
  long long min_take;
  for(long long book_i = number_books - 1; book_i >= 0 ; book_i--){
    for(long long scribe_left = 2 ; scribe_left <= mini(number_books - book_i, number_scribes) ; scribe_left++){
      sum_total = 0;
      sum_in = 0;
      min = LLONG_MAX;
      min_take = 1;
      for(long long book_take_i = 1 ; (book_take_i  + book_i) <= (number_books  - scribe_left + 1); book_take_i++){
         //cout << "book_i = " << book_i << " scribe_left = " << scribe_left << "sum_in = " << sum_in << "minbooks = " << minbooks[book_i + book_take_i][scribe_left - 1] <<endl;
         sum_in += books[book_i + book_take_i - 1];
         sum_total = maxi(sum_in, minbooks[book_i + book_take_i][scribe_left - 1]);
         if(sum_total < min){
           min_take = book_take_i;
           min = sum_total;
         }
      }
      minbooks[book_i][scribe_left] = min;
      backtrack[book_i][scribe_left] = min_take;
    }
  }
  backtrackingminlast(number_scribes,number_books);

}
int main(){
  for(int i = 0 ; i < 500 ; i++){
    for(int j = 0; j <= 500; j++){
        minbooks[i][j] = -1;
        backtrack[i][j] = -1;
    }
  }

  long long int n;
  int number_books,number_scribes;
  cin >> n;

  for(long long int i = 0 ; i < n ; i++){
    cin >> number_books >> number_scribes;
    number_scribes = min(number_books,number_scribes);
    solver(number_books,number_scribes);
    cout << endl;

  }

  return 0;

}

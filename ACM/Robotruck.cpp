#include <iostream>
#include <vector>
#include <list>
using namespace std;
#include <climits>
long long mini_j[100000];
long long mini[100000];
long long package[100000][3];


void initialise(long long number_package){
  for(long long i = 0 ; i < number_package ; i++){
    cin >> package[i][0];
    cin >> package[i][1];
    cin >> package[i][2];
  }

}

long long solver(long long max_weight,long long number_package){
  initialise(number_package);
  for(long long i = number_package -1 ; i >= 0 ; i--){
    long long weight_i = 0;
    long long j;
    for(j = i ; j < number_package; j++){
        if(weight_i + package[j][2] <= max_weight){
          weight_i += package[j][2];
        }
        else break;
    }
    long long last_to_check = j - 1;
    long long min = LLONG_MAX;
    long long min_j = -1;
    long long x = 0;
    long long y = 0;
    long long sum = 0;
    long long sum_position = 0;
    //cout << "Je check pour i = "<< i << " les positions suivantes :"<<endl;
    for(long long position = 0 ; position <= last_to_check - i  ; position++){
        sum_position = 0;
        sum += abs(x - package[i + position][0]) + abs(y - package[i + position][1]);
        //cout << "la " << abs(x - package[i + position][0]) + abs(y - package[i + position][1]) <<endl;
        //cout << "sum = " << sum << endl;
        x = package[i + position][0];
        y = package[i + position][1];
        sum_position += sum + x + y;
        if((position + i + 1) <= number_package -1){
          sum_position += mini[position + i + 1];
          //cout << "ici"<<endl;
        }
        //cout << "Pour " << position + i << " le score est de " << sum_position << "et la somme " << sum << endl;
        if(sum_position <= min){
          min = sum_position;
          min_j = position + i;
        }
    }

    mini[i] = min;
    mini_j[i] = min_j;
    //cout << "Pour " << i << " il faut prendre "<< min_j << " il a le score de " << min << endl;
  }
  return mini[0];
}

int main(){
  long long nbr_case;
  long long max_weight;
  long long number_package;
  long long anwser;
  cin >> nbr_case;
  for(long long i = 0; i < nbr_case ; i++){
    cin >> max_weight;
    cin >> number_package;
    anwser = solver(max_weight,number_package);
    cout << anwser << endl;
    if(i != nbr_case -1)cout<<endl;
  }
  return 0;

}

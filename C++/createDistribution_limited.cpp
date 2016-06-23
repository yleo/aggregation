#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Tau
{
  double x; double y;
};

int main(int argc, char *argv[]) {
  vector <int > tau;
  double average=0, sv=0;
  vector < Tau > Norm;
  tau.resize(100001);
  int number=0, buffer=0;
  Tau point;
  int s1, s2, t1, h,t,ni;
  int maxt=0, maxp=0; 

  

  //RECUPERATION DES DONNEES
  while (cin >> t1 >> s1 >> s2 >> t >> h >> ni) {
     if (t1>maxt) {maxt=t1;}
     tau[(int) (100000* (double) h/t)]++;
     average += (double) h/t;
     sv += ((double) h/t)*((double) h/t);
     number++;
  }

  const int n = maxt+1;

  for (int i = 100000; i>=0; i--) {
    buffer+=tau[i];
    point.x=(double) i/100000;
    point.y=((double) buffer/number);
    if (tau[i]) {Norm.push_back(point);}
    if (tau[i]) {cout << point.x << " " << point.y << endl;}
  }

  //MK distance
  double a =1, b=0, aire=0, x, y;

  for (int i = 0; i<Norm.size(); i++) {
    x=Norm[i].x;
    y=Norm[i].y;
    if (x+b>=1) {aire+=((b+x-1)*(a-x)+((a-x)*(a-x))/2);}
    else if (a+b<=1) {aire+=((1-a-b)*(a-x)+((a-x)*(a-x))/2);}
    else if (x+b<1 and a+b>1) {aire+=(((a-x)*(a-x))/2-(b+a-1)*(1-x-b));}  
    a=x; b=y;
  }
  aire+=a*a/2;
  if (aire<0) {aire=-aire;}

  double buffer1=0, shanon1=0, temp=0;

  for (int j = 9; j>=0; j--) {
    buffer1=0;
    for (int i = 100000; i>=0; i--) {
      if (i>j*10000 and i<=(j+1)*10000) {
	buffer1+=tau[i];
      }
    }
    temp= double (buffer1/number);
    if (temp) {shanon1-=(double) temp*log(temp);}
  }

  double buffer2=0, shanon2=0;

  for (int j = 9; j>=0; j--) {
    buffer2=0;
    for (int i = 100000; i>=0; i--) {
      if (i>j*10000) {
	buffer2+=tau[i];
      }
    }
    temp= double (buffer2/number);
    if (temp) {shanon2-=(double) temp*log(temp);}
  }
  
  cerr << atoi(argv[1]) << " " << average/number << " " << 0.5-aire << " " << sqrt(sv/number-((average/number)*(average/number))) << " " << shanon1 << " " << shanon2 << endl;
  return 0;
}

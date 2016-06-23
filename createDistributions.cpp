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
  int shannonInt = 0;
  

  //RECUPERATION DES DONNEES
  while (cin >> t1 >> s1 >> s2 >> t >> h >> ni) {
    if (!(h==1 && t==1)) {
     if (t1>maxt) {maxt=t1;}
     tau[(int) (100000* (double) h/t)]++;
     average += (double) h/t;
     sv += ((double) h/t)*((double) h/t);
     number++;
    }
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

  double buffer10=0, shanon10=0, temp=0;

  for (int j = 9; j>=0; j--) {
    buffer10=0;
    for (int i = 100000; i>=0; i--) {
      if (i>j*10000 and i<=(j+1)*10000) {
	buffer10+=tau[i];
      }
    }
    temp= double (buffer10/number);
    if (temp) {shanon10-=(double) temp*log(temp);}
  }

  double buffer20=0, shanon20=0;

  for (int j = 19; j>=0; j--) {
    buffer20=0; 
    for (int i = 100000; i>=0; i--) {
      if (i>j*5000 and i<=(j+1)*5000) {
	buffer20+=tau[i];
      }
    }
    temp= double (buffer20/number);
    if (temp) {shanon20-=(double) temp*log(temp);}
  }

  int shanonInt=2;
  double buffer0=0;
  double shanon2=0;

  for (int j = shanonInt-1; j>=0; j--) {
    buffer0=0; 
    for (int i = 100000; i>=0; i--) {
      if (i>j*100000/shanonInt and i<=(j+1)*100000/shanonInt) {
	buffer0+=tau[i];
      }
    }
    temp= double (buffer0/number);
    if (temp) {shanon2-=(double) temp*log(temp);}
  }

  shanonInt=50;
  buffer0=0;
  double shanon50=0;

  for (int j = shanonInt-1; j>=0; j--) {
    buffer0=0; 
    for (int i = 100000; i>=0; i--) {
      if (i>j*100000/shanonInt and i<=(j+1)*100000/shanonInt) {
	buffer0+=tau[i];
      }
    }
    temp= double (buffer0/number);
    if (temp) {shanon50-=(double) temp*log(temp);}
  }

  shanonInt=100;
  buffer0=0;
  double shanon100=0;

  for (int j = shanonInt-1; j>=0; j--) {
    buffer0=0; 
    for (int i = 100000; i>=0; i--) {
      if (i>j*100000/shanonInt and i<=(j+1)*100000/shanonInt) {
	buffer0+=tau[i];
      }
    }
    temp= double (buffer0/number);
    if (temp) {shanon100-=(double) temp*log(temp);}
  }

  shanonInt=30;
  buffer0=0;
  double shanon30=0;

  for (int j = shanonInt-1; j>=0; j--) {
    buffer0=0; 
    for (int i = 100000; i>=0; i--) {
      if (i>j*100000/shanonInt and i<=(j+1)*100000/shanonInt) {
	buffer0+=tau[i];
      }
    }
    temp= double (buffer0/number);
    if (temp) {shanon30-=(double) temp*log(temp);}
  }

  shanonInt=40;
  buffer0=0;
  double shanon40=0;

  for (int j = shanonInt-1; j>=0; j--) {
    buffer0=0; 
    for (int i = 100000; i>=0; i--) {
      if (i>j*100000/shanonInt and i<=(j+1)*100000/shanonInt) {
	buffer0+=tau[i];
      }
    }
    temp= double (buffer0/number);
    if (temp) {shanon40-=(double) temp*log(temp);}
  }

  
  double buffer5=0, shanon5=0;

  for (int j = 4; j>=0; j--) {
    buffer5=0; 
    for (int i = 100000; i>=0; i--) {
      if (i>j*20000 and i<=(j+1)*20000) {
	buffer5+=tau[i];
      }
    }
    temp= double (buffer5/number);
    if (temp) {shanon5-=(double) temp*log(temp);}
  }

  double cre=0;
  a=100000, b=-1;
  for (int i = 100000; i>=0; i--) {
    if (tau[i]>0) {
      if (b>=0) {
	//cout << i << " " << a << " " << b/number << " " << log(b/number) << " " << number << " " << cre << endl;
	cre+=((i-a)/100000)*(b/number)*log(b/number);
      }
      a=i;
      if (b<0) {
	b=tau[i];
      }
      else {
	b+=tau[i];
      }
    }
  }
  

  
  cerr << atoi(argv[1]) << " " << average/number << " " << 0.5-aire << " " << sqrt(sv/number-((average/number)*(average/number))) << " " << shanon2 << " " << shanon5 << " " << shanon10 << " " << shanon20 << " " << shanon30 << " " << shanon40 << " " << shanon50 << " " << shanon100 << " " << cre << endl;
  return 0;
}

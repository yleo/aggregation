//cas t1=t2 et croissant par les ti
//output not uniq
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct myclass {
  bool operator() (int i,int j) { return (i<j);}
} myobject;

struct Arete
{
  int u; int v;
};

int main(int argc, char *argv[]) {
 
  map < int, int > Convert;
  Arete arr, buf;
  int s1, s2, t1, t2;
  map < int, vector < Arete > > Graph;
  int maxT=atoi(argv[1]), maxN=0; //  274882 102543 
  int temp,i2,i4,x;
  i4=0;
  for (int i=maxT; i>0;i--) {
    i2=maxT/i;
    if (i2>i4) {
      i4=i2;
      Convert[i]=0;
    }
  }
  
  
  int n = 0;
  int p = 0;
  
    
  while (cin >> s1 >> s2 >> t1 >> t2) {
    for (std::map <int, int >::iterator it=Convert.begin(); it!=Convert.end(); ++it) {
      x=it->first;
      n = (int) (maxT+1)/x;
      p = (maxT+1)-n*x;
      if (t1<p*(n+1)) {
	temp=t1/(n+1);
	if ((temp+1)*(n+1)<=t1+t2) {
	  Convert[it->first]++;
	}
      }
      else {
	temp=(t1-p*(n+1))/n;
	if (p*(n+1)+(temp+1)*n<t1+t2) {
	  Convert[it->first]++;
	}
      }
    }
  }

  for (std::map <int, int >::iterator it=Convert.begin(); it!=Convert.end(); ++it) {
    cout << maxT/(it->first) << " " << Convert[it->first] << endl;
  }

  return 0;
}

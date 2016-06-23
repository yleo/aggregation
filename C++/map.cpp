#include <iostream>
#include <vector>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <cmath>
#include <map>
using namespace std;

struct Time
{
  int t1;
  int t2;
};


int main(int argc, char *argv[]) {
  Time time;
  map < int , int > maping;
  map < int , int > temp;

  int s1, s2, t1, t2;
  int i=1;
  
  while (cin >> s1 >> s2 >> t1 >> t2) {
    if (!(temp[s1]==1 || temp[s2]==1)) {
      if (maping[s1]) {
	if (maping[s2]) {
	  cout << maping[s1] << " " << maping[s2] << " " << t1 << " " << t2 << endl;
	}
	else { 
	  maping[s2]=i;i++;
	  cout << maping[s1] << " " << maping[s2] << " " << t1 << " " << t2 << endl;
	}
      }
      else if (maping[s2]) {
	maping[s1]=i;i++;
	cout << maping[s1] << " " << maping[s2] << " " << t1 << " " << t2 << endl;
      }
      else {
	maping[s1]=i;i++;
	maping[s2]=i;i++;
	cout << maping[s1] << " " << maping[s2] << " " << t1 << " " << t2 << endl;
      }
    }
  }
cerr << i << endl;
  return 0;
}


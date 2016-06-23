#include <iostream>
#include <vector>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[]) {
  srand ( time(NULL) );
  int const n = atoi(argv[1]);
  int T =  atoi(argv[2]);
  int C = atoi(argv[3]);
  int r=0, yes=0;
  vector <int > test;
    for (int j =1; j<=n; j++) {
      for (int k =1; k<=n; k++) {
	if (k>j) {
	  test.resize(0);
	  for (int l=0; l<C; l++) {
	    r=rand() % T;
	    yes=1;
	    for (int m=0; m<test.size(); m++) {
	      if (test[m]==r) {yes=0;}
	    }
	    if (yes) {test.push_back(r);}
	  }
	  for (int m=0; m<test.size(); m++) {
	    cout << j << " " << k << " " << test[m] << " " << test[m] << endl;
	  }
	}
      }
    }
  return 0;
}

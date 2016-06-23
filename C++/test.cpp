#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[]) {
  const int nb=50000;
  int t[nb][nb], h[nb][nb], r[nb][nb], number[nb][nb];
  for (int j=1; j<nb;j++) {
    for (int k=1 ; k<nb; k++) {
      r[j][k]=0;
      t[j][k]=0;
      h[j][k]=0;
      number[j][k]=0;
      r[j][k]=0;
    }
  }
  return 0;
}

#include <iostream>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <cmath>

using namespace std;

const int nb=42000;
static char tableau[nb][nb];

int main(int argc, char *argv[]) {
 
  
  for (int i = 0; i<nb; i++) {
    for (int j = 0; j<nb; j++) {
      tableau[i][j]='1';
    }
  }

  return 0;
}

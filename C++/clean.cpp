#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

struct Path
{
  int s; int w; int h; int c;
};

struct Result
{
  int time; int hops;
};

int main(int argc, char *argv[]) {
  std::fstream fs;
  fs.open ("test", std::fstream::in | std::fstream::out | std::fstream::app);

  //Buffer d'entree
  int s1,temp, s2, t1, v;
  int maxp=0; 
  vector <int> deleted;

  map <int, int > know; 
  map <int, int > maping;
  int t2,i=1;
  while (fs >> temp) {
    know[temp]=1;
  }

  //RECUPERATION DES DONNEES
  while (cin >> s1 >> s2 >> t1 >> t2) {
    
  }

  fs.close();

  return 0;
}

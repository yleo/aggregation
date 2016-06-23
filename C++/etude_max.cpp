#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Result
{
  unsigned short int time; 
  unsigned short int hops;
};

struct Arete
{
  unsigned short int u;
  unsigned short int v;
};

struct Step
{
  unsigned short int node; 
  unsigned short int time;
};

int main(int argc, char *argv[]) {
  int oriented=0;
  if (argc==2) {oriented=1;}
  int s1, s2, t1, T; //Buffer d'entree
  int maxt=0, maxp=0;
  int maxi[10];
  Arete arr;
  int nombre1=0, nombre2=0, nombre=0;
  map <int, vector < Arete > > Graph; // stockage du graphe
  int Max[50000];
  while (cin >> t1 >> s1 >> s2) {
    if (t1>maxt) {maxt=t1;}
    if (s1>maxp) {maxp=s1;}
    if (s2>maxp) {maxp=s2;}
    if (t1>Max[s1]) {Max[s1]=t1;}
    if (t1>Max[s2]) {Max[s2]=t1;}
    if (!Graph[t1].size()) {Graph[t1]=vector<Arete>();}
    arr.u=s2;
    arr.v=s1;
    Graph[t1].push_back(arr);
    if (!oriented) {
      arr.u=s1;
      arr.v=s2;
      Graph[t1].push_back(arr);
    }
  }
  for (int i = 0; i<maxp+1; i++) {
    cout << i << " " << Max[i] << endl;
  }
  
  cerr << nombre << " " << nombre1 << endl;
  return 0;
}

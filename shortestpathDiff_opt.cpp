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
  int time; int hops; int number;
};

struct Arete
{
  int u; int v;
};

struct Step
{
  int node; int time; int number;
};

int main(int argc, char *argv[]) {
  int oriented=0;
  if (argc==2) {oriented=1;cerr << "orienter !" << endl;}
  int s1, s2, t1, T; //Buffer d'entree
  int maxt=0, maxp=0;
  int maxi[10];
  Arete arr;
  int nombre1=0, nombre2=0, nombre=0;
  map <int, vector < Arete > > Graph; // stockage du graphe
  vector < int > Max;
  Max.resize(100000);
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

  const int nb = maxp+1;
  const int n = maxt+1;
  
  vector < vector <Result > > before;
  before.resize(nb);
  int temp;
  for (int k=1; k<nb; k++) {before[k].resize(nb);}
  Result result;
  int no_path=100000000;
  for (int k = 1; k<nb; k++) {	
    for (int i = 1; i<nb; i++) {
      before[k][i].time=no_path;
      before[k][i].hops=no_path;
      before[k][i].number=no_path;
    }
  }

  int s;
  int progress=0, autre;
  Step step;
  vector < vector < int > > t, h, r, number;
  r.resize(nb);t.resize(nb);h.resize(nb);number.resize(nb);
  for (int j=1; j<nb;j++) {
    r[j].resize(nb);
    t[j].resize(nb);
    h[j].resize(nb);
    number[j].resize(nb);
  }

  int old_i=0, i=0, delay=0;
  for (std::map <int, vector<Arete > >::iterator it=Graph.begin(); it!=Graph.end(); ++it) {
    i = it->first;
    delay=i-old_i; 
    for (int j=1; j<nb;j++) {
      for (int k=1 ; k<nb; k++) {
	nombre++;
	if (before[j][k].time!=no_path) {
	  t[j][k]=before[j][k].time+delay;
	} 
	else {
	  t[j][k]=before[j][k].time;
	}
	h[j][k]=before[j][k].hops;
	number[j][k]=before[j][k].number;
      }
    }
    
    for (int k = 0; k<Graph[i].size(); k++) {
      int j=Graph[i][k].u;
      s=Graph[i][k].v;
      t[j][s]=1;
      h[j][s]=1;
      r[j][s]=1;
      number[j][s]=1;
      for (int l = 1; l<nb; l++) {
	if (l!=j) {
	  if (before[s][l].time<no_path and (before[s][l].time+delay<t[j][l] or (before[s][l].time+delay==t[j][l] and before[s][l].hops+1 < h[j][l]))) {
	    t[j][l]=before[s][l].time+delay;
	    h[j][l]=before[s][l].hops+1;
	    number[j][l]=before[s][l].number;
	    r[j][l]=1;
	  } 
	  else if (before[s][l].time+delay==t[j][l] and before[s][l].hops+1 == h[j][l]) {
	    number[j][l]+=before[s][l].number;
	  } 
	}
      }
    }
    for (int j = 1; j<nb;j++) {
      for (int k = 1; k<nb; k++) {
	if (j!=k) {
	  if (r[j][k]==1) {
	    nombre1++;
	    if (i<=Max[j] and i<=Max[k]) {cout << i << " " << j << " " << k << " " << t[j][k] << " " << h[j][k] << " " << number[j][k] << endl;}
	  }
	}
      }
    }
    for (int j = 1; j<nb;j++) {
      for (int k=1; k<nb; k++) {
	if (j!=k) {
	  before[j][k].time = t[j][k];
	  before[j][k].hops = h[j][k];
	  before[j][k].number = number[j][k];
	  if (before[j][k].time<no_path) {r[j][k]=2;}
	}
      }   
    }
    old_i=i;
  }
  cerr << nombre << " " << nombre1 << endl;
  return 0;
}

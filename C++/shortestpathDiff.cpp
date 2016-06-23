#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Result
{
  int time; int hops; int number;
};

struct Step
{
  int node; int time; int number;
};

int main(int argc, char *argv[]) {
  int s1, s2, t1, T; //Buffer d'entree
  int maxt=0, maxp=0;
  int maxi[10];
  int nombre1=0, nombre2=0, nombre=0;
  vector <vector <vector < int > > > Graph; // stockage du graphe
  vector < int > Max;
  Max.resize(1000);
  cerr << "ok" << endl;
  //RECUPERATION DES DONNEES
  while (cin >> t1 >> s1 >> s2) {
    if (t1>maxt) {maxt=t1;}
    if (s1>maxp) {maxp=s1;}
    if (s2>maxp) {maxp=s2;}
    Graph.resize(maxt+1);
    Graph[t1].resize(maxp+1);
    Graph[t1][s1].push_back(s2);
    Graph[t1][s2].push_back(s1);
    if (t1>Max[s1]) {Max[s1]=t1;}
    if (t1>Max[s2]) {Max[s2]=t1;}
  }
  const int nb = maxp+1;
  const int n = maxt+1;
  
  for (int i = 0; i < n; i++) {
    Graph[i].resize(nb);
  }
  vector <Result > before[nb];
  int temp;
  for (int k=1; k<nb; k++) {before[k].resize(nb);}
  Result result;
  int no_path=1000000;
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
  int t[nb][nb], h[nb][nb], r[nb][nb], number[nb][nb];
   for (int j=1; j<nb;j++) {
      for (int k=1 ; k<nb; k++) {
	r[j][k]=0;
      }
   }
  for (int i=0; i<n; i++) {
    for (int j=1; j<nb;j++) {
      for (int k=1 ; k<nb; k++) {
	nombre++;
	if (before[j][k].time!=no_path) {
	  t[j][k]=before[j][k].time+1;
	} 
	else {
	  t[j][k]=before[j][k].time;
	}
	h[j][k]=before[j][k].hops;
	number[j][k]=before[j][k].number;
      }
      for (int k = 0; k<Graph[i][j].size(); k++) {
	s=Graph[i][j][k];
	t[j][s]=1;
	h[j][s]=1;
	r[j][s]=1;
	number[j][s]=1;
	for (int l = 1; l<nb; l++) {
	  if (l!=j) {
	    if (before[s][l].time<no_path and (before[s][l].time+1<t[j][l] or (before[s][l].time+1==t[j][l] and before[s][l].hops+1 < h[j][l]))) {
	      t[j][l]=before[s][l].time+1;
	      h[j][l]=before[s][l].hops+1;
	      number[j][l]=before[s][l].number;
	      r[j][l]=1;
	    } 
	    else if (before[s][l].time+1==t[j][l] and before[s][l].hops+1 == h[j][l]) {
	      number[j][l]+=before[s][l].number;
	    } 
	  }
	}
      }
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
  }
  cerr << nombre << " " << nombre1 << endl;
  return 0;
}

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
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
  

  //Buffer d'entree
  int s1, s2, t1, v;
  int maxp=0; 
  vector <vector < int > > Graph; // stockage du graphe
  vector <int > flag;
  queue <int > Q;
  //RECUPERATION DES DONNEES
  while (cin >> t1 >> s1 >> s2) {
    if (s1>maxp) {maxp=s1;}
    if (s2>maxp) {maxp=s2;}
    Graph.resize(maxp+1);
    Graph[s1].push_back(s2);
    //Graph[s2].push_back(s1);
  }

  flag.resize(maxp+1);

  Q.push(62);
  while(!Q.empty()){
    v=Q.front();
    Q.pop();
    if (!flag[v]) {
      flag[v]=1;
      for (int i =1; i<Graph[v].size(); i++) {
	if (!flag[Graph[v][i]]) {Q.push(Graph[v][i]);}
      }
    }
  }
  int vrai =0;
  for (int i =1; i<flag.size(); i++ ) {
    if (!flag[i]) {vrai++; cout << i << endl;}
  }
  cerr << endl << vrai << endl;
  
  return 0;
}

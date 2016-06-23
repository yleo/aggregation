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
  if (argc != 3) {cerr << "ERROR : not good number of arguments" << endl;return 0;}
  int option=0;
  char* o = argv[1];
  Arete arr, buf;
  if (o[1]=='g' and o[0]=='-') {option=1;}
  else if (o[1]=='t' and o[0]=='-') {option=2;}
  else {cerr << "ERROR : choose option -t or -g" << endl;}
  if (option==0) {return 0;}
  else {
    int s1, s2, t1, t2;
    map < int, vector < Arete > > Graph;
    int maxT=0, minT = 500000, maxN=0; //  274882 102543 
   //RECUPERATION DES DONNEES
    while (cin >> s1 >> s2 >> t1 >> t2) {
      if (s1 > maxN) {maxN=s1;}
      if (s2 > maxN) {maxN=s2;}
      if (t1<minT) {minT=t1;}
      if (t2>maxT) {maxT=t2;}
      arr.u=s1;
      arr.v=s2;
      for (int i = t1; i<=t2; i++) {
	if (!Graph[i].size()) {Graph[i]=vector<Arete>();}
	Graph[i].push_back(arr);
      }
    }
    int a=0;
    minT=0;
    if (option==1) {a = atoi(argv[2]);}
    else if (option==2) {if (atoi(argv[2])<1) {cerr << "ERROR : Agregation value is too small" << endl;return 0;} a = (maxT-minT+1)/atoi(argv[2]);}
    const int x = a;
    if (x>maxT-minT+1) {if (option==1) {cerr << "ERROR : Agregation graph value is too big" << endl;} else {cerr << "ERROR : Agregation time value is too small" << endl;} return 0;}
    else if (x<1) {if (option==1) {cerr << "ERROR : Agregation graph value is too small" << endl;} else {cerr << "ERROR : Agregation time value is too big" << endl;} return 0;}
    const int nb = maxN+1;
    cerr << "Number of Graphs : " << x << endl;
    cerr << "Option ";
    if (option==1) {cerr<< "-g ";} else {cerr << "-t " << (maxT-minT+1)/a << " " ;}
    cerr << "with " << x << " graphs and " << maxN << " vertex" <<endl;
    //CONSTRUCTION DES GRAPHES AGREGES
    vector < int > intervalle;
    intervalle.resize(x+1);
    int n = (int) (maxT-minT+1)/x;
    int p = (maxT-minT+1)-n*x;
    intervalle[0]=0;
    for (int i = 1; i <= x; i++) {if (i<=p) {intervalle[i]=i*(n+1);} else {intervalle[i]=i*n+p;}}
    map <int, map <int,vector < int > > > Agregation;
    int ind_it=0;
    
    int cond = 0, write = 0;
    vector < Arete > buffer_edges;
    for (std::map <int, vector<Arete > >::iterator it=Graph.begin(); it!=Graph.end(); ++it) {
      cond=0;
      if ((it->first) >= intervalle[ind_it+1]) {
	buffer_edges.resize(0);
	while ((it->first) >= intervalle[ind_it+1] and ind_it<x) {
	  if (ind_it<x) {ind_it++;}
	}
      }
      for (int i = 0; i<Graph[it->first].size(); i++) {
	arr=Graph[it->first][i];
	write = 1;
	for (int j = 0; j<buffer_edges.size(); j++) {
	  if (buffer_edges[j].u==arr.u && buffer_edges[j].v==arr.v) {write=0;}
	}
	if (write) {
	  buffer_edges.push_back(arr);
	  cout << ind_it << " " << arr.u << " " << arr.v << endl;
	}
      }
    }
    return 0;
  }
}

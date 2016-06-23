#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Result
{
  int time; unsigned short int hops;
};

struct Arete
{
  unsigned short int u; unsigned short int v;
};

struct Step
{
  unsigned short int node; int time;
};

int main(int argc, char *argv[]) {
  int oriented=0;
  if (argc==2) {oriented=1;cerr << "orienter !" << endl;}
  unsigned short int s1, s2;
  int t1, T; //Buffer d'entree
  int maxt=0, maxp=0;
  int maxi[10];
  Arete arr;
  int nombre1=0, nombre2=0, nombre=0;
  map <int, vector < Arete > > Graph; // stockage du graphe
  vector < int > Max;
  Max.resize(100000);
  for (int i = 0; i<100000; i++) {Max[i]=0;}
  while (cin >> t1 >> s1 >> s2) {
    if (t1>maxt) {maxt=t1;}
    if (s1>maxp) {maxp=s1;}
    if (s2>maxp) {maxp=s2;}
    if (t1>Max[s1]) {Max[s1]=t1;}
    if (t1>Max[s2]) {Max[s2]=t1;}
    if (!Graph[t1].size()) {Graph[t1]=vector<Arete>();}
    if (!oriented) {
      arr.u=s1;
      arr.v=s2;
      Graph[t1].push_back(arr);
    }
    arr.u=s2;
    arr.v=s1;
    Graph[t1].push_back(arr);
  }
  const int nb = maxp+1;
  const int n = maxt+1;

  vector < vector < vector < vector < Step  > > > > Paths;
  vector < vector < vector < vector < Step  > > > > OldPaths;
  vector < vector < vector < vector < Step  > > > > Temp;
  vector < vector < vector < short int > > > Passage;
  Paths.resize(nb);OldPaths.resize(nb);Temp.resize(nb);Passage.resize(nb);
  int ind;
  unsigned short int temp;
  for (int k=1; k<nb; k++) {Paths[k].resize(nb);OldPaths[k].resize(nb);Temp[k].resize(nb);Passage[k].resize(nb);}
  for (int k1=1; k1<nb; k1++) {
    for (int k2=1; k2<nb; k2++) {
      Paths[k1][k2].resize(1);
      OldPaths[k1][k2].resize(1);
    }
  }
  

  vector < vector <Result > > before;
  before.resize(nb);
  for (int k=1; k<nb; k++) {before[k].resize(nb);}
  Result result;
  int no_path=100000000;
  unsigned short int no_path_1 = 65530;
  for (int k = 1; k<nb; k++) {	
    for (int i = 1; i<nb; i++) {
      before[k][i].time=no_path;
      before[k][i].hops=no_path_1;
    }
  }

  int s;
  int progress=0, autre;
  Step step;
  vector < vector < int > > t, taille;
  vector < vector < unsigned short int > > r, h;
  r.resize(nb);t.resize(nb);h.resize(nb);taille.resize(nb);
  for (int j=1; j<nb;j++) {
    r[j].resize(nb);
    t[j].resize(nb);
    h[j].resize(nb);
    taille[j].resize(nb);
  }

  int old_i=-1, i=0, delay=0;
  for (std::map <int, vector<Arete > >::iterator it=Graph.begin(); it!=Graph.end(); ++it) {
    i = it->first;
    delay=i-old_i;
    for (int j=1; j<nb;j++) {
      for (int k=1 ; k<nb; k++) {
	if (Max[j]>=i and Max[k]>=i) {
	  nombre++;
	  if (before[j][k].time!=no_path) {
	    t[j][k]=before[j][k].time+delay;
	  } 
	  else {
	    t[j][k]=before[j][k].time;
	  }
	  h[j][k]=before[j][k].hops;
	}
      }
    }
    for (int k = 0; k<Graph[i].size(); k++) {
      int j = Graph[i][k].u;
      s = Graph[i][k].v;
      t[j][s]=1;
      h[j][s]=1;
      r[j][s]=1;
      step.node=s;
      step.time=1;
      Passage[j][s].resize(0);
      Paths[j][s].resize(1);
      Paths[j][s][0].resize(0);
      Paths[j][s][0].push_back(step);
      for (int l = 1; l<nb; l++) {
	if (l!=j and Max[l]>=i) {
	  if (before[s][l].time<no_path and (before[s][l].time+delay<t[j][l] or (before[s][l].time+delay==t[j][l] and before[s][l].hops+1 < h[j][l]))) {
	    t[j][l]=before[s][l].time+delay;
	    h[j][l]=before[s][l].hops+1;
	    Passage[j][l].resize(0);
	    Passage[j][l].push_back(s);
	    r[j][l]=1;
	  } 
	  else if (before[s][l].time+delay==t[j][l] and before[s][l].hops+1 == h[j][l]) {
	    Passage[j][l].push_back(s);
	  }
	}
      }
    }
    for (int j = 1; j<nb; j++) {
      for (int k = 1; k<nb; k++) {
	if (j!=k and Max[j]>=i and Max[k]>=i) {
	  if (r[j][k]) {  
	    Temp[j][k].resize(0);
	    taille[j][k]=0;
	    ind=0;
	    if (r[j][k]==1) {
	      nombre1++;
	      for (int i1=0; i1<Passage[j][k].size(); i1++) {
		temp = Passage[j][k][i1];
		taille[j][k]+=OldPaths[temp][k].size();
	      }
	      if (!Passage[j][k].size()) {
		taille[j][k]=1;
	      }
	      if (t[j][k]>maxi[0]) {maxi[0]=t[j][k];maxi[1]=i;maxi[2]=j;maxi[3]=k;}
	      if (i<=Max[j] and i<=Max[k] and t[j][k]>1) {cout << taille[j][k] << " " << i << " " << j << " " << k << " " << t[j][k] << " " << h[j][k] << " " << 0;}
	      
	      if (!Passage[j][k].size()) {
		for (int i2=0; i2<Paths[j][k].size(); i2++) {
		  Temp[j][k].resize(1);
		  Temp[j][k][0].resize(0);
		  Temp[j][k][0].push_back(Paths[j][k][0][0]);
		  if (i<=Max[j] and i<=Max[k] and t[j][k]>1) {
		    cout << " " << 1 << " " << Paths[j][k][0][0].node << " " << Paths[j][k][0][0].time;
		  }
		}
	      }
	      
	      else {
		Temp[j][k].resize(taille[j][k]);
		if (!Passage[j][k].size()) {}
		for (int i1=0; i1<Passage[j][k].size(); i1++) {
		  temp = Passage[j][k][i1];
		  for (int i2=0; i2<OldPaths[temp][k].size(); i2++) {
		    if (i<=Max[j] and i<=Max[k] and t[j][k]>1) {cout << " " << OldPaths[temp][k].size()+1 << " "<< temp << " 1";}		    	    
		    step.node=temp;
		    step.time=1;
		    
		    Temp[j][k][ind].push_back(step);
		    
		    for (int i3=OldPaths[temp][k][i2].size()-1; i3>=0; i3--) {
		      step.node=OldPaths[temp][k][i2][i3].node;
		      step.time=OldPaths[temp][k][i2][i3].time;
		      Temp[j][k][ind].push_back(step);
		      if (i<=Max[j] and i<=Max[k] and t[j][k]>1) {
			if (i3==OldPaths[temp][k][i2].size()-1) {cout << " " << step.node << " " << step.time+delay-1;}
			else {cout << " " << step.node << " " << step.time;}
		      }
		    }
		    ind++;
		  }
		}
	      }
	      if (i<=Max[j] and i<=Max[k] and t[j][k]>1) {cout << endl;}
	    }
	    else if (r[j][k]==2) {
	      nombre2++;
	      taille[j][k]=Paths[j][k].size();
	      Temp[j][k].resize(taille[j][k]);
	      for (int i2=0; i2<Paths[j][k].size(); i2++) {
		for (int i3=Paths[j][k][i2].size()-1; i3>=0; i3--) {
		  if (i3==Paths[j][k][i2].size()-1) {
		    step.time=Paths[j][k][i2][i3].time+delay;
		  }
		  else {
		    step.time=Paths[j][k][i2][i3].time;
		  }
		  step.node=Paths[j][k][i2][i3].node;
		  Temp[j][k][i2].push_back(step);
		}
	      }
	    }
	  }
	}//comp   
      }//k
    }//j
    for (int j = 1; j<nb;j++) {
      	if (Max[j]<i) {
	  Paths[j].resize(0);OldPaths[j].resize(0);t[j].resize(0);h[j].resize(0);taille[j].resize(0);r[j].resize(0);
	  for (int k=1; k<nb; k++) {
	    if (Max[k]>=i) {Paths[k][j].resize(0);OldPaths[k][j].resize(0);}
	  }
	}
      for (int k=1; k<nb; k++) {
	if (j!=k and Max[j]>=i and Max[k]>=i) {
	  before[j][k].time = t[j][k];
	  before[j][k].hops = h[j][k];
	  if (before[j][k].time<no_path) {r[j][k]=2;}
	  Paths[j][k].resize(0);
	  Paths[j][k].resize(taille[j][k]);
	  OldPaths[j][k].resize(0);
	  OldPaths[j][k].resize(taille[j][k]);
	  for (int i2=0; i2<Temp[j][k].size(); i2++) {
	    for (int i3=Temp[j][k][i2].size()-1; i3>=0; i3--) {
	      step.node=Temp[j][k][i2][i3].node;
	      step.time=Temp[j][k][i2][i3].time;
	      Paths[j][k][i2].push_back(step);
	      OldPaths[j][k][i2].push_back(step);
	    }
	  }
	}
      }
    }
    old_i=i;
  }//i
  cerr << nombre << " " << nombre1 << " " << nombre2 << endl;
  return 0;
}

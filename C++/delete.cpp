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
  int s1, s2, t1, t2, temp;
  map <int, int > know; 
  map <int, int > maping;
  int i=1;

  while (fs >> temp) {
    know[temp]=1;
   
  }

  //RECUPERATION DES DONNEES
  while (cin >> s1 >> s2 >> t1 >> t2) {
    
    if (know[s1]!=1 and know[s2]!=1) {
      
      if (maping[s1]) {
	if (maping[s2]) {
	  cout << maping[s1] << " " << maping[s2] << " " << t1 << " " << t2 << endl;
	}
	else { 
	  maping[s2]=i;
	  i++;
	  cout << maping[s1] << " " << maping[s2] << " " << t1 << " " << t2 << endl;
     
	}
      }
      else if (maping[s2]) {
	maping[s1]=i;i++;
	cout << maping[s1] << " " << maping[s2] << " " << t1 << " " << t2 << endl;
      }
      else {
	maping[s1]=i;
	i++;
	maping[s2]=i;
	i++;
	cout << maping[s1] << " " << maping[s2] << " " << t1 << " " << t2 << endl;
      }
    }
  }
  cerr << i << endl;
  fs.close();

  return 0;
}

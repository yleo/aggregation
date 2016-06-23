#include <iostream>
#include <map>

using namespace std;

struct Arete
{
  int u; int v;
};

int main(int argc, char *argv[]) {
  
  int s1, s2, t1, cond;
  map < int, int > density;
  
  while (cin >> t1 >> s1 >> s2) {
    density[t1]++;
  }

  int ind=0;
  for (std::map <int,int>::iterator it=density.begin(); it!=density.end(); ++it) {
    for (int i = ind; i<it->first; i++) {
      cout << i << " 0" << endl;
    }
    cout << it->first << " " << density[it->first] << endl;
    ind=(it->first)+1;
  }

  return 0;
}

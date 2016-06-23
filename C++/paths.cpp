#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  
  int np, td, s1, s2, h, t, n;
  int p, Dt, time, s, s_current;
  
  while (cin >> np >> td >> s1 >> s2 >> t >> h >> n) {
    time=td;
    for (int i =0; i<np; i++) {
      cin >> p >> s >> Dt;
      time-=Dt;
      for (int j=0; j<h-1; j++) {
	cin >> s_current >> Dt;
	time-=Dt;
	cout << s << " " << s_current << " " << time << " " << Dt << endl;
	s=s_current;
      }      
    }
  }
  return 0;
}
// np td s1 s2 t h n p s1 p1 s2 p2

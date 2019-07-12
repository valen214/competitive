

/** test cases:

8 1 3
2
2 1 1
1
8 3 5
1 3 4
4 5 1
1 2 3 4 5
8 5 4
1 2 3 4 5
7 2 5
2 3
7 2 6
2 3
7 3 3
2 2 2
8 3 2
2 2 2
8 3 2
3 4 5


*/

#include <iostream>
#include <cmath> // floor, ceil

using namespace std;

int main(int argc, char **argv){
	int m, n, t;
	while(cin >> m >> n >> t){
		double p = m; // remaining (complete)
		double q; // being used temporary
		double eaten = 0; // eaten wholely
		int *c = new int[n];
		for(int i = 0; i < n; ++i){
			cin >> c[i];
			q = static_cast<double>(c[i]);
			p -= ceil(t / q);
			eaten += floor(t / q);
		}
		
		
		n = n + p;
		if(eaten > m){
			q = 0;
			p = 0;
		} else if(p < 0){
			/*
			negative p means they eat too much
			and most likely some cats are not getting fishes
			
			the abs(p) is the number of cats
			not getting fish at time = t;
			
			m = p + eaten + q
			*/
			// I don't know why -1 but so far correct
			q = m - (eaten + p) - 1;
			p = 0;
		} else{
			q = m - p - eaten;
		}
		
		cout << p << " " << q << endl;
	}
}
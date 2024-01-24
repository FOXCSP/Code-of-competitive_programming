#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int Q[9][9], n, m, M[9][9], T, a[100];
double MM[9][9];
int ans[9][9];

double A(int x) {
	if (x != 0) return 1.;
	else return sqrt(1./2);
}

double pi = acos(-1.);
double COS(double i, double u) {
	return cos(pi/8.*(0.5+i)*u);
}
double turn(int x, int y) {
	double res = 0;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			res += A(i) * A(j) * (1.0 * M[i][j]) * COS(x, i) * COS(y, j);
	return res/4.; 
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++)
      cin >> Q[i][j];

  cin >> n;
  
  cin >> T;
  
  int x = 0, y = 0, t = 1;
	for (int i = 1; i <= n; i++) {
  	cin >> a[i];
  	
		M[x][y] = a[i];
		
		if ((x == 0 || y == 7) && t == 1){ 
			if (y + 1 < 8) y++, t = 0;
			else x++, t = 0;
		}
		else if ((y == 0 || x == 7) && t == 0) {
			if (x + 1 < 8) x++, t = 1;
			else y++, t = 1;
		}
		else {
			if (t == 0) y--, x++;
			if (t == 1) x--, y++;
		}
		
	} 
  
  if (T == 0) {
	for (int i = 0; i < 8; i++)
  	for (int j = 0; j < 8; j++)
  		cout << M[i][j] << " \n"[j == 7];
		return 0;
	}

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			M[i][j] *= Q[i][j];
	
	if (T == 1) {
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				cout << M[i][j] << " \n"[j == 7]; 
		return 0;
	}
	
	
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			MM[i][j] = turn(i, j);
	
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			MM[i][j] = (int)(MM[i][j] + 128. + 0.5);

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			ans[i][j] = max(0, min(255, (int)MM[i][j]));
	
	if (T == 2) {
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				cout << ans[i][j] << " \n"[j == 7];
	}	

  return 0;
}

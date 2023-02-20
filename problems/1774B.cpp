#include<iostream>
#include<string>

using namespace std;

int pick(int * count, int same, int m){
	int color = 0;
	while(color < m && (count[color]==0 || color == same) ) color++;
	if(color<m) count[color]--;
	return color;
}

bool check(int * positions, int k, int i){
	int past = positions[0];
	int count = 1;
	for(int j=2;j<=i;j++){
		if(positions[j]==past) count++;
		else                   count=1;
		if(count>k) return false;
		past = positions[j];
	}
	return true;
}

int main(){
	int testcase, n, m, k, i;
	int p[1000000000];
	int c[100000];
	cin >> testcase;
	for(int a_case = 0;a_case < testcase;a_case++){
		cin >> n >> m >> k;
		for(int j=0;j<n;j++) p[j]=m;
		i = 0;
		while(i<n){
			p[i] = pick(c, p[i], m);
			if(check(p, k, i)) i++;
			else{
				while((p[i] = pick(c, p[i], m))==m);
			}
		}
	}
	return 0;
}

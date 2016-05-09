#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<sstream>
using namespace std;
int a[30],i,bot=0;
bool first=true;
bool check(int si){
	for (int j = 0; j < si; j++) {
		if (j == si - 1) return true;
		if (a[j] > a[j + 1]) return false;
	}return true;
}
void flap() {
	int k=0,buf[30],max=0;//i-no.k
	for (int j = 0; j < i; j++) {
		if (a[j] > max) { 
			k = j + 1;
			max = a[j]; 
		}
	}//k=max
	if (first) first = false;
	else cout << ' ';
	bool is_top = false;
	if (k == 1) { is_top = true; k = i; }
	cout <<i - k+ bot+1;
	for (int j = 0; j < k; j++) 
		buf[j] = a[k - 1 - j];
	for (int j = 0; j < k; j++)
		a[j] = buf[j]; 
	if (is_top) {i--; bot++;}
}
int main() {
	string s;
	while (getline(cin, s)) {
		memset(a, 0, sizeof(a));
		stringstream ss(s);
		i = 0; bot = 0;
		first = true;
		bool pfirst = true;

		while (ss >> a[i++]) {
			if (pfirst) pfirst = false;
			else cout << ' ';
			cout<<a[i - 1];
		};
		cout << endl;
		i--;
		// i = bottom+1
		int si = i;
		while (!check(si)) flap();
		if (!first) cout << ' ';
		cout << "0" << endl;
	}
	//system("PAUSE");
	return 0;
}
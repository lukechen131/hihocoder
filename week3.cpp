#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define MAXPLEN 10005
#define MAXSLEN 1000005

int _next [MAXPLEN] = {-1}; // -1 is used when index<0, so there are no prefix matched, _next[i] = index + 1 = 0;
char p[MAXPLEN];
char s[MAXSLEN];
int s_len;
int p_len;

void calculate(char* p)
{
	for(unsigned int i(1); i<=p_len; ++i){  // use one extra number to store _next at p_len;
		int index = _next[i-1];
		while(true){
			if(index < 0 || p[i-1] == p[index]){
				_next[i] = index + 1;
				break;
			}
			else {
				index = _next[index]; // recursively reduce the prefix length, until index reaches -1;
			}
		}
	}
}

int KMP(char* s, char* p)
{
	int count = 0;
	calculate(p); // calculate the _next array.
	int i=0, j=0;
	while(true){
		if(s[i] == p[j]){
			i++; 
			j++;
		} 
		else {
			if(j == 0){
				i++;
			}
			else{
				j = _next[j];
			}
		}

		if(j == p_len){
			count++;
			/*
				Be careful here. 
				Using the extra number in _next, we can move p instead of s in the next run. 
				Do not use: 			
				j = 0;
				i = i - p_len + 1;
			*/
			j = _next[j];  
		}
		if(i > s_len)
			return count;
	}
}


int main()
{
	int N;
	cin >> N;
	// string p;	// pattern
	// string s;	// string

	
	while(N--){
		cin >> p;
		cin >> s;
		s_len = strlen(s);
		p_len = strlen(p);
		cout << KMP(s,p) << endl;
	}

	// string s("BCBCBDB"), p("BCB");
	// cout << KMP(s, p) << endl;
	// return 0;
}
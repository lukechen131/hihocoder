#include <iostream>
using namespace std;
string pre_order, mid_order;

void print_post_order(unsigned int pre_start, unsigned int mid_start, unsigned int len)
{
	// special cases when len == 1 or len == 0; 
	// recursion stops.
	if(len==0)
		return;
	if(len==1){
		cout << pre_order[pre_start];
		return;
	}

	unsigned int i;
	char c = pre_order[pre_start]; 			// first char of the substring of pre_order string.
	for(i=mid_start; mid_order[i]!=c; ++i);
		; 

	// divide the problem into smaller sub-problems.
	print_post_order(pre_start+1, mid_start, i-mid_start);
	print_post_order(pre_start+i-mid_start+1, i+1, len-(i-mid_start+1));
	cout << c;
}

int main()
{
	cin >> pre_order >> mid_order;
	print_post_order(0, 0, pre_order.size());
	cout << endl;
}
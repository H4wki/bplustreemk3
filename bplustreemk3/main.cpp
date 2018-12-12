#include "bplustreemk3.h"
#include <iostream>
#include <vector>
using namespace std;


int main() {

	bplustreemk3 t1;
	cout << "Insert Success " << t1.insert(3) << endl;
	t1.toString();
	cout << "Insert Success " << t1.insert(5) << endl;
	t1.toString();
	cout << "Insert Success " << t1.insert(4) << endl;

	t1.toString();
	return 1;
}
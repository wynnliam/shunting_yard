// Liam Wynn, 2/26/2018

#include <iostream>
#include "token_queue.h"

using namespace std;

int main() {
	token_queue tq;

	tq.insert("3");
	tq.insert("+");
	tq.insert("4");

	return 0;
}

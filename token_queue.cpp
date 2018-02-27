// Liam Wynn, 2/26/2018

#include "token_queue.h"
#include <iostream>
#include <cstring>

using namespace std;

token_queue::token_queue() {
	rear = NULL;
}

token_queue::~token_queue() {
	// TODO: Finish me!
}

void token_queue::insert(const char* token) {
	if(!token) {
		return;
	}

	token_node* temp = new token_node;
	temp->token = new char[strlen(token) + 1];
	strcpy(temp->token, token);

	if(!rear) {
		temp->next = temp;
		rear = temp;
	}

	else {
		temp->next = rear->next;
		rear->next = temp;
		rear = temp;
	}
}

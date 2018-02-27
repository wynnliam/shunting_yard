// Liam Wynn, 2/26/2018

#include <iostream>
#include <cstring>
#include "token_queue.h"

using namespace std;

const char* symbols = "+-*/()";
const char* digits = "0123456789";

// Returns a string without whitespace.
char* remove_white_space(const char*);
// Verifies that a given expression has
// no invalid symbols.
bool verify_symbols(const char*);
// Builds a token queue from an input string.
// Note that input has no whitespace and no invalid
// symbols.
void parse_input(const char*, token_queue&);

int main() {
	char* input = "7 * (3 + 4)   ";
	char* input_no_white_space = remove_white_space(input);
	token_queue tq;

	if(verify_symbols(input_no_white_space))
		cout << "ACCEPT" << endl;
	else {
		cout << "REJECT" << endl;

		delete[] input_no_white_space;
		input_no_white_space = NULL;

		return 0;
	}

	parse_input(input_no_white_space, tq);
	tq.display();

	delete[] input_no_white_space;
	input_no_white_space = NULL;

	return 0;
}

char* remove_white_space(const char* input) {
	if(!input)
		return NULL;

	int input_len = strlen(input);
	int output_len = input_len;
	char* output;
	int curr_out_index = 0;

	for(int i = 0; i < input_len; ++i) {
		if(isspace(input[i]))
			--output_len;
	}

	output = new char[output_len + 1];

	for(int i = 0; i < input_len; ++i) {
		if(!isspace(input[i])) {
			output[curr_out_index] = input[i];
			++curr_out_index;
		}
	}

	return output;
}

bool verify_symbols(const char* exp) {
	if(!exp)
		return false;

	int exp_len = strlen(exp);

	for(int i = 0; i < exp_len; ++i) {
		if(!strchr(symbols, exp[i]) && !strchr(digits, exp[i]))
			return false;
	}

	return true;
}

void parse_input(const char* input, token_queue& out_tokens) {
	if(!input)
		return;

	char curr_token[1000];
	int input_len = strlen(input);
	int curr_token_index = 0;

	for(int i = 0; i < input_len; ++i) {
		if(strchr(symbols, input[i])) {
			curr_token[0] = input[i];
			curr_token[1] = '\0';
			out_tokens.insert(curr_token);
		}

		else {
			curr_token[curr_token_index] = input[i];
			++curr_token_index;

			if(i + 1 >= input_len || strchr(symbols, input[i + 1])) {
				curr_token[curr_token_index] = '\0';
				out_tokens.insert(curr_token);
				curr_token_index = 0;
			}
		}
	}
}

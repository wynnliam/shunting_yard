// Liam Wynn, 2/26/2018

#include <iostream>
#include <cstring>

using namespace std;

char* remove_white_space(const char*);

int main() {
	char* input = "3 + 4";
	char* output = remove_white_space(input);

	cout << output << endl;
	delete[] output;

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

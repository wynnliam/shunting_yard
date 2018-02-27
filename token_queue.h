// Liam Wynn, 2/26/2018

struct token_node {
	char* token;
	token_node* next;
};

class token_queue {
	public:
		token_queue();
		~token_queue();

		void insert(const char* token);

	private:
		token_node* rear;
};

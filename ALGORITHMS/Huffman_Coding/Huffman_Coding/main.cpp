#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <fstream>
#include <sstream>
#include <map>

std::string Data{};
std::map<char, int32_t> Occurencies;

void Load_Data(const std::string& file_name)
{
	std::fstream file;
	file.open(file_name.c_str(), std::ios_base::in);
	std::stringstream buffer;
	buffer << file.rdbuf();
	Data = buffer.str();
}

class HuffmanCodes
{
	struct Node
	{
		char data;
		size_t freq;
		Node* left;
		Node* right;
		Node(char data, size_t freq) : data(data),
			freq(freq),
			left(nullptr),
			right(nullptr)
		{}
		~Node()
		{
			delete left;
			delete right;
		}
	};

	struct compare
	{
		bool operator()(Node* l, Node* r)
		{
			return (l->freq > r->freq);
		}
	};

	Node* top;

	void printCode(Node* root, std::string str)
	{
		if (root == nullptr)
			return;

		if (root->data == '$')
		{
			printCode(root->left, str + "0");
			printCode(root->right, str + "1");
		}
		else if (root->data != '$')
		{
			std::cout << root->data << " : " << str << "\n";
			str = {};
			printCode(root->left, str + "0");
			printCode(root->right, str + "1");
		}
	}

public:
	HuffmanCodes()
	{

	};
	~HuffmanCodes()
	{
		delete top;
	}
	void GenerateCode()
	{
		Node* left;
		Node* right;
		std::priority_queue<Node*, std::vector<Node*>, compare > minHeap;

		for (typename std::string::const_iterator string_iterator = Data.begin(); string_iterator != Data.end(); ++string_iterator)
		{
			Occurencies[*string_iterator]++;
		}

		for (typename std::map<char, int32_t>::const_iterator map_iterator = Occurencies.begin(); map_iterator != Occurencies.end(); ++map_iterator)
		{
			minHeap.push(new Node(map_iterator->first, map_iterator->second));
		}

		while (minHeap.size() != 1)
		{
			left = minHeap.top();
			minHeap.pop();

			right = minHeap.top();
			minHeap.pop();

			top = new Node('$', left->freq + right->freq);
			top->left = left;
			top->right = right;
			minHeap.push(top);
		}
		printCode(minHeap.top(), "");
	}
};

int main()
{
	//Load_Data("file.in");
	std::cout << "$ ";
	std::cin >> Data;
	HuffmanCodes set1;
	set1.GenerateCode();

	std::cin.get();
	return 0;
}
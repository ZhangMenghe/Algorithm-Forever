#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
//able to handle cases when one of the patterns is a prefx of another pattern.
//add "isword" to node
struct edge;

struct node{

public:
	node(int i){
		index = i;
		isword = false;
	}
	int index;
	vector<edge> edges;
	bool isword;
	bool is_leaf(){ return edges.empty(); }
};

struct edge {
public:
	edge(char ch, node* next){
		symbol = ch;
		nextNode = next;
	}
	char symbol;
	node* nextNode;
};


void create_new_edge(char currentSymbol, int &index, node *& currentNode) {
	auto newOne = new node(++index);
	edge e(currentSymbol, newOne);
	currentNode->edges.push_back(e);
	currentNode = newOne;
}
edge * is_there_edge(node *node, char symbol){
	edge* result = nullptr;
	for (int i = 0; i < node->edges.size(); ++i) {
		if (node->edges.at(i).symbol == symbol){
			result = &(node->edges.at(i));
			break;
		}
	}
	return result;
}
node* build_trie(vector<string> & patterns){
	int index = 0;
	node* root = new node(index);
	edge* foundEdge = nullptr;
	for (int i = 0; i < patterns.size(); ++i) {
		node *currentNode = root;
		auto pattern = patterns.at(i);
		for (int j = 0; j < pattern.size(); ++j) {
			char currentSymbol = pattern.at(j);
			if (currentNode->edges.empty()){
				create_new_edge(currentSymbol, index, currentNode);
			}
			else if ((foundEdge = is_there_edge(currentNode, currentSymbol)) != nullptr){
				currentNode = foundEdge->nextNode;
				foundEdge = nullptr;
			}
			else{
				create_new_edge(currentSymbol, index, currentNode);
			}
		}
		currentNode->isword = true;
	}
	return root;
}

void printTrie(node* root){
	if (root == nullptr || root->is_leaf()){
		return;
	}
	for (int i = 0; i < root->edges.size(); ++i) {
		auto edge = root->edges.at(i);
		std::cout << root->index << "->" << edge.nextNode->index << ":" << edge.symbol << "\n";
		printTrie(edge.nextNode);
	}
}
long long prefix_trie_matching(string& text, int startSymbolIndex, node* root){
	node* currentNode = root;
	long long initIndex = startSymbolIndex;
	char currentSymbol = text.at(initIndex);

	edge* foundEdge = nullptr;
	while (true){
		if (currentNode->isword){
			return initIndex;
		}
		else if ((foundEdge = is_there_edge(currentNode, currentSymbol)) != nullptr){
			currentNode = foundEdge->nextNode;
			currentSymbol = (++startSymbolIndex < text.size()) ? text.at(startSymbolIndex) : '\0';
			foundEdge = nullptr;
		}
		else{
			return -1;
		}
	}
}
vector<long long> trie_matching(string& text, node* root){
	vector<long long> results;
	for (long long i = 0; i < text.size(); ++i) {
		auto result = prefix_trie_matching(text, i, root);
		if (result > -1){
			results.push_back(result);
		}
	}
	return results;
}
int main() {
	string text;
	std::cin >> text;

	size_t n;
	std::cin >> n;
	vector<string> patterns;
	for (size_t i = 0; i < n; i++) {
		string s;
		std::cin >> s;
		patterns.push_back(s);
	}

	node* trie = build_trie(patterns);
	auto results = trie_matching(text, trie);

	for (long long i = 0; i < results.size(); ++i) {
		cout << results.at(i) << " ";
	}

	//clean_up(trie);
	//printTrie(trie);

	return 0;
}
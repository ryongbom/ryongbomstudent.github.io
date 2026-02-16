#include "FileManager.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

// save file
void saveToFileHelper(Btree* root, ofstream& file) {
	if (root == nullptr) return;
	
	file << root->data.toFileString() << endl;
	saveToFileHelper(root->left, file);
	saveToFileHelper(root->right, file);
}

void saveToFile(Btree* root, const string& filename) {
	ofstream file(filename);
	if (!file.is_open()) {
		cerr << "Can not open file: " << filename << endl;
		return;
	}
	
	saveToFileHelper(root, file);
	file.close();
}

// load file
Btree* loadFromFile(const string& filename) {
	ifstream file(filename);
	if (!file.is_open()) {
		cerr << "Can not open file: " << filename << endl;
		return nullptr;	
	}
	
	Btree* root = nullptr;
	string line;
	
	while (getline(file, line)) {
		
		if (line.empty()) continue;
		
		stringstream ss(line);
		string token;
		vector<string> tokens;
		
		while (getline(ss, token, ',')) {
			tokens.push_back(token);
		}
		
		if (tokens.size() == 4) {
			string code = tokens[0];
			string name = tokens[1];
			double price = stod(tokens[2]);
			double weight = stod(tokens[3]);
			
			Data newData(code, name, price, weight);
			root = insertNode(root, newData);
		}
	}
	
	file.close();
	return root;
}
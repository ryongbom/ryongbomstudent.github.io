#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <queue>
#include <sstream>
#include <vector>

using namespace std;


struct Data {
    string code;
    string name;
    double price;
    double weight;
    
    Data() : code(""), name(""), price(0.0), weight(0.0) { }
    
    Data(string c, string n, double p, double w) 
		: code(c), name(n), price(p), weight(w) { }
    
    void display() const {
        cout << left << setw(10) << code 
             << setw(20) << name
             << setw(10) << price
             << setw(10) << weight << endl;
    }
    
    string toFileString() const {
    	return code + "," + name + "," + to_string(price) + "," + to_string(weight);
	}
};

struct Btree {
    Data data;
    Btree* left;
    Btree* right;
    
    Btree(const Data& d) : data(d), left(nullptr), right(nullptr) { }
};

// tree operation function
Btree* insertNode(Btree* root, const Data& data);
Btree* deleteNode(Btree* root, const string& code);
Btree* searchNode(Btree* root, const string& code);
void deleteTree(Btree* root);

void inorderTraversal(Btree* root);
void inorderDescending(Btree* root);
void preorderTraversal(Btree* root);
void postorderTraversal(Btree* root);

// functions for menu
void showMenu();
void processConsoleInput(Btree*& root);
void processFileInput(Btree*& root);

// it is my task function
int countAboveAveragePrice(Btree* root);

// utility functions
void calculateSumAndCount(Btree* root, double& sum, int& count);
double calculateAverage(Btree* root);
void countAboveHelper(Btree* root, double average, int& count);

// file input output function
void saveToFile(Btree* root, const string& filename);
void saveToFileHelper(Btree* root, ofstream& file);
Btree* loadFromFile(const string& filename);

int main() {
    Btree* root = nullptr;
    int choice;
    
    do {
        cout << endl;
        showMenu();
        cout << ">> Select an option: ";
        cin >> choice;
        cin.ignore();
        
        switch(choice) {
            case 1:
                processConsoleInput(root);
                break;
            case 2: {
            	string filename;
				cout << "Enter filename to load additional data: ";
				getline(cin, filename);
				
				deleteTree(root);
				root = nullptr;
				
				root = loadFromFile(filename);	
				break;
			}
            case 3:
            	cout << endl;
            	cout << "=== All parts in tree ===" << endl;
            	if (root == nullptr) {
            		cout << "Tree is empty." << endl;
				} else {
					inorderTraversal(root); 
				}
				break;
            case 4: {
            	string code;
				cout << "Enter part code to search: ";
				getline(cin, code);
				
				Btree* found = searchNode(root, code);
				if (found) {
					cout << endl;
					cout << "=== Part found ===" << endl;
					found->data.display();
				} else {
					cout << "Part not found." << endl;
				}
				break;
			}
            case 5: cout << "5" << endl; break;
            case 6: {
            	int count = countAboveAveragePrice(root);
            	cout << "\nResult: " << count << " parts have price above average." << endl;
				break;
			}
            case 7: cout << "7" << endl; break;
            case 8: {
            	if (root == nullptr) {
            		cout << "Tree is empty. Nothing to save." << endl;
				} else {
					string filename;
					cout << "Enter filename to save: ";
					getline(cin, filename);
					saveToFile(root, filename);
					cout << "Tree saved to " << filename << endl;
				}
				break;
			}
            case 9: {
            	string filename;
            	cout << "Enter filename to load: ";
            	getline(cin, filename);
            	
            	deleteTree(root);
            	root = nullptr;
            	root = loadFromFile(filename);
				break;
			}
            case 0: cout << "0" << endl; break;
            default: cout << "Invalid choice! Please try again." << endl; break;
        }
    } while (choice != 0);
    
    return 0;
}

void showMenu() {
    cout << "=== Parts Management System ===" << endl;
    cout << "1. Enter part data from console" << endl;
    cout << "2. Load data from file" << endl;
    cout << "3. Display all parts in tree" << endl;
    cout << "4. Search for a part" << endl;
    cout << "5. Delete a part" << endl;
    cout << "6. Count parts with price above average" << endl;
    cout << "7. Run tests" << endl;
    cout << "8. Save tree to file" << endl;
    cout << "9. Load tree from file" << endl;
    cout << "0. Exit" << endl;
    cout << "================================" << endl;
}

void processConsoleInput(Btree*& root) {
    int n;
    cout << "Enter the number of parts: ";
    cin >> n;
    cin.ignore();
    
    for (int i = 0; i < n; i++) {
        cout << "Part #" << i + 1 << ":" << endl;
        
        string code, name;
        double price, weight;
        
        cout << "Part code: ";
        getline(cin, code);
        
        cout << "Part name: ";
        getline(cin, name);
        
        cout << "Price: ";
        cin >> price;
        
        cout << "Weight: ";
        cin >> weight;
        cin.ignore();
        
        Data newData(code, name, price, weight);
        root = insertNode(root, newData);
    } 
}

Btree* insertNode(Btree* root, const Data& data) {
	if (root == nullptr) {
		return new Btree(data);
	}
	
	if (data.code < root->data.code) {
		root->left = insertNode(root->left, data);
	}
	else if (data.code > root->data.code) {
		root->right = insertNode(root->right, data);
	}
	return root;
}

void inorderTraversal(Btree* root) {
	if (root == nullptr) return ;
	
	inorderTraversal(root->left);
	root->data.display();
	inorderTraversal(root->right);
}

Btree* searchNode(Btree* root, const string& code) {
	if (root == nullptr || root->data.code == code) {
		return root;
	}
	if (code < root->data.code) {
		return searchNode(root->left, code);
	}
	return searchNode(root->right, code);
}

Btree* deleteNode(Btree* root, const string& code) {
	cout << "Delete function not yet implemented." << endl;
    return root;
}

void calculateSumAndCount(Btree* root, double& sum, int& count) {
	if (root == nullptr) return;
	
	sum += root->data.price;
	count++;
	calculateSumAndCount(root->left, sum, count);
	calculateSumAndCount(root->right, sum, count);
}

double calculateAverage(Btree* root) {
	if (root == nullptr) return 0;
	
	double sum = 0.0;
	int count = 0;
	calculateSumAndCount(root, sum, count);
	
	return (count > 0) ? sum / count : 0;
}

void countAboveHelper(Btree* root, double average, int& count) {
	if (root == nullptr) return;
	
	if (root->data.price > average) {
		count++;
		root->data.display();
	}
	
	countAboveHelper(root->left, average, count);
	countAboveHelper(root->right, average, count);
}

int countAboveAveragePrice(Btree* root) {
	if (root == nullptr) return 0;
	
	double average = calculateAverage(root);
	int count = 0;
	
	cout << fixed << setprecision(2);
	cout << endl;
	cout << "=== Price Analysis ===" << endl;
	cout << "Average price: $" << average << endl;
	cout << endl;
	cout << "=== Parts above average price ===" << endl;
	
	countAboveHelper(root, average, count);
	
	return count;
}

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

void deleteTree(Btree* root) {
	if (root == nullptr) return;
	
	deleteTree(root->left);
	deleteTree(root->right);
	delete root;
}

void inorderDescending(Btree* root) {
    if (root == nullptr) return;
    inorderDescending(root->right);
    root->data.display();
    inorderDescending(root->left);
}

void preorderTraversal(Btree* root) {
    if (root == nullptr) return;
    root->data.display();
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Btree* root) {
    if (root == nullptr) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    root->data.display();
}
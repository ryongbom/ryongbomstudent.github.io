#include "MenuFunctions.h"
#include "FileManager.h"
#include <iostream>
using namespace std;

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

void handleSearch(Btree* root) {
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
}

void handleDelete(Btree*& root) {
	string code;
	cout << "Enter part code to delete: ";
    getline(cin, code);
    root = deleteNode(root, code);
    cout << "Part deleted (if existed)." << endl;
}

void handleSave(Btree* root) {
	if (root == nullptr) {
        cout << "Tree is empty. Nothing to save." << endl;
    } else {
        string filename;
        cout << "Enter filename to save: ";
        getline(cin, filename);
        saveToFile(root, filename);
    }
}

void handleLoad(Btree*& root) {
	string filename;
    cout << "Enter filename to load: ";
    getline(cin, filename);
    
    deleteTree(root);
    root = nullptr;
    root = loadFromFile(filename);
    if (root != nullptr) {
        cout << "Tree loaded successfully!" << endl;
    }
}

void handleTests(Btree* root) {
	cout << endl;
	cout << "=== Running tests ===" << endl;
	
	int testChoice;
	cout << "Select test (1~5): ";
	cin >> testChoice;
	cin.ignore();
	
	switch(testChoice) {
		case 1:
			cout << "Test insert: Add a sample part" << endl;
			{
				Data testData("T999", "Test Part", 99.99, 5.5);
				root = insertNode(root, testData);
				cout << "Added test part with code T999" << endl;
			}
			break;
		case 2:
			cout << "Test search: Search for code T999" << endl;
			{
				Btree* found = searchNode(root, "T999");
				if (found) {
					cout << "Found: ";
					found->data.display();
				} else {
					cout << "Not found" << endl;
				}
			}	
			break;
		case 3:
			cout << "Test delete: Delete code T999" << endl;
			root = deleteNode(root, "T999");
			cout << "Deleted (if existed)" << endl;
			break;
		case 4:
			cout << "Test File I/O" << endl;
			{
				string testFile = "test.txt";
				saveToFile(root, testFile);
				cout << "saved to " << testFile << endl;
				
				Btree* newRoot = loadFromFile(testFile);
				if (newRoot) {
					cout << "Loaded successfully" << endl;
					deleteTree(newRoot);
				}
			}
			break;
		case 5:
			cout << "Test count above average" << endl;
			{
				int count = countAboveAveragePrice(root);
				cout << "Count: " << count << endl;
			}
			break:
		default:
			cout << "Invalid test" << endl;
	}
}
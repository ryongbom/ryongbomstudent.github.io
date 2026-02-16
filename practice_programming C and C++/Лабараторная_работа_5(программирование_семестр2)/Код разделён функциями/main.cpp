#include "FileManager.h"
#include "MenuFunctions.h"
#include <iostream>

using namespace std;

int main() {
    Btree* root = nullptr;
    int choice;
    
    do {
        showMenu();
        cout << ">> Select an option: ";
        cin >> choice;
        cin.ignore();
        
        switch(choice) {
            case 1:
                processConsoleInput(root);
                break;
            case 2:
                handleLoad(root);
                break;
            case 3:
                cout << "\n=== All parts in tree ===" << endl;
                if (root == nullptr) {
                    cout << "Tree is empty." << endl;
                } else {
                    inorderTraversal(root); 
                }
                break;
            case 4:
                handleSearch(root);
                break;
            case 5:
                handleDelete(root);
                break;
            case 6: {
                int count = countAboveAveragePrice(root);
                cout << "\nResult: " << count << " parts have price above average." << endl;
                break;
            }
            case 7:
                handleTests(root);
                break;
            case 8:
                handleSave(root);
                break;
            case 9: {
                string filename;
                cout << "Enter filename to load additional data: ";
                getline(cin, filename);
                
                Btree* additionalRoot = loadFromFile(filename);
                if (additionalRoot != nullptr) {
                    cout << "Additional data loaded. (Merge not yet implemented)" << endl;
                }
                break;
            }
            case 0:
                cout << "Exiting program. Cleaning up memory..." << endl;
                deleteTree(root);
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    } while (choice != 0);
    
    return 0;
}
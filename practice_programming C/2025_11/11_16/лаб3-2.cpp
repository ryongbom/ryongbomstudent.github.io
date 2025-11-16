#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Subscriber {
	int index;
	string title;
	int period;
	string surname;
	string address;
	double cost_per_month;
	int post_office;
};

int const MAX_SUBSCRIBERS = 100;

void inputSubscribers(Subscriber subscriber[], int& count) {
	cout << "How many subscribers: ";
	cin >> count;
	cin.ignore();
	
	for (int i = 0; i < count; i++) {
		cout << "\n=== No." << i + 1 << " subscriber ===" << endl;
		
		cout << "index: ";
		cin >> subscriber[i].index;
		cin.ignore();
		cout << "title: ";
		getline(cin, subscriber[i].title);
		cout << "period: ";
		cin >> subscriber[i].period;
		cin.ignore();
		cout << "surname: ";
		cin >> subscriber[i].surname;
		cin.ignore();
		cout << "adress: ";
		getline(cin, subscriber[i].address);
		cout << "cost_per_month: ";
		cin >> subscriber[i].cost_per_month;
		cout << "post_office: ";
		cin >> subscriber[i].post_office;
	}
}

void listByPostoffice(const Subscriber subscriber[], int count) {
	int p_office;
	cout << "number post_office: ";
	cin >> p_office;
	
	cout << "\n=== No." << p_office << " post_office ===" << endl;
	bool found = false;
	
	for (int i = 0; i < count; i++) {
		if(subscriber[i].post_office == p_office) {
			cout << "surname: " << subscriber[i].surname 
			     << ", title: " << subscriber[i].title
			     << ", adress: " << subscriber[i].address << endl;
		found = true;    
		}
	}
	
	if (!found) {
		cout << "subscriber is not found." << endl;
	}
}

void searchBySurname(const Subscriber subscriber[], int count) {
	string sname;
	cout << "subscriber's surname: ";
	cin >> sname;
	
	cout << "\n=== subscriber's surname " << sname << " ===" << endl;
	double total_cost = 0;
	bool found = false;
	
	for (int i = 0; i < count; i++) {
		if (subscriber[i].surname == sname) {
			double cost = subscriber[i].cost_per_month * subscriber[i].period;
			cout << "title: " << subscriber[i].title
				 << ", period: " << subscriber[i].period 
				 << ", cost: " << subscriber[i].cost_per_month;
			total_cost += cost;
			found = true;
		}
	}
	if (found) {
		cout << "total_cost: " << total_cost << " pyb." << endl;
	}
	else
		cout << "subscriber's surname is not found." << endl;
}

void FindPopularEdition(const Subscriber subscriber[], int count) {
	int count_title[MAX_SUBSCRIBERS] = {0};
	string edition[MAX_SUBSCRIBERS];
	int title[MAX_SUBSCRIBERS] = {1};
	int i, j;
	
	for (i = 0; i < count; i++) {
		if (title[i]) {
			edition[i] = subscriber[i].title;
			count_title[i] = 1;
		}
		for (j = i + 1; j < count; j++) {
			if (edition[i] == subscriber[j].title) {
				title[j] = 0;
				count_title[i]++;
			}
		}
	}
	
	int max_count = 0;
	int temp;
	for (i = 0; i < count; i++) {
		if(count_title[i] > max_count)
			max_count = count_title[i];
			temp = i;
	}
	
	cout << "\n=== popular title ===" << endl;
	cout << "title: " << subscriber[temp].title << endl;
	cout << "How many: " << max_count << endl;	
}

void displayAllSubscribers(const Subscriber subscriber[], int count) {
	cout << "\n=== All subscribers ===" << endl;
	for (int i = 0; i < count; i++) {
		cout << i + 1 << ". " << subscriber[i].surname
			 << " - " << subscriber[i].address
			 << " - " << subscriber[i].title
			 << " - " << subscriber[i].period
			 << " (post_office's number: " << subscriber[i].post_office << ")" << endl;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	Subscriber subscriber[MAX_SUBSCRIBERS];
	int count = 0;
	int choice = 0;
	
	cout << "\n=== system for caculator of subscribers ===" << endl;
	do {
		cout << "\n=== menu ===" << endl;
		cout << "1. input data of subscribers" << endl;
		cout << "2. show all data of subscribers" << endl;
		cout << "3. list of subscribers of one post_office" << endl;
		cout << "4. title search of one subscriber's surname" << endl;
		cout << "5. popular title" << endl;
		cout << "0. exit" << endl;
		cout << "selet choice" << endl;
		cin >> choice;
		
		switch(choice) {
			case 1:
				inputSubscribers(subscriber, count);
				break;
			case 2:
				displayAllSubscribers(subscriber, count);
				break;
			case 3:
				listByPostoffice(subscriber, count);
				break;
			case 4:
				searchBySurname(subscriber, count);
				break;
			case 5:
				FindPopularEdition(subscriber, count);
				break;
			case 0:
				cout << "exit programm" << endl;
				break;
			default:
				cout << "false, once again selet choice" << endl;
				break;
		}
	} while (choice != 0);
	
	return 0;
} 

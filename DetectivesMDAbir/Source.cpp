//MD Abir A. Choudhury
//04/28/18
//CIS LAB 5: Detectives

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//class definitions
class Detective{
public:
	string name;
	string specialty;
	int experience;
	//Member Functions
};

//function prototypes
void displayMessage();
void addNewDetective(Detective detectiveList[], int &count);
void searchDetective(Detective detectiveList[], int count);
void reportDetectiveByDept(Detective detectiveList[], int count);
void readFromFile(Detective detectiveList[], int &count);
void writeToFile(Detective detectiveList[], int count);

int main() {
	const int SIZE = 1000;
	Detective detectiveList[SIZE];
	int choice = 0;
	int count = 0;
	
	readFromFile(detectiveList, count);

	do{
		displayMessage();
		cin >> choice;
		if (choice == 1) {
			addNewDetective(detectiveList, count);
		}
		else if (choice == 2) {
			searchDetective(detectiveList, count);
		}
		else if (choice == 3) {
			reportDetectiveByDept(detectiveList, count);
		}
	} while (choice != 0);

	writeToFile(detectiveList, count);

	system("PAUSE");
	return 0;
}

//function definitions
void displayMessage() {
	cout << "Welcome to Detective v2.2\n"
		<< "=========================\n"
		<< "1 - Add a Detective\n"
		<< "2 - Seatch a Detective\n"
		<< "3 - Report\n"
		<< "0 - Exit\n"
		<< "Choose one: ";
}
void addNewDetective(Detective detectiveList[], int &count) {
	cout << "Name: ";
	string testName;
	cin >> testName;
	for (int i = 0; i < count; i++) {
		if (detectiveList[i].name == testName) {
			cout << "That name is already taken. Please try again.\n";
			return;
		}
	}
	detectiveList[count].name = testName;
	cout << "Specialty (Options:Homicide, Fraud, Theft, Traffic, Gangs): ";
	cin >> detectiveList[count].specialty;
	cout << "Experience: ";
	cin >> detectiveList[count].experience;
	count++;
}
void searchDetective(Detective detectiveList[], int count) {
	string option;
	int years;
	cout << "What speciality do you need (Options: Homicide, Fraud, Theft, Traffic, Gangs): \n";
	cin >> option;
	cout << "What is the minimum years of experience required: \n";
	cin >> years;


	int chosenIndex = -1;
	for (int i = 0; i < count; i++) {
		if (detectiveList[i].experience > years && detectiveList[i].specialty == option) {
			if (chosenIndex == -1 || detectiveList[i].experience > detectiveList[chosenIndex].experience) {
				chosenIndex = i;
			}
		}
	}
	if (chosenIndex == -1) {
		cout << "Could not find matching detectives\n.";
		return;
	}
	else {
		cout << "Detective " << detectiveList[chosenIndex].name << " is the perfect fit for the job.\n";

	}
}
void reportDetectiveByDept(Detective detectiveList[], int count) {
	cout << "Homicide\n"
		<< "=============================\n";
	for (int i = 0; i < count; i++) {
		if (detectiveList[i].specialty == "Homicide") {
			cout << "Detective " << detectiveList[i].name << " with " << detectiveList[i].experience << " years of experience.\n";
		}
	}

	cout << "Fraud\n"
		<< "=============================\n";
	for (int i = 0; i < count; i++) {
		if (detectiveList[i].specialty == "Fraud") {
			cout << "Detective " << detectiveList[i].name << " with " << detectiveList[i].experience << " years of experience.\n";
		}
	}

	cout << "Theft\n"
		<< "=============================\n";
	for (int i = 0; i < count; i++) {
		if (detectiveList[i].specialty == "Theft") {
			cout << "Detective " << detectiveList[i].name << " with " << detectiveList[i].experience << " years of experience.\n";
		}
	}
	cout << "Traffic\n"
		<< "=============================\n";
	for (int i = 0; i < count; i++) {
		if (detectiveList[i].specialty == "Traffic") {
			cout << "Detective " << detectiveList[i].name << " with " << detectiveList[i].experience << " years of experience.\n";
		}
	}
	cout << "Gangs\n"
		<< "=============================\n";
	for (int i = 0; i < count; i++) {
		if (detectiveList[i].specialty == "Gangs") {
			cout << "Detective " << detectiveList[i].name << " with " << detectiveList[i].experience << " years of experience.\n";
		}
	}
}
void readFromFile(Detective detectiveList[], int &count) {
	ifstream fileIn("ioFile.txt");

	if (!fileIn){
		cout << "Failed to find file.\n";
		exit(EXIT_FAILURE);
	}
	while (!fileIn.eof()) {
		fileIn >> detectiveList[count].name;
		fileIn >> detectiveList[count].specialty;
		fileIn >> detectiveList[count].experience;
		count++;
	}

	fileIn.close();
}
void writeToFile(Detective detectiveList[], int count) {
	ofstream fileOut("ioFile.txt");
	
	for (int i = 0; i < count; i++) {
		fileOut << detectiveList[i].name << " " << detectiveList[i].specialty << " " << detectiveList[i].experience;
		if (i < count - 1) {
			fileOut << endl;
		}
	}

	fileOut.close();
}

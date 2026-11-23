#include <iostream>
#include <limits>
#include <string>

using std::cout;
using std::cin;
using std::endl;

int main() {

	std::string name{ "" };
	cout << "What is your name?" << endl;
	cin >> name;

	int age{ 0 };
	cout << "what is your age?" << endl;
	cin >> age;

	while (cin.fail()) {
		cout << "ERROR: invalid input, only accepts numbers!" << endl;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Try again...." << endl;
		cin >> age;
	}
	if (age < 25) {
		cout << "Hello " << name << ", you are already " << age << " years old." << endl;
	}
	else {
		cout << "Hello " << name << ", you are very wise for your age" << endl;
	}

	cout << "Press enter to continue." << endl;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cin.get();

	return 0;
}
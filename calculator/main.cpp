#include <iostream>
#include <cstdint>

int checkForInput();
char checkForOperator();
bool readOperators(char op);

int main() {

	std::cout << "Please enter a number: " << std::endl;
	double num1 = checkForInput();
	std::cout << "Please enter a operator: " << std::endl;
	char op = checkForOperator();
	std::cout << "Please enter a number: " << std::endl;
	double num2 = checkForInput();
	double sum{ 0 };

	switch (op) {
	case '+':
		sum = num1 + num2;
		break;
	case '-':
		sum = num1 - num2;
		break;
	case '*':
		sum = num1 * num2;
		break;
	case '/':
		if (num1 != 0 && num2 != 0) {
			sum = num1 / num2;
		}
		else std::cout << "Cannot divide with 0!" << std::endl;
		break;
	}
	std::cout << "result: " << sum << std::endl;
	return 0;
}

int checkForInput()
{
	double num{ 0 };
	std::cin >> num;
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "INVALID input, please enter a number!" << std::endl;
		std::cin >> num;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return num;
}

char checkForOperator()
{
	char op{ '+' };
	std::cin >> op;
	while (!readOperators(op)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "INVALID input, please enter a operator(\'+ - * /\')!" << std::endl;
		std::cin >> op;
	}
	return op;
}

bool readOperators(char op)
{
	return op == '+' || op == '-' || op == '*' || op == '/';
}

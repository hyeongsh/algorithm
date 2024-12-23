
#include <iostream>
#include <string>

void fizzbuzz(int num);

int main(void) {
	std::string word[3];

	std::cin >> word[0] >> word[1] >> word[2];
	int tmp = 0;
	for (int i = 0; i < 3; i++) {
		try {
			tmp = std::stoi(word[i]);
			fizzbuzz(tmp + 3 - i);
			return 0;
		} catch (std::exception &e) {
			;
		}
	}
}

void fizzbuzz(int num) {
	if (num % 3 == 0 && num % 5 == 0) {
		std::cout << "FizzBuzz" << std::endl;
	} else if (num % 3 == 0) {
		std::cout << "Fizz" << std::endl;
	} else if (num % 5 == 0) {
		std::cout << "Buzz" << std::endl;
	} else {
		std::cout << num << std::endl;
	}
}
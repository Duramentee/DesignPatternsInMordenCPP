#ifndef BANKACCOUNT_HPP
#define BANKACCOUNT_HPP

#include <iostream>

using namespace std;

struct BankAccount {
	int deposit_;

	explicit BankAccount(const int deposit) : deposit_{deposit} {}

	void deposit() const {
		std::cout << "Your account have " << deposit_ << " yuan" << std::endl;
	}
};

#endif //BANKACCOUNT_HPP

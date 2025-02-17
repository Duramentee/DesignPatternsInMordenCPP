#include <iostream>
#include "Person.h"

class Person::PersonImpl {
public:
	static void greet(const Person* p) ;
};

Person::Person() : impl_{new PersonImpl} {

}

Person::~Person() {
	delete impl_;
}

void Person::greet() const {
	PersonImpl::greet(this);
}

void Person::PersonImpl::greet(const Person* p) {
	std::cout << "Hello, " << p->name_ << std::endl;
}

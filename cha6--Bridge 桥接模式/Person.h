#ifndef PERSON_H
#define PERSON_H

#include <string>

struct Person {
	class PersonImpl;

	std::string name_;
	PersonImpl* impl_{};

	void greet() const;

	Person();
	~Person();
};

#endif //PERSON_H

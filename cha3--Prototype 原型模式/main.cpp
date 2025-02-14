#include <memory>
#include <string>
#include <utility>

using namespace std;

struct Address {
	string street;
	string city;
	int suite{0};

	Address() = default;
	Address(string street, string city, const int& suite)
		: street{std::move(street)}, city{std::move(city)}, suite{suite} {}
};

struct Contact {
	string name;
	unique_ptr<Address> address;

	Contact(const Contact& ano_contact)
		: name{ano_contact.name}, address{make_unique<Address>(*ano_contact.address)} {}
};

struct EmployeeFactory {
public:
	static Contact main;
	static Contact aux;

	static unique_ptr<Contact> NewMainOfficeEmployee(const string& name, const int& suite) {
		return NewEmployee(name, suite, main);
	}
	static unique_ptr<Contact> NewAuxOfficeEmployee(const string& name, const int& suite) {
		return NewEmployee(name, suite, aux);
	}

private:
	static unique_ptr<Contact> NewEmployee(const string& name, const int& suite,
										   Contact& proto) {
		auto result = make_unique<Contact>(proto);
		result->name = name;
		result->address->suite = suite;
		return result;
	}
};

void test() {
	auto john = EmployeeFactory::NewAuxOfficeEmployee("John Doe", 123);
	auto jane = EmployeeFactory::NewMainOfficeEmployee("Jane Doe", 125);
}




int main() {
	return 0;
}
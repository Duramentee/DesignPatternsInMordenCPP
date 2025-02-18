//
// Created by lsx31 on 25-2-12.
//

#include <string>
#include <utility>
#include <iostream>

using namespace std;

// 以下是一个组合创建者的例子

class PersonBuilderBase;
class PersonBuilder;
class PersonAddressBuilder;
class PersonJobBuilder;

// Person 记录关于一个人的一些信息
// 主要可分为地址信息和就业信息

class Person {
	friend class PersonBuilder;
	friend class PersonAddressBuilder;
	friend class PersonJobBuilder;

	// address
	string street_address;
	string post_code;
	string city;

	// employment
	string company_name;
	string position;
	int annual_income = 0;

	Person() = default;

public:
	// 此处直接定义会因为PersonBuilder在之后定义而导致类型不完全, 所以放到了后面
	static PersonBuilder create();

	// Getter methods
	[[nodiscard]] string get_street_address() const { return street_address; }
	[[nodiscard]] string get_post_code() const { return post_code; }
	[[nodiscard]] string get_city() const { return city; }
	[[nodiscard]] string get_company_name() const { return company_name; }
	[[nodiscard]] string get_position() const { return position; }
	[[nodiscard]] int get_annual_income() const { return annual_income; }
};

class PersonBuilderBase {
protected:
	// 引用 person 是对正在构建的对象的引用
	// 这可能看起来很奇怪，但它是为子建造者特意完成的
	// 注意!!! 此类中不存在 Person 的物理存储, 只是存有一个根类的引用,而不是构造的对象
	Person& person;

	// 引用拷贝构造函数受到保护，
	// 因此只有继承者（PersonAddressBuilder 和 PersonJobBuilder）可以使用它
	explicit PersonBuilderBase(Person& person) : person{person} {}

public:
	// 类型转换运算符
	// 作用是将 PersonBuilderBase 对象隐式或显式地转换为 Person 对象
	// 这个运算符允许在需要 Person 对象的地方使用 PersonBuilderBase 对象，编译器会自动调用这个运算符来完成转换
	// explicit operator Person() const { return std::move(person); }

	// lives() 和 works() 是返回建造者方面的函数
	[[nodiscard]] PersonAddressBuilder lives() const;
	[[nodiscard]] PersonJobBuilder works() const;

	// build 用于构造一个 Person 类型的对象, 作为链式调用的返回值
	[[nodiscard]] Person build_object() const {
		return std::move(person);
	}
};

class PersonBuilder : public PersonBuilderBase {
private:
	Person p;
public:
	PersonBuilder() : PersonBuilderBase{p} {}
};


class PersonAddressBuilder : public PersonBuilderBase {
	typedef PersonAddressBuilder self;

public:
	explicit PersonAddressBuilder(Person& person) : PersonBuilderBase{person} {}

	self& at(string street_address) {
		person.street_address = std::move(street_address);
		return *this;
	}
	self& with_postcode(string post_code) {
		person.post_code = std::move(post_code);
		return *this;
	}
	self& in(string city) {
		person.city = std::move(city);
		return *this;
	}
};

class PersonJobBuilder : public PersonBuilderBase {
	typedef PersonJobBuilder self;

public:
	explicit PersonJobBuilder(Person& person) : PersonBuilderBase{person} {}

	self& at(string company_name) {
		person.company_name = std::move(company_name);
		return *this;
	}
	self& as_a(string position) {
		person.position = std::move(position);
		return *this;
	}
	self& earning(const int& annual_income) {
		person.annual_income = annual_income;
		return *this;
	}
};

PersonBuilder Person::create() {
	return PersonBuilder{};
}

[[nodiscard]] PersonAddressBuilder PersonBuilderBase::lives() const {
	return PersonAddressBuilder{person};
}

[[nodiscard]] PersonJobBuilder PersonBuilderBase::works() const {
	return PersonJobBuilder{person};
}

void test_person_builder() {
	// 创建一个 Person 对象
	Person p = Person::create()
				.lives()
					.at("123 London Road")
					.with_postcode("SW1 1GB")
					.in("London")
				.works()
					.at("PragmaSoft")
					.as_a("Consultant")
					.earning(10e6)
				.build_object();

	// 输出 Person 对象的详细信息以验证
	std::cout << "Person Details:" << std::endl;
	std::cout << "Street Address: " << p.get_street_address() << std::endl;
	std::cout << "Post Code: " << p.get_post_code() << std::endl;
	std::cout << "City: " << p.get_city() << std::endl;
	std::cout << "Company Name: " << p.get_company_name() << std::endl;
	std::cout << "Position: " << p.get_position() << std::endl;
	std::cout << "Annual Income: " << p.get_annual_income() << std::endl;
}

int main() {
	test_person_builder();
	return 0;
}
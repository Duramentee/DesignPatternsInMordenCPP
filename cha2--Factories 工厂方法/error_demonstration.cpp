#include <iostream>
#include <memory>
#include <map>

using namespace std;

struct HotDrink {
	virtual void prepare(const int& volume) = 0;
	virtual ~HotDrink() = default;
};

struct Tea final : HotDrink {
	void prepare(const int& volume) override {
		cout << "Take tea bag, boil water, pour "
			 << volume
			 << "ml, add some lemon" << endl;
	}
};

struct Coffee final : HotDrink {
	void prepare(const int& volume) override {
		cout << "Take some coffee, boil water, pour "
			 << volume << endl;
	}
};

struct HotDrinkFactory {
	virtual ~HotDrinkFactory() = default;

	[[nodiscard]] virtual unique_ptr<HotDrink> make() const = 0;
};

struct TeaFactory final : HotDrinkFactory {
	[[nodiscard]] unique_ptr<HotDrink> make() const override {
		return make_unique<Tea>();
	}
};

struct CoffeeFactory final : HotDrinkFactory {
	[[nodiscard]] unique_ptr<HotDrink> make() const override {
		return make_unique<Coffee>();
	}
};

class DrinkFactory {
	map<string, unique_ptr<HotDrinkFactory>> hot_factories;

	DrinkFactory() {
		hot_factories["coffee"] = make_unique<CoffeeFactory>();
		hot_factories["tea"] = make_unique<TeaFactory>();
	}

	unique_ptr<HotDrink> make_drink(const string &name) {
		auto drink = hot_factories[name]->make();
		drink->prepare(200); // oops!
		return drink;
	}
};

unique_ptr<HotDrink> make_drink(const string& type) {
	unique_ptr<HotDrink> drink;
	if(type == "tea") {
		drink = make_unique<Tea>();
		drink->prepare(200);
	} else {
		drink = make_unique<Coffee>();
		drink->prepare(50);
	}
	return drink;
}

void test() {

}




















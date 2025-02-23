#include "Graphic.h"

#include <iostream>
#include <vector>

class GraphicObject {
public:
	virtual ~GraphicObject() = default;
	virtual void draw() = 0;
};

struct Circle final : GraphicObject {
	void draw() override {
		std::cout << "Circle" << std::endl;
	}
};

struct Group final : GraphicObject {
public:
	std::string name_;
	std::vector<GraphicObject*> objects;

	explicit Group(std::string name) : name_{std::move(name)} {}

	void draw() override {
		std::cout << "Group" << name_ << " contains:" << std::endl;
		for(auto&& o:objects) {
			o->draw();
		}
	}
};

void test() {
	Group root("root");
	Circle c1, c2;
	root.objects.push_back(&c1);

	Group subgroup("sub");
	subgroup.objects.push_back(&c2);

	root.objects.push_back(&subgroup);

	root.draw();
}
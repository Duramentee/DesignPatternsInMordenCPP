#include <iostream>
#include <string>
#include <memory>

using namespace std;

struct Creature {
	string name_;
	int attack_;
	int defense_;

	Creature(string&& name, const int attack, const int defense)
		: name_{move(name)}, attack_{attack}, defense_{defense} {}

	friend ostream& operator<<(ostream& os, const Creature& creature) {
		os << "Creature name: " << creature.name_ << endl
			<< "Creature attack: " << creature.attack_ << endl
			<< "Creature defense " << creature.defense_ << endl;

		return os;
	}
};

class CreatureModifier {
private:
	shared_ptr<CreatureModifier> next_{nullptr};

protected:
	Creature& creature_;

public:
	explicit CreatureModifier(Creature& creature) : creature_{creature} {}
	virtual ~CreatureModifier() = default;

	void add(shared_ptr<CreatureModifier> cm) {
		if (next_) {
			next_->add(cm);
		}
		else {
			next_ = move(cm);
		}
	}

	// 注意 handle 是从下一个对象开始调用的
	// 一般抽象类是根, 具体类对象从第二个开始
	virtual void handle() {
		if (next_) {
			next_->handle();
		}
	}
};

class DoubleAttackModifier final : public CreatureModifier {
public:
	explicit DoubleAttackModifier(Creature& creature)
		: CreatureModifier{creature} {}

	void handle() override {
		creature_.attack_ *= 2;
		CreatureModifier::handle();
	}
};

class IncreaseDefenseModifier final : public CreatureModifier {
public:
	explicit IncreaseDefenseModifier(Creature& creature)
		: CreatureModifier{creature} {}

	void handle() override {
		if (creature_.attack_ <= 2)
			creature_.defense_ += 1;
		CreatureModifier::handle();
	}
};

class NoBonusesModifier final : public CreatureModifier {
public:
	explicit NoBonusesModifier(Creature& creature) : CreatureModifier(creature) {}

	void handle() override {
		// 在这里什么也不需要做！
	}
};

void test() {
	Creature goblin{"Goblin", 1, 1};
	CreatureModifier root{goblin};
	DoubleAttackModifier r1{goblin};
	DoubleAttackModifier r1_2{goblin};
	IncreaseDefenseModifier r2{goblin};

	root.add(make_shared<DoubleAttackModifier>(r1));
	root.add(make_shared<DoubleAttackModifier>(r1_2));
	root.add(make_shared<IncreaseDefenseModifier>(r2));
	root.handle();
	cout << goblin << endl;
}

int main() {
	test();
}

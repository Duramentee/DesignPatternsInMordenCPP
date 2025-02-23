#include "Creature.h"

#include <algorithm>
#include <array>
#include <numeric>

class Creature {
private:
	enum class Abilities {
		strength_,
		agility_,
		intelligence_,
		count,
	};

	std::array<int, static_cast<std::size_t>(Abilities::count)> abilities;

public:
	Creature() : abilities{0, 0, 0} {} // 初始化数组

	[[nodiscard]] int get_strength() const {
		return abilities[static_cast<std::size_t>(Abilities::strength_)];
	}

	void set_strength(const int strength) {
		abilities[static_cast<std::size_t>(Abilities::strength_)] = strength;
	}

	[[nodiscard]] int get_agility() const {
		return abilities[static_cast<std::size_t>(Abilities::agility_)];
	}

	void set_agility(const int agility) {
		abilities[static_cast<std::size_t>(Abilities::agility_)] = agility;
	}

	[[nodiscard]] int get_intelligence() const {
		return abilities[static_cast<std::size_t>(Abilities::intelligence_)];
	}

	void set_intelligence(const int intelligence) {
		abilities[static_cast<std::size_t>(Abilities::intelligence_)] = intelligence;
	}

	[[nodiscard]] int sum() const {
		return std::accumulate(abilities.begin(), abilities.end(), 0);
	}
	[[nodiscard]] double average() const {
		return sum() / static_cast<double>(Abilities::count);
	}
	[[nodiscard]] int max() const {
		return *std::max_element(abilities.begin(), abilities.end());
	}
};
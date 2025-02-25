#ifndef PROPERTY_HPP
#define PROPERTY_HPP

template <typename T>
struct Property {
	T value_;

	explicit Property(const T initial_value) : value_{initial_value} {}

	explicit operator T() const {
		return value_;
		// 执行一些getter操作
	}

	Property& operator=(const T& new_value) {
		value_ = new_value;
		// 执行一些setter操作
		return *this;
	}
};

struct Creature {
	Property<int> strength{10};
	Property<int> agility{5};
};

#endif //PROPERTY_HPP

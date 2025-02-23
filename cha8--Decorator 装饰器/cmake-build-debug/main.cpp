#include <string>
#include <sstream>
#include <cstdint>
#include <memory>
#include <iostream>

using namespace std;

struct Shape {
	virtual ~Shape() = default;
	[[nodiscard]] virtual std::string str() const = 0;
	[[nodiscard]] virtual std::unique_ptr<Shape> clone() const = 0;
};

// 显式定义Decorator抽象类
class Decorator : public Shape {
protected:
	std::unique_ptr<Shape> component_;

public:
	explicit Decorator(std::unique_ptr<Shape> component)
		: component_(std::move(component)) {}

	[[nodiscard]] std::unique_ptr<Shape> clone() const override {
		return std::make_unique<Decorator>(component_->clone());
	}
};

struct Circle : Shape {
public:
	float radius_;
	explicit Circle(const float& radius) : radius_{radius} {}

	void resize(const float& factor) { radius_ *= factor; }

	[[nodiscard]] unique_ptr<Shape> clone() const override {
		return make_unique<Circle>(*this);
	}

	[[nodiscard]] string str() const override {
		ostringstream oss;
		oss << "A circle of radius " << radius_;
		return oss.str();
	}
};

struct Square : Shape {
public:
	float length_;
	explicit Square(const float& length) : length_{length} {}

	void resize(const float& factor) { length_ *= factor; }

	[[nodiscard]] unique_ptr<Shape> clone() const override {
		return make_unique<Square>(*this);
	}

	[[nodiscard]] string str() const override {
		ostringstream oss;
		oss << "A Square of length: " << length_;
		return oss.str();
	}
};

class ColoredShape final : public Decorator {
	std::string color_;

public:
	ColoredShape(std::unique_ptr<Shape> shape, std::string color)
		: Decorator(std::move(shape)), color_(std::move(color)) {}

	[[nodiscard]] std::string str() const override {
		return component_->str() + " with color " + color_;
	}

	[[nodiscard]] std::unique_ptr<Shape> clone() const override {
		return std::make_unique<ColoredShape>(component_->clone(), color_);
	}
};

class TransparentShape final : public Decorator {
	uint8_t transparency_;

public:
	TransparentShape(std::unique_ptr<Shape> shape, uint8_t transparency)
		: Decorator(std::move(shape)), transparency_(transparency) {}

	[[nodiscard]] std::string str() const override {
		return component_->str() + " with " +
			std::to_string(static_cast<float>(transparency_) / 255 * 100) + "% transparency";
	}

	[[nodiscard]] std::unique_ptr<Shape> clone() const override {
		return std::make_unique<TransparentShape>(component_->clone(), transparency_);
	}
};

#include <functional>
#include <utility>
#include <string>

double add(double a, double b)
{
	cout << a << "+" << b << "=" << (a + b) << endl;
	return a + b;
}

template <typename R, typename... Args>
struct Logger {
	function<R(Args...)> func_;
	string name_;

	Logger(const function<R(Args...)>& func, string name):
		func_{func}, name_{std::move(name)} {}

	R operator()(Args... args) const {
		cout << "Entering" << name_ << endl;
		R result = func(args...);
		cout << "Exiting" << name_ << endl;

		return result;
	}
};

template <typename R, typename... Args>
auto make_logger(R (*func)(Args...), const string& name)
{
	return Logger<R(Args...)>{function<R(Args...)>(func),  name }; // () = call now
}



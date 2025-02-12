//
// Created by lsx31 on 25-2-12.
//

#include <iostream>
#include <sstream>
#include <memory>
#include <utility>
#include <vector>

using namespace std;

// 可以通过OOP的方法定义一个HtmlElement类来存储关于每个tag的信息:
struct HtmlElement {
	// 使建造者能访问构造函数
	friend struct HtmlBuilder;

	string name;
	string text;
	vector<HtmlElement> elements;
	const size_t indent_size = 2;

	// 暴露给外界的创建接口: 一个静态的 build 函数, 返回智能指针
	static unique_ptr<HtmlElement> build(const string& root_name) {
		return make_unique<HtmlElement>(*(new HtmlElement(root_name)));
	}

	// 将构造函数设为受保护, 强制用户用建造者构建对象
protected:
	HtmlElement() = default;
	explicit HtmlElement(string name) : name{std::move(name)} {}
	HtmlElement(string name, string text) : name{std::move(name)}, text{std::move(text)} {}

public:
	// 递归生成 HTML 字符串
	[[nodiscard]] string str(int indent = 0) const {
		ostringstream oss;
		string i(indent_size * indent, ' ');
		oss << i << "<" << name << ">" << endl;

		if (!text.empty()) {
			oss << string(indent_size * (indent + 1), ' ') << text << endl;
		}

		for (const auto& e : elements) {
			oss << e.str(indent + 1);
		}

		oss << i << "</" << name << ">" << endl;
		return oss.str();
	}
};

// 构建每个HtmlElement的过程不是很方便，我们可以通过实现建造者模式来改进它。
// 建造者
struct HtmlBuilder {
	HtmlElement root;

	explicit HtmlBuilder(const string& root_name) : root{root_name}{}

	[[nodiscard]] HtmlElement build() const {
		return root;
	}

	explicit operator HtmlElement() const { return root; }

	// 通过返回对建造者本身的引用 (用指针的形式也是可以的)，现在可以在建造者进行链式调用。
	// 这就是所谓的流畅接口(fluent interface)

	// HtmlBuilder builder{ "ul" };
	// builder.add_child("li", "hello").add_child("li", "world");
	// cout << builder.str() << endl;
	HtmlBuilder& add_child(string child_name, string child_text) {
		HtmlElement child{std::move(child_name), std::move(child_text)};
		root.elements.emplace_back(child);

		return *this;
	}

	// 调用所需创建对象的对应函数
	[[nodiscard]] string str() const { return root.str(); }
};

void test_html_builder() {
	HtmlBuilder builder("ul");
	builder.add_child("li", "hello").add_child("li", "world");

	std::cout << builder.str() << std::endl;
}

// int main() {
// 	test_html_builder();
// 	return 0;
// }
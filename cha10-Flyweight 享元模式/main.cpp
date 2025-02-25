#include <utility>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class BetterFormattedText {
public:
	struct TextRange {
		int start_;
		int end_;
		bool capitalize_;
		// other options here, e.g. bold, italic, etc.
		[[nodiscard]] bool covers(const int position) const {
			return position >= start_ && position <= end_;
		}
	};

private:
	string plain_text;
	vector<TextRange> formatting;

public:
	explicit BetterFormattedText(string text) : plain_text(std::move(text)) {}

	TextRange& get_range(const int start, const int end) {
		formatting.emplace_back(TextRange{start, end});
		return *formatting.rbegin();
	}

	friend std::ostream& operator<<(std::ostream& os,
	                                const BetterFormattedText& obj) {
		string s;
		for (int i = 0; i < obj.plain_text.length(); i++) {
			auto c = obj.plain_text[i];
			for (const auto& rng : obj.formatting) {
				if (rng.covers(i) && rng.capitalize_)
					c = static_cast<char>(toupper(c));
			}
			s += c;
		}
		return os << s;
	}
};

void test() {
	BetterFormattedText bft("This is a brave new world");
	bft.get_range(10, 15).capitalize_ = true;
	cout << bft << endl;
}

int main() {
	test();
}
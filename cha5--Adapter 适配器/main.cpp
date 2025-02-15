#include <vector>
#include <memory>

struct Point {
	int x;
	int y;
};

struct Line {
	Point start;
	Point end;
};

struct VectorObject {
	virtual ~VectorObject() = default;

	virtual std::vector<Line>::iterator begin() = 0;
	virtual std::vector<Line>::iterator end() = 0;
};

struct VectorRectangle final : VectorObject {
private:
	int width_;
	int height_;
	std::vector<Line> lines_;

public:
	// 构造长, 宽, 四条边
	VectorRectangle(const int& x, const int& y, const int& width, const int& height)
		: width_{width}, height_{height} {
		lines_.emplace_back(Line{Point{x, y}, Point{x + width, y}});
		lines_.emplace_back(Line{Point{x + width, y}, Point{x + width, y + height}});
		lines_.emplace_back(Line{Point{x + width, y + height}, Point{x, y + height}});
		lines_.emplace_back(Line{Point{x, y + height}, Point{x, y}});
	}

	std::vector<Line>::iterator begin() override {
		return lines_.begin();
	}

	std::vector<Line>::iterator end() override {
		return lines_.end();
	}
};

struct LineToPointAdapter final {
public:
	using Points = std::vector<Point>;

private:
	Points points;

public:
	// 直接在构造函数中完成转换
	explicit LineToPointAdapter(const Line& line) {
		const int left   = std::min(line.start.x, line.end.x);
		const int right  = std::max(line.start.x, line.end.x);
		const int bottom = std::min(line.start.y, line.end.y);
		const int top    = std::max(line.start.y, line.end.y);
		const int dx     = right - left;
		const int dy     = top - bottom;

		// 仅适用于水平线和垂直线
		if (dx == 0) {
			// 对于垂直线
			for (int y = bottom; y <= top; ++y) {
				points.emplace_back( Point{left, y} );
			}
		} else if (dy == 0) {
			// 对于水平线
			for (int x = left; x <= right; ++x) {
				points.emplace_back( Point{x, top} );
			}
		}
	}
	virtual ~LineToPointAdapter() = default;

	virtual Points::iterator begin() {
		return points.begin();
	}
	virtual Points::iterator end() {
		return points.end();
	}
};

void dosomething() {
	for (auto&& obj : vectorObjects) {
		for (auto&& line : *obj) {
			LineToPointAdapter lpo{ line };
			DrawPoints(dc, lpo.begin(), lpo.end());
		}
	};
}

void test() {
	std::vector<std::shared_ptr<VectorRectangle>> VectorRectangles {
		std::make_shared<VectorRectangle>(10, 10, 100, 100),
		std::make_shared<VectorRectangle>(10, 10, 100, 100)
	};

	std::vector<Point> points;

	for (auto&& o : VectorRectangles) {
		for (auto&& l : *o) {
			LineToPointAdapter lpo{ l };
			for (auto&& p : lpo) {
				points.push_back(p);
			}
		}
	}

	DrawPoints(dc, points.begin(), points.end());
}






















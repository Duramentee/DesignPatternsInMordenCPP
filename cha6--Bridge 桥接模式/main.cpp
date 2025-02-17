#include <iostream>

// 图形渲染所需实现的接口
struct Renderer {
	virtual ~Renderer() = default;

	virtual void render_circle(float x, float y, float radius) = 0;
};

// 矢量实现渲染
struct VectorRenderer final : Renderer {
	void render_circle(float x, float y, float radius) override {
		std::cout << "Rasterizing circle of radius." << radius << std::endl;
	}
};

// 栅格实现渲染
struct RasterRenderer final : Renderer {
	void render_circle(float x, float y, float radius) override {
		std::cout << "Drawing a vector circle of radius." << radius << std::endl;
	}
};

struct Shape {
protected:
	Renderer& renderer_;
	explicit Shape(Renderer& renderer) : renderer_{renderer} { }

public:
	virtual ~Shape() = default;

	virtual void draw() = 0;
	virtual void resize(const float& factor) = 0;
};

struct Circle final : Shape {
	float x_;
	float y_;
	float radius_;

	void draw() override {
		renderer_.render_circle(x_, y_, radius_);
	}
	void resize(const float& factor) override {
		radius_ *= factor;
	}
	Circle(Renderer& renderer, const float& x, const float& y, const float& radius)
		: Shape{renderer_}, x_{x}, y_{y}, radius_{radius} {

	}
};

void test() {
	RasterRenderer rr;
	Circle raster_circle{ rr, 5, 5, 5 };
	raster_circle.draw();
	raster_circle.resize(2);
	raster_circle.draw();
}









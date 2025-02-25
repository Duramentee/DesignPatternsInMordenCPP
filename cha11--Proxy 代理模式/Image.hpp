#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <iostream>
#include <memory>
#include <string>
#include <utility>

// 1. Subject接口
class Image {
public:
	virtual ~Image() = default;
	virtual void display() const = 0;
};

// 2. RealSubject：真实图片类
class RealImage final : public Image {
public:
	explicit RealImage(std::string filename)
		: filename_(std::move(filename)) {
		loadFromDisk();
	}

	void display() const override {
		std::cout << "Displaying image: " << filename_ << std::endl;
	}

private:
	void loadFromDisk() const {
		std::cout << "Loading heavy image: " << filename_ << " (Costly operation)" << std::endl;
	}

	std::string filename_;
};

// 3. Proxy：控制图片的延迟加载
class ProxyImage final : public Image {
private:
	std::string filename_;
	mutable std::unique_ptr<RealImage> real_image_; // mutable允许在const方法中修改
public:
	explicit ProxyImage(std::string filename)
		: filename_(std::move(filename)) {}

	void display() const override {
		if (!real_image_) {
			// 延迟初始化：仅在第一次调用display时加载真实图片
			real_image_ = std::make_unique<RealImage>(filename_);
		}
		real_image_->display();
	}
};

#endif //IMAGE_HPP

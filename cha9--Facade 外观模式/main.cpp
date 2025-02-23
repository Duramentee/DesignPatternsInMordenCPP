#include <vector>
#include <string>

using namespace std;

class IBuffer {
public:
	virtual ~IBuffer() = default;

	virtual void write(const void* data, size_t size) = 0;
	virtual void clear() = 0;
	[[nodiscard]] virtual size_t size() const = 0;
};

class TableBuffer final : public IBuffer {
private:
	vector<char> buffer_;

public:
	struct TableColumnSpec {
		// 表头
		string header_;
		// 宽度
		int width_;

		// 对齐方式
		enum class TableColumnAlignment { Left, Center, Right } alignment_;
	};

	TableBuffer(const vector<TableColumnSpec>& spec, int totalHeight) {
		// 根据列规格和总高度初始化表格结构
	}

	// 实现 IBuffer 的纯虚函数
	void write(const void* data, const size_t size) override {
		const auto bytes = static_cast<const char*>(data);
		buffer_.insert(buffer_.end(), bytes, bytes + size);
	}

	void clear() override {
		buffer_.clear();
	}

	[[nodiscard]] size_t size() const override {
		return buffer_.size(); // 应维护一个存储实际数据的成员变量
	}
};

struct Console {
	vector<ViewPort*> viewPorts_;
	Size charSize_;
	Size girdSize_;
};

Console::Console(bool fullscreen, int char_width, int char_height,
                 int width, int height, optional<Size> client_size) {
	// 创建单个缓冲和视窗
	// 把缓冲和视图结合在一起并放入合适的集合中
	// 生成图像纹理
	// 网格大小的计算取决于我们是否需要全屏模式
}

Console::Console(const ConsoleCreationParameters& ccp) {

}

struct ConsoleCreationParameters {
	optional<Size> client_size;
	int character_width{10};
	int character_height{14};
	int width{20};
	int height{30};
	bool fullscreen{false};
	bool create_default_view_and_buffer{true};
};

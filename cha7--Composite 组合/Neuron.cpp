#include "Neuron.h"
#include <vector>

struct Neuron;

template <typename Self>
struct SomeNeurons {
public:
    template <typename T>
    void connect_to(T& other);
};

struct Neuron : SomeNeurons<Neuron> {  // 此时SomeNeurons已完整定义
    std::vector<Neuron*> in_;
    std::vector<Neuron*> out_;
    unsigned int id_;

    Neuron() {
        static int id = 1;
        id_ = id++;
    }

    Neuron* begin() { return this; }
    Neuron* end() { return this + 1; }
};

// 定义 NeuronLayer 类
struct NeuronLayer : std::vector<Neuron>, SomeNeurons<NeuronLayer> {
    explicit NeuronLayer(int count) {
        while (count-- > 0) {
            emplace_back();
        }
    }

    // 复用 vector 的迭代器
    auto begin() { return std::vector<Neuron>::begin(); }
    auto end() { return std::vector<Neuron>::end(); }
};

// 实现需放在Neuron定义后（因依赖Neuron的迭代器）
template <typename Self>
template <typename T>
void SomeNeurons<Self>::connect_to(T& other) {
    for (Neuron& from : *static_cast<Self*>(this)) {
        for (Neuron& to : other) {
            from.out_.push_back(&to);
            to.in_.push_back(&from);
        }
    }
}

void test() {
    Neuron n1, n2;
    NeuronLayer layer1(3), layer2(4);

    n1.connect_to(n2);
    n1.connect_to(layer1);
    layer1.connect_to(n1);
    layer1.connect_to(layer2);
}

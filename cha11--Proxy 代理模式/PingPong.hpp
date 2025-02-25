#ifndef PINGPONG_HPP
#define PINGPONG_HPP

#include <string>
#include <iostream>

using namespace std;

struct Pingable {
	virtual ~Pingable() = default;
	virtual wstring ping(const wstring& message) = 0;
};

struct Pong final : Pingable {
	wstring ping(const wstring& message) override { return message + L" pong"; }
};

void tryit(Pingable& pp) {
	wcout << pp.ping(L"ping") << "\n";
}

void test() {
	RemotePong pp;  // was Pong
	for (int i = 0; i < 3; ++i) {
		tryit(pp);
	}
}

#endif //PINGPONG_HPP

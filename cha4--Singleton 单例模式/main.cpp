#include <stdexcept>
#include <map>
#include <vector>

using namespace std;

class Database {
public:
	virtual ~Database() = default;
	virtual int get_population(const std::string& name) = 0;
};

class SingletonDatabase : public Database {
private:
	SingletonDatabase() {
		static int instance_count{0};
		if (++instance_count > 1)
			throw std::runtime_error("Cannot make >1 database!");
	}

	map<string, int> capitals;

public:
	SingletonDatabase(SingletonDatabase const&) = delete;
	SingletonDatabase(SingletonDatabase&&) = delete;
	SingletonDatabase& operator=(SingletonDatabase const&) = delete;
	SingletonDatabase& operator=(SingletonDatabase&&) = delete;

	static SingletonDatabase& get() {
		static auto database = new SingletonDatabase();

		return *database;
	}

	int get_population(const std::string& name) override {
		return capitals[name];
	}
};

struct SingletonRecordFinder {
public:
	static int total_population(const vector<string>& names) {
		int result = 0;
		for (auto& name : names)
			result += SingletonDatabase::get().get_population(name);

		return result;
	}
};

class DummyDatabase final : public Database {
private:
	std::map<std::string, int> capitals;

public:
	DummyDatabase() {
		capitals["alpha"] = 1;
		capitals["beta"] = 2;
		capitals["gamma"] = 3;
	}

	int get_population(const std::string& name) override {
		return capitals[name];
	}
};

struct ConfigurableRecordFinder {
public:
	Database& db;

	explicit ConfigurableRecordFinder(Database& db) : db{db} {}

	[[nodiscard]] int total_population(const std::vector<std::string>& names) const {
		int result = 0;
		for (auto& name : names)
			result += db.get_population(name);

		return result;
	}
};

TEST(RecordFinderTests, DummyTotalPopulationTest) {
	DummyDatabase db{};
	ConfigurableRecordFinder rf{db};
	EXPECT_EQ(4, rf.total_population(std::vector<std::string>{"alpha", "gamma"}));
}

class Printer {
	static int id;
public:
	int get_id() const { return id; }
	void set_id(int value) { id = value; }
};





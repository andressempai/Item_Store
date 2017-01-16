#include <sstream>

//Weapon Class

class Weapon {
private:
	std::string WName;
	int WLevel;
public:
	static int WTotal;
	Weapon(std::string _wname, int _wlevel) : WName(_wname), WLevel(_wlevel) {
		WTotal += 1;
	}
	~Weapon() {
		std::cout << WName << " Destroy" << std::endl;
		WTotal -= 1;
	}
	void setWName(std::string _wname) {
		WName = _wname;
	}
	void setWLevel(int _wlevel) {
		WLevel = _wlevel;
	}
	std::string getWName() {
		return WName;
	}
	int getWLevel() {
		return WLevel;
	}
	std::string getInfo() {
		std::stringstream info;
		info << "Weapon Name: " << WName << std::endl << "Weapon Level: " << WLevel << std::endl;
		return info.str();
	}
	int getTotal() {
		return WTotal;
	}
};

int Weapon::WTotal = 0;
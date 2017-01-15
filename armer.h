#include <iostream>
#include <vector>
#include "weapon.h"

//Armer Class

class Armer {
private:
	std::vector<Weapon*> all_weapons;
	int Total;
public:
	~Armer() {
	}
	void CreateWeapon(std::string _name, int _level) {
		all_weapons.push_back(new Weapon((_name), _level));
		Total = Weapon::WTotal;
	}

	void Delete_Weapon(int _index) {
		delete all_weapons[_index];
		all_weapons.erase(all_weapons.begin() + _index);
		Total = Weapon::WTotal;
	}

	void Get_WeaponInfo() {
		for (std::vector<Weapon*>::iterator WIter = all_weapons.begin(); WIter < all_weapons.end(); ++WIter) {
			std::cout << (*WIter)->getInfo() << std::endl;
		}
	}

	void GetArmer_Info() {
		std::cout << "Weapons at vector are: " << all_weapons.size() << std::endl;
		std::cout << "Total of weapons are: " << Total << std::endl;
	}
};
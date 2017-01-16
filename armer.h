#include <map>
#include "weapon.h"

//Armer Class

class Armer {
private:
	std::map<std::string, Weapon*> all_weapons;
	int Total;
public:
	~Armer() {
	}
	void CreateWeapon(std::string _name, int _level) {
		all_weapons[_name] = new Weapon(_name, _level);
		++Total;
	}

	void Delete_Weapon(std::string _name) {
		delete all_weapons[_name];
		all_weapons.erase(_name);
		--Total;
	}

	Weapon* Get_Weapon(std::string _name) {
		return all_weapons[_name];
	}

	std::string Get_WeaponInfo() {
		std::stringstream Weapons_Info;
		if (all_weapons.empty()) {
			Weapons_Info << "No Weapons Equip" << std::endl;
		}
		else {
			for (std::map<std::string, Weapon*>::iterator WIter = all_weapons.begin(); WIter != all_weapons.end(); ++WIter) {
				Weapons_Info << WIter->second->getInfo() << std::endl;
			}
		}
		return Weapons_Info.str();
	}

	std::string GetArmer_Info() {
		std::stringstream Weapons_Total;
		Weapons_Total << "Armer have " << Total << " Weapons" << std::endl;
		return Weapons_Total.str();
	}

	bool IsEmpty() {
		if (all_weapons.empty()) {
			return true;
		}
		else {
			return false;
		}
	}
};
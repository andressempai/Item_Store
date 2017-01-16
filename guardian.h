#include "armer.h"

//Guardian Class

class Guardian {
private:
	std::map<std::string, Weapon*> GuardianWeapons;
	std::string Name, TClass;
	int Count;
public:
	Guardian() {
		Name = "";
		TClass = "";
		Count = 0;
	}

	Guardian(std::string _name, std::string _tclass) : Name(_name), TClass(_tclass) {
		Count = 0;
	}

	~Guardian() {}

	void EquipWeapon(std::string _name, int _level) {
		GuardianWeapons[_name] = new Weapon(_name, _level);
		++Count;
	}

	void Unequip_Weapon(std::string _name) {
		delete GuardianWeapons[_name];
		GuardianWeapons.erase(_name);
		--Count;
	}

	std::string GetGuardian_Info() {
		return "Guardian name: " + Name + " Class Type: " + TClass + "\n";
	}

	std::string GetEquip_Weapons() {

		std::stringstream Weapons_Info;

		if (GuardianWeapons.empty()) {
			Weapons_Info << "No Weapons Equip" << std::endl;
		}
		else {
			for (std::map<std::string, Weapon*>::iterator WIter = GuardianWeapons.begin(); WIter != GuardianWeapons.end(); ++WIter) {
				Weapons_Info << WIter->second->getInfo() << std::endl;
			}
		}
		return Weapons_Info.str();
	}

	std::string GetTotal_Weapons() {
		std::stringstream Weapons_Total;

		Weapons_Total << "Total of weapons are: " << Count << std::endl;
		return Weapons_Total.str();
	}
};
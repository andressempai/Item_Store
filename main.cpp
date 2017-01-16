#include <iostream>
#include "guardian.h"

/*"Fate Of All Fools", 260
"Epitaph 2261", 358
"The Last Rebellion", 170*/

void MainWindow(Armer _armer, Guardian _guardian)
{
	std::cout << "========================================================================" << std::endl;
	std::cout << "=                               Armer                                  =" << std::endl;
	std::cout << "========================================================================" << std::endl;

	std::cout << _armer.Get_WeaponInfo() << std::endl;
	std::cout << _armer.GetArmer_Info() << std::endl;

	std::cout << "========================================================================" << std::endl;
	std::cout << "=                              Guardian                                =" << std::endl;
	std::cout << "========================================================================" << std::endl;

	std::cout << _guardian.GetGuardian_Info() << std::endl;
	std::cout << _guardian.GetEquip_Weapons() << std::endl;
	std::cout << _guardian.GetTotal_Weapons() << std::endl;

	std::cout << "========================================================================" << std::endl;
	std::cout << "Total of Weapons are: " << Weapon::WTotal << std::endl << std::endl;
}

void main() {

	//Variables
	Armer armer;
	armer.CreateWeapon("Fate Of All Fools", 260);
	armer.CreateWeapon("Epitaph 2261", 358);
	armer.CreateWeapon("The Last Rebellion", 170);
	Guardian guardian1("Silvestre", "Titan");
	std::string Weapon_Choice;
	int Choice = 1;

	MainWindow(armer, guardian1);
	std::cout << "Do You Want to buy a Weapon? (No = 0 / Yes = 1 )   ";
	std::cin >> Choice;
	if (Choice == 1)
	{
		while (Choice == 1)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (armer.IsEmpty()) {
				std::cout << "No Weapons Avaible" << std::endl;
				Choice = 0;
			}
			else {
				std::cout << "Insert the Weapon Name: ";
				std::getline(std::cin, Weapon_Choice);
				guardian1.EquipWeapon(armer.Get_Weapon(Weapon_Choice)->getWName(), armer.Get_Weapon(Weapon_Choice)->getWLevel());
				armer.Delete_Weapon(Weapon_Choice);
				MainWindow(armer, guardian1);
				std::cin.clear();
				std::cin.sync();
				std::cout << "Do You Want To Buy Another Weapon? (No = 0 / Yes = 1 )   ";
				std::cin >> Choice;
			}
		}
	}

	system("pause");

}
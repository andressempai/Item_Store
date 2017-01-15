#include "armer.h"

void main() {

	Armer armer;
	armer.CreateWeapon("Fate Of All Fools", 260);
	armer.CreateWeapon("Epitaph 2261", 358);
	armer.CreateWeapon("The Last Rebellion", 170);

	armer.Get_WeaponInfo();
	armer.GetArmer_Info();
	armer.Delete_Weapon(0);
	armer.Get_WeaponInfo();
	armer.GetArmer_Info();
	

	system("pause");

}
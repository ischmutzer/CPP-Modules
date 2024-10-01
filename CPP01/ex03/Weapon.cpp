#include "Weapon.hpp"

Weapon::Weapon() {

}

Weapon::Weapon(std::string weaponType) {
	_type = weaponType;
}

Weapon::~Weapon() {

}

//the const at the beginnning of the ft means the caller is not allowed to modify the str through the returned ref
const std::string&  Weapon::getType() {
	
	return	_type;
}

void    Weapon::setType(std::string newType) {
	_type = newType;
}







//CONST FT

//the const at the end of the ft means the ft does not modify the object it belongs to

//const at the end means the ft is const and can only be called on const/non modifiable objects

//The const at the end of the function means that this function is guaranteed not to modify any member variables of the class. It ensures that the function doesn't alter the state of the object.
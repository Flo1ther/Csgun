#include <iostream>
#include <vector>

class Weapon {
public:
    virtual void shoot() = 0;
    virtual void drop() = 0;
    virtual void pickUp() = 0;
    virtual void reload() = 0;
};

class Pistol : public Weapon {
public:
    virtual void shoot() override {
        std::cout << "Pistol shooting..." << std::endl;
    }

    virtual void drop() override {
        std::cout << "Dropping pistol..." << std::endl;
    }

    virtual void pickUp() override {
        std::cout << "Picking up pistol..." << std::endl;
    }

    virtual void reload() override {
        std::cout << "Reloading pistol..." << std::endl;
    }
};

class Rifle : public Weapon {
public:
    virtual void shoot() override {
        std::cout << "Rifle shooting..." << std::endl;
    }

    virtual void drop() override {
        std::cout << "Dropping rifle..." << std::endl;
    }

    virtual void pickUp() override {
        std::cout << "Picking up rifle..." << std::endl;
    }

    virtual void reload() override {
        std::cout << "Reloading rifle..." << std::endl;
    }
};

class Character {
private:
    std::vector<Weapon*> weapons;

public:
    void pickUpWeapon(Weapon* weapon) {
        if (weapons.size() < 3) {
            weapons.push_back(weapon);
            weapon->pickUp();
        }
        else {
            std::cout << "Cannot pick up weapon. Inventory is full." << std::endl;
        }
    }

    void dropWeapon(int index) {
        if (index >= 0 && index < weapons.size()) {
            Weapon* droppedWeapon = weapons[index];
            if (droppedWeapon != nullptr) {
                if (dynamic_cast<Pistol*>(droppedWeapon) == nullptr) {
                    droppedWeapon->drop();
                    delete droppedWeapon;
                    weapons.erase(weapons.begin() + index);
                }
                else {
                    std::cout << "Cannot drop pistol." << std::endl;
                }
            }
        }
        else {
            std::cout << "Invalid weapon index." << std::endl;
        }
    }

    void shootWithCurrentWeapon() {
        if (!weapons.empty()) {
            weapons.back()->shoot();
        }
        else {
            std::cout << "No weapon to shoot with." << std::endl;
        }
    }

    void reloadCurrentWeapon() {
        if (!weapons.empty()) {
            weapons.back()->reload();
        }
        else {
            std::cout << "No weapon to reload." << std::endl;
        }
    }
};

int main() {
    Character player;

    Weapon* pistol = new Pistol();
    Weapon* rifle = new Rifle();

    player.pickUpWeapon(pistol);
    player.pickUpWeapon(rifle);

    player.shootWithCurrentWeapon();
    player.reloadCurrentWeapon();

    player.dropWeapon(1);

    return 0;
}

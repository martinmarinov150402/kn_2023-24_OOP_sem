#include <iostream>
#include <cstring>

class Character
{
    private:
        char name[31];
        double attackPoints;
        double lifePoints;
        char type[51];

    public:
        Character()
        {
            strcpy(type, "Ordinary Character");
        }
        Character(char* type)
        {
            strcpy(this->type, type);
        }
        
        double getLifePoints() const { return lifePoints;};
        double getAttackPoints() const { return attackPoints;};

        virtual void deal_damage_to(Character& other) const;
        virtual void take_damage(double points);
        virtual void heal(double points);
        bool compare_name(const char* name) const;
        virtual void print() const;
};

void Character::deal_damage_to(Character& other) const
{
    other.take_damage(attackPoints);
}
void Character::take_damage(double points)
{
    lifePoints -= points;
}
void Character::heal(double points)
{
    lifePoints += points;
}
bool Character::compare_name(const char* name) const
{
    return strcmp(this->name, name) == 0;
}
void Character::print() const
{
    std::cout << "Name: " << name           << std::endl
              << "Type: " << type           << std::endl
              << "HP: "   << lifePoints     << std::endl
              << "DMG: "  << attackPoints   << std::endl;
}

class Knight : public Character
{
    public:
        void take_damage(double points) override;
        void heal(double points) override;
        Knight() : Character("Knight"){};
};

void Knight::take_damage(double points)
{
    Character::take_damage(points * 0.75);
}

void Knight::heal(double points)
{
    Character::heal(points * 1.05);
}

class Archer : public Character
{

        void take_damage(double points) override;
        void deal_damage_to(Character& other) const override;
        Archer() : Character("Archer"){};
};
void Archer::take_damage(double points)
{
    Character::take_damage(points * 1.15);
}
void Archer::deal_damage_to(Character& other) const
{
    other.take_damage(getAttackPoints() * 1.33);
}
int main()
{
    Character* i = new Knight();
    i->print();
}
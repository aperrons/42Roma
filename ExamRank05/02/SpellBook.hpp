#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <string>
#include <map>
#include "ASpell.hpp"

class SpellBook {
private:
    std::map<std::string, ASpell*> spells;

    SpellBook(const SpellBook&);
    SpellBook& operator=(const SpellBook&);

public:
    SpellBook();
    ~SpellBook();

    void learnSpell(ASpell* spell);
    void forgetSpell(const std::string& spellName);
    ASpell* createSpell(const std::string& spellName);
};

#endif // SPELLBOOK_HPP

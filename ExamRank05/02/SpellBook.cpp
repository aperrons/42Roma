#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {
    std::map<std::string, ASpell*>::iterator it = spells.begin();
    while (it != spells.end()) {
        delete it->second;
        ++it;
    }
    spells.clear();
}

void SpellBook::learnSpell(ASpell* spell) {
    if (spell)
        spells[spell->getName()] = spell->clone();
}

void SpellBook::forgetSpell(const std::string& spellName) {
    std::map<std::string, ASpell*>::iterator it = spells.find(spellName);
    if (it != spells.end()) {
        delete it->second;
        spells.erase(it);
    }
}

ASpell* SpellBook::createSpell(const std::string& spellName) {
    std::map<std::string, ASpell*>::iterator it = spells.find(spellName);
    if (it != spells.end())
        return it->second->clone();
    return NULL;
}

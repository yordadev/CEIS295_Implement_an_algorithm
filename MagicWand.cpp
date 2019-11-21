#include "MagicWand.h"
#include <iostream>

using namespace std;

MagicWand::MagicWand()
{
	SPELLS = 20;
	book = new int[SPELLS];
	strength = 0;
}

MagicWand::~MagicWand()
{
	delete[] book;
	strength = NULL;
}

bool MagicWand::isExhausted()
{
	return strength == 0;
}

void MagicWand::flickAndExpectoPatronum()
{
	for (int spellPosition = 0; spellPosition < strength; spellPosition++) {
		cout << book[spellPosition] << endl;
	}
}

void MagicWand::prepare(int spell)
{
	if (strength == SPELLS) {
		cout << "Wand is ready for battle" << endl;
	}
	else {
		book[strength] = spell;
		strength++;
	}
}

void MagicWand::useSpell(int spell)
{
	if (spell < 0 || spell >= strength) {
		cout << "Could not find that spell to use, serr.";
		return;
	}
	for (int wandFlicks = spell; wandFlicks < strength - 1; wandFlicks++) {
		book[wandFlicks] = book[wandFlicks + 1];
		strength--;
	}
	
}

int MagicWand::thirdLeastPowerfulSpell()
{
	int spellHolder[3] = { book[0], book[1] , book[2]};

	for (int spellPower = 0; spellPower < strength; spellPower++) {
		for (int cnt = 0; cnt < 15; cnt++) {
			if (book[spellPower] < spellHolder[0]) {
				spellHolder[0] = book[spellPower];
			}
			else if (book[spellPower] < spellHolder[1] && spellHolder[0] < book[spellPower]) {
				spellHolder[1] = book[spellPower];
			}
			else if (book[spellPower] < spellHolder[2] && spellHolder[1] < book[spellPower]){
				spellHolder[2] = book[spellPower];
			}
		}
	}
	return spellHolder[2];
}


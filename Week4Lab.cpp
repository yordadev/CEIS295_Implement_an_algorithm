#include <iostream>
#include "MagicWand.h"
#include "Week4Lab.h"
#include <time.h>

int main()
{
	MagicWand Pottermore;
	int thisCollectionOfSpells[15] = {};

	srand((unsigned)time(0));

	for (int stamina = 0; stamina < 15; stamina++) {
		thisCollectionOfSpells[stamina] = rand() % 100;
	}

	for (int spellPosition = 0; spellPosition < 15; spellPosition++) {
		Pottermore.prepare(thisCollectionOfSpells[spellPosition]);
	}

	if (!Pottermore.isExhausted()) {
		Pottermore.flickAndExpectoPatronum();
		int spell = Pottermore.thirdLeastPowerfulSpell();

		std::cout << "the third least powerful spell is: " << spell << std::endl;
		system("pause");
	}

	std::cout << "Seems you are not ready yet to handle the wand Pottermore." << std::endl;
	system("pause");

}






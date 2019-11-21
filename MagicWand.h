#pragma once
class MagicWand
{
	public:
		MagicWand();
		~MagicWand();
		bool isExhausted();
		void flickAndExpectoPatronum();
		void prepare(int);
		void useSpell(int);
		int thirdLeastPowerfulSpell();

	private:
		int SPELLS;
		int *book;
		int strength;
};


#include <iostream>
#include <clocale>
#include <cstdint>
#include <string>

#include "Snack.h"
#include "SnakSlot.h"
#include "VendingMachine.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "Использование классов согласно домашнего задания" << endl;
	{
		Snack* bounty = new Snack("Bounty");
		Snack* snickers = new Snack("Snickers");
		SnakSlot* slot = new SnakSlot(10);
		slot->addSnack(bounty);
		slot->addSnack(snickers);
		uint16_t slotCount = 5;
		VendingMachine* machine = new VendingMachine(slotCount);
		machine->addSlot(slot);
		cout << machine->getEmptySlotsCount();

		delete machine;
		delete slot;
		delete snickers;
		delete bounty;
	}

	cout << endl << endl << "Тут прошу проверить реализацию конструкторов копирования и деструкторов" << endl;
	{
		Snack* snack_b1 = new Snack{ "Bounty", 25.45, 350 };
		Snack* snack_b2 = new Snack{ *snack_b1 };
		Snack* snack_b3 = new Snack{ *snack_b1 };
		Snack* snack_b4 = new Snack{ *snack_b1 };
		Snack* snack_b5 = new Snack{ *snack_b1 };

		Snack* snack_s1 = new Snack{ "Snickers", 19.95, 237 };
		Snack* snack_s2 = new Snack{ *snack_s1 };
		Snack* snack_s3 = new Snack{ *snack_s1 };
		Snack* snack_s4 = new Snack{ *snack_s1 };
		Snack* snack_s5 = new Snack{ *snack_s1 };

		SnakSlot* slot_b = new SnakSlot(10);
		slot_b->addSnack(snack_b1);
		slot_b->addSnack(snack_b2);
		slot_b->addSnack(snack_b3);
		slot_b->addSnack(snack_b4);
		slot_b->addSnack(snack_b5);
		slot_b->printSnakSlot();

		SnakSlot* slot_b2 = new SnakSlot{ *slot_b };
		slot_b2->printSnakSlot();

		SnakSlot* slot_s = new SnakSlot(8);
		slot_s->addSnack(snack_s1);
		slot_s->addSnack(snack_s2);
		slot_s->addSnack(snack_s3);
		slot_s->addSnack(snack_s4);
		slot_s->addSnack(snack_s5);
		slot_s->printSnakSlot();

		uint16_t slotCount = 5;
		VendingMachine* machine1 = new VendingMachine(slotCount);
		machine1->addSlot(slot_s);
		machine1->addSlot(slot_b);
		machine1->printMachine();

		VendingMachine* machine2 = new VendingMachine{ *machine1 };
		machine2->addSlot(slot_b2);
		cout << endl;
		machine2->printMachine();

		cout << endl;
		delete machine2;
		cout << endl;
		delete machine1;
		cout << endl;

		delete slot_s;
		delete slot_b;
		delete slot_b2;

		delete snack_s5;
		delete snack_s4;
		delete snack_s3;
		delete snack_s2;
		delete snack_s1;
		delete snack_b5;
		delete snack_b4;
		delete snack_b3;
		delete snack_b2;
		delete snack_b1;
	}
	return 0;
}
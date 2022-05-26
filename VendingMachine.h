#pragma once
#include <iostream>
#include <clocale>
#include <cstdint>
#include "SnakSlot.h"

using namespace std;

class VendingMachine
{
public:
	VendingMachine(uint16_t slotCount);
	VendingMachine(const VendingMachine& other);
	~VendingMachine();
	void addSlot(SnakSlot* slot);
	uint16_t getEmptySlotsCount();
	void printMachine();

private:
	uint16_t _slotCount;
	uint16_t _slotPosition;
	uint16_t _copyPosition; // для конструктора копий, чтобы в деструкторе удалить те объекты из кучи, что были созданы в конструкторе копий
	SnakSlot** _machine_ptr;
};


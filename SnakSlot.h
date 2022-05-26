#pragma once
#include <cstdint>
#include <string>
#include <iostream>
#include "Snack.h"

using namespace std;

class SnakSlot
{
public:
	SnakSlot(uint16_t slotSize);	
	SnakSlot(const SnakSlot& other);
	~SnakSlot();
	void addSnack(Snack* snack);
	uint16_t getEmptyCells();
	uint16_t getFullCells();
	void printSnakSlot();

private:
	uint16_t _slotSize;
	uint16_t _snackPosition;
	int16_t _copyPosition;   // ��� ������������ �����, ����� � ����������� ������� �� ������� �� ����, ��� ���� ������� � ������������ �����
	Snack** _slot_ptr;
};
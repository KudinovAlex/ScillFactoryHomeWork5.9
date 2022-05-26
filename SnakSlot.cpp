#include "SnakSlot.h"

SnakSlot::SnakSlot(uint16_t slotSize)
{
	_slotSize = slotSize;
	_snackPosition = 0;
	_copyPosition = _snackPosition;
	_slot_ptr = new Snack * [_slotSize];
	for (uint16_t i = 0; i < _slotSize; i++) {
		_slot_ptr[i] = nullptr;
	}
}

SnakSlot::SnakSlot(const SnakSlot& other)
{
	_slotSize = other._slotSize;
	_snackPosition = other._snackPosition;
	_copyPosition = _snackPosition;
	_slot_ptr = new Snack * [_slotSize];

	for (uint16_t i = 0; i < _slotSize; i++) {
		_slot_ptr[i] = other._slot_ptr[i] != nullptr ? new Snack{ *other._slot_ptr[i] } : nullptr;
	}
}

SnakSlot::~SnakSlot()
{
	while (_copyPosition > 0) {
		delete _slot_ptr[--_copyPosition];
	}
	delete[] _slot_ptr;
}

void SnakSlot::addSnack(Snack* snack)
{
	if (_snackPosition >= _slotSize) {
		cout << "Невозможно добавить снек, слот полон" << endl;
		return;
	}

	for (uint16_t i = 0; i < _snackPosition; i++) {
		if (_slot_ptr[i] != nullptr && _slot_ptr[i] == snack) {
			cout << "Этот снек уже загружен в слот" << endl;
			return;
		}
	}
	_slot_ptr[_snackPosition++] = snack;
}

uint16_t SnakSlot::getEmptyCells()
{
	if (_slot_ptr[0] == nullptr) return _slotSize;
	return _slotSize - _snackPosition;
}

uint16_t SnakSlot::getFullCells()
{
	if (_slot_ptr[0] == nullptr) return 0;
	return _snackPosition;
}

void SnakSlot::printSnakSlot()
{
	for (uint16_t i = 0; i < _snackPosition; i++) {
		cout << i << ": " << _slot_ptr[i] << " - " << *_slot_ptr[i];
	}
	cout << "Заполнено слотов: " << getFullCells() << endl;
	cout << "Свободно слотов: " << getEmptyCells() << endl << endl;
}
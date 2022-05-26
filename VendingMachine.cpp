#include "VendingMachine.h"

VendingMachine::VendingMachine(uint16_t slotCount)
{
	_copyPosition = 0;
	_slotPosition = 0;
	_slotCount = slotCount;
	_machine_ptr = new SnakSlot * [_slotCount];
	for (uint16_t i = 0; i < _slotCount; i++) {
		_machine_ptr[i] = nullptr;
	}
}

VendingMachine::VendingMachine(const VendingMachine& other)
{
	_copyPosition = other._slotPosition;
	_slotCount = other._slotCount;
	_slotPosition = other._slotPosition;
	_machine_ptr = new SnakSlot * [_slotCount];

	for (uint16_t i = 0; i < _slotCount; i++) {
		_machine_ptr[i] = other._machine_ptr[i] != nullptr ? new SnakSlot{ *other._machine_ptr[i] } : nullptr;
	}
}

VendingMachine::~VendingMachine()
{
	while (_copyPosition > 0) {
		delete _machine_ptr[--_copyPosition];
	}
	delete[] _machine_ptr;
}

void VendingMachine::addSlot(SnakSlot* slot)
{
	if (_slotPosition >= _slotCount) {
		cout << "Ќевозможно добавить слот, машина полна" << endl;
		return;
	}

	for (uint16_t i = 0; i < _slotPosition; i++) {
		if (_machine_ptr[i] != nullptr && _machine_ptr[i] == slot) {
			cout << "Ётот слот уже загружен в машину" << endl;
			return;
		}
	}

	_machine_ptr[_slotPosition++] = slot;
}

uint16_t VendingMachine::getEmptySlotsCount()
{
	uint16_t returnVal = 0;
	for (uint16_t i = 0; i < _slotCount; i++) {
		if (_machine_ptr[i] == nullptr) break;
		returnVal += _machine_ptr[i]->getEmptyCells();
	}
	return returnVal;
}

void VendingMachine::printMachine()
{
	for (uint16_t i = 0; i < _slotCount; i++) {
		if (_machine_ptr[i] == nullptr) {
			cout << "¬сего пустых слотов: " << getEmptySlotsCount() << endl;
			return;
		}
		_machine_ptr[i]->printSnakSlot();
	}
	cout << endl;
}

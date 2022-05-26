#include "Snack.h"

Snack::Snack(const string& name, const float& price, const uint16_t& calories)
{
	_name = name;
	_price = price;
	_calories = calories;
}

Snack::Snack(const string& name, const float& price)
{
	_name = name;
	_price = price;
	_calories = 0;
}

Snack::Snack(const string& name)
{
	_name = name;
	_price = 0;
	_calories = 0;
}

void Snack::setSnackName(const string& name)
{
	_name = name;
}

void Snack::setSnackPrice(const float& price)
{
	_price = price;
}

void Snack::setSnackCalories(const uint16_t& calories)
{
	_calories = calories;
}

string Snack::getSnackName() const
{
	return _name;
}

float Snack::getSnackPrice() const
{
	return _price;
}

uint16_t Snack::getSnackCalories() const
{
	return _calories;
}

ostream& operator<<(ostream& output, const Snack& m)
{
	output << "Название: " << m._name << "\tЦена: " << m._price << "\tКалорийность: " << m._calories << endl;
	return output;
}

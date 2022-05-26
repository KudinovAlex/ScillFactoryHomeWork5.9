#pragma once
#include <cstdint>
#include <string>
#include <iostream>
#include "Snack.h"

using namespace std;

class Snack
{
public:
	Snack(const string& name, const float& price, const uint16_t& calories);
	Snack(const string& name, const float& price);
	Snack(const string& name);
	void setSnackName(const string& name);
	void setSnackPrice(const float& price);
	void setSnackCalories(const uint16_t& calories);
	string getSnackName() const;
	float getSnackPrice() const;
	uint16_t getSnackCalories() const;
	friend ostream& operator<<(ostream& output, const Snack& m);

private:
	string _name;
	float _price;
	uint16_t _calories;
	bool _classCopy;
};
#include "food.h"

Food::Food() : name {""}, price{0}, quantity{0}
{	}

Food::Food(std::string name, float price, int quantity)
	: name {name}, price{price}, quantity{quantity}
{	}

void Food::setQuantity(int quantity)
{
	this->quantity = quantity;
}

float Food::getPrice()
{
	return price;
}

float Food::calculateTotal()
{
	return price * quantity;
}

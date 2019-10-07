#include "food.h"

Food::Food() : name {""}, price{0}, quantity{0}
{	}

Food::Food(QString name, double price, int quantity)
	: name {name}, price{price}, quantity{quantity}
{	}

void Food::setQuantity(int quantity)
{
	this->quantity = quantity;
}

double Food::getPrice()
{
	return price;
}

QString Food::getName()
{
	return name;
}

double Food::calculateTotal()
{
	return price * quantity;
}

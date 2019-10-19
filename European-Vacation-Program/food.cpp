#include "food.h"

Food::Food() : name {""}, price{0}, quantity{0}
{	}

Food::Food(QString name, double price, int quantity)
	: name {name}, price{price}, quantity{quantity}
{	}

Food::~Food()
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

Food &Food::operator=(Food other)
{
	std::swap(name, other.name);
	std::swap(price, other.price);
	std::swap(quantity, other.quantity);
	return *this;
}

Food &Food::operator=(Food &&other)
{
	name = std::move(other.name);
	price = std::move(other.price);
	quantity = std::move(other.quantity);
	return *this;
}

Food::Food(const Food &other)
{
	name = other.name;
	price = other.price;
	quantity = other.quantity;
}

Food::Food(Food &&other)
{
	name = other.name;
	price = other.price;
	quantity = other.quantity;

	other.name = nullptr;
	other.price = 0;
	other.quantity = 0;
}

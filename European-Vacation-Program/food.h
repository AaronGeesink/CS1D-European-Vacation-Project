#ifndef FOOD_H
#define FOOD_H

#include <string>

class Food
{
public:
	Food();
	Food(std::string name, float price, int quantity = 0);

	void setQuantity(int quantity);
	float getPrice();
	float calculateTotal();

private:
	std::string name;
	float price;
	int quantity;
};

#endif // FOOD_H

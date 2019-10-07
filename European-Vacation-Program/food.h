#ifndef FOOD_H
#define FOOD_H

#include <QString>

class Food
{
public:
	Food();
	Food(QString name, double price, int quantity = 0);

	void setQuantity(int quantity);
	double getPrice();
	QString getName();
	double calculateTotal();

private:
	QString name;
	double price;
	int quantity;
};

#endif // FOOD_H

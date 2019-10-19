#ifndef FOOD_H
#define FOOD_H

#include <QString>
#include <utility>

class Food
{
public:
	Food();
	Food(QString name, double price, int quantity = 0);
	~Food();

	void setQuantity(int quantity);
	double getPrice();
	QString getName();
	double calculateTotal();

	Food& operator=(Food other);
	Food& operator=(Food&& other);
	Food(const Food& other);
	Food(Food&& other);

private:
	QString name;
	double price;
	int quantity;
};

#endif // FOOD_H

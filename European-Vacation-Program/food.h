#ifndef FOOD_H
#define FOOD_H

#include <QString>
#include <utility>

/**
 *@author Aaron Geesink
 *@brief Food class
 * A food class for instantiating food
 *@date October 2019
 */
class Food
{
public:
	/**
	 *@author Aaron Geesink
	 *@brief Food()
	 * Default constructor
	 */
	Food();

	/**
	 *@author Aaron Geesink
	 *@brief Food(QString name, double price, int quantity = 0)
	 * Overloaded constructor
	 */
	Food(QString name, double price, int quantity = 0);

	/**
	 *@author Aaron Geesink
	 *@brief ~Food()
	 * Destructor
	 */
	~Food();

	/**
	 *@author Aaron Geesink
	 *@brief setQuantity(int quantity)
	 * Sets the quantity of food the user purchases
	 * @param int quantity
	 */
	void setQuantity(int quantity);

	/**
	 *@author Aaron Geesink
	 *@brief getPrice()
	 * Returns the price of a food item
	 * @return double
	 */
	double getPrice();

	/**
	 *@author Aaron Geesink
	 *@brief getName()
	 * Returns the name of a food item
	 * @return Qstring
	 */
	QString getName();

	/**
	 *@author Aaron Geesink
	 *@brief calculateTotal()
	 * Returns the total price of all purchased food items
	 * @return double
	 */
	double calculateTotal();

	/**
	 *@author Aaron Geesink
	 *@brief getQuantity()
	 * Returns the quantity of food purchased of a given food item
	 * @return int
	 */
	int getQuantity();

	/**
	 *@author Aaron Geesink
	 *@brief operator=(Food other)
	 * An copy assignment for food items
	 * @return Food &
	 */
	Food& operator=(Food other);

	/**
	 *@author Aaron Geesink
	 *@brief operator=(Food&& other)
	 * A move assignment for food items
	 * @return Food&
	 */
	Food& operator=(Food&& other);

	/**
	 *@author Aaron Geesink
	 *@brief Food(const Food& other);
	 * A copy constructor for food items
	 */
	Food(const Food& other);

	/**
	 *@author Aaron Geesink
	 *@brief Food(const Food& other);
	 * A copy assignment for food items
	 */
	Food(Food&& other);

private:
	QString name;	/// The name of the food item
	double price;	/// The price of a food item
	int quantity;	/// The quantity of food purchased
};

#endif // FOOD_H

#include "dbQuery.h"

std::vector<QString> queryCityNames()
{
	std::vector<QString> cityNames;

	// City names are hard coded for testing purposes
	// will query city names from the SQL database once it it implemented
	cityNames.push_back("London");
	cityNames.push_back("Berlin");
	cityNames.push_back("Paris");
	cityNames.push_back("Rome");

	return cityNames;
}

#include <stdio.h>

int main(void)
{
	int highBurger, middleBurger, lowBurger, cola, cider;
	int minBurger = 0, minBeverage = 0;

	scanf("%d %d %d %d %d", &highBurger, &middleBurger, &lowBurger, &cola, &cider);

	minBurger = highBurger;
	if (minBurger > middleBurger)
		minBurger = middleBurger;
	if (minBurger > lowBurger)
		minBurger = lowBurger;

	minBeverage = cola;
	if (minBeverage > cider)
		minBeverage = cider;

	printf("%d\n", minBurger + minBeverage - 50);

	return 0;
}

#include "dog.h"
#include "stddef.h"

/**
 * init_dog - initializes a variable of type struct dog
 * @d: pointer to the struct dog
 * @name: name to assign
 * @age: age to assign
 * @owner: owner to assign
 */

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d != NULL)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}

#include "Updatable.h"

void Updatable::Updating()
{
	if (!IsEnable()) return;

	Update();
}

void Updatable::Starting()
{
	if (!IsEnable()) return;

	Start();
}


void Updatable::Awakeing()
{
	if (!IsEnable()) return;

	Awake();
}

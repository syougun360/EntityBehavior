#include "Renderable.h"

void Renderable::Rendering()
{
	if (!IsEnable()) return;

	Render();
}
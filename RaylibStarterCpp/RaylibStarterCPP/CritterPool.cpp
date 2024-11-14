#include "CritterPool.h"

#include <utils.h>
#include <iostream>
//CrittaPool::CrittaPool()
//
//	std::vector<Critta*> c;
//	crittasInPool = c;
//	inactiveIndex = 0;
//

CritterPool::CritterPool(const std::vector<Critter*> _objects)
{
	crittersInPool = _objects;
	inactiveIndex = crittersInPool.size() - 1;
}

Critter* CritterPool::Activate()
{
	//check for inactive crittas
	if(inactiveIndex == crittersInPool.size())
	{
		return nullptr;
	}
	inactiveIndex++;
	return crittersInPool[inactiveIndex - 1];
}

void CritterPool::Deactivate(Critter* c)
{
	c->Destroy();
	inactiveIndex--;
	std::swap(c, crittersInPool[inactiveIndex]);
}

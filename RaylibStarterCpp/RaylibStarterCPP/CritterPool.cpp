#include "CritterPool.h"

#include <iostream>
#include <algorithm>
//CrittaPool::CrittaPool()
//
//	std::vector<Critta*> c;
//	crittasInPool = c;
//	inactiveIndex = 0;
//

CritterPool::CritterPool(const std::vector<Critter*>& _objects)
{
	crittersInPool = _objects;
	inactiveIndex = crittersInPool.size() - 1;
}

CritterPool::~CritterPool()
{
	for (auto critter : crittersInPool)
	{
		delete critter;
	}
	crittersInPool.clear();
}

//make this void return, and have critter activate before increment
Critter* CritterPool::Activate()
{
	//check for inactive crittas
	//rexamine this, thiis should be an impossible state as it implies youre indexing out of bounds
	if (inactiveIndex == crittersInPool.size())
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
	auto foundPos = std::find(crittersInPool.begin(), crittersInPool.end(), c);
	//how to calculate index
	//foundPos - crittersInPool.begin();
	std::swap(*foundPos, crittersInPool[inactiveIndex]);

}

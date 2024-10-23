#include "CrittaPool.h"

#include <utils.h>
#include <iostream>
//CrittaPool::CrittaPool()
//
//	std::vector<Critta*> c;
//	crittasInPool = c;
//	inactiveIndex = 0;
//

CrittaPool::CrittaPool(const std::vector<Critta*> _objects)
{
	crittasInPool = _objects;
	inactiveIndex = crittasInPool.size() - 1;
}

Critta* CrittaPool::Activate()
{
	//check for inactive crittas
	if(inactiveIndex == crittasInPool.size())
	{
		return nullptr;
	}
	inactiveIndex++;
	return crittasInPool[inactiveIndex - 1];
}

void CrittaPool::Deactivate(Critta* c)
{
	c->Destroy();
	inactiveIndex--;
	std::swap(c, crittasInPool[inactiveIndex]);
}

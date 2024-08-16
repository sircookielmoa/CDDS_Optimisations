#include "CrittaPool.h"

#include <utils.h>

//CrittaPool::CrittaPool()
//
//	std::vector<Critta*> c;
//	crittasInPool = c;
//	inactiveIndex = 0;
//

CrittaPool::CrittaPool(const std::vector<Critta*>& _objects)
{
	crittasInPool = _objects;
	//poolSize = crittasInPool.size();
	inactiveIndex = crittasInPool.size();
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
	
}

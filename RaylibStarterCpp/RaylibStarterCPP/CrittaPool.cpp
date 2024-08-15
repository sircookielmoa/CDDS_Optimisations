#include "CrittaPool.h"

CrittaPool::CrittaPool()
{
	
}

CrittaPool::CrittaPool(std::vector<Critta*> _objects)
{
	
}

void CrittaPool::Allocate()
{
	
}

void CrittaPool::Deallocate()
{
	
}

void CrittaPool::IsActive(bool _isDead)
{
	if(_isDead == true)
	{
		//blah blah blah
		//deallocate(?) so that critta stays dead
		//that typa thing
	}
	else
	{
		//maybe allocate(?) reallocate(?)
		//just leave it ig. i mean its already alive
		//type stuff
	}
}

//std::vector<Critta*> CrittaPool::ActiveCrittas()
//{
//
//}

#ifndef _OBJECT_STRUCTURE_H_
#define _OBJECT_STRUCTURE_H_
//存储数据结构
#include"element.h"
#include<list>

class City
{
public:
	~City();
	void Attach(IPlace* place);
	void Detach(IPlace* place);
	void Accept(IVisitor* visitor);

private:
	std::list<IPlace*> m_listPlace;
};

City::~City(){}

void City::Attach(IPlace* place)
{
	m_listPlace.push_back(place);
}

void City::Detach(IPlace* place)
{
	m_listPlace.remove(place);
}

void City::Accept(IVisitor* visitor)
{
	// 为每一个 element 设置 visitor，进行对应的操作
	for (std::list<IPlace*>::iterator it = m_listPlace.begin(); it != m_listPlace.end(); ++it)
	{
		(*it)->Accept(visitor);
	}
}

#endif // !_OBJECT_STRUCTURE_H_

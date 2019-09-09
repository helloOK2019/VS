#ifndef _FLYWEIGHT_H_
#define _FLYWEIGHT_H_
//抽象享元
class FlyWeight
{
public:
	FlyWeight();
	virtual ~FlyWeight();
	virtual void Operation() = 0;//
private:

};
//具体享元
class ConcreteFlyWeight : public FlyWeight	//继承
{
public:
	ConcreteFlyWeight();
	~ConcreteFlyWeight();
	void Operation();
private:

};

#endif // !_FLYWEIGHT_H_

#ifndef _FLYWEIGHT_H_
#define _FLYWEIGHT_H_
//������Ԫ
class FlyWeight
{
public:
	FlyWeight();
	virtual ~FlyWeight();
	virtual void Operation() = 0;//
private:

};
//������Ԫ
class ConcreteFlyWeight : public FlyWeight	//�̳�
{
public:
	ConcreteFlyWeight();
	~ConcreteFlyWeight();
	void Operation();
private:

};

#endif // !_FLYWEIGHT_H_

#pragma once

#include <assert.h>
#include <cstdio>

#pragma execution_character_set("utf-8")

template<class E>
class SeqQueue 
{	 //队列类定义
protected:
	int rear, front;		       //队尾与队头指针
	E *elements;		       //队列存放数组
	int maxSize;		       //队列最大容量
public:
	SeqQueue(int sz = 10);                    //构造函数
	~SeqQueue() { delete[] elements; }  //析构函数
	bool EnQueue(E x);            //新元素进队列
	bool DeQueue(E& x);         //退出队头元素
	bool getFront(E& x);	      //取队头元素值
	bool getRear(E& x);
	void makeEmpty() { front = rear = 0; }
	bool IsEmpty() const { return front == rear; }
	bool IsFull() const
	{
		return ((rear + 1) % maxSize == front);
	}
	int getSize() const
	{
		return (rear - front + maxSize) % maxSize;
	}
};

template<class E>
SeqQueue<E>::SeqQueue(int sz)
: front(0), rear(0), maxSize(sz) 
{     //构造函数
	elements = new E[maxSize];
	for (int i = 0; i < maxSize; i++)
		elements[i] = 0;
	assert(elements != NULL);
};

template<class E>
bool SeqQueue<E>::getFront(E& x) 
{
	//若队列不空则函数返回该队列队头元素的值
	if (IsEmpty() == true) return false;    //队列空
	x = elements[front];		    //返回队头元素
	return true;
};

template<class E>
bool SeqQueue<E>::getRear(E &x)
{
	if (IsEmpty() == true) return false;
	if (rear == 0){
		x = elements[maxSize - 1];
	}
	else{
		x = elements[(rear - 1) % maxSize];
	}
	return true;
}

template<class E>
bool SeqQueue<E>::EnQueue(E x)
{
	//若队列不满, 则将x插入到该队列队尾, 否则返回    
	if (IsFull() == true) return false;
	elements[rear] = x;                    //先存入
	rear = (rear + 1) % maxSize;       //尾指针加一
	return true;
};

template<class E>
bool SeqQueue<E>::DeQueue(E& x)
{   //若队列不空则函数退队头元素并返回其值
	if (IsEmpty() == true) return false;
	x = elements[front];                  //先取队头
	front = (front + 1) % maxSize;   //再队头指针加一
	return true;
};

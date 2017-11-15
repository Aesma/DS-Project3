#pragma once

#include <assert.h>
#include <cstdio>

#pragma execution_character_set("utf-8")

template<class E>
class SeqQueue 
{	 //�����ඨ��
protected:
	int rear, front;		       //��β���ͷָ��
	E *elements;		       //���д������
	int maxSize;		       //�����������
public:
	SeqQueue(int sz = 10);                    //���캯��
	~SeqQueue() { delete[] elements; }  //��������
	bool EnQueue(E x);            //��Ԫ�ؽ�����
	bool DeQueue(E& x);         //�˳���ͷԪ��
	bool getFront(E& x);	      //ȡ��ͷԪ��ֵ
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
{     //���캯��
	elements = new E[maxSize];
	for (int i = 0; i < maxSize; i++)
		elements[i] = 0;
	assert(elements != NULL);
};

template<class E>
bool SeqQueue<E>::getFront(E& x) 
{
	//�����в����������ظö��ж�ͷԪ�ص�ֵ
	if (IsEmpty() == true) return false;    //���п�
	x = elements[front];		    //���ض�ͷԪ��
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
	//�����в���, ��x���뵽�ö��ж�β, ���򷵻�    
	if (IsFull() == true) return false;
	elements[rear] = x;                    //�ȴ���
	rear = (rear + 1) % maxSize;       //βָ���һ
	return true;
};

template<class E>
bool SeqQueue<E>::DeQueue(E& x)
{   //�����в��������˶�ͷԪ�ز�������ֵ
	if (IsEmpty() == true) return false;
	x = elements[front];                  //��ȡ��ͷ
	front = (front + 1) % maxSize;   //�ٶ�ͷָ���һ
	return true;
};

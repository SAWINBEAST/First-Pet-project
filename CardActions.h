#pragma once
#include <iostream>
#include <string>
using namespace std;

class CardActions {
private:

public:
	CardActions()
	{}
	~CardActions()
	{
		std::cout << "Destructor called for class CardActions" << std::endl;
	}
	//����� ������ �����
	void GetNums();
	//�������� ����� �����
	void EnterNew();	//21
	//��������� ������ ������ �����
	void ChangeNumsFirst();
	void ChangeNumsSecond();
	//�������� ����� ����� ������������
	void RemoveCard();
	//�������� ���� ���� ������������
	void RemoveCards();
};
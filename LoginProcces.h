#pragma once
#include <iostream>
#include <string>
using namespace std;

//�������� ����� � �����������
class LoginProcess {
private:

public:
	LoginProcess()
	{}
	~LoginProcess()
	{}
	// �������� ����������� ������ ������������ � ������ ��� ������ � ����
	void Registration();
	// ������������ ���� ��� ������������������� ������������
	bool IsLoggedIn();

}; 

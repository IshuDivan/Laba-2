#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Order {
public:
	string ido;
	int price;
	int deadline;
	string address;
	string courierid;
	int weight;
	void addorder(string orderfile);
	void osearchid(string orderfile); // ����� �� id
};

class Courier {
public:
	string idc;
	string name;
	string phone;
	string orderid1; // ������� �����
	string orderid2; // ������� �����
	int car;
	int deliverytime;
	void addcourier(string courierfile);
	void courierdeleting(string courierfile); // �������� �� id
	void csearchname(string courierfile); // ����� �� ����� 
	void csearchphone(string courierfile); // ����� �� ��������
	void allcourierclear(string courierfile); //�������� ���� � �������
	};

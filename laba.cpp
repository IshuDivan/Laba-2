void addcourier(string courierfile)
{//���������� ��������
	ifstream fin;
	ofstream fout;
	fin.open(courierfile);
	int  i = 0;
	int k = 0;
	string s;
	cout << "Enter the courier you want to put('name /n phone /n idc /n car(0 or 1)')" << endl;
	while (!fin.eof()) {//������� ���������� ����� � ������=���������� ����� ��������
		getline(fin, s);
		k++;
	}
	k--;
	Courier* a = new Courier[k + 1];//�������� ������ �� ������ ����  struct(� �������)
	//fin.seekg( 0 );//�� �������� ������� ������ � ������
	fin.close();//������� �� �����
	fin.open(courierfile);
	for (i = 0; i < k; i++) {
		fin >> a[i].idc;
		fin >> a[i].name;
		fin >> a[i].phone;
		fin >> a[i].orderid1;
		fin >> a[i].orderid2;
		fin >> a[i].car;
		fin >> a[i].deliverytime;
		//��������� �������� �� �����, ������ ������� �� ����� ��� ������� ��������
	}
	int j;
	string name;
	string phone;
	string idc;
	int car;
	cin >> name >> phone >> idc >> car;
	for (i = 0; i < k; i++) {
		if (a[i].idc == idc) {//���������� ��������� 
			cout << "courier with same id already exists. Try the other one" << endl;
			fin.close();
			exit(0);
		}
		if (a[i].name == name) {//���������� ��������� 
			cout << "courier with same name already exists. Try the other one" << endl;
			fin.close();
			exit(0);
		}
		if (a[i].phone == phone) {//���������� ��������� 
			cout << "courier with same phone already exists. Try the other one" << endl;
			fin.close();
			exit(0);
		}
	}
	fin.close();//��������� ��������� �������� ����
	a[k].idc = idc;
	a[k].name = name;
	a[k].phone = phone;
	a[k].car = car;
	a[k].deliverytime = 30 - 20 * car; // ����� �������� ��� ������ �������, 10 ���. � �������, 30 ���. ��� ������, ��� ��� car ��������� �������� 1, ���� ���� ������, 0 - ���� ���
	a[k].orderid1 = "0";
	a[k].orderid2 = "0";
	fout.open(courierfile, ios::out);//�� ����� � �����, �� �� ������ ������
	for (i = 0; i < k + 1; i++) {//������������ ���� ����������� ������ � ��������
		fout << a[i].idc << " " << a[i].name << " " << a[i].phone << " " << a[i].orderid1 << " "a[i].orderid2 << " " << a[i].car << " " << a[i].deliverytime << endl;
	}
	fout.close();//������� �� �����
	delete[] a;//������� �� ������2
}
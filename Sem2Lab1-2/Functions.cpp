#include "students.h" // ����������� ����������������� ������������� �����

using namespace std;

struct Students // ��������� �� �������
{
	string* group;
	string* faculty;
	int* countOfStudents;
	int* countOfGoodStudents;
};

// ���� ���������� ����������

bool flag = false;

// ���� ������������� ���������� ����������

int totalAmountStudents = 0;
int totalGoodStudents = 0;
int storagedMemory = 0;

// �������� ���������� ���������� ���������

Students students;

// ���� ����

void menu() {
	int k = 0;

	while (k != 5) {
		cout << "\n �������� ����� ���� \n";
		cout << " 1 - ��������� ����" << "\n";
		cout << " 2 - �������� ����" << "\n";
		cout << " 3 - ����� ������� �� ����� ���������" << "\n";
		cout << " 4 - ��������� ����" << "\n";
		cout << " 5 - �����" << "\n";
		cin >> k;
		switch (k)
		{
			case 1:{
					inputFromFile();
			}break;

			case 2: {
					choseEdit();
			}break;

			case 3: {
					cout << "\n" << percentOfGoodStudents();
			}break;

			case 4: {
					writeFile();
			}break;
			case 5: {
					exit;
			}break;

			default: {
					cout << "\n �� ��������������� �������� \n";
			}break;
		}
	}
}

// �������� ��� �������� �������� ������

int getsetMemory(int memory)  { // >0 ��� ������ �������� ������ <=0 ��� ����� �������� ������

	if(memory < 0){
		return storagedMemory;
	}
	else {
		storagedMemory = memory;
	}
}

// ���� ��������������� ���������� ������������ ���������� ����� ��� �������

int findValueOfMemory(string fileName) {
	// ��������� ����������
	char *temp;
	string *tempS;

	//
	
	int memorySTR = 0; // ���������� �����
	int memoryCOL = 0; // ���������� �������


	ifstream fin;
	fin.open(fileName);
	// ��������� ������ ��������� ������

	tempS = new string;
	temp = new char[32];

	while (!fin.eof())
	{
		fin.getline(temp, 32, '\n');
		memorySTR++;
	}
	fin.close();
	
	fin.open(fileName);

	while (!fin.eof())
	{
		fin >> *tempS;
		memoryCOL++;
	}
	fin.close();

	// ����� ���������� ������� �� ���������� �����, � ��� �� ��������� ��� ��������, ����� ������ ������� ������ ��� ������ ��� ����������.

	memoryCOL = floor(memoryCOL/memorySTR);
	
	cout << "������ ������� ���������: "<< memorySTR << "\n";
	cout << "������ ������� ���������: "<< memoryCOL << "\n";

	// ������������ ��������� ������
	delete tempS;
	delete temp;

	// ��������� ���������� ����� � �������� ���������� � ���������� ����������� �����

	getsetMemory(memorySTR);
	return memorySTR;
}

	// ���� ����� �� ����� � ���������� 

void inputFromFile() {
	string fileName;
	int memory = 0;

	ifstream finp;

	cout << "\n ������� ��� ��������� �����, ��� ����������.\n";
	cout << "���� ���� � ����� � ����������, ������ ��� �����. ����� ���� �� ����. \n";
	cout << "����:  "; 
	cin >> fileName;

	// ����� ������� ��������������� ����������� ������� �������
	memory = findValueOfMemory(fileName);
	finp.open(fileName);


	students.faculty = new string[memory];
	students.group = new string[memory];
	students.countOfGoodStudents = new int[memory];
	students.countOfStudents = new int[memory];
	
	int it = 0;

	while (it < memory) {
		finp >> students.faculty[it];
		finp >> students.group[it];
		finp >> students.countOfStudents[it];
		finp >> students.countOfGoodStudents[it];
		totalAmountStudents += students.countOfStudents[it];
		totalGoodStudents += students.countOfGoodStudents[it];
		cout << "\n � ���� ����� ����� ���������: " << totalAmountStudents << " |  " << students.countOfStudents[it];
		cout << "\n � ���� ����� ����� good ���������: " << totalGoodStudents << " |  " << students.countOfGoodStudents[it];
		it++;
	}

	if(memory > 0){
		flag = true;
	}
	else {
		cout << "� ��������� ������ �� ���� ��������, ������ ��� ���� ������.";
	}

}

// ���� ������ ������������ �������� ��� ��������������

void choseEdit() {
	int p = 0;
	int memory = getsetMemory(-1);
	int elementNum;

	if (flag == true) {
		cout << "��� �� ������ ��������? \n";
		cout << "1 - ��������� \n";
		cout << "2 - ������ \n";
		cout << "3 - ���������� ���������\n";
		cout << "4 - ���������� ���������� \n";
		cout << "5 - ����� � ���� \n";

		
		cin >> p;

		switch (p)
		{
		case 1: {
			cout << "����� ������� �� ����� �� ������ �������������? \n";
			cout << "� ��������� �� 1 �� " << memory << "\n";
			cin >> elementNum;
			if (elementNum < memory && flag == true) {
				edit(p, elementNum);
			}
			else {
				cout << "������ �������� �� ����������";
			}
		}break;
		case 2: {
			cout << "����� ������� �� ����� �� ������ �������������? \n";
			cout << "� ��������� �� 1 �� " << memory << "\n";
			cin >> elementNum;
			if (elementNum < memory && flag == true) {
				edit(p, elementNum);
			}
			else {
				cout << "������ �������� �� ����������";
			}
		}break;
		case 3: {
			cout << "����� ������� �� ����� �� ������ �������������? \n";
			cout << "� ��������� �� 1 �� " << memory << "\n";
			cin >> elementNum;
			if (elementNum < memory && flag == true) {
				edit(p, elementNum);
			}
			else {
				cout << "������ �������� �� ����������";
			}
		}break;
		case 4: {
			cout << "����� ������� �� ����� �� ������ �������������? \n";
			cout << "� ��������� �� 1 �� " << memory << "\n";
			cin >> elementNum;
			if (elementNum < memory && flag == true) {
				edit(p, elementNum);
			}
			else {
				cout << "������ �������� �� ����������";
			}
		}break;
		case 5: {
			menu();
		}
		default:
			break;
		}
	}
	else
	{
		cout << "\n ���� �� ��� ��������, ���������� �������� �������� \n";
	}
}

 //���� �������������� ����������� ����������

void edit(int typeForEditing, int elementForEditing) {
	string newStr;
	int newInt = 0;


	switch (typeForEditing)
	{
	case 1: {
		cout << "������� ������ �� ������� ������ ��������" << '\n';
		cin >> newStr;
		students.faculty[elementForEditing - 1] = newStr;
	}break;
	case 2: {
		cout << "������� ������ �� ������� ������ ��������" << '\n';
		cin >> newStr;
		students.group[elementForEditing - 1] = newStr;
	}break;
	case 3: {
		cout << "������� ����� ����� �� ������� ������ ��������" << '\n';
		cin >> newInt;
		students.countOfStudents[elementForEditing - 1] = newInt;
	}break;
	case 4: {
		cout << "������� ����� ����� �� ������� ������ ��������" << '\n';
		cin >> newInt;
		students.countOfGoodStudents[elementForEditing - 1] = newInt;
	}break;

	default:
		break;
	}

}

// ���� ���������� �������� ������� ���������

double percentOfGoodStudents() {
	double percantage = 0.0;
	double allStudents = totalAmountStudents;
	double goodStudents = totalGoodStudents;

	if (allStudents > 0 && goodStudents > 0) {
		percantage = (goodStudents / allStudents) * 100.0;
		return percantage;
	}
	else
	{
		cout << "\n ����������� ���������� ��������� \n ���������� ��������������� ������� ���� 1. \n";
	}

}

// ���� ������ � ����

void writeFile() {
	int counter = 0;
	int amountOfUnits = getsetMemory(-1);
	double percent;
	if (percentOfGoodStudents > 0) {
		percent = percentOfGoodStudents();
	}
	else {
		cout << "\n ��������� ���. \n";
	}
	cout << percent;
	string fileName;
	cout << "\n ������� ��� ����� � ����������. \n";
	cin >> fileName;

	ofstream ofs(fileName);
	ofs <<"������� ���������� = "  << percent << "% \n";
	ofs << "��������� | " << " ������ | " << " ���������� �������� | " << " ���������� ���������� " << "\n";

	while (counter < amountOfUnits) {
		ofs << students.faculty[counter] << " ";
		ofs << students.group[counter] << " ";
		ofs << students.countOfStudents[counter] << " ";
		ofs << students.countOfGoodStudents[counter] << "\n";
		counter++;
	}
}
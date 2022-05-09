//#include<iostream>
//#include<string>
//#include<time.h>
//#include<math.h>
//#include<conio.h>
//#include<stdio.h>
//#include<windows.h>
//using namespace std;
//
//void gotoxy(int x, int y) {
//	COORD coord;
//	coord.X = x;
//	coord.Y = y;
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//}
//
//class Node {
//private:
//	Node* next;
//	Node* prev;
//	Node* top;
//	Node* bot;
//	Node* dkaatas;
//	Node* dkiatas;
//	Node* dkabawah;
//	Node* dkibawah;
//	int value, urutan;
//public:
//	Node(int val = 0) {
//		value = val;
//		next = NULL;
//		prev = NULL;
//		top = NULL;
//		bot = NULL;
//		dkaatas = NULL;
//		dkiatas = NULL;
//		dkabawah = NULL;
//		dkibawah = NULL;
//	}
//	void setUrutan(int _urutan) {
//		urutan = _urutan;
//	}
//	void setVal(int _value) {
//		value = _value;
//	}
//	void setNext(Node* _next) {
//		next = _next;
//	}
//	void setPrev(Node* _prev) {
//		prev = _prev;
//	}
//	void setTop(Node* _top) {
//		top = _top;
//	}
//	void setBot(Node* _bot) {
//		bot = _bot;
//	}
//	void setDkananAtas(Node* _dkaatas) {
//		dkaatas = _dkaatas;
//	}
//	void setDkiriAtas(Node* _dkiatas) {
//		dkiatas = _dkiatas;
//	}
//	void setDkananBawah(Node* _dkabawah) {
//		dkabawah = _dkabawah;
//	}
//	void setDkiriBawah(Node* _dkibawah) {
//		dkibawah = _dkibawah;
//	}
//	int getUrutan() {
//		return urutan;
//	}
//	int getVal() {
//		return value;
//	}
//	Node* getNext() {
//		return next;
//	}
//	Node* getPrev() {
//		return prev;
//	}
//	Node* getTop() {
//		return top;
//	}
//	Node* getBot() {
//		return bot;
//	}
//	Node* getDkananAtas() {
//		return dkaatas;
//	}
//	Node* getDkiriAtas() {
//		return dkiatas;
//	}
//	Node* getDkananBawah() {
//		return dkabawah;
//	}
//	Node* getDkiriBawah() {
//		return dkibawah;
//	}
//};
//
//class OctaLinkedList {
//private:
//	int size;
//	Node* head;
//	Node* tail;
//	int cek = 0;
//public:
//	OctaLinkedList() {
//		head = NULL;
//		tail = NULL;
//		size = 0;
//		cek = 0;
//	}
//	bool batasAtas(int angka, int n = 0) {
//		if (angka > 0 && angka <= 9)
//			return true;
//		return false;
//	}
//	bool batasKiri(int angka, int n = 0) {
//		int x = angka;
//		while (angka > 0) {
//			angka -= 20;
//		}
//		if (angka == 0)
//			return true;
//		return false;
//	}
//	bool batasKanan(int angka, int n = 0) {
//		int x = angka;
//
//		while (x > 10) {
//			x -= 20;
//		}
//		if (x == 10)
//			return true;
//		return false;
//	}
//	bool batasKiriDiagonal(int angka, int n = 0) {
//		int x = angka;
//		while (angka > 0) {
//			angka -= 20;
//		}
//		if (angka == 0)
//			return true;
//
//		while (x > 19) {
//			x -= 20;
//		}
//		if (x == 19)
//			return true;
//		return false;
//	}
//	bool batasKananDiagonal(int angka, int n = 0) {
//		int x = angka;
//		while (angka > 9) {
//			angka -= 20;
//		}
//		if (angka == 9)
//			return true;
//
//		while (x > 10) {
//			x -= 20;
//		}
//		if (x == 10)
//			return true;
//		return false;
//	}
//	void field(int n, int player = 1) {
//		HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
//		int x = n, a = 8;
//		while (n > 0) {
//			gotoxy(36, a++);
//			cout << "-";
//			for (int i = 0; i < 10; i++)
//			{
//				cout << "------";
//			}
//			gotoxy(36, a++);
//			cout << "|";
//			for (int i = 0; i < 10; i++)
//			{
//				cout << "     |";
//			}
//			n -= 10;
//			x = n;
//			if (n < 10) {
//				x = 10;
//			}
//		}
//		gotoxy(36, a++);
//		cout << "-";
//		for (int i = 0; i < 10; i++)
//		{
//			cout << "------";
//		}
//
//		if (player == 1)
//			SetConsoleTextAttribute(hstdout, 12);
//		else
//			SetConsoleTextAttribute(hstdout, 11);
//
//		gotoxy(36, a + 2);
//		cout << "-------------------------------------------------------------";
//		gotoxy(36, a + 3);
//		cout << "|                                                           |";
//		gotoxy(36, a + 4);
//		cout << "-------------------------------------------------------------";
//
//		SetConsoleTextAttribute(hstdout, 15);
//	}
//	void addValue(int val) {
//		Node* temp = new Node(val);
//		temp->setUrutan(size);
//		if (size == 0) {
//			head = temp;
//			tail = temp;
//		}
//		else if (batasAtas(size)) {
//			tail->setNext(temp);
//			temp->setPrev(tail);
//			tail = temp;
//		}
//		else if (batasKanan(size) || batasKiri(size)) {
//			tail->setBot(temp);
//			temp->setTop(tail);
//
//			//dibedakan
//			if (batasKanan(size)) {
//				tail->getPrev()->setDkananBawah(temp);
//				temp->setDkiriAtas(tail->getPrev());
//				cek = 1;
//			}
//			else {
//				tail->getPrev()->setDkiriBawah(temp);
//				temp->setDkananAtas(tail->getPrev());
//				cek = 0;
//			}
//			tail = temp;
//		}
//		else {
//			tail->setNext(temp);
//			temp->setPrev(tail);
//
//			temp->setTop(tail->getTop()->getPrev());
//			tail->getTop()->getPrev()->setBot(temp);
//
//			if (batasKananDiagonal(size)) {
//				tail->getTop()->setDkananBawah(temp);
//				temp->setDkiriAtas(tail->getTop());
//			}
//			else if (batasKiriDiagonal(size)) {
//				tail->getTop()->setDkiriBawah(temp);
//				temp->setDkananAtas(tail->getTop());
//			}
//
//			if (!batasKananDiagonal(size) && !batasKiriDiagonal(size)) {
//				if (cek == 1) {
//					tail->getTop()->getPrev()->getPrev()->setDkananBawah(temp);
//					temp->setDkiriAtas(tail->getTop()->getPrev()->getPrev());
//
//					tail->getTop()->setDkiriBawah(temp);
//					temp->setDkananAtas(tail->getTop());
//				}
//				if (cek == 0) {
//					tail->getTop()->getPrev()->getPrev()->setDkiriBawah(temp);
//					temp->setDkananAtas(tail->getTop()->getPrev()->getPrev());
//
//					tail->getTop()->setDkananBawah(temp);
//					temp->setDkiriAtas(tail->getTop());
//				}
//			}
//			tail = temp;
//		}
//		size++;
//	}
//	int getSize() {
//		return size;
//	}
//	void display() {
//		HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
//
//		Node* iterator = head;
//		int x = 38, y = 9, z = 0;
//		for (int i = 0; i < size; i++) {
//			if (z == 0) {
//				gotoxy(x, y);
//			}
//			else if (z == 1) {
//				gotoxy(130 - x, y);
//			}
//
//			if (iterator->getVal() == 0) {
//				SetConsoleTextAttribute(hstdout, 7);
//				cout << iterator->getUrutan();
//				SetConsoleTextAttribute(hstdout, 15);
//			}
//			else if (iterator->getVal() == 1) {
//				SetConsoleTextAttribute(hstdout, 12);
//				cout << " X";
//				SetConsoleTextAttribute(hstdout, 15);
//			}
//			else if (iterator->getVal() == 2) {
//				SetConsoleTextAttribute(hstdout, 11);
//				cout << " O";
//				SetConsoleTextAttribute(hstdout, 15);
//			}
//			else if (iterator->getVal() == 3) {
//				SetConsoleTextAttribute(hstdout, 6);
//				cout << " #";
//				SetConsoleTextAttribute(hstdout, 15);
//			}
//			x += 6;
//
//			if (batasKanan(i + 1) || batasKiri(i + 1)) {
//				iterator = iterator->getBot();
//				x = 38;
//				y += 2;
//				if (z == 0)
//					z = 1;
//				else if (z == 1)
//					z = 0;
//			}
//			else {
//				iterator = iterator->getNext();
//			}
//		}
//	}
//	void updateValue(int _index, int _value) {
//		Node* iterator = head;
//		for (int i = 0; i < _index; i++) {
//			if (batasKanan(i + 1) || batasKiri(i + 1)) {
//				iterator = iterator->getBot();
//			}
//			else {
//				iterator = iterator->getNext();
//			}
//		}
//		iterator->setVal(_value);
//	}
//	int operator[](int _index) {
//		Node* iterator = head;
//		for (int i = 0; i < _index; i++) {
//			if (batasKanan(i + 1) || batasKiri(i + 1)) {
//				iterator = iterator->getBot();
//			}
//			else {
//				iterator = iterator->getNext();
//			}
//		}
//		return iterator->getVal();
//	}
//	int cekVertikal(int _index, int player)
//	{
//		Node* iterator = head;
//		Node* temp;
//		for (int i = 0; i < _index; i++) {
//			if (batasKanan(i + 1) || batasKiri(i + 1)) {
//				iterator = iterator->getBot();
//			}
//			else {
//				iterator = iterator->getNext();
//			}
//		}
//		temp = iterator;
//
//		int co = 0;
//		while (iterator->getTop() != NULL && iterator->getTop()->getVal() == player) {
//			co++;
//			iterator = iterator->getTop();
//		}
//		iterator = temp;
//		while (iterator->getBot() != NULL && iterator->getBot()->getVal() == player) {
//			co++;
//			iterator = iterator->getBot();
//		}
//
//		return co + 1;
//	}
//	int cekHorizontal(int _index, int player)
//	{
//		Node* iterator = head;
//		Node* temp;
//		for (int i = 0; i < _index; i++) {
//			if (batasKanan(i + 1) || batasKiri(i + 1)) {
//				iterator = iterator->getBot();
//			}
//			else {
//				iterator = iterator->getNext();
//			}
//		}
//		temp = iterator;
//
//		int co = 0;
//		while (iterator->getNext() != NULL && iterator->getNext()->getVal() == player) {
//			co++;
//			iterator = iterator->getNext();
//		}
//		iterator = temp;
//		while (iterator->getPrev() != NULL && iterator->getPrev()->getVal() == player) {
//			co++;
//			iterator = iterator->getPrev();
//		}
//
//		return co + 1;
//	}
//	int cekDiagonalMiringKiri(int _index, int player) { // ("\")
//		Node* iterator = head;
//		Node* temp;
//		for (int i = 0; i < _index; i++) {
//			if (batasKanan(i + 1) || batasKiri(i + 1)) {
//				iterator = iterator->getBot();
//			}
//			else {
//				iterator = iterator->getNext();
//			}
//		}
//		temp = iterator;
//
//		int co = 1;
//		while (iterator->getDkiriAtas() != NULL && iterator->getDkiriAtas()->getVal() == player) {
//			co++;
//			iterator = iterator->getDkiriAtas
//			();
//		}
//		iterator = temp;
//		while (iterator->getDkananBawah() != NULL && iterator->getDkananBawah()->getVal() == player) {
//			co++;
//			iterator = iterator->getDkananBawah();
//		}
//
//		return co;
//	}
//	int cekDiagonalMiringKanan(int _index, int player) { // ("/")
//		Node* iterator = head;
//		Node* temp;
//		for (int i = 0; i < _index; i++) {
//			if (batasKanan(i + 1) || batasKiri(i + 1)) {
//				iterator = iterator->getBot();
//			}
//			else {
//				iterator = iterator->getNext();
//			}
//		}
//		temp = iterator;
//
//		int co = 1;
//		while (iterator->getDkananAtas() != NULL && iterator->getDkananAtas()->getVal() == player) {
//			co++;
//			iterator = iterator->getDkananAtas();
//		}
//		iterator = temp;
//		while (iterator->getDkiriBawah() != NULL && iterator->getDkiriBawah()->getVal() == player) {
//			co++;
//			iterator = iterator->getDkiriBawah();
//		}
//
//		return co;
//	}
//
//	int tips1(int _index, int player) {
//		Node* iterator = head;
//		Node* temp;
//		for (int i = 0; i < _index; i++) {
//			if (batasKanan(i + 1) || batasKiri(i + 1)) {
//				iterator = iterator->getBot();
//			}
//			else {
//				iterator = iterator->getNext();
//			}
//		}
//		temp = iterator;
//
//		int p;
//		if (player == 1) {
//			p = 2;
//		}
//		else {
//			p = 1;
//		}
//
//		int co = 0;
//		//Input Top
//		if (iterator->getBot() != NULL && iterator->getBot()->getVal() == p) {
//			iterator = iterator->getBot();
//			co++;
//			if (iterator->getBot() != NULL && iterator->getBot()->getVal() == player) {
//				co++;
//			}
//			if (iterator->getPrev() != NULL && iterator->getPrev()->getVal() == player) {
//				co++;
//			}
//			if (iterator->getNext() != NULL && iterator->getNext()->getVal() == player) {
//				co++;
//			}
//		}
//		if (co == 4) {
//			updateValue(iterator->getUrutan(), player);
//			return iterator->getUrutan();
//		}
//		else
//			co = 0;
//		iterator = temp;
//
//		//Input Bot
//		if (iterator->getTop() != NULL && iterator->getTop()->getVal() == p) {
//			iterator = iterator->getTop();
//			co++;
//			if (iterator->getTop() != NULL && iterator->getTop()->getVal() == player) {
//				co++;
//			}
//			if (iterator->getPrev() != NULL && iterator->getPrev()->getVal() == player) {
//				co++;
//			}
//			if (iterator->getNext() != NULL && iterator->getNext()->getVal() == player) {
//				co++;
//			}
//		}
//		if (co == 4) {
//			updateValue(iterator->getUrutan(), player);
//			return iterator->getUrutan();
//		}
//		else
//			co = 0;
//		iterator = temp;
//
//		//Input Prev
//		if (iterator->getNext() != NULL && iterator->getNext()->getVal() == p) {
//			iterator = iterator->getNext();
//			co++;
//			if (iterator->getNext() != NULL && iterator->getNext()->getVal() == player) {
//				co++;
//			}
//			if (iterator->getTop() != NULL && iterator->getTop()->getVal() == player) {
//				co++;
//			}
//			if (iterator->getBot() != NULL && iterator->getBot()->getVal() == player) {
//				co++;
//			}
//		}
//		if (co == 4) {
//			updateValue(iterator->getUrutan(), player);
//			return iterator->getUrutan();
//		}
//		else
//			co = 0;
//		iterator = temp;
//
//		//Input Next
//		if (iterator->getPrev() != NULL && iterator->getPrev()->getVal() == p) {
//			iterator = iterator->getPrev();
//			co++;
//			if (iterator->getPrev() != NULL && iterator->getPrev()->getVal() == player) {
//				co++;
//			}
//			if (iterator->getTop() != NULL && iterator->getTop()->getVal() == player) {
//				co++;
//			}
//			if (iterator->getBot() != NULL && iterator->getBot()->getVal() == player) {
//				co++;
//			}
//		}
//		if (co == 4) {
//			updateValue(iterator->getUrutan(), player);
//			return iterator->getUrutan();
//		}
//		else
//			co = 0;
//		iterator = temp;
//
//		return -1;
//	}
//
//	int BD_tips1(int _index, int player) {
//		Node* iterator = head;
//		Node* temp;
//		for (int i = 0; i < _index; i++) {
//			if (batasKanan(i + 1) || batasKiri(i + 1)) {
//				iterator = iterator->getBot();
//			}
//			else {
//				iterator = iterator->getNext();
//			}
//		}
//		temp = iterator;
//
//		int p;
//		if (player == 1) {
//			p = 2;
//		}
//		else {
//			p = 1;
//		}
//
//		int co = 0;
//		//Check + Bunuh Diri
//		//atas
//		if (iterator->getTop() != NULL && iterator->getTop()->getVal() == p) {
//			co++;
//		}
//		iterator = temp;
//
//		//bawah
//		if (iterator->getBot() != NULL && iterator->getBot()->getVal() == p) {
//			co++;
//		}
//		iterator = temp;
//
//		//kanan
//		if (iterator->getNext() != NULL && iterator->getNext()->getVal() == p) {
//			co++;
//		}
//		iterator = temp;
//
//		//kiri
//		if (iterator->getPrev() != NULL && iterator->getPrev()->getVal() == p) {
//			co++;
//		}
//		iterator = temp;
//
//		if (co == 4) {
//			updateValue(iterator->getUrutan(), p);
//			return temp->getUrutan();
//		}
//		return -1;
//	}
//
//	int tips2(int _index, int player) //TIPS2
//	{
//		Node* iterator = head;
//		Node* temp;
//		for (int i = 0; i < _index; i++) {
//			if (batasKanan(i + 1) || batasKiri(i + 1)) {
//				iterator = iterator->getBot();
//			}
//			else {
//				iterator = iterator->getNext();
//			}
//		}
//		temp = iterator;
//
//		int p;
//		if (player == 1) {
//			p = 2;
//		}
//		else {
//			p = 1;
//		}
//
//		int co = 0;
//		//Input Kiri Atas
//		if (iterator->getDkananBawah() != NULL && iterator->getDkananBawah()->getVal() == p) {
//			iterator = iterator->getDkananBawah();
//			co++;
//			if (iterator->getDkiriBawah() != NULL && iterator->getDkiriBawah()->getVal() == player) {
//				co++;
//			}
//			if (iterator->getDkananBawah() != NULL && iterator->getDkananBawah()->getVal() == player) {
//				co++;
//			}
//			if (iterator->getDkananAtas() != NULL && iterator->getDkananAtas()->getVal() == player) {
//				co++;
//			}
//		}
//		if (co == 4) {
//			updateValue(iterator->getUrutan(), 0);
//			return iterator->getUrutan();
//		}
//		else
//			co = 0;
//		iterator = temp;
//
//		//Input Kanan Atas
//		if (iterator->getDkiriBawah() != NULL && iterator->getDkiriBawah()->getVal() == p) {
//			iterator = iterator->getDkiriBawah();
//			co++;
//			if (iterator->getDkananBawah() != NULL && iterator->getDkananBawah()->getVal() == player) {
//				co++;
//			}
//			if (iterator->getDkiriBawah() != NULL && iterator->getDkiriBawah()->getVal() == player) {
//				co++;
//			}
//			if (iterator->getDkiriAtas() != NULL && iterator->getDkiriAtas()->getVal() == player) {
//				co++;
//			}
//		}
//		if (co == 4) {
//			updateValue(iterator->getUrutan(), 0);
//			return iterator->getUrutan();
//		}
//		else
//			co = 0;
//		iterator = temp;
//
//		//Input Kiri Bawah
//		if (iterator->getDkananAtas() != NULL && iterator->getDkananAtas()->getVal() == p) {
//			iterator = iterator->getDkananAtas();
//			co++;
//			if (iterator->getDkananAtas() != NULL && iterator->getDkananAtas()->getVal() == player) {
//				co++;
//			}
//			if (iterator->getDkananBawah() != NULL && iterator->getDkananBawah()->getVal() == player) {
//				co++;
//			}
//			if (iterator->getDkiriAtas() != NULL && iterator->getDkiriAtas()->getVal() == player) {
//				co++;
//			}
//		}
//		if (co == 4) {
//			updateValue(iterator->getUrutan(), 0);
//			return iterator->getUrutan();
//		}
//		else
//			co = 0;
//		iterator = temp;
//
//		//Input Kanan Bawah
//		if (iterator->getDkiriAtas() != NULL && iterator->getDkiriAtas()->getVal() == p) {
//			iterator = iterator->getDkiriAtas();
//			co++;
//			if (iterator->getDkananAtas() != NULL && iterator->getDkananAtas()->getVal() == player) {
//				co++;
//			}
//			if (iterator->getDkiriBawah() != NULL && iterator->getDkiriBawah()->getVal() == player) {
//				co++;
//			}
//			if (iterator->getDkiriAtas() != NULL && iterator->getDkiriAtas()->getVal() == player) {
//				co++;
//			}
//		}
//		if (co == 4) {
//			updateValue(iterator->getUrutan(), 0);
//			return iterator->getUrutan();
//		}
//		else
//			co = 0;
//		iterator = temp;
//
//		return -1;
//	}
//
//	int BD_tips2(int _index, int player) {
//		Node* iterator = head;
//		Node* temp;
//		for (int i = 0; i < _index; i++) {
//			if (batasKanan(i + 1) || batasKiri(i + 1)) {
//				iterator = iterator->getBot();
//			}
//			else {
//				iterator = iterator->getNext();
//			}
//		}
//		temp = iterator;
//
//		int p;
//		if (player == 1) {
//			p = 2;
//		}
//		else {
//			p = 1;
//		}
//
//
//		int co = 0;
//		//Check X Bunuh Diri
//		//Kanan atas
//		if (iterator->getDkananAtas() != NULL && iterator->getDkananAtas()->getVal() == p) {
//			co++;
//		}
//		iterator = temp;
//
//		//Kanan bawah
//		if (iterator->getDkananBawah() != NULL && iterator->getDkananBawah()->getVal() == p) {
//			co++;
//		}
//		iterator = temp;
//
//		//Kiri Atas
//		if (iterator->getDkiriAtas() != NULL && iterator->getDkiriAtas()->getVal() == p) {
//			co++;
//		}
//		iterator = temp;
//
//		//kiri Bawah
//		if (iterator->getDkiriBawah() != NULL && iterator->getDkiriBawah()->getVal() == p) {
//			co++;
//		}
//		iterator = temp;
//
//		if (co == 4) {
//			updateValue(iterator->getUrutan(), 0);
//			return temp->getUrutan();
//		}
//		return -1;
//	}
//
//	int cekTips3(Node* iterator) {
//		int co = 0;
//		if (iterator->getDkiriAtas() != NULL && iterator->getDkiriAtas()->getVal() != 0) {
//			co++;
//			if (iterator->getDkiriBawah() != NULL && iterator->getDkiriBawah()->getVal() != 0) {
//				co++;
//				if (iterator->getDkananAtas() != NULL && iterator->getDkananAtas()->getVal() != 0) {
//					co++;
//					if (iterator->getDkananBawah() != NULL && iterator->getDkananBawah()->getVal() != 0) {
//						co++;
//						if (iterator->getTop() != NULL && iterator->getTop()->getVal() != 0) {
//							co++;
//							if (iterator->getBot() != NULL && iterator->getBot()->getVal() != 0) {
//								co++;
//								if (iterator->getPrev() != NULL && iterator->getPrev()->getVal() != 0) {
//									co++;
//									if (iterator->getNext() != NULL && iterator->getNext()->getVal() != 0) {
//										co++;
//									}
//								}
//							}
//						}
//					}
//				}
//			}
//		}
//		return co;
//	}
//
//	int tips3(int _index, int player) //TIPS3
//	{
//		Node* iterator = head;
//		Node* temp;
//		for (int i = 0; i < _index; i++) {
//			if (batasKanan(i + 1) || batasKiri(i + 1)) {
//				iterator = iterator->getBot();
//			}
//			else {
//				iterator = iterator->getNext();
//			}
//		}
//		temp = iterator;
//
//		if (iterator->getDkananAtas() != NULL && iterator->getDkananAtas()->getVal() == 3) {
//			iterator = iterator->getDkananAtas();
//			if (cekTips3(iterator) == 8) {
//				updateValue(iterator->getUrutan(), 0);
//				return iterator->getUrutan();
//			}
//		}
//		iterator = temp;
//
//		if (iterator->getDkananBawah() != NULL && iterator->getDkananBawah()->getVal() == 3) {
//			iterator = iterator->getDkananBawah();
//			if (cekTips3(iterator) == 8) {
//				updateValue(iterator->getUrutan(), 0);
//				return iterator->getUrutan();
//			}
//		}
//		iterator = temp;
//
//		if (iterator->getDkiriAtas() != NULL && iterator->getDkiriAtas()->getVal() == 3) {
//			iterator = iterator->getDkiriAtas();
//			if (cekTips3(iterator) == 8) {
//				updateValue(iterator->getUrutan(), 0);
//				return iterator->getUrutan();
//			}
//		}
//		iterator = temp;
//
//		if (iterator->getDkiriBawah() != NULL && iterator->getDkiriBawah()->getVal() == 3) {
//			iterator = iterator->getDkiriBawah();
//			if (cekTips3(iterator) == 8) {
//				updateValue(iterator->getUrutan(), 0);
//				return iterator->getUrutan();
//			}
//		}
//		iterator = temp;
//
//		if (iterator->getTop() != NULL && iterator->getTop()->getVal() == 3) {
//			iterator = iterator->getTop();
//			if (cekTips3(iterator) == 8) {
//				updateValue(iterator->getUrutan(), 0);
//				return iterator->getUrutan();
//			}
//		}
//		iterator = temp;
//
//		if (iterator->getBot() != NULL && iterator->getBot()->getVal() == 3) {
//			iterator = iterator->getBot();
//			if (cekTips3(iterator) == 8) {
//				updateValue(iterator->getUrutan(), 0);
//				return iterator->getUrutan();
//			}
//		}
//		iterator = temp;
//
//		if (iterator->getPrev() != NULL && iterator->getPrev()->getVal() == 3) {
//			iterator = iterator->getPrev();
//			if (cekTips3(iterator) == 8) {
//				updateValue(iterator->getUrutan(), 0);
//				return iterator->getUrutan();
//			}
//		}
//		iterator = temp;
//
//		if (iterator->getNext() != NULL && iterator->getNext()->getVal() == 3) {
//			iterator = iterator->getNext();
//			if (cekTips3(iterator) == 8) {
//				updateValue(iterator->getUrutan(), 0);
//				return iterator->getUrutan();
//			}
//		}
//		iterator = temp;
//
//		return -1;
//	}
//
//	bool draw() {
//		Node* iterator = head;
//		for (int i = 0; i < size; i++) {
//
//			if (iterator->getVal() == 0)
//				return false;
//
//			if (batasKanan(i + 1) || batasKiri(i + 1)) {
//				iterator = iterator->getBot();
//			}
//			else {
//				iterator = iterator->getNext();
//			}
//		}
//		return true;
//	}
//
//};
//
//class Game {
//private:
//	OctaLinkedList oll;
//	int player, x, input, n;
//	bool gameOn;
//
//public:
//	Game() {
//		player = 1;
//		gameOn = true;
//	}
//
//	void Initialize(int x) {
//		srand(time(NULL));
//		n = x;
//		for (int i = 0; i < n; i++) {
//			oll.addValue(0);
//		}
//		int totwall = n / 10;
//
//		while (totwall > 0 && totwall != 1)
//		{
//			int random = rand() % n;
//			for (int i = 0; i < n; i++)
//			{
//				if (i == random && !oll.batasAtas(i) && !oll.batasKananDiagonal(i) && !oll.batasKiriDiagonal(i))
//				{
//					if (oll[i] != 3) {
//						oll.updateValue(i, 3);
//						totwall--;
//					}
//				}
//			}
//		}
//
//		if (totwall == 1) {
//			int random = rand() % n;
//			oll.updateValue(random, 3);
//		}
//	}
//
//	void Draw() {
//		HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
//		cout << "  _______ _            ______ _             _______               _   _                __          ___ _ _  __          ___       " << endl;
//		cout << " |__   __| |          |  ____(_)           |__   __|             | | | |               \\ \\        / (_| | | \\ \\        / (_)      " << endl;
//		cout << "    | |  | |__   ___  | |__   ___   _____     | | ___   __ _  ___| |_| |__   ___ _ __   \\ \\  /\\  / / _| | |  \\ \\  /\\  / / _ _ __  " << endl;
//		cout << "    | |  | '_ \\ / _ \\ |  __| | \\ \\ / / _ \\    | |/ _ \\ / _` |/ _ | __| '_ \\ / _ | '__|   \\ \\/  \\/ / | | | |   \\ \\/  \\/ / | | '_  \\ " << endl;
//		cout << "    | |  | | | |  __/ | |    | |\\ V |  __/    | | (_) | (_| |  __| |_| | | |  __| |       \\  /\\  /  | | | |    \\  /\\  /  | | | | |" << endl;
//		cout << "    |_|  |_| |_|\\___| |_|    |_| \\_/ \\___|    |_|\\___/ \\__, |\\___|\\__|_| |_|\\___|_|        \\/  \\/   |_|_|_|     \\/  \\/   |_|_| |_|" << endl;
//		cout << "                                                        __/ |                                                                     " << endl;
//		cout << "                                                       |___/                                                                      " << endl;
//
//		gotoxy(2, 10);
//		SetConsoleTextAttribute(hstdout, 12);
//		cout << "\tX = PLAYER 1" << endl;
//		gotoxy(2, 11);
//		SetConsoleTextAttribute(hstdout, 11);
//		cout << "\tO = PLAYER 2" << endl << endl;
//		SetConsoleTextAttribute(hstdout, 15);
//
//		oll.field(n, player);
//		oll.display();
//		cout << endl << endl;
//	}
//
//	void ProcessInput() {
//		int z = n;
//
//		if (z % 10 != 0) {
//			z += 10;
//		}
//
//		gotoxy(38, (z / 10) * 2 + 12);
//		cout << "Player " << player << " Input angka : ";
//		cin >> input;
//
//		while (input < 0 || input > n - 1) { //make sure 0-n
//			system("CLS");
//			Draw();
//			gotoxy(38, (z / 10) * 2 + 10);
//			cout << "Invalid choice!" << endl;
//			gotoxy(38, (z / 10) * 2 + 12);
//			cout << "Player " << player << " Input angka : ";
//			cin >> input;
//		}
//
//		if (player == 1 && oll[input] == 0) { //input
//			oll.updateValue(input, 1);
//			player = 2;
//		}
//		else if (player == 2 && oll[input] == 0) {
//			oll.updateValue(input, 2);
//			player = 1;
//		}
//		else {
//			gotoxy(38, (z / 10) * 2 + 10);
//			cout << "Invalid choice!" << endl;
//			cin.get();
//		}
//	}
//	void Update() {
//		int z = n;
//		int x = 1;
//
//		if (z % 10 != 0) {
//			z += 10;
//		}
//
//		if (player == 1) {
//			x = 2;
//		}
//
//		if (player == 2) {
//			x = 1;
//		}
//
//		//Check Tips 1
//		int tips1 = oll.tips1(input, x);
//		if (tips1 != -1) {
//			system("CLS");
//			Draw();
//
//			gotoxy(38, (z / 10) * 2 + 12);
//			cout << "Berhasil Mengubah ";
//			if (x == 1)
//				cout << "O menjadi X di index ke-" << tips1 << endl;
//			else
//				cout << "X menjadi O di index ke-" << tips1 << endl;
//			system("pause");
//		}
//
//		//Check BD Tips1
//		int BD_tips1 = oll.BD_tips1(input, x);
//		if (BD_tips1 != -1) {
//			system("CLS");
//			Draw();
//
//			gotoxy(38, (z / 10) * 2 + 12);
//			cout << "Bunuh Diri !!! Mengubah ";
//			if (x == 1)
//				cout << "X menjadi O di index ke-";
//			else
//				cout << "O menjadi X di index ke-";
//
//			cout << BD_tips1 << endl;
//
//			system("pause");
//		}
//
//		//check Tips 2
//		int tips2 = oll.tips2(input, x);
//		if (tips2 != -1) {
//			system("CLS");
//			Draw();
//
//			gotoxy(38, (z / 10) * 2 + 12);
//			cout << "Berhasil Menghilangkan ";
//			if (x == 1)
//				cout << "O di index ke-" << tips2 << endl;
//			else
//				cout << "X di index ke-" << tips2 << endl;
//			system("pause");
//		}
//
//		//Check BD Tips 2
//		int BD_tips2 = oll.BD_tips2(input, x);
//		if (BD_tips2 != -1) {
//			system("CLS");
//			Draw();
//
//			gotoxy(38, (z / 10) * 2 + 12);
//			cout << "Bunuh Diri !!! Menghilangkan ";
//			if (x == 1)
//				cout << "X di index ke-";
//			else
//				cout << "O di index ke-";
//
//			cout << BD_tips2 << endl;
//
//			system("pause");
//		}
//
//		//Check Tips 3
//		int tips3 = oll.tips3(input, x);
//		if (tips3 != -1) {
//			system("CLS");
//			Draw();
//
//			gotoxy(38, (z / 10) * 2 + 12);
//			cout << "Berhasil Menghilangkan # di index ke-" << tips3 << endl;
//			system("pause");
//		}
//
//		//Check Win
//		if (oll.cekVertikal(input, x) >= 5 || oll.cekHorizontal(input, x) >= 5 || oll.cekDiagonalMiringKiri(input, x) >= 5 || oll.cekDiagonalMiringKanan(input, x) >= 5) {
//			system("CLS");
//			Draw();
//
//			gotoxy(38, (z / 10) * 2 + 12);
//			cout << "Player " << x << " Win!" << endl;
//			gameOn = false;
//		}
//
//		//Check Draw
//		if (oll.draw()) {
//			system("CLS");
//			Draw();
//
//			gotoxy(38, (z / 10) * 2 + 12);
//			cout << "Draw !!" << endl;
//			gameOn = false;
//
//		}
//	}
//
//	void Start() {
//		HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
//
//		SetConsoleTextAttribute(hstdout, 14);
//		gotoxy(1, 20);
//		cout << "\t\t\t\t\t\t\t      Kelompok: " << endl;
//		gotoxy(1, 21);
//		cout << "\t\t\t\t\t\t       Dick Jovian / C14190076 " << endl;
//		gotoxy(1, 22);
//		cout << "\t\t\t\t\t\t  Andrean Dewanta Bisma / C14190106 " << endl;
//		gotoxy(1, 23);
//		cout << "\t\t\t\t\t\t Bryan Fernando Liauwan  / C14190020 " << endl;
//
//		SetConsoleTextAttribute(hstdout, 15);
//		gotoxy(25, 5);
//		cout << "                *   )   )              (    )                  )      " << endl; gotoxy(25, 6);
//		cout << "              ` )  /(( /(   (       (  )\\( /((     )      ) ( /(  (   " << endl; gotoxy(25, 7);
//		cout << "               ( )(_))\\()) ))\\      )\\((_)\\())\\   (    ( /( )\\())))\\  " << endl; gotoxy(25, 8);
//		cout << "              (_(_()((_)\\ /((_)  _ ((_)_(_))((_)  )\\  ')(_)(_))//((_) " << endl; gotoxy(25, 9);
//		cout << "              |_   _| |(_(_))   | | | | | |_ (_)_((_))((_)_| |_(_))   " << endl; gotoxy(25, 10);
//		cout << "                | | | ' \\/ -_)  | |_| | |  _|| | '  \\(/ _` |  _/ -_)  " << endl; gotoxy(25, 11);
//		cout << "                |_| |_||_\\___|   \\___/|_|\\__||_|_|_|_|\\__,_|\\__\\___|  " << endl; gotoxy(25, 12);
//		cout << "     __                  _     _          ___       ___                           " << endl; gotoxy(25, 13);
//		cout << "  /\\ \\ \\___  _   _  __ _| |__ | |_ ___   ( _ )     / ___ __ ___  ___ ___  ___ ___ " << endl; gotoxy(25, 14);
//		cout << " /  \\/ / _ \\| | | |/ _` | '_ \\| __/ __|  / _ \\/\\  / / | '__/ _ \\/ __/ __|/ _ / __|" << endl; gotoxy(25, 15);
//		cout << "/ /\\  | (_) | |_| | (_| | | | | |_\\__ \\ | (_>  < / /__| | | (_) \\__ \\__ |  __\\__ \\" << endl; gotoxy(25, 16);
//		cout << "\\_\\ \\/ \\___/ \\__,_|\\__, |_| |_|\\__|___/  \\___/\\/ \\____|_|  \\___/|___|___/\\___|___/" << endl; gotoxy(25, 17);
//		cout << "                   |___/                                                          " << endl; gotoxy(25, 18);
//		cout << "" << endl; gotoxy(25, 27);
//		cout << "                               ENTER TO CONTINUE" << endl;
//		cin.get();
//	}
//	void Rules() {
//		system("CLS");
//		HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
//		SetConsoleTextAttribute(hstdout, 14);
//
//		cout << endl << "\t\t\t\t            U _____ u _       ____  U  ___ u __  __ U _____ u " << endl;
//		cout << "\t\t\t\t __        _\\| ___'|/|'|   U /'___|\\ / '_ \\U|' \\/ '|\\| ___'|/ ." << endl;
//		cout << "\t\t\t\t \\'\\      /'/|  _ |'U| | u \\| | u    | | | || |\\/| |/|  _|'   " << endl;
//		cout << "\t\t\t\t /\\ \\ /\\ / /\\| |___ \\| |/__ | |/_.-,_| |_| || |  | | | |___   " << endl;
//		cout << "\t\t\t\tU  \\ V  V /  |_____| |_____| \\____\\_)-\\___/ |_|  |_| |_____|  " << endl;
//		cout << "\t\t\t\t.-,_\\ /\\ /_,-<<   >> //  \\ _// \\     \\  <<,-,,-.    <<   >>  " << endl;
//		cout << "\t\t\t\t \\_)-'  '-(_(__) (__(_')('_(__)(__)   (__)  (./  \\.)(__) (__) " << endl << endl;
//
//		SetConsoleTextAttribute(hstdout, 15);
//		cout << "   _____ ___ ___ ___    _  " << endl;
//		cout << "  |_   _|_ _| _ / __|  (_) " << endl;
//		cout << "    | |  | ||  _\\__ \\   _  " << endl;
//		cout << "    |_| |___|_| |___/  (_) " << endl << endl;
//		SetConsoleTextAttribute(hstdout, 12);
//		cout << "\tX = PLAYER 1" << endl;
//		SetConsoleTextAttribute(hstdout, 11);
//		cout << "\tO = PLAYER 2" << endl << endl;
//
//		SetConsoleTextAttribute(hstdout, 15);
//		cout << "\t 1.";
//		SetConsoleTextAttribute(hstdout, 12);
//		cout << "    X            X		  ";
//		SetConsoleTextAttribute(hstdout, 15);
//		cout << "/";
//		SetConsoleTextAttribute(hstdout, 11);
//		cout << "      O            O		" << endl;
//		SetConsoleTextAttribute(hstdout, 12);
//		cout << "\t     X";
//		SetConsoleTextAttribute(hstdout, 11);
//		cout << " O ";
//		SetConsoleTextAttribute(hstdout, 12);
//		cout << "X   ";
//		SetConsoleTextAttribute(hstdout, 15);
//		cout << "->";
//		SetConsoleTextAttribute(hstdout, 12);
//		cout << "   X X X		 ";
//		SetConsoleTextAttribute(hstdout, 15);
//		cout << "/     ";
//		SetConsoleTextAttribute(hstdout, 11);
//		cout << "O";
//		SetConsoleTextAttribute(hstdout, 12);
//		cout << " X";
//		SetConsoleTextAttribute(hstdout, 11);
//		cout << " O   ";
//		SetConsoleTextAttribute(hstdout, 15);
//		cout << "->   ";
//		SetConsoleTextAttribute(hstdout, 11);
//		cout << "O O O   " << endl;
//		SetConsoleTextAttribute(hstdout, 12);
//		cout << "\t       X            X		";
//		SetConsoleTextAttribute(hstdout, 15);
//		cout << "/";
//		SetConsoleTextAttribute(hstdout, 11);
//		cout << "        O            O		" << endl << endl << endl;
//		SetConsoleTextAttribute(hstdout, 15);
//
//		cout << "\t 2.";
//		SetConsoleTextAttribute(hstdout, 12);
//		cout << "  X   X       X   X ";
//		SetConsoleTextAttribute(hstdout, 15);
//		cout << "        /";
//		SetConsoleTextAttribute(hstdout, 11);
//		cout << "      O   O       O   O		" << endl;
//		cout << "\t       O    ";
//		SetConsoleTextAttribute(hstdout, 15);
//		cout << "->                /         ";
//		SetConsoleTextAttribute(hstdout, 12);
//		cout << "x     ";
//		SetConsoleTextAttribute(hstdout, 15);
//		cout << "->   " << endl;
//		SetConsoleTextAttribute(hstdout, 12);
//		cout << "\t     X   X       X   X ";
//		SetConsoleTextAttribute(hstdout, 15);
//		cout << "      /";
//		SetConsoleTextAttribute(hstdout, 11);
//		cout << "        O   O	  O   O	" << endl << endl << endl;
//
//		SetConsoleTextAttribute(hstdout, 15);
//		cout << "\t 3.  Jika WALL (#) diapit oleh X / O dari segala arah, maka WALL otomatis hancur. " << endl << endl;
//		SetConsoleTextAttribute(hstdout, 12);
//		cout << "\t     X";
//		SetConsoleTextAttribute(hstdout, 11);
//		cout << " O O       ";
//		SetConsoleTextAttribute(hstdout, 12);
//		cout << "X";
//		SetConsoleTextAttribute(hstdout, 11);
//		cout << " O O   " << endl;
//		SetConsoleTextAttribute(hstdout, 12);
//		cout << "\t     X ";
//		SetConsoleTextAttribute(hstdout, 8);
//		cout << "#";
//		SetConsoleTextAttribute(hstdout, 12);
//		cout << " X   ";
//		SetConsoleTextAttribute(hstdout, 15);
//		cout << "->  ";
//		SetConsoleTextAttribute(hstdout, 12);
//		cout << "X   X   " << endl;
//		cout << "\t     X ";
//		SetConsoleTextAttribute(hstdout, 11);
//		cout << "O";
//		SetConsoleTextAttribute(hstdout, 12);
//		cout << " X       X ";
//		SetConsoleTextAttribute(hstdout, 11);
//		cout << "O";
//		SetConsoleTextAttribute(hstdout, 12);
//		cout << " X   " << endl << endl;
//
//		SetConsoleTextAttribute(hstdout, 15);
//		cout << "\t\t\t\t\t\t\tENTER TO CONTINUE" << endl;
//
//		cin.get();
//	}
//
//	void Run() {
//		Start();
//		Rules();
//
//		system("CLS");
//		int n;
//		cout << "Input Board (*more than 50 is recommended): ";
//		cin >> n;
//		Initialize(n);
//
//		while (gameOn)
//		{
//			system("CLS");
//			Draw();
//			ProcessInput();
//			Update();
//			cin.get();
//		}
//	}
//};
//
//void main() {
//	HWND console = GetConsoleWindow();
//	RECT ConsoleRect;
//	GetWindowRect(console, &ConsoleRect);
//
//	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1000, 600, TRUE);
//	srand(time(NULL));
//
//	Game game;
//	game.Run();
//
//	cout << endl << endl;
//}
#pragma once
#include <iostream>
#include "Vector2.h"

#include <math.h>
using namespace std;

int main() {
	int c,t;
	Vector2 a,b;
	while (1) {
		cout << "Type coords for vector\na:\n";
		cin >> a;
		cout << "b:\n";
		cin >> b;
		cout << "Choose number of which comand to test:\n";
		cout << "0) exit\n1) '+'\n2) '+='\n3) '-'\n4) '-='\n5) '*'\n6) '^'\n7) '/'\n8) 'norm'\n9) 'len'\n10) 'squareLen'\n11) 'rotate'\n12) 'getRotated'\n13) 'perpendicular'\n14) unar '-'\n";
		cin >> c;
		system("cls");
		switch (c) {
			case 0:
			{
				return 0;
				break;
			}
			case 1:
			{
				cout << "a = " << a;
				cout << "\n";
				cout << "b = " << b;
				cout << "\n";
				cout << "a + b = " << a + b;
				cout << "\n";
				break;
			}
			case 2:
			{
				cout << "a = " << a;
				cout << "\n";
				cout << "b = " << b;
				cout << "\n";
				cout << "a - b = " << a - b;
				cout << "\n";
				break;
			}
			case 3:
			{
				cout << "a = " << a;
				cout << "\n";
				cout << "b = " << b;
				cout << "\n";
				a += b;
				cout << "a += b: " << a;
				cout << "\n";
				a += b;
				cout << "a += b: " << a;
				cout << "\n";
				b += a;
				cout << "b += a: " << b;
				cout << "\n";
				b += b;
				cout << "b += b: " << b;
				cout << "\n";
				break;
			}
			case 4:
			{
				cout << "a = " << a;
				cout << "\n";
				cout << "b = " << b;
				cout << "\n";
				a -= b;
				cout << "a -= b: " << a;
				cout << "\n";
				a -= b;
				cout << "a -= b: " << a;
				cout << "\n";
				b -= a;
				cout << "b -= a: " << b;
				cout << "\n";
				b -= b;
				cout << "b -= b: " << b;
				cout << "\n";
				break;
			}
			case 5:
			{
				cout << "a = " << a;
				cout << "\n";
				cout << "b = " << b;
				cout << "\n";
				cout << "a * b = " << a * b;
				cout << "\n";
				cout << "Choose on what number to *\n";
				cin >> t;
				cout << "a * " << t << " = " << a * t;
				cout << "\n";
				break;
			}
			case 6:
			{
				cout << "a = " << a;
				cout << "\n";
				cout << "a ^ b = " << (a ^ b) << "\n";
				break;
			}
			case 7:
			{
				cout << "a = " << a;
				cout << "\n";
				cout << "Choose on what number to /\n";
				cin >> t;
				cout << "a / " << t << " = " << a / t;
				cout << "\n";
				break;
			}
			case 8:
			{
				cout << "a = " << a;
				cout << "\n";
				cout << "a.norm() = " << a.norm();
				cout << "\n";
				break;
			}
			case 9:
			{
				cout << "a = " << a;
				cout << "\n";
				cout << "Length a = " << a.len() << "\n";
				break;
			}
			case 10:
			{
				cout << "a = " << a;
				cout << "\n";
				cout << "Length^2 a = " << a.squareLen() << "\n";
				break;
			}
			case 11:
			{
				cout << "a = " << a;
				cout << "\n";
				cout << "Choose angel of rotation in degrees\n";
				cin >> t;
				cout << "Rotated a: " << a.rotate(t);
				cout << "\n";
				break;
			}
			case 12:
			{
				cout << "a = " << a;
				cout << "\n";
				cout << "Choose angel of rotation in degrees\n";
				cin >> t;
				cout << "Rotated a: " << a.getRotated(t);
				cout << "\n";
				cout << "Choose angel of rotation in degrees\n";
				cin >> t;
				cout << "Rotated a: " << a.getRotated(t);
				cout << "\n";
				break;
			}
			case 13:
			{
				cout << "a = " << a;
				cout << "\n";
				cout << "a.perpendicular: " << a.perpendicular();
				cout << "\n";
				break;
			}
			case 14:
			{
				cout << "a = " << a;
				cout << "\n";
				cout << "-a " << -a;
				cout << "\n";
				break;
			}
			default:
			{
				cout << "No such comand exists\nTry again\n";
				break;
			}
		}
	}
}	


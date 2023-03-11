#include <iostream>
#include <cmath>

//����������
/*
(100 �.) ��������� �������� �������������� �����, ������������� �� ��������, �������������, 
�������������� �������������, �������������� �������������, ��������������� � ���������. 
�������� ��� ���� �� ���� ������� � ������ (��������, ������� ������) � ����������� �.
*/

class MathMixin {
public:
	//...����� � ��������...
	const double pi() const {
		return std::acos(-1);
	}

	double approximate_ellipse_perimeter(double a, double b) const {
		return pi() * std::sqrt(2 * (a * a + b * b));
	}
	//...����� � ��������...

	//������� ������
	double get_Heron(double a, double b, double c, double p) const{
		return std::sqrt(p * (p - a) * (p - b) * (p - c));
	}
};

//����� � ��������...
class Figure {
public:
	virtual double perimeter() const = 0;
	virtual double square() const = 0;
};

class Ellipse : public Figure, private MathMixin {
public:
	Ellipse(double a, double b) : a(a), b(b) {}

	double perimeter() const override {
		return approximate_ellipse_perimeter(a, b);
	}

	double square() const override {
		return pi() * a * b;
	}
private:
	double a, b;
};

class Circle : public Ellipse {
public:
	Circle(double r) : Ellipse(r, r) {}
};
//...����� � ��������...

//������� �����������
class Triangle : public Figure, private MathMixin {
public:
	Triangle(double a, double b, double c) : a{ a }, b{ b }, c{ c } {}

	double perimeter() const override {
		return (a + b + c);
	}
	double square() const override {
		double p = perimeter() / 2;
		return get_Heron(a, b, c, p);
	}

private:
	double a, b, c;
};

//������������� �����������
class Rectangular_Triangle : public Triangle {
public:
	Rectangular_Triangle(double a, double b) : Triangle(a, b, std::sqrt(a* a + b * b)) {}
};

//�������������� �����������
class Isosceles_Triangle : public Triangle {
public:
	Isosceles_Triangle(double a, double c) : Triangle(a, a, c) {}
};

//�������������� �����������
class Equipotential_Triangle : public Triangle {
public:
	Equipotential_Triangle(double a) : Triangle(a, a, a) {}
};

//�������������
class Rectangle : public Figure {
public:
	Rectangle(double a, double b) : a{ a }, b{ b } {}

	double perimeter() const override {
		return 2 * (a + b);
	}
	double square() const override {
		return a * b;
	}

private:
	double a, b;
};

//�������
class Square : public Rectangle {
public:
	Square(double a) : Rectangle(a, a) {}
};


int main() {

	//...����� � ��������...
	Ellipse ellipse(4, 5);
	std::cout << "Ellipse perimeter and square:" << std::endl;
	std::cout << ellipse.perimeter() << std::endl;
	std::cout << ellipse.square() << std::endl;

	Circle circle(3);
	std::cout << "CIrcle perimeter and square:" << std::endl;
	std::cout << circle.perimeter() << std::endl;
	std::cout << circle.square() << std::endl;
	//...����� � ��������...

	Triangle triangle(3, 4, 5);
	std::cout << "Triangle perimeter and square:" << std::endl;
	std::cout << triangle.perimeter() << std::endl;
	std::cout << triangle.square() << std::endl;

	Rectangular_Triangle rect_triangle(3, 4);
	std::cout << "Rectangular Triangle perimeter and square:" << std::endl;
	std::cout << rect_triangle.perimeter() << std::endl;
	std::cout << rect_triangle.square() << std::endl;

	Isosceles_Triangle iso_triangle(2, 3);
	std::cout << "Isosceles Triangle perimeter and square:" << std::endl;
	std::cout << iso_triangle.perimeter() << std::endl;
	std::cout << iso_triangle.square() << std::endl;

	Equipotential_Triangle eq_triangle(5);
	std::cout << "Equipotential Triangle perimeter and square:" << std::endl;
	std::cout << eq_triangle.perimeter() << std::endl;
	std::cout << eq_triangle.square() << std::endl;

	Rectangle rect(2, 5);
	std::cout << "Rectangle perimeter and square:" << std::endl;
	std::cout << rect.perimeter() << std::endl;
	std::cout << rect.square() << std::endl;

	Square squar(7);
	std::cout << "Square perimeter and square:" << std::endl;
	std::cout << squar.perimeter() << std::endl;
	std::cout << squar.square() << std::endl;
}

//***������ �� �������:
/*
1. (10 �.) ����� ��� ���� �������������� ���� ������������ �� ������ �������? ������ ������� ������ �� ���.

�����: ����� ������� ��� ���� ������������: public � private (���� ����� ��� �������� protected). 
Public ������������ ��������� ��������� ������ ������������ ��������� ���������� � ������ 
������������� ������ ��� ������ ����, ��� � � main: 
��������, ���� ����� Human, �� ���� ����� Man. 
� ������ human ���� ��������� ��������� ���������� human_knowledge. � main() ����� ��������: 
...
Man Herman;
std::cout << Herman.human_knowledge << std::endl;
...
���� ������������ private ������������, �� std::cout << Herman.human_knowledge << std::endl; ������ ������.

2. (10 �.) ������ ��������� ����� � ������ ������ ����������� ��� ������ ������?

�����: ��������� ����� � ������ ������ ����������� ��� ������ ������, 
��� ��� ���� �� ��������� - ������ �� ������ ostream (��� istream), 
������� � ������� ������ ����� �� ���������.

3. (10 �.) ��� ����� ����������� ������� �����, ��� ���������, � ��� �� ������ � �������� ������ ����������� �������?

����������� ����� (��� ���������) - ��� �����, 
� �������� ���� ������ [�����] ����������� ������, 
�.�. ��������� �������� ������ ������������ �������� ��� ����������. 
����� ����� ��������� ��� �� "����� ��������� ����, ��� ������ ����", �� ��� ��� �� ���������.
*/
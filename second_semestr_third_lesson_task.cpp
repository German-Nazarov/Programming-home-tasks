#include <iostream>
#include <cmath>

//Упражнение
/*
(100 б.) Дополните иерархию геометрических фигур, реализованную на семинаре, треугольником, 
равнобедренным треугольником, равносторонним треугольником, прямоугольником и квадратом. 
Добавьте ещё хотя бы одну формулу в миксин (например, формулу Герона) и используйте её.
*/

class MathMixin {
public:
	//...часть с семинара...
	const double pi() const {
		return std::acos(-1);
	}

	double approximate_ellipse_perimeter(double a, double b) const {
		return pi() * std::sqrt(2 * (a * a + b * b));
	}
	//...часть с семинара...

	//Формула Герона
	double get_Heron(double a, double b, double c, double p) const{
		return std::sqrt(p * (p - a) * (p - b) * (p - c));
	}
};

//Часть с семинара...
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
//...часть с семинара...

//Обычный треугольник
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

//Прямоугольный треугольник
class Rectangular_Triangle : public Triangle {
public:
	Rectangular_Triangle(double a, double b) : Triangle(a, b, std::sqrt(a* a + b * b)) {}
};

//Равнобедренный треугольник
class Isosceles_Triangle : public Triangle {
public:
	Isosceles_Triangle(double a, double c) : Triangle(a, a, c) {}
};

//Равносторонний треугольник
class Equipotential_Triangle : public Triangle {
public:
	Equipotential_Triangle(double a) : Triangle(a, a, a) {}
};

//Прямоугольник
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

//Квадрат
class Square : public Rectangle {
public:
	Square(double a) : Rectangle(a, a) {}
};


int main() {

	//...часть с семинара...
	Ellipse ellipse(4, 5);
	std::cout << "Ellipse perimeter and square:" << std::endl;
	std::cout << ellipse.perimeter() << std::endl;
	std::cout << ellipse.square() << std::endl;

	Circle circle(3);
	std::cout << "CIrcle perimeter and square:" << std::endl;
	std::cout << circle.perimeter() << std::endl;
	std::cout << circle.square() << std::endl;
	//...часть с семинара...

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

//***Ответы на вопросы:
/*
1. (10 б.) Какие два вида концептуальных вида наследования вы можете назвать? Кратко опишите каждый из них.

Ответ: Можно назвать два вида наследования: public и private (хотя можно ещё отметить protected). 
Public наследование позволяет дочернему классу использовать публичные переменные и методы 
родительского класса как внутри себя, так и в main: 
например, есть класс Human, от него класс Man. 
У класса human есть публичная публичная переменная human_knowledge. В main() можно написать: 
...
Man Herman;
std::cout << Herman.human_knowledge << std::endl;
...
Если использовать private наследование, то std::cout << Herman.human_knowledge << std::endl; выдаст ошибку.

2. (10 б.) Почему операторы ввода и вывода нельзя реализовать как методы класса?

Ответ: Операторы ввода и вывода нельзя реализовать как методы класса, 
так как один из операндов - ссылка на объект ostream (или istream), 
которая к данному классу никак не относится.

3. (10 б.) Что такое абстрактный базовый класс, или интерфейс, и как он связан с понятием чистой виртуальной функции?

Абстрактный класс (или интерфейс) - это класс, 
у которого есть только [чисто] виртуальные методы, 
т.е. интерфейс обладает только виртуальными методами без реализаций. 
Такой класс описывает как бы "общую структуру того, что должно быть", но сам это не реализует.
*/
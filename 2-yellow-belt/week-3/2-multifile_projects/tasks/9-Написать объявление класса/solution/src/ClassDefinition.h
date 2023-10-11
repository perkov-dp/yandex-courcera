#pragma once

#ifndef CLASSDEFINITION_H_
#define CLASSDEFINITION_H_


/* �������� ������������ ���� rectangle.h, ���������� ���������� ������ Rectangle.
 * ��� ������ ���� ����������� ������������ ����, ������� ����� ������������ � ������� �������.
 * � ���������, � �� ������ ���� ������ �������� �������� ���������.*/

class Rectangle {
public:
    Rectangle(int width, int height);
    int GetArea() const;
    int GetPerimeter() const;
    int GetWidth() const;
    int GetHeight() const;
private:
    int width_, height_;
};



#endif /* CLASSDEFINITION_H_ */

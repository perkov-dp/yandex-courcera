#pragma once

#ifndef CLASSDEFINITION_H_
#define CLASSDEFINITION_H_


/* Пришлите заголовочный файл rectangle.h, содержащий объявление класса Rectangle.
 * Это должен быть полноценный заголовочный файл, который можно использовать в большом проекте.
 * В частности, в нём должна быть решена проблема двойного включения.*/

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

﻿// Task08.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include "ISerializable.h"
#include "ISpeakable.h"

/* Кот. Обладает координатами (в центре головы). Может быть нарисован на холсте
 может говорить (мяукая) */
class Cat /* Написать недостающий код */
{
    /* Написать недостающий код */
};

/* Человек. Обладает именем и годом рождения.
может говорить (называет своё имя и год рождения) */
class Person
{

};

/* Ведёт разговор с набором объектов, с которыми можно побеседовать */
void SmallTalk(const ISpeakable)
{
    /* Написать недостающий код, заставляющий беседовать с объектами */
}

/* Рисует набор объектов, которые можно нарисовать на переданном холсте (принимает объекты и холст) */
void Draw(/* Написать недостающий код */)
{
    /* Написать недостающий код */
}

/* Копирует состояние из одного сериализуемого объекта в другой */
void CopyState(const ISerializable& from, ISerializable& to)
{
    /* Написать недостающий код */
}

int main()
{
    /*
    Нарисовать при помощи функции Draw домик с котиком рядом с ним:
        /\
       /  \
      / O  \
     --------
      |    |
      |    |
      ------
      до 8 баллов (8-6-4)
    */

    /* Создать прямоугольник.
     Скопировать в него при помощи CopyState состояние из прямоугольника,
     задающего стены дома
      до 6 баллов (6-5-3)
    */

    /*
    Создать человека по имени Ivanov Ivan 1980 года рождения.
    При помощи SmallTalk побеседовать с этим человеом и вышесозданным котом
      до 6 баллов (6-5-3)
    */

    return 0;
}
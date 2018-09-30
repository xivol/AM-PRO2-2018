﻿# Лабораторная работа №7
### Классы. Конструктор копирования и операция присваивания
Реализовать класс многоугольник. Класс должен содержать:
* закрытые поля массив вершин, размер массива (память выделяется динамически);
* конструктор, принимающий массив точек;
* деструктор;
* конструктор копии и операцию присваивания;
* метод доступа к количеству точек;
* [методы вычисления](http://algolist.manual.ru/maths/geom/polygon/):
 * цетра;
 * выпуклости;
 * периметра;
 * площади;
* перегрузку операций:
 * `operator==`, `operator!=`;
 * `operator[]` - доступа к точкам по индексу;
 * ввод/вывод. 

Дан файл, содержащий описание вершин многоугольника. Считать массив точек из файла и вычислить площадь многоугольника, заданного этими точками.
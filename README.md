# Задание

Поиск точки пересечения отрезков в трехмерном пространстве.

Требуется реализовать функцию ```Intersect```, которая будет находить точку пересечения двух заданных отрезков типа ```Segment3D```. В классы ```Vector3D``` и ```Segment3D``` можно добавлять любые методы для удобства решения задачи.

## Классы

### Vector3D

```c++
class Vector3D
{
    double X;
    double Y;
    double Z;
    // ...
}
```
Класс ```Vector3D``` представляет трехмерный вектор с координатами X, Y и Z.

### Segment3D

```c++
class Segment3D
{
    Vector3D start;
    Vector3D end;
    // ...
}
```

Класс ```Segment3D``` определяет трехмерный отрезок, который задается двумя точками (```start``` и ```end```).

## Пример использовния функции Intersect

```c++
    Segment3D s1 = Segment3D(Vector3D(2, 2, 2), Vector3D(-1, -1, -1));
    Segment3D s2 = Segment3D(Vector3D(-3, 1, 4), Vector3D(3, -1, -4));
    std::pair<bool, Vector3D> res = s2.Intersect(s1);
    std::cout << res.first << std::endl;
    std::cout << "(" << res.second.X << " " << res.second.Y << " " << res.second.Z << ")" << std::endl;
```

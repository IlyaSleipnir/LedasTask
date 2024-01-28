#include <iostream>
#include "Segment3D.h"

int main()
{
    Segment3D s1 = Segment3D(Vector3D(2, 2, 2), Vector3D(-1, -1, -1));
    Segment3D s2 = Segment3D(Vector3D(0, 0, 1), Vector3D(0, 0, -1));
    //Segment3D s2 = Segment3D(Vector3D(3, 2, 2), Vector3D(0, 0, -1));
    //Segment3D s2 = Segment3D(Vector3D(-3, 1, 4), Vector3D(3, -1, -4));
    std::pair<bool, Vector3D> res = s2.Intersect(s1);
    std::cout << res.first << std::endl;
    std::cout << "(" << res.second.X << " " << res.second.Y << " " << res.second.Z << ")" << std::endl;
}

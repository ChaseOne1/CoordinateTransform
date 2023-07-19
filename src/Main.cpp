#include <iostream>
#include "MathHelper\Matrix.h"
#include "CoordTransform\Transform.h"
using namespace std;

int main()
{
    Vector3 posn(1.0f, 1.0f, 1.0f), target(1.0f, 1.0f, 2.0f), up(0.0f, 1.0f, 0.0f);
    Transform *trans = new Transform();
    trans->SetCameraMatrix(posn, target, up);
    Vector3 worldOrigin;
    Vector3 world = trans->CamToWorld(worldOrigin);
    Vector3 camera = trans->WorldToCam(worldOrigin);
    printf("Camera Position in world :%.3f %.3f %.3f\n", world.x, world.y, world.z);
    printf("Origin of world in camera :%.3f %.3f %.3f\n", camera.x, camera.y, camera.z);
    system("pause");
    delete trans;
    return 0;
}
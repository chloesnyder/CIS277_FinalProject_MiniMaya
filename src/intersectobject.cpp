#include "intersectobject.h"

IntersectObject::IntersectObject(float t, Mesh* m, glm::vec4 P, glm::vec4 normal)
{
    this->t = t;
    this->m = m;
    this->P = P;
    this->nomral = normal;

}

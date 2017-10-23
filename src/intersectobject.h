#ifndef INTERSECTOBJECT_H
#define INTERSECTOBJECT_H
#include "mesh.h"

class IntersectObject
{
public:
    float t;
    Mesh* m; //this is the mesh intersected
    glm::vec4 P; //this is the point of intersection
    glm::vec4 nomral; //this is the normal of the interesection
    IntersectObject(float t, Mesh* m, glm::vec4 P, glm::vec4 normal);
};

#endif // INTERSECTOBJECT_H

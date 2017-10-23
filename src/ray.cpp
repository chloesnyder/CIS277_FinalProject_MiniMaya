#include "ray.h"
#include "shaderprogram.h"
#include "la.h"
#include <iostream>
#include <limits.h>
#include <math.h>



using namespace std;

static const int two = 2;

Ray::Ray()
    : bufIdx(QOpenGLBuffer::IndexBuffer),
      bufPos(QOpenGLBuffer::VertexBuffer),
      bufNor(QOpenGLBuffer::VertexBuffer),
      bufCol(QOpenGLBuffer::VertexBuffer){

}


Ray::Ray(glm::vec4 eye, glm::vec4 d) {
    origin = eye;
    direction = d/glm::length(d);
}

Ray::~Ray()
{



}

glm::vec4 Ray::getOrigin() {
    return origin;
}

glm::vec4 Ray::getDirection() {
    return direction;
}

void Ray::create() {
    GLuint ray_idx[two];

    ray_idx[0] = 0;
    ray_idx[1] = 1;


    glm::vec4 ray_positions[two];
    ray_positions[0] = origin;
    ray_positions[1] = origin + 1000.f * direction;


    bufIdx.create();
    bufIdx.bind();
    bufIdx.setUsagePattern(QOpenGLBuffer::StaticDraw);
    bufIdx.allocate(ray_idx, two * sizeof(GLuint));

    bufPos.create();
    bufPos.bind();
    bufPos.setUsagePattern(QOpenGLBuffer::StaticDraw);
    bufPos.allocate(ray_positions, two * sizeof(glm::vec4));


}

void Ray::destroy() {
  bufIdx.destroy();
  bufPos.destroy();
  bufNor.destroy();
  bufCol.destroy();
}



GLenum Ray::drawMode() {
  return GL_LINES;
}

int Ray::elemCount() {
  return two;
}

bool Ray::bindIdx() {
  return bufIdx.bind();
}

bool Ray::bindPos() {
  return bufPos.bind();
}

bool Ray::bindNor() {
  return bufNor.bind();
}

bool Ray::bindCol() {
  return bufCol.bind();
}



//returns point of intersection with a unit cube at the origin
glm::vec4 intersectCube(const Ray& r, const glm::mat4& transform) {
    //create scaled/rotated/translated ray
    //to treat geometry as unit
    glm::vec4  dir = glm::inverse(transform) * r.direction;
    glm::vec4  orig = glm::inverse(transform) * r.origin;

    float min = -0.5;
    float max = 0.5;
    float t_near =  - (std::numeric_limits<float>::max());
    float t_far = std::numeric_limits<float>::max();

    float t_oh;
    float t_one;

   //if parallel to any of the axes
    for (int i = 0; i < 3; i++) {
        if (dir[i] == 0 &&
                (orig[i] < min || orig[i] > max)) {
            return glm::vec4(0, 0, 0, 0);
        }

         t_oh = (min - orig[i])/dir[i];
         t_one = (max - orig[i])/dir[i];
         if (t_oh > t_one) {
             float temp = t_oh;
             t_oh = t_one;
             t_one = temp;
         }

         if (t_oh > t_near) {
             t_near = t_oh;

         }

         if (t_one < t_far) {
             t_far = t_one;

         }

    }

    if (t_near > t_far) {
          return glm::vec4(0, 0, 0, 0);
    }




    glm::vec4 p = orig + (t_near * dir);
    return transform * p;

}
/*
//returns the tvalue against
float intersectOctNode(const Ray& r, Octnode& octroot) {
    vec4 dir = r.direction;
    vec4 orig = r.origin;

    float bounds[6];
    bounds[0] = octroot.xmin;
    bounds[1] = octroot.ymin;
    bounds[2] = octroot.zmin;
    bounds[3] = octroot.xmax;
    bounds[4] = octroot.ymax;
    bounds[5] = octroot.zmax;

    float t_near =  - (std::numeric_limits<float>::max());
    float t_far = std::numeric_limits<float>::max();

    float t_oh;
    float t_one;

   //if parallel to any of the axes
    for (int i = 0; i < 3; i++) {
        if (dir[i] == 0 &&
                (orig[i] < bounds[i] || orig[i] > bounds [i + 3])) {
            return -1;
        }

         t_oh = (bounds[i] - orig[i])/dir[i];
         t_one = (bounds[i + 3] - orig[i])/dir[i];
         if (t_oh > t_one) {
             float temp = t_oh;
             t_oh = t_one;
             t_one = temp;
         }

         if (t_oh > t_near) {
             t_near = t_oh;

         }

         if (t_one < t_far) {
             t_far = t_one;

         }

    }

    if (t_near > t_far) {
       return -1;
    }



    //vec4 p = orig + (t_near * dir);
    return t_near;
}

*/


//returns point of intersection with a unit cylinder at the origin
glm::vec4 intersectCylinder(const Ray& r, const glm::mat4& transform) {

    glm::vec4 dir = la::inverse(transform) * r.direction;
    glm::vec4 orig = la::inverse(transform) * r.origin;


    //testing barrel
    glm::vec4 Cv = glm::vec4(0, 1, 0, 0);
    glm::vec4 Cs = glm::vec4(0, -0.5f, 0, 1);
    glm::vec4 Ce = glm::vec4(0, 0.5f, 0, 1);

    float radius = 0.5f;

    glm::vec4 H = glm::vec4(glm::cross(glm::vec3(orig - Cs), glm::vec3(Cv)), 0);
    glm::vec4 J = glm::vec4(glm::cross(glm::vec3(dir), glm::vec3(Cv)), 0);
    float K = std::pow(radius, 2) * std::pow(glm::length(Cv), 2);

    float A = pow(glm::length(J), 2);
    float B = 2 * glm::dot(H, J);
    float C = pow(glm::length(H), 2) - K;

    float discriminant = B*B - 4*A*C;

    if (discriminant < 0) {
        return glm::vec4(0, 0, 0, 0);
    }

    float t_oh = (-B - sqrt(discriminant))/(2 * A);
    float t_one = (-B + sqrt(discriminant))/(2 * A);


    if (t_oh > 0) {


        glm::vec4 p = orig + (t_oh * dir);

        if (p[1] >= Cs[1] && p[1] <= Ce[1]) {
            return transform * p;
        }
    }

    else if (t_one> 0)  {


        glm::vec4 p = orig + (t_one * dir);
       // std::cout << "this is the point of intersection with cylinder: " << p<< "  " << std::endl;
        if (p[1] >= -0.5f && p[1] <= 0.5f) {

            return transform * p;
        }

    }

    //testing top endcap
    glm::vec4 planeNorm = glm::vec4(0, 1, 0, 0);
    glm::vec4 S = glm::vec4(0.5f, 0.5f, 0, 1);
    float t = glm::dot(planeNorm, (S - orig))/glm::dot(planeNorm, dir);
    glm::vec4 P = orig + t * dir;
    if (glm::length(P - Ce) <= radius) {
        return P;
    }

    else {
        S = glm::vec4(0.5f, -0.5f, 0, 1);
        t = glm::dot(planeNorm, (S - orig))/glm::dot(planeNorm, dir);
        P = orig + t * dir;

        if (glm::length(P -Cs) <= radius) {
            return P;
        }
    }


// std::cout << "no intersection with cylinder:  " << std::endl;
    return glm::vec4(0, 0, 0, 0);

}

//returns point of intersection with a unit sphere at the origin
glm::vec4 intersectSphere(const Ray& r, const glm::mat4& transform, Camera* c) {
    //scale ray down
    float n = c->near_clip;
    glm::vec4 dir = la::inverse(transform) * r.direction;
    glm::vec4 orig = la::inverse(transform) * r.origin;

    float x0 = orig[0];
    float y0 = orig[1];
    float z0 = orig[2];

    float xd = dir[0];
    float yd = dir[1];
    float zd = dir[2];

    float A =  xd* xd + yd * yd + zd * zd;
    float B = 2 *(xd * x0 + yd* y0 + zd * z0);
    float C = x0 * x0 + y0 * y0 + z0 * z0 - 0.25f;


    float discriminant = B*B - 4*A*C;
    float t_oh = (-B - sqrt(discriminant))/(2 * A);
    float t_one = (-B + sqrt(discriminant))/(2 * A);

    //no intersection when discriminant is zero
    if (discriminant < 0) {

        return glm::vec4(0, 0, 0, 0);
    }

    else if (t_oh > n) {

        glm::vec4 p = orig + (t_oh * dir);
        return transform * p;
    }

    else if (t_one > n) {

        glm::vec4 p = orig + (t_one * dir);
        return transform * p;

    }

    return glm::vec4(0, 0, 0, 0);

}




// Prints the ray to a stream in a nice format
std::ostream &operator<<(std::ostream &o, const Ray &r) {
     o << std::endl << "origin: " << glm::to_string(r.origin) << std::endl << "direction: " << glm::to_string(r.direction) << std::endl;
     return o;
}

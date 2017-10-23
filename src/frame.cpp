#include "frame.h"
#include <iostream>

Frame::Frame(int t)
{

    setText(QString::number(t));
    time = t;
    transformation = glm::mat4();

}

Frame::Frame(glm::vec4 pos, glm::quat ro, int t) {

    //from pos, get translation
    glm::mat4 T;
    T[0] = glm::vec4(1, 0, 0, 0);
    T[1] = glm::vec4(0, 1, 0, 0);
    T[2] = glm::vec4(0, 0, 1, 0);
    T[3] = glm::vec4(pos[0], pos[1], pos[2], 1);


    //from quat, get rotation
    glm::mat4 R = glm::mat4_cast(ro);

    std::cout << " POS OF NEW FRAME " << t << "   " << glm::to_string(pos) << std::endl;
    std::cout << " RO OF NEW FRAME " << t << " " << glm::to_string(R) << std::endl;

    translation = pos;
    rotation = ro;


    transformation = T * R;


    time = t;
    setText(QString::number(t));


}

Frame::Frame(glm::mat4 tr, int t) {
     transformation = tr;
     time = t;
     setText(QString::number(t));

}

int Frame::getTime() {
    return time;
}


glm::mat4 Frame::getTransformation() {
    return transformation;
}


glm::vec4 Frame::getTranslation() {

    return translation;
}

glm::quat Frame::getRotation() {
    return rotation;
}


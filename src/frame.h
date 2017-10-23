#ifndef FRAME_H
#define FRAME_H

#include <QListWidgetItem>
#include "la.h"

class Frame : public QListWidgetItem
{
private:
    int time;
    glm::mat4 transformation;

    glm::vec4 translation;
    glm::quat rotation;

public:
    Frame(int t);
    Frame(glm::vec4, glm::quat, int t);
    Frame(glm::mat4, int);


    int getTime();
    glm::mat4 getTransformation();

    glm::vec4 getTranslation();
    glm::quat getRotation();
};

#endif // FRAME_H

#pragma once

#include "glm.hpp"
#include "ext.hpp"
#include "gtc/matrix_transform.hpp"

class Camera {
public:

    Camera(glm::vec3 position, float fov, float width, float height) : position(position) {
        projection = glm::perspective(fov/2.0f, width / height, 0.1f, 1000.0f);
        view = glm::mat4(1.0);
        update();
    }

    glm::mat4 getViewProj() {
        return viewProj;
    }

    virtual void update() {
        viewProj = projection * view;
    }

    virtual void translate(glm::vec3 v){
        position += v;
        view = glm::translate(view, v * -1.0f);
        update();
    }

protected:
    glm::vec3 position;
    glm::mat4 projection;
    glm::mat4 view;
    glm::mat4 viewProj;
};
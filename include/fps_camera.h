#pragma once
#include "camera.h"

class FPSCamera : public Camera
{
public:
    FPSCamera(glm::vec3 position, float fov, float width, float height) : Camera(position, fov, width, height),
                                                                          yaw(90.0f), pitch(0.0f),
                                                                          up(glm::vec3(0.0f, 1.0f, 0.0f))
    {
        onMouseMoved(0.0f, 0.0f);
        update();
    }

    void onMouseMoved(float xRel, float yRel)
    {
        yaw += xRel * mouseSensitivity;
        pitch -= yRel * mouseSensitivity;
        if (pitch > 89.0f)
        {
            pitch = 89.0f;
        }
        if (pitch < -89.0f)
        {
            pitch = -89.0f;
        }

        glm::vec3 front;
        front.x = cos(glm::radians(pitch)) * cos(glm::radians(yaw));
        front.y = sin(glm::radians(pitch));
        front.z = cos(glm::radians(pitch)) * sin(glm::radians(yaw));

        lookAt = glm::normalize(front);
        update();
    }

    void update() override
    {
        view = glm::lookAt(position, position + lookAt, up);
        viewProj = projection * view;
    }

    void movedFront(float amount)
    {
        translate(lookAt * amount);
        update();
    }

    void movedSideways(float amount)
    {
        translate(glm::normalize(glm::cross(lookAt, up)) * amount);
        update();
    }

    void moveUp(float amount) {
        translate(up * amount);
    }

protected:
    float yaw;
    float pitch;
    glm::vec3 lookAt;
    const float mouseSensitivity = 0.3f;
    glm::vec3 up;
};
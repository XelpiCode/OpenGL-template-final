#pragma once
#include <glm/glm.hpp>
#include "GLFW/glfw3.h"

class Camera {
    public:

    float yaw;
    float pitch;

    glm::vec3 cameraPos;
    glm::vec3 cameraFront;
    glm::vec3 cameraUp;

    const float cameraSpeed = 3.0f;
    const float cameraSensitivity = 0.1f;

    glm::vec3 direction;

    Camera();

    void processInput(GLFWwindow* window, float deltaTime);

    [[nodiscard]] glm::mat4 getViewMatrix() const;
};

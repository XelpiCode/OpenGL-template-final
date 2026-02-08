#include <camera.hpp>

#include "opengl_utils.hpp"
#include "GLFW/glfw3.h"
#include "glm/ext/matrix_transform.hpp"
#include "glm/gtc/quaternion.hpp"

Camera::Camera(int width, int height, float fov)
:   yaw(-90),
    pitch(0),

    cameraPos(0.0f, 0.0f, 3.0f),
    cameraFront(0.0f, 0.0f, -1.0f),
    cameraUp(0.0f, 1.0f, 0.0f),
    camFov(fov) {

    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch)) * cos(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw));

    lastX = static_cast<float>(width) / 2.0f;
    lastY = static_cast<float>(height) / 2.0f;
}

void Camera::processInput(GLFWwindow* window, const float deltaTime) {
    const float normalSpeed = cameraSpeed * deltaTime;

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        cameraPos += cameraFront * normalSpeed;
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        cameraPos -= cameraFront * normalSpeed;
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * normalSpeed;
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * normalSpeed;
    }
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
        cameraPos += cameraUp * normalSpeed;
    }
    if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS) {
        cameraPos -= cameraUp * normalSpeed;
    }
}

glm::mat4 Camera::getViewMatrix() const {
    return glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
}

void Camera::processMouseScroll(const float ypos) {
    camFov -= static_cast<float>(ypos);
    if (camFov < 1.0f) {
        camFov = 1.0f;
    }
    if (camFov > 45.0f) {
        camFov = 45.0f;
    }
}

void scrollCallback(GLFWwindow* window, double xoffset, const double yoffset) {
    auto* state = static_cast<openglState*>(glfwGetWindowUserPointer(window));
    state->camera.processMouseScroll(static_cast<float>(yoffset));
}

void Camera::processMouseMovement(const float xpos, const float ypos) {
    if (firstMouse) {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos;
    lastX = xpos;
    lastY = ypos;

    xoffset *= cameraSensitivity;
    yoffset *= cameraSensitivity;

    yaw += xoffset;
    pitch += yoffset;

    if (pitch > 89.0f) {
        pitch = 89.0f;
    }
    if (pitch < -89.0f) {
        pitch = -89.0f;
    }

    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    cameraFront = glm::normalize(direction);
}

// calls Camera.processMouseMovement()
void mouseCallback(GLFWwindow* window, const double xpos, const double ypos) {
    auto* state = static_cast<openglState*>(glfwGetWindowUserPointer(window));
    state->camera.processMouseMovement(static_cast<float>(xpos), static_cast<float>(ypos));
}
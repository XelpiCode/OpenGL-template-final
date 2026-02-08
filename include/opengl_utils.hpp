#pragma once
#include "GLFW/glfw3.h"
#include <camera.hpp>

struct openglState {
    GLFWwindow* window{};
    int width;
    int height;
    Camera camera;

    openglState(const int width, const int height)
        : width(width), height(height), camera(width, height, 45.0f)
    {}

};

bool initOpenGL(openglState &state);
void setWindowIcon(const openglState &state);
void cleanupOpenGL(const openglState &state);
void processInput(GLFWwindow *window);
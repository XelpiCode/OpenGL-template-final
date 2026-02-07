#pragma once
#include "GLFW/glfw3.h"
#include <camera.hpp>

struct openglState {
    GLFWwindow* window{};
    int width;
    int height;
    Camera camera;

    openglState(int width, int height)
        : width(width), height(height), camera(width, height)
    {}

};

bool initOpenGL(openglState &state);
void cleanupOpenGL(const openglState &state);
void processInput(GLFWwindow *window);
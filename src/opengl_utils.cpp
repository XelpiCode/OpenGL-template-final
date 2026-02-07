#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <opengl_utils.hpp>
#include <iostream>
#include <camera.hpp>

void cleanupOpenGL(const openglState &state) {
    glfwDestroyWindow(state.window);
    glfwTerminate();
}


bool initOpenGL(openglState &state) {
    bool initSuccess = true;

    if (!glfwInit()) {
        std::cout << "Failed to initialize glfw.\n";
        initSuccess = false;
    }

    state.window = glfwCreateWindow(state.width, state.height, "OpenGL window", nullptr, nullptr);
    if (!state.window) {
        std::cout << "Failed to create window.\n";
        initSuccess = false;
    }
    glfwMakeContextCurrent(state.window);

    if (!gladLoadGL(glfwGetProcAddress)) {
        std::cout << "Failed to initialize glad.\n";
        initSuccess = false;
    }

    glfwSetWindowUserPointer(state.window, &state);

    glViewport(0, 0, state.width, state.height);

    // allow blending of transparent pixels
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // enable depth buffer
    glEnable(GL_DEPTH_TEST);

    // Make cursor invisible
    glfwSetInputMode(state.window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // call mouse_callback when mouse moves
    glfwSetCursorPosCallback(state.window, mouseCallback);

    return initSuccess;
}

void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}
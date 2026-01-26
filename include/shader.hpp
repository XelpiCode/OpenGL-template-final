#pragma once

#include <glad/gl.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "glm/fwd.hpp"
#include "glm/vec3.hpp"

class Shader {
    public:

    // the program ID
    GLuint ID;

    // constructor reads and builds the shader
    Shader(const char* vertexPath, const char* fragmentPath);

    // use/activate the shader
    void use();

    // utility uniform functions
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
    void setVec3(const std::string &name, const glm::vec3 &value) const;
    void setMat4(const std::string &name, const glm::mat4 &value) const;

};

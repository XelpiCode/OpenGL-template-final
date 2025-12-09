#ifndef VAO_H
#define VAO_H

#include <glad/gl.h>
#include <bufferObjects/VBO.hpp>

class VAO {
    public:

    GLuint ID;

    VAO();

    void LinkAttribute(
        VBO& VBO,
        GLuint index,
        GLint size,
        GLenum type,
        GLboolean normalized,
        GLsizei stride,
        const void* pointer
    );

    void Bind();

    void Unbind();

    void Delete();
};

#endif
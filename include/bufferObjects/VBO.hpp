#ifndef VBO_H
#define VBO_H

#include<glad/gl.h>

class VBO {
    public:

    GLuint ID;

    VBO(float *vertices, GLsizeiptr size);

    void Bind();

    void Unbind();

    void Delete();

};

#endif
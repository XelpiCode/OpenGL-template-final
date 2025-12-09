#include <bufferObjects/VAO.hpp>

VAO::VAO() {

}

void LinkAttribute(
     VBO& VBO,
     GLuint index,
     GLint size,
     GLenum type,
     GLboolean normalized,
     GLsizei stride,
     const void* pointer
);

void VAO::Bind() {

};

void VAO::Unbind() {

};

void VBO::Delete() {

};

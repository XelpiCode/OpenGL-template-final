#include <texture.hpp>

Texture::Texture(
    const std::string& path,
    TexFilter filter,
    TexWrap wrap,
    std::optional<glm::vec4> borderColor
) {
    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D, ID);

}

Texture::~Texture() {

}

void Texture::Bind() {

}

void Texture::Unbind() {

}

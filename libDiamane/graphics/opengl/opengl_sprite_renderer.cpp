// Copyright (c) 2020 Tom Hancocks
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <stdexcept>
#include "libDiamane/graphics/opengl/opengl_sprite_renderer.hpp"

// MARK: - Construction

diamane::graphics::opengl::sprite_renderer::sprite_renderer(std::weak_ptr<opengl::shader> shader)
{
    // Make the sure that we have been provided a shader before proceeding.
    if (auto s = shader.lock()) {
        m_shader = s;
        m_shader->use();
    } else {
        throw std::logic_error("Attempted to construct a sprite renderer with absent shader information");
    }

    // Setup vertex information and arrays
    float vertices[] = {
        // pos      // tex
        0.0, 1.0,   0.0, 1.0,
        1.0, 0.0,   1.0, 0.0,
        0.0, 0.0,   0.0, 0.0,

        0.0, 1.0,   0.0, 1.0,
        1.0, 1.0,   1.0, 1.0,
        1.0, 0.0,   1.0, 0.0
    };

    glGenVertexArrays(1, &m_vao);

    glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(m_vao);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, false, 4 * sizeof(float), (void*)0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

// MARK: - Destruction

diamane::graphics::opengl::sprite_renderer::~sprite_renderer()
{
//    glDeleteVertexArrays(1, &m_vao);
//    glDeleteBuffers(1, &m_vbo);
}

// MARK: - Drawing / Rendering

auto diamane::graphics::opengl::sprite_renderer::draw(std::shared_ptr<graphics::sprite> sprite) const -> void
{
    auto texture = sprite->texture();
    if (!texture) {
        return;
    }

    m_shader->use();

    auto model = glm::mat4(1.0);
    model = glm::translate(model, glm::vec3(glm::vec2(sprite->origin().x(), sprite->origin().y()), 0.0));
    model = glm::scale(model, glm::vec3(glm::vec2(sprite->size().width(), sprite->size().height()), 1.0));

    m_shader->set_mat4("model", model);
    m_shader->set_vec3("spriteColor", 1.0, 1.0, 1.0);

    glActiveTexture(GL_TEXTURE0);
    texture->bind();

    glBindVertexArray(m_vao);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}
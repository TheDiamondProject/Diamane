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

#include "libDiamane/graphics/opengl/opengl_scene.hpp"
#include "libDiamane/graphics/opengl/opengl_headers.hpp"
#include "libDiamane/graphics/opengl/opengl_context.hpp"
#include "libDiamane/graphics/opengl/opengl_texture.hpp"

// MARK: - Construction

diamane::graphics::opengl::scene::scene(opengl::context& context)
    : graphics::scene(), m_context(context)
{

}

diamane::graphics::opengl::scene::scene(opengl::context& context, const std::string &name)
    : graphics::scene(name), m_context(context)
{

}

// MARK: - Loops

auto diamane::graphics::opengl::scene::update() -> void
{
    graphics::scene::update();
}

auto diamane::graphics::opengl::scene::render() -> void
{
    auto renderer = m_context.renderer();

    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    if (renderer.has_value()) {
        for (auto const& [name, sprite] : m_sprites) {
            renderer->draw(sprite);
        }
    }

    m_context.flush();
}

// MARK: - Textures

auto diamane::graphics::opengl::scene::create_texture(const std::string &name, const math::size &sz, std::vector<uint32_t> data) -> std::weak_ptr<graphics::texture>
{
    // Construct the texture
    if (auto existing = this->texture(name).lock()) {
        return {};
    }

    auto texture = std::make_shared<opengl::texture>(sz, data);
    m_textures.emplace(name, texture);
    return texture;
}
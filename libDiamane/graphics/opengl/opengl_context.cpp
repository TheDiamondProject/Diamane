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
#include <string>
#include <iostream>
#include "libDiamane/graphics/opengl/opengl_headers.hpp"
#include "libDiamane/graphics/opengl/opengl_context.hpp"
#include "libDiamane/graphics/opengl/opengl_texture.hpp"
#include "libDiamane/graphics/opengl/opengl_scene.hpp"

// MARK: - Built-in Constants

static std::string sprite_vertex_shader_source =
        "#version 330 core\n"
        "layout(location = 0) in vec4 vertex;"
        "out vec2 TexCoords;"
        "uniform mat4 model;"
        "uniform mat4 projection;"
        "void main() {"
        "   TexCoords = vertex.zw;"
        "   gl_Position = projection * model * vec4(vertex.xy, 0.0, 1.0);"
        "}";

static std::string sprite_fragment_shader_source =
        "#version 330 core\n"
        "in vec2 TexCoords;"
        "out vec4 color;"
        "uniform sampler2D image;"
        "uniform vec3 spriteColor;"
        "void main() {"
        "   color = vec4(spriteColor, 1.0) * texture(image, TexCoords);"
        "}";


// MARK: - Construction

diamane::graphics::opengl::context::context()
{
    if (!glfwInit()) {
        throw std::runtime_error("Could not initialise OpenGL");
    }

    // Configure the main window for the context.
#if __APPLE__
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#else
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
#endif
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true);

    glfwSetErrorCallback([](GLint code, const char *reason) {
        throw std::runtime_error("Failed to create a window for OpenGL context: " + std::string(reason));
    });

    m_window = glfwCreateWindow(800, 600, "OpenGL Context", NULL, NULL);
    if (!m_window) {
        glfwTerminate();
        throw std::runtime_error("Failed to create a window for OpenGL context.");
    }

    glfwMakeContextCurrent(m_window);
    glfwSwapInterval(1);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Configure the default sprite shader for the context.
    m_renderer = opengl::sprite_renderer(load_shader("sprite", sprite_vertex_shader_source, sprite_fragment_shader_source));

    m_running = true;
}

// MARK: - Configuration

auto diamane::graphics::opengl::context::configure_viewport(GLdouble width, GLdouble height) -> void
{
    glViewport(0, 0, width, height);
    glm::mat4 projection = glm::ortho(0.0, width, height, 0.0, -1.0, 0.0);

    auto shader = get_shader("sprite").lock();
    shader->set_mat4("projection", projection);
    shader->set_integer("image", 0);
}

auto diamane::graphics::opengl::context::set_title(const std::string &title) -> void
{
    glfwSetWindowTitle(m_window, title.c_str());
}

auto diamane::graphics::opengl::context::set_size(const double &width, const double& height) -> void
{
    glfwSetWindowSize(m_window, width, height);
    configure_viewport(width, height);
}


// MARK: - Runtime

auto diamane::graphics::opengl::context::is_running() const -> bool
{
    return m_running;
}

// MARK: - Shaders

auto diamane::graphics::opengl::context::get_shader(const std::string &name) -> std::weak_ptr<opengl::shader>
{
    if (m_shaders.find(name) == m_shaders.end()) {
        return {};
    }
    return m_shaders.at(name);
}

auto diamane::graphics::opengl::context::load_shader(const std::string& name, const std::string& vertex_source, const std::string& fragment_source) -> std::weak_ptr<opengl::shader>
{
    auto shader = std::make_shared<opengl::shader>();
    shader->compile(vertex_source, fragment_source);
    m_shaders.emplace(name, shader);
    return shader;
}

// MARK: - Access

auto diamane::graphics::opengl::context::renderer() const -> std::optional<opengl::sprite_renderer>
{
    return m_renderer;
}

auto diamane::graphics::opengl::context::flush() const -> void
{
    glfwSwapBuffers(m_window);
    glfwPollEvents();
}

auto diamane::graphics::opengl::context::begin_scene(const std::string &name) -> std::weak_ptr<graphics::scene>
{
    auto scene = std::make_shared<opengl::scene>(*this, name);
    m_scenes.emplace_back(scene);
    return scene;
}

// MARK: - Input Processing

auto diamane::graphics::opengl::context::key(event::keycode code, event::key_state state) const -> bool
{
    int input_state = glfwGetKey(m_window, code);

    switch (input_state) {
        case GLFW_PRESS:
            return state == event::pressed;

        case GLFW_REPEAT:
            return state == event::held;

        case GLFW_RELEASE:
            return state == event::released;

        default:
            return false;
    }
}
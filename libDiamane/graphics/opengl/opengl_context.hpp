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

#if !defined(DIAMANE_OPENGL_CONTEXT_HPP)
#define DIAMANE_OPENGL_CONTEXT_HPP

#include <map>
#include <optional>
#include "libDiamane/graphics/opengl/opengl_headers.hpp"
#include "libDiamane/graphics/opengl/opengl_shader.hpp"
#include "libDiamane/graphics/common/context.hpp"
#include "libDiamane/graphics/opengl/opengl_sprite_renderer.hpp"

namespace diamane { namespace graphics { namespace opengl {

    /**
     * OpenGL Graphics Context
     *
     * This provides the API for each of the publicly exposed graphics functions.
     */
    class context : public graphics::context
    {
    private:
        GLFWwindow *m_window { nullptr };
        std::map<std::string, std::shared_ptr<opengl::shader>> m_shaders;
        bool m_running { false };
        std::optional<opengl::sprite_renderer> m_renderer;

        auto configure_viewport(GLdouble width, GLdouble height) -> void;

    public:
        context();

        auto window() const -> GLFWwindow *;

        auto set_title(const std::string& title) -> void override;
        auto set_size(const double& width, const double& height) -> void override;

        auto is_running() const -> bool override;

        auto get_shader(const std::string& name) -> std::weak_ptr<opengl::shader>;
        auto load_shader(const std::string& name, const std::string& vertex_source, const std::string& fragment_source) -> std::weak_ptr<opengl::shader>;

        auto begin_scene(const std::string &name) -> std::weak_ptr<graphics::scene> override;

        auto renderer() const -> std::optional<opengl::sprite_renderer>;
        auto flush() const -> void;

        auto key(event::keycode code, event::key_state state) const -> bool override;
    };

}}};

#endif //DIAMANE_OPENGL_CONTEXT_HPP

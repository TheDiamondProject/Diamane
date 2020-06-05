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

#if !defined(DIAMANE_OPENGL_SHADER_HPP)
#define DIAMANE_OPENGL_SHADER_HPP

#include <memory>
#include <string>
#include "libDiamane/graphics/opengl/opengl_headers.hpp"

namespace diamane { namespace graphics { namespace opengl {

    class shader: public std::enable_shared_from_this<opengl::shader>
    {
    private:
        GLuint m_id { 0 };

        auto check(GLuint object, const std::string &type) -> void;

    public:
        shader();

        auto use() -> std::shared_ptr<opengl::shader>;

        auto compile(const std::string& vertex_source, const std::string& fragment_source) -> void;

        auto set_float(const std::string& name, float value, bool use_shader = false) -> void;
        auto set_integer(const std::string& name, float value, bool use_shader = false) -> void;
        auto set_vec2(const std::string& name, float x, float y, bool use_shader = false) -> void;
        auto set_vec2(const std::string& name, glm::vec2 &value, bool use_shader = false) -> void;
        auto set_vec3(const std::string& name, float x, float y, float z, bool use_shader = false) -> void;
        auto set_vec3(const std::string& name, glm::vec3 &value, bool use_shader = false) -> void;
        auto set_vec4(const std::string& name, float x, float y, float z, float w, bool use_shader = false) -> void;
        auto set_vec4(const std::string& name, glm::vec4 &value, bool use_shader = false) -> void;
        auto set_mat4(const std::string& name, glm::mat4 &matrix, bool use_shader = false) -> void;
    };
}}};

#endif //DIAMANE_OPENGL_SHADER_HPP

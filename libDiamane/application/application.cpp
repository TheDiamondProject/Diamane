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

#include "libDiamane/application/application.hpp"
#include "libDiamane/graphics/opengl/opengl_context.hpp"


// MARK: - Construction

diamane::application::application()
{

}

// MARK: - Application Entry Point

auto diamane::application::start(int argc, const char **argv, std::function<auto(std::vector<std::string>)->void> entry) -> int
{
    for (auto i = 1; i < argc; ++i) {
        m_arguments.emplace_back(std::string(argv[i]));
    }

    m_context = std::make_shared<graphics::opengl::context>();
    entry(m_arguments);

    while (m_context && m_context->is_running()) {
        m_context->tick();
    }

    return 0;
}

// MARK: - Accessors

auto diamane::application::current_context() -> std::shared_ptr<graphics::context>
{
    return m_context;
}
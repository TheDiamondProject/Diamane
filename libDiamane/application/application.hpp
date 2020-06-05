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

#if !defined(DIAMANE_APPLICATION_HPP)
#define DIAMANE_APPLICATION_HPP

#include <memory>
#include <string>
#include <vector>
#include <functional>
#include "libDiamane/graphics/common/context.hpp"

namespace diamane
{

    /**
     * The diamane::application class is used to manage the lifetime of the application
     * or game.
     */
    class application
    {
    private:
        std::shared_ptr<graphics::context> m_context;
        std::vector<std::string> m_arguments;

        application();

    public:
        application(const application&) = delete;
        application& operator=(const application&) = delete;
        application(application&&) = delete;
        application& operator=(application&&) = delete;

        static auto shared() -> application&
        {
            static application instance;
            return instance;
        }

        auto start(int argc, const char **argv, std::function<auto(std::vector<std::string>)->void> entry) -> int;

        auto current_context() -> std::shared_ptr<graphics::context>;

    };

    static auto app() -> application&
    {
        return application::shared();
    }

}

#endif //DIAMANE_APPLICATION_HPP

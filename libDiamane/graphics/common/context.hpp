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

#if !defined(DIAMANE_CONTEXT_HPP)
#define DIAMANE_CONTEXT_HPP

#include <vector>
#include <memory>
#include <chrono>
#include <string>
#include <functional>
#include "libDiamane/graphics/common/scene.hpp"
#include "libDiamane/application/events/keyboard.hpp"

namespace diamane { namespace graphics {

    using game_clock = std::chrono::steady_clock;
    using ms = std::chrono::milliseconds;
    using seconds = std::chrono::duration<float>;
    using game_time_point = std::chrono::time_point<game_clock, seconds>;

    class context : public std::enable_shared_from_this<graphics::context>
    {
    protected:
        double m_time { 0.0 };
        double m_delta { 0.01 };
        game_time_point  m_current_time { game_clock::now() };
        double m_accumulator { 0.0 };
        std::vector<std::shared_ptr<graphics::scene>> m_scenes;

    public:
        virtual auto set_title(const std::string& title) -> void {};
        virtual auto set_size(const double& width, const double& height) -> void {};

        virtual auto begin_scene(const std::string& name) -> std::weak_ptr<graphics::scene>;
        virtual auto end_scene() -> void;
        virtual auto current_scene() -> std::weak_ptr<graphics::scene>;

        virtual auto is_running() const -> bool { return false; };

        virtual auto tick() -> void;
        virtual auto update() -> void;
        virtual auto render() -> void;
    };

}};

#endif //DIAMANE_CONTEXT_HPP

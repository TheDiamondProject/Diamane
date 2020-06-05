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

#include "libDiamane/graphics/common/context.hpp"

// MARK: - Run Loop

auto diamane::graphics::context::tick() -> void
{
    game_time_point new_time { game_clock::now() };
    double frame_time = (new_time - m_current_time).count();
    if (frame_time > 0.25) {
        frame_time = 0.25;
    }
    m_current_time = new_time;
    m_accumulator += frame_time;

    while (m_accumulator >= m_delta) {
        update();
        m_time += m_delta;
        m_accumulator -= m_delta;
    }

    render();
}

// MARK: - Scene Management

auto diamane::graphics::context::begin_scene(const std::string &name) -> std::weak_ptr<graphics::scene>
{
    auto scene = std::make_shared<graphics::scene>(name);
    m_scenes.emplace_back(scene);
    return scene;
}

auto diamane::graphics::context::end_scene() -> void
{
    auto scene = m_scenes.back();
    m_scenes.pop_back();

    // TODO: scene.end();
}

auto diamane::graphics::context::current_scene() -> std::weak_ptr<graphics::scene>
{
    return m_scenes.back();
}

// MARK: - Loops

auto diamane::graphics::context::update() -> void
{
    if (auto scene = current_scene().lock()) {
        scene->update();
    }
}

auto diamane::graphics::context::render() -> void
{
    if (auto scene = current_scene().lock()) {
        scene->render();
    }
}

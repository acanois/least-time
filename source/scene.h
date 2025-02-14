//
// Created by David Richter on 1/29/25.
//

#include "appconfig.h"
#include "bar.h"
#include "scenecamera.h"

#include "raylib.h"

#include <iostream>
#include <cmath>
#include <memory>
#include <array>
#include <vector>
#include <ranges>

#pragma once

class Scene {
public:
    Scene();

    void update();
    void draw();

    static void showGrid();

private:
    void drawSceneElements();

    static constexpr int mWidth { 1280 };
    static constexpr int mHeight { 720 };
    static constexpr int mPanelSize { 512 };

    bool mShowGrid { false };

    std::unique_ptr<SceneCamera> mCamera = nullptr;

    std::vector<std::unique_ptr<Bar>> mBars;
};


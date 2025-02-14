//
// Created by David Richter on 1/29/25.
//

#include "scene.h"

Scene::Scene()
: mCamera(std::make_unique<SceneCamera>(
              Vector3{0.f, GRID_SIZE, 0.f},  // Position
              Vector3{0.f, 0.f, 1.f},        // Target
              Vector3{0.f, 1.f, 0.f},        // Up
              45.f,                          // FOV
              CAMERA_PERSPECTIVE
          )
) {
    InitWindow(mWidth, mHeight, "Principle of Least Time");

    auto numBars = 128;
    auto angle = 0.f;
    auto angleIncrement = 360.f / static_cast<float>(numBars);
    auto radius = GRID_SIZE * 0.33f;
    auto color = swatch::EERIE_BLACK;

    for (auto i = 0; i < numBars; i++) {
        auto randColor = GetRandomValue(1, 3);
        if (randColor == 1)
            color = swatch::BACKGROUND;
        else if (randColor == 2)
            color = swatch::EERIE_BLACK;
        else if (randColor == 3)
            color = swatch::BLACK_OLIVE;

        auto theta = angle * static_cast<float>(M_PI) / 180.f;
        mBars.push_back(std::make_unique<Bar>(
            Vector3{
                sin(theta) * radius,
                4.f,
                cos(theta) * radius
            },
            Vector3{ 2.f, 2.f, 2.f },
            color
        ));
        angle += angleIncrement;
    }
}

void Scene::update() {
    
}

void Scene::drawSceneElements() {
    for (auto&& bar : mBars) {
        bar->update();
        bar->draw();
    }

    DrawCubeV(
        Vector3 { 0.f, 1.f, 0.f },
        Vector3 { (GRID_SIZE * 1.5) * 1.25, 1.f, GRID_SIZE * 1.25 },
        swatch::TIMBERWOLF
    );
}

void Scene::draw() {
    BeginDrawing();
    ClearBackground(swatch::BACKGROUND);
    mCamera->beginMode3d();

    mCamera->updateCamera();

    if (IsKeyDown(KEY_G)) mShowGrid = !mShowGrid;
    if (mShowGrid) showGrid();

    drawSceneElements();

    mCamera->endMode3d();
    EndDrawing();
}

void Scene::showGrid() {
    DrawGrid(mPanelSize, 1.f);
}

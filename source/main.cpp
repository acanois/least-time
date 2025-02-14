#include "scene.h"

#include "raylib.h"

#include <iostream>
#include <memory>

int main() {
    SetTargetFPS(60);

    std::unique_ptr<Scene> scene = std::make_unique<Scene>();

    while (!WindowShouldClose()) {
        scene->showGrid();
        scene->draw();
    }

    return 0;
}

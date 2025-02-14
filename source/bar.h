//
// Created by David Richter on 1/30/25.
//

#include "raylib.h"


class Bar {
public:
    Bar() = default;

    Bar(Vector3 position, Vector3 size, Color color);

    void update();
    void setPostion(Vector3 position);
    void setHeight(float height);

    void draw();

private:
    Vector3 mPosition;
    Vector3 mSize;

    Color mColor;
};

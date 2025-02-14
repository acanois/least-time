//
// Created by David Richter on 1/30/25.
//

#include "bar.h"

Bar::Bar(Vector3 position, Vector3 size, Color color)
    : mPosition(position),
      mSize(size),
      mColor(color)
{

}

void Bar::update() {

}

void Bar::setPostion(Vector3 position) {
    mPosition = position;
}

void Bar::setHeight(float height) {
    mSize.y = height;
}

void Bar::draw() {
//    DrawCubeV(mPosition, mSize, mColor);
    DrawCylinder(mPosition, 1.f, 1.f, mSize.y, 12.f, mColor);
}

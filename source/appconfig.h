//
// Created by David Richter on 1/26/25.
//

#include "raylib.h"

# pragma once

/*
<palette>
  <color name="Floral white" hex="fffcf2" r="255" g="252" b="242" />
  <color name="Timberwolf" hex="ccc5b9" r="204" g="197" b="185" />
  <color name="Black olive" hex="403d39" r="64" g="61" b="57" />
  <color name="Eerie black" hex="252422" r="37" g="36" b="34" />
  <color name="Flame" hex="eb5e28" r="235" g="94" b="40" />
</palette>
 */

// Color Scheme
namespace swatch {
    static constexpr Color BACKGROUND = Color { 15, 15, 15, 255 };
    static constexpr Color JET = Color{ 42, 43, 42, 255 };
    static constexpr Color BLACK_OLIVE = Color{ 64, 61, 57, 255 };
    static constexpr Color EERIE_BLACK = Color{ 37, 36, 34, 255 };
    static constexpr Color FLORAL_WHITE = Color{ 255, 252, 242, 255 };
    static constexpr Color TIMBERWOLF = Color{ 204, 197, 185, 255 };
    static constexpr Color FLAME = Color{ 226, 88, 34, 255 };
    static constexpr Color INDIGO_DYE = Color{ 39, 39, 96, 255 };
}

// Reference Grid
static constexpr int GRID_SIZE = 512;

// Frequency Bars
static constexpr int FFT_SIZE = 512;

// Unit Scale
static constexpr float UNIT_SCALE = 1.f;



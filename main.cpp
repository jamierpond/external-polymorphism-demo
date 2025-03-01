#include <memory>
#include "shapes.h"
#include <memory>

using CircleModel = ShapeModel<Circle<int>>;
using SquareModel = ShapeModel<Square<int>>;

auto make_circle(int radius) {
  return std::make_unique<CircleModel>(Circle<int>{radius}, CLIDrawStrategy<int>());
}

auto make_square(int side) {
  return std::make_unique<SquareModel>(Square<int>{side}, CLIDrawStrategy<int>());
}

int main() {
  std::vector<std::unique_ptr<ShapeConcept>> shapes{};

  shapes.push_back(make_circle(10));
  shapes.push_back(make_circle(20));
  shapes.push_back(make_square(10));

  for (auto& shape : shapes) {
    shape->draw();
  }

  return 0;
}

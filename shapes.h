#include <functional>

/* Shapes */
template <typename T>
struct Circle {
  explicit Circle(T radius) : radius(radius) {}
  T radius;
};

template <typename T>
struct Square {
  explicit Square(T side) : side(side) {}
  T side;
};

/* Shape Concepts */
struct ShapeConcept {
  virtual void draw() const = 0;
};

/* Shape Model */
template <typename Shape>
struct ShapeModel : public ShapeConcept {
  using DrawStrategy = std::function<void(const Shape&)>;
  explicit ShapeModel(const Shape& shape, DrawStrategy strategy)
    : shape(shape), draw_strategy(strategy) {}

  void draw() const override { draw_strategy(shape); }

  Shape shape;
  DrawStrategy draw_strategy;
};


/* Draw Strategies */
#include <iostream>
template <typename T>
struct CLIDrawStrategy {
  // define the operator() for each shape
  void operator()(const Circle<T>& shape) const {
    std::cout << "Drawing a " << typeid(Circle<T>).name() << std::endl;
  }

  void operator()(const Square<T>& shape) const {
    std::cout << "Drawing a " << typeid(Square<T>).name() << std::endl;
  }
};

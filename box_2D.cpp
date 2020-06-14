#include "box_2D.h"
#include "circle_2D.h"


Box_2D::Box_2D(float width, float height, Vector_2D translation) : _translation(translation.x(), translation.y()) {
				_width = width;
				_height = height;
}


float Box_2D::width() {
				return _width;
}

float Box_2D::height() {
				return _height;
}

void Box_2D::setSize(float width, float height) {
				_width = width;
				_height = height;
}

Vector_2D Box_2D::translation() {
				return _translation;
}

void Box_2D::set_translation(Vector_2D translation)
{
				_translation = translation;
}
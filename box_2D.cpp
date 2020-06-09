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

float Box_2D::intersection_depth(Circle_2D other)
{
				return 0.0;
				/*
				if (_radius == 0.0f || other._radius == 0.0f)
				{
								return 0.0;
				}

				const float distance_to_other = (other.translation() - _translation).magnitude();

				if (distance_to_other < (_radius + other._radius))
				{
								return (_radius + other._radius) - distance_to_other;
				}
				else
				{
								return 0.0f;
				}
				*/
}
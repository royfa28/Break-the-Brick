#include "collision_2D.h"


Collision_2D::Collision_2D(float radius, Vector_2D translation) : _translation(translation.x(), translation.y()) {
				_radius = radius;
}

float Collision_2D::radius() {
				return _radius;
}

void Collision_2D::set_radius(float radius) {

				_radius = radius;
}

float Collision_2D::width() {
				return _width;
}

float Collision_2D::height() {
				return _height;
}


void Collision_2D::setSize(float width, float height) {
				_width = width;
				_height = height;
}

Vector_2D Collision_2D::translation() {
				return _translation;
}

void Collision_2D::set_translation(Vector_2D translation)
{
				_translation = translation;
}

float Collision_2D::intersection_depth(Collision_2D other)
{
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
}
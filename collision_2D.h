#pragma once
#pragma once

#include "vector_2D.h"

class Collision_2D
{

public:

				Collision_2D(float radius, Vector_2D translation);

				float radius();
				float width();
				float height();

				void set_radius(float radius);
				void setSize(float width, float height);

				Vector_2D translation();
				void set_translation(Vector_2D translation);

				float intersection_depth(Collision_2D other);

private:
				float _radius;
				float _width, _height;
				Vector_2D _translation;
};
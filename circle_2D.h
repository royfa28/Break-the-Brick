#pragma once

#include "vector_2D.h"
#include "box_2D.h"
#include <iostream>

class Circle_2D
{

public:

				Circle_2D(float radius, Vector_2D translation);

				float radius();

				void set_radius(float radius);

				Vector_2D translation();
				void set_translation(Vector_2D translation);

				float intersection_depth(Box_2D other, Circle_2D circleCollider); // Is this correct?
private:
				float _radius;
				Vector_2D _translation;
};
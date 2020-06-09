#pragma once

#include "vector_2D.h"

class Box_2D
{

public:

				Box_2D(float width, float height, Vector_2D translation);

				float width();
				float height();

				void setSize(float width, float height);

				Vector_2D translation();
				void set_translation(Vector_2D translation);

				float intersection_depth(Box_2D other);

private:
				float _radius;
				float _width, _height;
				Vector_2D _translation;
};
#include "circle_2D.h"

Circle_2D::Circle_2D(float radius, Vector_2D translation) : _translation(translation.x(), translation.y()) {
				_radius = radius;
}

float Circle_2D::radius() {
				return _radius;
}

void Circle_2D::set_radius(float radius) {

				_radius = radius;
}

Vector_2D Circle_2D::translation() {
				return _translation;
}

void Circle_2D::set_translation(Vector_2D translation)
{
				_translation = translation;
}

float Circle_2D::intersection_depth(Box_2D other, Circle_2D circleCollider) // Do I make the contructor  
// float Circle_2D::intersection_depth(Box_2D other)
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

				/*
								I'm guessing this is where the code goes?

								boolean circleRect(float ballXPosition, float ballYPosition, float radius, float brickXPosition, float brickYPosition, float brickWidth, float brickHeight) {


								In this case:
								ballXPosition = circleCollider.translation().x();
								ballYPosition = circleCollider.translation().y();
								radius = circleCollider.radius();

								brickXPosition = other.translation().x();
								brickYPosition = other.translation().y();
								brickWidth = other.width();
								brickHeight = other.height();


								// temporary variables to set edges for testing
								float testX = ballXPosition;
								float testY = ballYPosition;

								// which edge is closest?
								if (ballXPosition < brickXPosition)
												testX = rx;																																	// test left edge
								else if (ballXPosition > brickXPosition + brickWidth) 
												testX = brickXPosition + rw;																// right edge
								if (ballYPosition < brickYPosition)         
												testY = brickYPosition;																					// top edge
								else if (ballYPosition > brickYPosition + brickHeight) 
												testY = ry + rh;																												// bottom edge

								// get distance from closest edges
								float distX = ballXPosition - testX;
								float distY = ballYPosition - testY;
								float distance = sqrt((distX * distX) + (distY * distY));

								// if the distance is less than the radius, collision!
								if (distance <= radius) {
												return true;
								}
								return false;
				}
				
				*/
}
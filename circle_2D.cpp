#include "circle_2D.h"
#include "ball.h"
#include "game_object.h"

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
{
				Ball ball = ball;

				float ballXPosition = circleCollider.translation().x();
				float ballYPosition = circleCollider.translation().y();
				float radius = circleCollider.radius();

				float brickXPosition = other.translation().x();
				float brickYPosition = other.translation().y();
				float brickWidth = other.width();
				float brickHeight = other.height();

				if ((ballYPosition + radius < brickYPosition)
								|| (ballYPosition > brickYPosition + brickHeight)
								|| (ballXPosition > brickXPosition + brickWidth)
								|| (ballXPosition + radius < brickXPosition))
				{
								// No collision
				}
				else {
								if (ballYPosition <= brickYPosition + brickHeight)
								{
												std::cout << "Hit from btm" << std::endl;
												ball.ballCollision(3);
												return 0.0;
								}
								//Hit was from below the brick

								if (ballYPosition < brickYPosition)
								{
												std::cout << "Hit from top" << std::endl;
												ball.ballCollision(1);
												return 0.0;
								}
								//Hit was from above the brick

								if (ballXPosition < brickXPosition)
								{
												ball.ballCollision(0);
												std::cout << "Hit from left" << std::endl;
												return 0.0;
								}
								//Hit was on left

								if (ballXPosition > brickXPosition + brickWidth)
								{
												ball.ballCollision(2);
												std::cout << "Hit from right" << std::endl;
												return 0.0;
								}
								//Hit was on right
				}
				/*
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
				*/
				return 0.1f;
}

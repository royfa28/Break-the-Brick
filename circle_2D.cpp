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
								if (ballYPosition >= brickYPosition + brickHeight / 2)
								{
												std::cout << "Hit from btm" << std::endl;
												return 3.0;
								}
								//Hit was from below the brick

								if (ballYPosition <= brickYPosition)
								{
												std::cout << "Hit from top" << std::endl;
												return 1.0;
								}
								//Hit was from above the brick

								if (ballXPosition <= brickXPosition)
								{
												std::cout << "Hit from left" << std::endl;
												return 0.0;
								}
								//Hit was on left

								if (ballXPosition >= brickXPosition + brickWidth / 2)
								{
												std::cout << "Hit from right" << std::endl;
												return 2.0;
								}
								//Hit was on left
				}
				return 0.1f;
}

float Circle_2D::ballPaddleCollision(Box_2D other, Circle_2D circleCollider) {

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
								if (ballYPosition <= brickYPosition)
								{
												if (ballXPosition <= brickXPosition + brickWidth && ballXPosition >= brickXPosition + brickWidth * 0.75) {
																return 1.0f;
												}
												if (ballXPosition <= brickXPosition + brickWidth * 0.75 && ballXPosition >= brickXPosition + brickWidth * 0.5) {
																return 2.0f;
												}
												if (ballXPosition <= brickXPosition + brickWidth * 0.5 && ballXPosition >= brickXPosition + brickWidth * 0.25) {
																return 3.0f;
												}
												if (ballXPosition <= brickXPosition + brickWidth * 0.25 && ballXPosition >= brickXPosition) {
																return 4.0f;
												}
								}
				}
				return 0.1f;
}

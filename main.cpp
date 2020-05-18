#include <iostream>
#include <chrono>
#include <thread>

#include "engine.h"

int main(void)
{
				Engine* engine = new Engine();

				const Uint32 milliseconds_per_seconds = 1000;
				const Uint32 frames_per_second = 60;
				const Uint32 frame_time_ms = milliseconds_per_seconds / frames_per_second;

				Uint32 frame_start_time_ms = 0;
				Uint32 frame_end_time_ms = frame_time_ms;
				while (true)
				{
								Uint32 previous_frame_duration = frame_end_time_ms - frame_start_time_ms;
								frame_start_time_ms = SDL_GetTicks();

								engine->simulate(previous_frame_duration);

								const Uint32 current_time_ms = SDL_GetTicks();
								const Uint32 frame_duration_ms = current_time_ms - frame_start_time_ms;
								if (frame_duration_ms < frame_time_ms)
								{
												const Uint32 time_to_sleep_for = frame_time_ms - frame_duration_ms;
												std::this_thread::sleep_for(std::chrono::milliseconds(time_to_sleep_for));
								}

								frame_end_time_ms = SDL_GetTicks();

				}

				return 0;
}
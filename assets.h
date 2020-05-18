#pragma once

#include <map>

#include "texture.h"


class Assets
{
public:
				Assets(SDL_Renderer* renderer);
				~Assets();

				Texture* get_texture(std::string id);

private:
				std::map<std::string, Texture*> _textures;
};
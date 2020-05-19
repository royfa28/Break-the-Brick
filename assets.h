#pragma once

#include <map>

#include "texture.h"


class Assets {

public:
				Assets(SDL_Renderer* renderer);
				~Assets();

				Asset* get_asset(std::string id);

private:
				std::map<std::string, Asset*> _assets;
};
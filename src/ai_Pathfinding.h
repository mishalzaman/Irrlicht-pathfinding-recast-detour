#ifndef AI_PATHFINDING_H
#define AI_PATHFINDING_H

#include <irrlicht.h>
#include <vector>
#include "ai_util_RecastDetour.h"

using namespace irr;

class ai_Pathfinding
{
public:
	ai_Pathfinding();
	~ai_Pathfinding();
	bool load(io::path filename, scene::ISceneManager* smgr);
	std::vector<irr::core::vector3df> getPath(core::vector3df start, core::vector3df end);
	void renderDebugPath(std::vector<irr::core::vector3df> path, video::IVideoDriver* driver);
private:
	io::path						  filename;
	scene::IMeshSceneNode*			  navMesh = 0;				// the nav mesh scene node
	scene::ISceneNode*				  naviDebugData = 0;		// the nav mesh with polygon debug data
	ai_util_RecastDetour*			  recast = 0;
	std::vector<irr::core::vector3df> path;
};

#endif


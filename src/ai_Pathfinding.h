//MIT License
//
//Copyright(c) 2020 MZ
//
//Permission is hereby granted, free of charge, to any person obtaining a copy
//of this softwareand associated documentation files(the "Software"), to deal
//in the Software without restriction, including without limitation the rights
//to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
//copies of the Software, and to permit persons to whom the Software is
//furnished to do so, subject to the following conditions :
//
//The above copyright noticeand this permission notice shall be included in all
//copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//SOFTWARE.

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


# Irrlicht Pathfinding

## Dependencies
- Irrlicht 1.84
- [Recast/Detaour](https://github.com/recastnavigation/recastnavigation)

This is an implementation of Recast/Detour's pathfinding algorithm within Irrlicht framework. Recast/Detour are two C++ libraries where one handles the navigation mesh, and the other creates a path (using A*) between nodes.

This repo contains two sets of header/cpp files which handle the pathfinding:

### ai_util_RecastDetour.h/cpp
This header file requires the Recast/Detour includes. It takes in an Irrlicht `irr::scene::IMeshBuffer*` to build the navigation mesh.

### ai_Pathfinding.h/cpp
This header file is a wrapper for `ai_util_RecastDetour`. It takes a filename of the navigation model (obj, b3d etc) and uses `ai_util_RecastDetour` to build the navigation mesh and provide path data.

## Example of Usage

    ai_Pathfinding*          pathFinding = 0;
    
    // Initialize ai_Pathfinding and load a model file
    pathFinding = new ai_Pathfinding();
    if (!pathFinding->load("assets/navmesh/navmesh.obj", smgr)) {
        printf("Error loading navmesh");
    }
    
    /* return an std::vector<core::vector3df> which contains the path between the aPosition
       and bPosition. This vector can then be used to move the object based on a delta time. */
    std::vector<core::vector3df> path = pathFinding->getPath(aPosition, bPosition);

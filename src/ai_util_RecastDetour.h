
#ifndef _RECAST_UTIL_H_
#define _RECAST_UTIL_H_

#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstddef>
#include <math.h>
#include <irrlicht.h>
#include <Recast/Recast.h>
#include <Detour/DetourNavMeshQuery.h>
#include <Detour/DetourNavMeshBuilder.h>
#include <Detour/DetourNavMesh.h>

#ifndef RECAST_UTIL_PROPERTIES
#define RECAST_UTIL_PROPERTIES
#endif

/// These are just sample areas to use consistent values across the samples.
/// The use should specify these base on his needs.
enum SamplePolyAreas
{
    SAMPLE_POLYAREA_GROUND,
    SAMPLE_POLYAREA_WATER,
    SAMPLE_POLYAREA_ROAD,
    SAMPLE_POLYAREA_DOOR,
    SAMPLE_POLYAREA_GRASS,
    SAMPLE_POLYAREA_JUMP,
};
enum SamplePolyFlags
{
    SAMPLE_POLYFLAGS_WALK = 0x01,       // Ability to walk (ground, grass, road)
    SAMPLE_POLYFLAGS_SWIM = 0x02,       // Ability to swim (water).
    SAMPLE_POLYFLAGS_DOOR = 0x04,       // Ability to move through doors.
    SAMPLE_POLYFLAGS_JUMP = 0x08,       // Ability to jump.
    SAMPLE_POLYFLAGS_DISABLED = 0x10,       // Disabled polygon
    SAMPLE_POLYFLAGS_ALL = 0xffff   // All abilities.
};

class ai_util_RecastDetour
{
public:
    ai_util_RecastDetour()
    {
        verts = 0;
        tris = 0;

        m_ctx = 0;
        m_keepInterResults = true;
        m_totalBuildTimeMs = 0;
        m_triareas = 0;

        m_solid = 0;
        m_chf = 0;
        m_cset = 0;
        m_pmesh = 0;
        m_dmesh = 0;
        rcContext* ctx;

        m_ctx = new rcContext();

        this->resetCommonSettings();
    };
    ~ai_util_RecastDetour()
    {
        cleanup();
    };


private:
    float* verts;
    int* tris;

    float m_cellSize;
    float m_cellHeight;
    float m_agentHeight;
    float m_agentRadius;
    float m_agentMaxClimb;
    float m_agentMaxSlope;
    float m_regionMinSize;
    float m_regionMergeSize;
    bool m_monotonePartitioning;
    float m_edgeMaxLen;
    float m_edgeMaxError;
    float m_vertsPerPoly;
    float m_detailSampleDist;
    float m_detailSampleMaxError;

    rcContext* m_ctx;

    bool m_keepInterResults;
    float m_totalBuildTimeMs;

    unsigned char* m_triareas;
    rcHeightfield* m_solid;
    rcCompactHeightfield* m_chf;
    rcContourSet* m_cset;
    rcPolyMesh* m_pmesh;
    rcConfig m_cfg;
    rcPolyMeshDetail* m_dmesh;
    void cleanup();

protected:
    dtNavMeshQuery* m_navQuery;
    dtNavMesh* m_navMesh;

public:
    void setContext(rcContext* ctx) { m_ctx = ctx; }

    bool handleBuild(irr::scene::IMeshBuffer* buffer);
    void resetCommonSettings();
    bool getMeshBufferData
    (
        irr::scene::IMeshBuffer* buffer,
        std::vector<float>& verts, int& nverts,
        std::vector<int>& tris, int& ntris
    );

    bool setupIrrSMeshFromRecastDetailMesh(irr::scene::SMesh* smesh);
    void showHeightFieldInfo(const rcHeightfield& hf);
    bool getMeshDataFromPolyMeshDetail
    (
        rcPolyMeshDetail* dmesh,
        std::vector<float>& vertsOut, int& nvertsOut,
        std::vector<int>& trisOut, int& ntrisOut
    );

    bool setMeshBufferData
    (
        irr::scene::SMeshBuffer& buffer,
        const std::vector<float>& verts, int& nverts,
        const std::vector<int>& tris, int& ntris
    );

    std::vector<irr::core::vector3df> returnPath(irr::core::vector3df pStart, irr::core::vector3df pEnd);
};

#endif


#ifndef __MODEL_PUZZLEBLOCK_H__
#define __MODEL_PUZZLEBLOCK_H__

#include "cocos2d.h"
#include <spine/CCSkeletonAnimation.h>

namespace Model
{
    class PuzzleBlock : public spine::SkeletonAnimation
    {
        CC_SYNTHESIZE(int, coordinateX, CoordinateX);
        CC_SYNTHESIZE(int, coordinateY, CoordinateY);

    public:
        PuzzleBlock(const char* skeletonDataFile, const char* atlasFile, float scale);
        static PuzzleBlock* createRandom();
    };
}

#endif // __MODEL_PUZZLEBLOCK_H__

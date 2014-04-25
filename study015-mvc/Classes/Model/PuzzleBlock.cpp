#include "PuzzleBlock.h"
//#include "PuzzleBlockType1.h"
//#include "PuzzleBlockType2.h"
//#include "PuzzleBlockType3.h"
//#include "PuzzleBlockType4.h"
//#include "PuzzleBlockType5.h"
#include "cocos2d.h"

namespace Model
{
    PuzzleBlock::PuzzleBlock(const char* skeletonDataFile, const char* atlasFile, float scale = 0)
        : SkeletonAnimation(skeletonDataFile, atlasFile, scale)
    {
        this->autorelease();
    }

    PuzzleBlock* PuzzleBlock::createRandom()
    {
        int type = rand() % 5 + 1;

        PuzzleBlock* block = nullptr;
        switch (type) {
            case 1:
                block = new PuzzleBlock("block/base.json", "block/red.atlas");
                break;
            case 2:
                block = new PuzzleBlock("block/base.json", "block/blue.atlas");
                break;
            case 3:
                block = new PuzzleBlock("block/base.json", "block/yellow.atlas");
                break;
            case 4:
                block = new PuzzleBlock("block/base.json", "block/green.atlas");
                break;
            case 5:
                block = new PuzzleBlock("block/base.json", "block/purple.atlas");
                break;
            default:
                CCASSERT(false, "no such block.");
                break;
        }
        return block;
    }
}

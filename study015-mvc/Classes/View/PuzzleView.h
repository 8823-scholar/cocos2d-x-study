#ifndef __PUZZLE_VIEW_H__
#define __PUZZLE_VIEW_H__

#include "View.h"
#include "cocos2d.h"

namespace View
{
    class PuzzleView : public View
    {
    public:
        virtual bool init();
        static PuzzleView* create(cocos2d::Scene* scene);
    };
}

#endif // __PUZZLE_VIEW_H__

#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H

#include "Config.h"
#include <raylib.h>
#include "DropObject.h"

enum GameObjectType {
    EGG,
    ROCK
};

class ObjectFactory {
public:
    static DropObject* Create(GameObjectType type) {
        switch (type) {
            case EGG: {
                Egg* returnEgg = new Egg();
                returnEgg->SetRadius(GetRandomValue(EGG_MIN_RADIUS, EGG_MAX_RADIUS));
                returnEgg->SetX(GetRandomValue(53 + returnEgg->GetRadius(), PLAY_WINDOW_WIDTH - returnEgg->GetRadius()));
                returnEgg->SetY(EGG_INIT_Y);
                returnEgg->SetYVelocity(0.0f);
                returnEgg->SetXVelocity(0.0f);
                return returnEgg;
            }
            case ROCK: {
                Rock* returnRock = new Rock();
                returnRock->SetRadius(GetRandomValue(7, 15));
                returnRock->SetX(GetRandomValue(53 + returnRock->GetRadius(), PLAY_WINDOW_WIDTH - returnRock->GetRadius()));
                returnRock->SetY(ROCK_INIT_Y);
                returnRock->SetYVelocity(0.0f);
                returnRock->SetXVelocity(0.0f);
                return returnRock;
            }
            default:
                return nullptr;
        }
    }
};



#endif
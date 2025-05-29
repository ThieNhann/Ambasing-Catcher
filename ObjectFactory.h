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
                returnEgg->SetX(GetRandomValue(75 + returnEgg->GetRadius(), PLAY_WINDOW_WIDTH - returnEgg->GetRadius()));
                returnEgg->SetY(EGG_INIT_Y);
                returnEgg->SetYVelocity(0.0f);
                returnEgg->SetXVelocity(EGG_INIT_Y_VELOCITY);
                returnEgg->LoadTexture("resource/images/egg.png");
                return returnEgg;
            }
            case ROCK: {
                Rock* returnRock = new Rock();
                returnRock->SetRadius(GetRandomValue(ROCK_MIN_RADIUS, ROCK_MAX_RADIUS));
                returnRock->SetX(GetRandomValue(75 + returnRock->GetRadius(), PLAY_WINDOW_WIDTH - returnRock->GetRadius()));
                returnRock->SetY(ROCK_INIT_Y);
                returnRock->SetYVelocity(0.0f);
                returnRock->SetXVelocity(0.0f);
                returnRock->LoadTexture("resource/images/rock.png");
                return returnRock;
            }
            default:
                return nullptr;
        }
    }
};



#endif
#include "Player.h"
#include "Global.h"

#define INVINCIBLE false

FocusHitbox::FocusHitbox() {}

void FocusHitbox::Load() {
    char* texturedata=Reader.getFile("Hitbox.png");
    size_t texturesize=Reader.getEntryFileSize("Hitbox.png");
    Texture.loadFromMemory(texturedata,texturesize);
    delete[] texturedata;
    Texture.setSmooth(true);
    for (unsigned int i=0; i<4; ++i) {
        Sprite[i].setTexture(Texture);
        Sprite[i].setTextureRect(sf::IntRect(1,1,80,80));
        Sprite[i].setOrigin(Sprite[i].getLocalBounds().width/2, Sprite[i].getLocalBounds().height/2);
        Sprite[i].setScale(0.f,0.f);
    }
    Sprite[2].setRotation(45);
    Sprite[3].setRotation(-45);

    PlayerPointer=Engine.Player;
}

void FocusHitbox::Draw() {
    float scale=Sprite[0].getScale().x;
    scale+=8.0f*PlayerPointer->EnginePointer->FrameTime*(PlayerPointer->EnginePointer->ShiftPressed==true?1:-1);
    if (scale>1.0f)
        scale=1.0f;
    else if (scale<0.0f)
        scale=0.0f;

    for (unsigned int i=0; i<4; ++i) {
        Sprite[i].setScale(scale,scale);
        Sprite[i].setPosition(PlayerPointer->Position);
        Sprite[i].rotate(120*PlayerPointer->EnginePointer->FrameTime*(i%2==0?1:-1));
        MainWindow.draw(Sprite[i]);
    }
}

void MyPlayer::Load() {
    char *imagebuffer=Reader.getFile(SelectedShotType.TextureFile);
    int imagesize=Reader.getEntryFileSize(SelectedShotType.TextureFile);
    Image.loadFromMemory(imagebuffer,imagesize);
    Image.setSmooth(true);
    delete[] imagebuffer;
    auto spritewidth=Image.getSize().x/4, spriteheight=Image.getSize().y;
    for (int i=0; i<4; i++) {
        Sprite[i].setTexture(Image);
        Sprite[i].setTextureRect(sf::IntRect(spritewidth*i, 0, spritewidth, spriteheight));
        Sprite[i].setOrigin(spritewidth/2,spriteheight/2);
        Sprite[i].setScale(1.2,1.2);
    }
    DeathTime=ChargeTime=BombTime=0.f;

    for (int i=0; i<2; ++i) {
        imagebuffer=Reader.getFile(SelectedShotType.ShotTextureFile[i]);
        imagesize=Reader.getEntryFileSize(SelectedShotType.ShotTextureFile[i]);
        SelectedShotType.ShotTexture[i].loadFromMemory(imagebuffer, imagesize);
        delete[] imagebuffer;
    }
}

void MyPlayer::CheckCollision() {
    bool HasToDie=false;
    if (DeathTime==0 && ChargeTime==0.0f && BombTime==0.0f) {
        //Check enemy bullet to player collisions
        for (unsigned int i=0; i<Engine.EnemyBullets.size(); i++) {
            double Quad_X=pow((Position.x-Engine.EnemyBullets.at(i)->Sprite.getPosition().x), 2);
            double Quad_Y=pow((Position.y-Engine.EnemyBullets.at(i)->Sprite.getPosition().y), 2);
            double QuadDistance=Quad_X+Quad_Y;
            double QuadHitDistance=pow(this->SelectedShotType.HitboxRadius+Engine.EnemyBullets.at(i)->Radius,2);
            double QuadGrazeDistance=pow(this->SelectedShotType.HitboxRadius+Engine.EnemyBullets.at(i)->Radius+39,2);
            if (QuadDistance <= QuadGrazeDistance) {
                if (QuadDistance <= QuadHitDistance) { //The player has been hit
                    HasToDie=true;
                    #if DEBUG
                        unsigned long long debug_collided_bullet_index=i;
                        double debug_quad_x=Quad_X;
                        double debug_quad_y=Quad_Y;
                        double debug_quad_distance=QuadDistance;
                        double debug_quad_hitdistance=QuadHitDistance;
                        double debug_distance=sqrt(debug_quad_distance);
                        double debug_hitdistance=sqrt(debug_quad_hitdistance);
                        std::fstream f;
                        f.open(DEATH_DEBUG_REPORT, std::ios::out);
                        f<<"\n" <<"Player->Position.x=" <<Position.x <<"\n"
                                <<"Player->Position.y=" <<Position.y <<"\n"
                                <<"Bullet->Position.x=" <<Engine.EnemyBullets.at(debug_collided_bullet_index)->Sprite.getPosition().x <<"\n"
                                <<"Bullet->Position.y=" <<Engine.EnemyBullets.at(debug_collided_bullet_index)->Sprite.getPosition().y <<"\n"
                                <<"Bullet->Radius=" <<Engine.EnemyBullets.at(debug_collided_bullet_index)->Radius <<"\n"
                                <<"Bullet->Scale=" <<Engine.EnemyBullets.at(debug_collided_bullet_index)->Sprite.GetScale().x <<"\n"
                                <<"Quad_X=(" <<Position.x <<"-" <<Engine.EnemyBullets.at(debug_collided_bullet_index)->Sprite.getPosition().x <<")^2=" <<debug_quad_x <<"\n"
                                <<"Quad_y=(" <<Position.y <<"-" <<Engine.EnemyBullets.at(debug_collided_bullet_index)->Sprite.getPosition().y <<")^2=" <<debug_quad_y <<"\n"
                                <<"Distance=sqrt(" <<debug_quad_x <<"+" <<debug_quad_y <<")=" <<debug_distance <<"\n"
                                <<"HitDistance=" <<this->Radius <<"+" <<Engine.EnemyBullets.at(debug_collided_bullet_index)->Radius <<"=" <<debug_hitdistance;
                        f.close();
                        MainWindow.capture().saveToFile(DEATH_DEBUG_IMAGE);
                    #endif
                    break;
                }
                else if (Engine.EnemyBullets.at(i)->Grazed==false) {//The player grazed the bullet
                    Play(PLAYERGRAZE);
                    if (Charge < 1000)
                        ++Charge;
                    Engine.EnemyBullets.at(i)->Grazed=true;
                    Engine.Graze++;
                }
            }
        }

        //Check enemy bodies to player collisions
        for (unsigned int i=0; i<Engine.Enemies.size(); i++) {
            unsigned Quad_X=pow((Position.x-Engine.Enemies.at(i)->Position.x), 2);
            unsigned Quad_Y=pow((Position.y-Engine.Enemies.at(i)->Position.y), 2);
            unsigned Quad_Distance=Quad_X+Quad_Y;
            unsigned Quad_HitDistance=pow((SelectedShotType.HitboxRadius+Engine.Enemies.at(i)->Radius), 2);
            if (Quad_Distance <= Quad_HitDistance)
                if (ChargeTime==0.0f && BombTime==0.0f)
                    HasToDie=true;
        }

        //Check boss's body to player collision
        unsigned Quad_X=pow((Position.x-Engine.LevelBoss->Position.x), 2);
        unsigned Quad_Y=pow((Position.y-Engine.LevelBoss->Position.y), 2);
        unsigned Quad_Distance=Quad_X+Quad_Y;
        unsigned Quad_HitDistance=pow((SelectedShotType.HitboxRadius+Engine.LevelBoss->Radius), 2);
        if (Quad_Distance <= Quad_HitDistance)
            if (ChargeTime==0.0f && BombTime==0.0f)
                HasToDie=true;
    }
    if (HasToDie)
        Die();
}

void MyPlayer::Die() {
    DeathTime=3.5f;
    Play(SelectedShotType.DeathSoundID);
    Engine.VisualEffects.AddEffect(new EffectExplosion(Position.x, Position.y, 350.f, 0.9f));
    //Move player to spawn point
    Engine.Player->PrevPosition.x=Engine.Player->Position.x=250;
    Engine.Player->PrevPosition.y=Engine.Player->Position.y=500;
    for (unsigned i=0; i<Engine.EnemyBullets.size(); i++) {
        Engine.VisualEffects.AddEffect(new EffectExplosion(Engine.EnemyBullets.at(i)->Sprite.getPosition().x,
                                                           Engine.EnemyBullets.at(i)->Sprite.getPosition().y,
                                                           Engine.EnemyBullets.at(i)->Radius,
                                                           0.4f));
        delete Engine.EnemyBullets.at(i);
    }
    Engine.EnemyBullets.clear();
    for (unsigned i=0; i<Engine.LevelBoss->Bullets.size();) {
        if (Engine.LevelBoss->Bullets.at(i)->Deletable==true) {
            Engine.VisualEffects.AddEffect(new EffectExplosion(Engine.LevelBoss->Bullets.at(i)->Sprite.getPosition().x,
                                                                Engine.LevelBoss->Bullets.at(i)->Sprite.getPosition().y,
                                                                Engine.LevelBoss->Bullets.at(i)->Radius,
                                                                0.4f));
            delete Engine.LevelBoss->Bullets.at(i);
            Engine.LevelBoss->Bullets.erase(Engine.LevelBoss->Bullets.begin()+i);
        }
        else
            i++;
    }
    #if (INVINCIBLE==FALSE)
    Lives--;
    #endif
    if (Bombs<3)
        Bombs=3;
    for (int i=0; i<4; i++)
        Sprite[i].setColor(sf::Color(128,128,128,255));
    Power=Power>100?Power-100:0;
}

void MyPlayer::Draw() {
    float f=fmodf(EnginePointer->PastTime,0.4f);
    short w=f>=0.2f?1:0;
    if (EnginePointer->LeftPressed==false && EnginePointer->RightPressed==false)
        MainWindow.draw(Sprite[w]);
    else if (EnginePointer->LeftPressed==true)
        MainWindow.draw(Sprite[2]);
    else
        MainWindow.draw(Sprite[3]);
    Hitbox.Draw();
}

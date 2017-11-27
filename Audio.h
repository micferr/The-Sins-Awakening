#ifndef AUDIO_H
#define AUDIO_H

#include <vector>
#include <string>
#include <SFML/Audio.hpp>

/* Name: SoundID
 * Description: List of IDs of all the game's sound effects
 */
enum SoundID {
    MENUSCROLL=0,
    MENUCONFIRM=1,
    ATERSHOOT=2,
    ATERAUXSHOOT=3,
    ATERBOMB=4,
    ATERDEATH=5,
    ALBASHOOT=6,
    ALBAAUXSHOOT=7,
    ALBABOMB=8,
    ALBADEATH=9,
    PLAYERCHARGE=10,
    PLAYERGRAZE=11,
    PLAYERGAMEOVER=12,
    ESCMENU=13,
    ENEMYDEATH=14,
    BOSSBAREMPTY=15,
    BOSSDEATH=16,
    ITEMCOLLECTED=17,
    LIFEGAINED=18
};

//Ditto for musics
enum MusicID {
    NOMUSIC=-1,
    MENUTHEME=0,
    LEVEL1_THEME=1,
    BOSS1_THEME=2,
    LEVEL2_THEME=3,
    BOSS2_THEME=4,
    LEVEL3_THEME=5,
    BOSS3_THEME=6,
    LEVEL4_THEME=7,
    BOSS4_THEME=8,
    LEVEL5_THEME=9,
    BOSS5_THEME=10,
    LEVEL6_THEME=11,
    BOSS6_THEME=12,
    LEVEL7_THEME=13,
    BOSS7_THEME=14,
    LEVELEXTRA_THEME=15,
    BOSSEXTRA_THEME=16
};

class AudioHandler {
    ///Sounds
    std::vector<sf::SoundBuffer*> SoundData; //Data
    std::vector<sf::Sound*> SoundHandles; //Data handles

    ///Music
    std::vector<std::string> MusicNames;
    sf::SoundBuffer MusicBuffer;
    sf::Music BGMMusic; //Background music
    MusicID LoadedMusic;
    bool IsMusicLoaded;

    sf::Thread* FadeOutThread;

    ///Members
    public:
    AudioHandler(); //Ctor, loads the sound effects
    ~AudioHandler(); //Dtor, delete everything
    void Play(SoundID ID); //Start playing a sound
    void Play(MusicID ID); //Start playing BGM

    bool LoadMusic(MusicID ID); //Load a music without playing it
    void PlayMusic(); //Play/Resume the music
    void PauseMusic(); //Pause the music
    void StopMusic(); //Stop the music
    void FadeOut(); //To define (delete?)
    void FadeOutEnd();
    void SetMusicVolume(int volume); //Set BGMMusic volume
    void SetAudioPitch(float pitch);
    void SetSEVolume(int volume); //Set Sound Effects volume
    void SetLoop(bool setloop);

    bool IsPlaying();
    unsigned GetMusicVolume();
};

//Helpers
void LoadMusic(MusicID ID);
void PlayMusic();
void PauseMusic();
void StopMusic();
void Play(SoundID ID);
void Play(MusicID ID);
void SetMusicVolume(int volume);
void SetSEVolume(int volume);
void SetMusicLoop(bool setloop);
void FadeOutMusic();

#endif // AUDIO_H

#include <SFML/Audio.hpp>
#include "Global.h"
#include "GameEngine.h"
#include "Audio.h"

/* ---------------------
 * Name: AUDIO_ENABLED
 * Description: If this is false, no music nor audio
 * Default: true
 * --------------------- */
 #define AUDIO_ENABLED true
 #define BINNING_VERSION false
//Ctor
AudioHandler::AudioHandler() : LoadedMusic(NOMUSIC), IsMusicLoaded(false), FadeOutThread(nullptr) {
    #if AUDIO_ENABLED
    const std::string MENUSCROLL_SOUNDNAME("menuscroll.ogg");
    const std::string MENUCONFIRM_SOUNDNAME("confirm.ogg");
    const std::string ATERSHOOT_SOUNDNAME("atershoot.ogg");
    const std::string ATERAUXSHOOT_SOUNDNAME("aterauxshoot.ogg");
    const std::string ATERBOMB_SOUNDNAME("aterbomb.ogg");
    const std::string ATERDEATH_SOUNDNAME("aterdeath.ogg");
    const std::string ALBASHOOT_SOUNDNAME("albashoot.ogg");
    const std::string ALBAAUXSHOOT_SOUNDNAME("albaauxshoot.ogg");
    const std::string ALBABOMB_SOUNDNAME("albabomb.ogg");
    const std::string ALBADEATH_SOUNDNAME("albadeath.ogg");
    const std::string PLAYERCHARGE_SOUNDNAME("charge.ogg");
    const std::string PLAYERGRAZE_SOUNDNAME("graze.ogg");
    const std::string PLAYERGAMEOVER_SOUNDNAME("gameover.ogg");
    const std::string ESCMENU_SOUNDNAME("escmenu.ogg");
    const std::string ENEMYDEATH_SOUNDNAME("enemydeath.ogg");
    const std::string BOSSBAREMPTY_SOUNDNAME("bossbarempty.ogg");
    const std::string BOSSDEATH_SOUNDNAME("bossdeath.ogg");
    const std::string ITEMCOLLECTED_SOUNDNAME("itemcollected.ogg");
    const std::string LIFEGAINED_SOUNDNAME("lifegained.ogg");

    const std::string MAINTHEME_MUSICNAME("menutheme.ogg");
    const std::string LEVEL1THEME_MUSICNAME("level1theme.ogg");
    const std::string BOSS1THEME_MUSICNAME("boss1theme.ogg");
    const std::string LEVEL2THEME_MUSICNAME("level2theme.ogg");
    const std::string BOSS2THEME_MUSICNAME("boss2theme.ogg");
    const std::string LEVEL3THEME_MUSICNAME("level3theme.ogg");
    const std::string BOSS3THEME_MUSICNAME("boss3theme.ogg");
    const std::string LEVEL4THEME_MUSICNAME("level4theme.ogg");
    const std::string BOSS4THEME_MUSICNAME("boss4theme.ogg");
    const std::string LEVEL5THEME_MUSICNAME("level5theme.ogg");
    const std::string BOSS5THEME_MUSICNAME("boss5theme.ogg");
    const std::string LEVEL6THEME_MUSICNAME("level6theme.ogg");
    const std::string BOSS6THEME_MUSICNAME("boss6theme.ogg");
    const std::string LEVEL7THEME_MUSICNAME("level7theme.ogg");
    const std::string BOSS7THEME_MUSICNAME("boss7theme.ogg");

    ///Sounds
    //Names of the sound files to load
    std::vector<std::string> soundfiles;
    soundfiles.push_back(MENUSCROLL_SOUNDNAME);
    soundfiles.push_back(MENUCONFIRM_SOUNDNAME);
    soundfiles.push_back(ATERSHOOT_SOUNDNAME);
    soundfiles.push_back(ATERAUXSHOOT_SOUNDNAME);
    soundfiles.push_back(ATERBOMB_SOUNDNAME);
    soundfiles.push_back(ATERDEATH_SOUNDNAME);
    soundfiles.push_back(ALBASHOOT_SOUNDNAME);
    soundfiles.push_back(ALBAAUXSHOOT_SOUNDNAME);
    soundfiles.push_back(ALBABOMB_SOUNDNAME);
    soundfiles.push_back(ALBADEATH_SOUNDNAME);
    soundfiles.push_back(PLAYERCHARGE_SOUNDNAME);
    soundfiles.push_back(PLAYERGRAZE_SOUNDNAME);
    soundfiles.push_back(PLAYERGAMEOVER_SOUNDNAME);
    soundfiles.push_back(ESCMENU_SOUNDNAME);
    soundfiles.push_back(ENEMYDEATH_SOUNDNAME);
    soundfiles.push_back(BOSSBAREMPTY_SOUNDNAME);
    soundfiles.push_back(BOSSDEATH_SOUNDNAME);
    soundfiles.push_back(ITEMCOLLECTED_SOUNDNAME);
    soundfiles.push_back(LIFEGAINED_SOUNDNAME);

    //Loads the SoundBuffers
    #if !BINNING_VERSION
    for (size_t i=0; i<soundfiles.size(); ++i) {
        char* sound_data=Reader.getFile(soundfiles[i]);
        long long sound_size=Reader.getEntryFileSize(soundfiles[i]);
        SoundData.push_back(new sf::SoundBuffer);
        SoundData.back()->loadFromMemory(sound_data, sound_size);
        delete[] sound_data;
        SoundHandles.push_back(new sf::Sound(*SoundData[i]));
    }
    #else
    for (unsigned short i=0; i<soundfiles.size(); ++i) {
        SoundData.push_back(new sf::SoundBuffer);
        SoundData.back()->loadFromFile(soundfiles[i]);
        SoundHandles.push_back(new sf::Sound(*SoundData[i]));
    }
    #endif

    ///Music
    BGMMusic.setLoop(true);
    MusicNames.push_back(MAINTHEME_MUSICNAME);
    MusicNames.push_back(LEVEL1THEME_MUSICNAME);
    MusicNames.push_back(BOSS1THEME_MUSICNAME);
    MusicNames.push_back(LEVEL2THEME_MUSICNAME);
    MusicNames.push_back(BOSS2THEME_MUSICNAME);
    MusicNames.push_back(LEVEL3THEME_MUSICNAME);
    MusicNames.push_back(BOSS3THEME_MUSICNAME);
    MusicNames.push_back(LEVEL4THEME_MUSICNAME);
    MusicNames.push_back(BOSS4THEME_MUSICNAME);
    MusicNames.push_back(LEVEL5THEME_MUSICNAME);
    MusicNames.push_back(BOSS5THEME_MUSICNAME);
    MusicNames.push_back(LEVEL6THEME_MUSICNAME);
    MusicNames.push_back(BOSS6THEME_MUSICNAME);
    MusicNames.push_back(LEVEL7THEME_MUSICNAME);
    MusicNames.push_back(BOSS7THEME_MUSICNAME);
    #endif
}

//Dtor
AudioHandler::~AudioHandler() {
    #if AUDIO_ENABLED
    //Delete the Sounds
    for (unsigned long i=0; i<SoundHandles.size(); ++i)
        delete SoundHandles[i];

    //Delete the SoundBuffers
    for (unsigned long i=0; i<SoundData.size(); ++i)
        delete SoundData[i];
    #endif
}

//Play a sound
void AudioHandler::Play(SoundID ID) {
    #if AUDIO_ENABLED
    if (SoundHandles.at(ID)->getStatus()!=sf::Sound::Status::Stopped)
        SoundHandles.at(ID)->stop();
    SoundHandles.at(ID)->play();
    #endif
}

//Play music
void AudioHandler::Play(MusicID ID) {
    #if AUDIO_ENABLED
    if (LoadedMusic!=ID || BGMMusic.getStatus()!=sf::Sound::Playing) {
        if (this->LoadMusic(ID)) {
            if (BGMMusic.getStatus()!=sf::Sound::Status::Playing)
                this->PlayMusic();
        }
    }
    #endif
}

bool AudioHandler::LoadMusic(MusicID ID) {
    #if AUDIO_ENABLED && (!BINNING_VERSION)
    static char *rawmusic=nullptr;
    StopMusic();
    if (ID!=LoadedMusic) {
        char* tempBuffer = Reader.getFile(MusicNames[ID]); // Gets track data
        size_t musicSize = Reader.getEntryFileSize(MusicNames[ID]); // Gets track size
        BGMMusic.openFromMemory(tempBuffer, musicSize);
        if (rawmusic != nullptr) {
            delete[] rawmusic;
        }
        rawmusic = tempBuffer;
        LoadedMusic=ID;
        IsMusicLoaded=true;
        return true;
    }
    IsMusicLoaded=false;
    return false;
    #elif AUDIO_ENABLED && BINNING_VERSION
    StopMusic();
    if (ID!=LoadedMusic) {
        LoadedMusic=ID;
        std::fstream f;
        f.open(MusicNames[ID], std::ios::in);
        if (f.is_open()) {
            //f.close();
            BGMMusic.openFromFile(MusicNames[ID]);
            IsMusicLoaded=true;
            return true;
        }
    }
    IsMusicLoaded=false;
    return false;
    #endif
}

//Starts playing the music
void AudioHandler::PlayMusic(void) {
    #if AUDIO_ENABLED
    if (IsMusicLoaded) {
        BGMMusic.setVolume(Data.BGMVolume);
        BGMMusic.play();
    }
    #endif
}

void AudioHandler::PauseMusic(void) {
    BGMMusic.pause();
}

void AudioHandler::StopMusic(void) {
    BGMMusic.stop();
}

static void fadeoutfunc(void* args) {

}

void AudioHandler::FadeOut(void) {
    #warning "Fade Out hasn't been implemented yet"
    #if AUDIO_ENABLED
    /*if (FadeOutThread!=nullptr) {
        FadeOutEnd();
    }
    FadeOutThread=new sf::Thread(fadeoutfunc);*/
    #endif
}

void AudioHandler::FadeOutEnd(void) {
    /*if (FadeOutThread!=nullptr) {
        FadeOutThread->wait();
        delete FadeOutThread;
        FadeOutThread=nullptr;
    }*/
}

void AudioHandler::SetMusicVolume(int volume) {
    BGMMusic.setVolume(volume);
}

void AudioHandler::SetAudioPitch(float pitch) {
    BGMMusic.setPitch(pitch);
    for (auto soundhandle : SoundHandles)
        soundhandle->setPitch(pitch);
}

void AudioHandler::SetSEVolume(int volume) {
    for (unsigned i=0; i<SoundHandles.size(); ++i)
        SoundHandles[i]->setVolume(volume);
}

void AudioHandler::SetLoop(bool setloop) {
    BGMMusic.setLoop(setloop);
}

bool AudioHandler::IsPlaying(void) {
    return BGMMusic.getStatus()==sf::SoundSource::Status::Playing;
}

unsigned AudioHandler::GetMusicVolume() {
    return BGMMusic.getVolume();
}

void LoadMusic(MusicID ID) {
    Engine.AudioHandle->LoadMusic(ID);
}

void PlayMusic(void) {
    Engine.AudioHandle->PlayMusic();
}

void PauseMusic(void) {
    Engine.AudioHandle->PauseMusic();
}

void StopMusic(void) {
    Engine.AudioHandle->PauseMusic();
}

void Play(SoundID ID) {
    Engine.AudioHandle->Play(ID);
}

void Play(MusicID ID) {
    Engine.AudioHandle->Play(ID);
}

void SetMusicVolume(int volume) {
    Engine.AudioHandle->SetMusicVolume(volume);
}

void SetSEVolume(int volume) {
    Engine.AudioHandle->SetSEVolume(volume);
}

void SetMusicLoop(bool setloop) {
    Engine.AudioHandle->SetLoop(setloop);
}

void FadeOutMusic() {
    Engine.AudioHandle->FadeOut();
}

void FadeOutEndMusic() {
    Engine.AudioHandle->FadeOutEnd();
}

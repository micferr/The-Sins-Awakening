#ifndef DATASTRUCT_H
#define DATASTRUCT_H

#pragma pack(push, 1)

struct DataStruct {
    //Record data
    std::int16_t UnlockedStage;
    //Normal game
    std::uint64_t Score[10];
    std::uint8_t Name[10][10];
    //Final level
    std::uint8_t FinalUnlocked;
    std::uint64_t FinalScore[10];
    std::uint8_t FinalName[10][10];
    //Extra Level - Eight level - Phantasm level - As you want
    std::uint8_t ExtraUnlocked;
    std::uint64_t ExtraScore[10];
    std::uint8_t ExtraName[10][10];

    //Settings' data
    std::uint8_t MaxLives;
    std::uint8_t BGMVolume;
    std::uint8_t SEVolume;
};

#pragma pack(pop)

void LoadDataStruct(DataStruct& Data);
void WriteDataStruct(DataStruct& Data);
DataStruct SwapDataStructEndianness(DataStruct Data);

#endif

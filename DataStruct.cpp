#include <fstream>
#include <cassert>
#include <bitset>
#include "DataStruct.h"
#include "Endianness.h"

void LoadDataStruct(DataStruct& Data) {
    std::fstream istr("tsadata.dat", std::ios::binary | std::ios::in);
    if (istr.is_open()) {
        istr.read((char*)&Data, sizeof(Data));
        if (O32_HOST_ORDER == O32_BIG_ENDIAN)
            Data=SwapDataStructEndianness(Data);
        istr.close();
    }
    else {
        for (short i=0; i<10; ++i) {
            Data.Score[i]=0;
            for (short j=0; j<10; ++j)
                Data.Name[i][j]='-';

            Data.FinalScore[i]=0;
            for (short j=0; j<10; ++j)
                Data.FinalName[i][j]='-';

            Data.ExtraScore[i]=0;
            for (short j=0; j<10; ++j)
                Data.ExtraName[i][j]='-';
        }
        Data.UnlockedStage=0;
        Data.FinalUnlocked=false;
        Data.ExtraUnlocked=false;
        Data.MaxLives=3;
        Data.BGMVolume=70;
        Data.SEVolume=70;
        WriteDataStruct(Data);
    }
}

void WriteDataStruct(DataStruct& Data) {
    std::fstream ostr("tsadata.dat", std::ios::binary | std::ios::out);
    if (O32_HOST_ORDER == O32_BIG_ENDIAN) {
        DataStruct SwappedData=SwapDataStructEndianness(Data);
        ostr.write(static_cast<char*>(static_cast<void*>(&SwappedData)),sizeof(SwappedData));
    }
    else {
        ostr.write((char*)&Data,sizeof(Data));
    }
    ostr.close();
}

DataStruct SwapDataStructEndianness(DataStruct Data) {
    //Endian-swap everything
    swap_endianness_reference(Data.UnlockedStage);
    for (unsigned i=0; i<10; ++i)
        swap_endianness_reference(Data.Score[i]);
    for (unsigned i=0; i<10; ++i)
        for (unsigned j=0; j<10; ++j)
            swap_endianness_reference(Data.Name[i][j]);
    swap_endianness_reference(Data.FinalUnlocked);
    for (unsigned i=0; i<10; ++i)
        swap_endianness_reference(Data.FinalScore[i]);
    for (unsigned i=0; i<10; ++i)
        for (unsigned j=0; j<10; ++j)
            swap_endianness_reference(Data.FinalName[i][j]);
    swap_endianness_reference(Data.ExtraUnlocked);
    for (unsigned i=0; i<10; ++i)
        swap_endianness_reference(Data.ExtraScore[i]);
    for (unsigned i=0; i<10; ++i)
        for (unsigned j=0; j<10; ++j)
            swap_endianness_reference(Data.ExtraName[i][j]);
    swap_endianness_reference(Data.MaxLives);
    swap_endianness_reference(Data.BGMVolume);
    swap_endianness_reference(Data.SEVolume);

    return Data;
}

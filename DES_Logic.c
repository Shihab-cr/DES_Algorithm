#include <stdio.h>
#include <stdint.h>

//Shihab Mohamed 2201366

const int PC1_TABLE[] =
{57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18,
 10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36,
 63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22,
 14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4};

 const int PC2_TABLE[] =
 {14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10, 23, 19,
 12, 4, 26, 8, 16, 7, 27, 20, 13, 2, 41, 52, 31, 37,
 47, 55, 30, 40, 51, 45, 33, 48, 44, 49, 39, 56, 34,
 53, 46, 42, 50, 36, 29, 32};

 const int IP_TABLE[64] =
 {
     58,50,42,34,26,18, 10,2,
     60,52,44,36,28,20,12,4,
     62,54,46,38,30,22,14,6,
     64,56,48,40,32,24,16,8,
     57,49,41,33,25,17,9,1,
     59,51,43,35,27,19,11,3,
     61,53,45,37,29,21,13,5,
     63, 55,47,39,31,23,15,7
 };

 const int EP_BOX_TABLE[48] =
 {
     32,1,2,3,4,5, 4,5,6,7,8,9,8,9,10,11,12,13,
     12,13,14,15,16,17,16,17,18,19,20,21,20,21,
     22,23,24,25,24,25,26,27,28,29,28,29,30,31,
     32,1
 };
const int S_BOX[8][64] = {
    { // S1 flattened
        14,  0,  4, 15, 13,  7,  1,  4,  2, 14, 15,  2, 11, 13,  8,  1,
         3, 10, 10,  6,  6, 12, 12, 11,  5,  9,  9,  5,  0,  3,  7,  8,
         4, 15,  1, 12, 14,  8,  8,  2, 13,  4,  6,  9,  2,  1, 11,  7,
        15,  5, 12, 11,  9,  3,  7, 14,  3, 10, 10,  0,  5,  6,  0, 13
    },
    { // S2 flattened
        15,  3,  1, 13,  8,  4, 14,  7,  6, 15, 11,  2,  3,  8,  4, 14,
         9, 12,  7,  0,  2,  1, 13, 10, 12,  6,  0,  9,  5, 11, 10,  5,
         0, 13, 14,  8,  7, 10, 11,  1, 10,  3,  4, 15, 13,  4,  1,  2,
         5, 11,  8,  6, 12,  7,  6, 12,  9,  0,  3,  5,  2, 14, 15,  9
    },
    { // S3 flattened
        10, 13,  0,  7,  9,  0, 14,  9,  6,  3,  3,  4, 15,  6,  5, 10,
         1,  2, 13,  8, 12,  5,  7, 14, 11, 12,  4, 11,  2, 15,  8,  1,
        13,  1,  6, 10,  4, 13,  9,  0,  8,  6, 15,  9,  3,  8,  0,  7,
        11,  4,  1, 15,  2, 14, 12,  3,  5, 11, 10,  5, 14,  2,  7, 12
    },
    { // S4 flattened
         7, 13, 13,  8, 14, 11,  3,  5,  0,  6,  6, 15,  9,  0, 10,  3,
         1,  4,  2,  7,  8,  2,  5, 12, 11,  1, 12, 10,  4, 14, 15,  9,
        10,  3,  6, 15,  9,  0,  0,  6, 12, 10, 11,  1,  7, 13, 13,  8,
        15,  9,  1,  4,  3,  5, 14, 11,  5, 12,  2,  7,  8,  2,  4, 14
    },
    { // S5 flattened
         2, 14, 12, 11,  4,  2,  1, 12,  7,  4, 10,  7, 11, 13,  6,  1,
         8,  5,  5,  0,  3, 15, 15, 10, 13,  3,  0,  9, 14,  8,  9,  6,
         4, 11,  2,  8,  1, 12, 11,  7, 10,  1, 13, 14,  7,  2,  8, 13,
        15,  6,  9, 15, 12,  0,  5,  9,  6, 10,  3,  4,  0,  5, 14,  3
    },
    { // S6 flattened
        12, 10,  1, 15, 10,  4, 15,  2,  9,  7,  2, 12,  6,  9,  8,  5,
         0,  6, 13,  1,  3, 13,  4, 14, 14,  0,  7, 11,  5,  3, 11,  8,
         9,  4, 14,  3, 15,  2,  5, 12,  2,  9,  8,  5, 12, 15,  3, 10,
         7, 11,  0, 14,  4,  1, 10,  7,  1,  6, 13,  0, 11,  8,  6, 13
    },
    { // S7 flattened
         4, 13, 11,  0,  2, 11, 14,  7, 15,  4,  0,  9,  8,  1, 13, 10,
         3, 14, 12,  3,  9,  5,  7, 12,  5,  2, 10, 15,  6,  8,  1,  6,
         1,  6,  4, 11, 11, 13, 13,  8, 12,  1,  3,  4,  7, 10, 14,  7,
        10,  9, 15,  5,  6,  0,  8, 15,  0, 14,  5,  2,  9,  3,  2, 12
    },
    { // S8 flattened
        13,  1,  2, 15,  8, 13,  4,  8,  6, 10, 15,  3, 11,  7,  1,  4,
        10, 12,  9,  5,  3,  6, 14, 11,  5,  0,  0, 14, 12,  9,  7,  2,
         7,  2, 11,  1,  4, 14,  1,  7,  9,  4, 12, 10, 14,  8,  2, 13,
         0, 15,  6, 12, 10,  9, 13,  0, 15,  3,  3,  5,  5,  6,  8, 11
    }
};

 const int P_TABLE[32] = {
    16,7,20,21,29,12,28,17,
    1,15,23,26,5,18,31,10,
    2,8,24,14,32,27,3,9,19,
    13,30,6,22,11,4,25
 };

 const int KEY_SHIFT_SCHEDULE[16] = {
    1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1
 };

const int INVERSE_IP_TABLE[64] = {
    40,  8, 48, 16, 56, 24, 64, 32,
    39,  7, 47, 15, 55, 23, 63, 31,
    38,  6, 46, 14, 54, 22, 62, 30,
    37,  5, 45, 13, 53, 21, 61, 29,
    36,  4, 44, 12, 52, 20, 60, 28,
    35,  3, 43, 11, 51, 19, 59, 27,
    34,  2, 42, 10, 50, 18, 58, 26,
    33,  1, 41,  9, 49, 17, 57, 25
};


uint64_t CircularLeftShift_28_Bit(uint64_t data, int shiftAmount){
    return (data<<shiftAmount | (data>>(28-shiftAmount))) & 0x0FFFFFFF;
}


uint64_t ApplyPermutation(uint64_t data,const int* table,int inSize,int outSize){
    uint64_t result = 0x00000000;
    for(int i=0;i<outSize;i++){
        int newIndex = table[i];
        uint64_t temp = (data>>(inSize-newIndex))&0x01;
        result |= (temp<<(outSize-i-1));
    }
    return result;
}
uint64_t SwapByteEndiannes(uint64_t data){
    return
    ((data & 0x00000000000000FFULL)<<56) |
    ((data & 0x000000000000FF00ULL)<<40) |
    ((data & 0x0000000000FF0000ULL)<<24) |
    ((data & 0x00000000FF000000ULL)<<8) |
    ((data & 0x000000FF00000000ULL)>>8) |
    ((data & 0x0000FF0000000000ULL)>>24) |
    ((data & 0x00FF000000000000ULL)>>40) |
    ((data & 0xFF00000000000000ULL)>>56);
}

void GenerateAllSubKeys(char* k_Path, uint64_t keyArray[16]){

    uint64_t keyBuffer =0;
    FILE *inFile = fopen(k_Path,"rb");
    if (!inFile) {
    printf("Error: Could not open files.\n");
    return;
    }
    size_t items_read = fread(&keyBuffer,0x01,sizeof(keyBuffer),inFile);
    fclose(inFile);
    keyBuffer = SwapByteEndiannes(keyBuffer);
    uint64_t permutedKey = ApplyPermutation(keyBuffer,PC1_TABLE,64,56);
    uint64_t leftKeyHalf_C = (permutedKey>>28 & 0x00FFFFFFFULL);
    uint64_t rightKeyHalf_D = permutedKey & 0x00FFFFFFFULL;

    for(int i=0;i<16;i++){
        leftKeyHalf_C = CircularLeftShift_28_Bit(leftKeyHalf_C,KEY_SHIFT_SCHEDULE[i]);
        rightKeyHalf_D = CircularLeftShift_28_Bit(rightKeyHalf_D,KEY_SHIFT_SCHEDULE[i]);

        uint64_t roundSubKey = (leftKeyHalf_C<<28) | rightKeyHalf_D;
        roundSubKey = ApplyPermutation(roundSubKey,PC2_TABLE,56,48);
        keyArray[i] = roundSubKey;
    }
}





uint32_t ApplySBoxSubstitution(uint64_t data){
    uint32_t result = 0x00;
    for(int i=0;i<8;i++){
        uint8_t sboxInputChunk = (data>>(42-(i*6)))&0x03F;
        result =((uint32_t)S_BOX[i][sboxInputChunk] <<(28-(i*4)) ) | result;
    }
    return result;
}



int main(int argc, char **argv)
{
    if (argc < 5) {
    printf("Usage: %s <e/d> <key> <input> <output>\n", argv[0]);
    return 1;
    }
    char* keyPath = argv[2];
    char* plainTextPath = argv[3];
    char* cipherTextPath = argv[4];

    FILE *inFile;
    FILE *outFile;
    outFile = fopen(cipherTextPath,"wb");

    inFile = fopen(plainTextPath,"rb");
    if (!inFile || !outFile) {
    printf("Error: Could not open files.\n");
    return 1;
    }
    uint64_t currentDataBlock = 0;
    size_t items_read = fread(&currentDataBlock,0x01,sizeof(currentDataBlock),inFile);
    currentDataBlock = SwapByteEndiannes(currentDataBlock);
    uint64_t keys[16];
    GenerateAllSubKeys(keyPath,keys);
    while(items_read != 0){
        if(argv[1][0] =='e'){
        //perform encryption
        // *********************** one time only ************************
        uint64_t initialPermutedBlock = ApplyPermutation(currentDataBlock,IP_TABLE,64,64);
        uint64_t rightDataHalf_R = initialPermutedBlock & 0x00FFFFFFFFULL;
        uint64_t leftDataHalf_L = (initialPermutedBlock& 0xFFFFFFFF00000000ULL)>>32;

        //***************************************************************

        for(int i=0;i<16;i++){


            uint64_t fiestalOutput= ApplyPermutation(rightDataHalf_R,EP_BOX_TABLE,32,48) ^ keys[i];
            uint32_t sboxResult = ApplySBoxSubstitution(fiestalOutput);
            //apply S-box substitution
            fiestalOutput= ApplyPermutation(sboxResult,P_TABLE,32,32) ^ leftDataHalf_L;

            leftDataHalf_L = rightDataHalf_R;
            rightDataHalf_R = fiestalOutput;
        }

        uint64_t preOutputBlock = rightDataHalf_R<<32 | leftDataHalf_L;
        preOutputBlock = ApplyPermutation(preOutputBlock,INVERSE_IP_TABLE,64,64);

        preOutputBlock = SwapByteEndiannes(preOutputBlock);
        fwrite(&preOutputBlock,0x01,sizeof(preOutputBlock),outFile);
        currentDataBlock =0;
        items_read = fread(&currentDataBlock, 0x01,sizeof(currentDataBlock),inFile);
        currentDataBlock = SwapByteEndiannes(currentDataBlock);
    }
    else if(argv[1][0] == 'd'){
        //perform decryption
        // *********************** one time only ************************
        uint64_t initialPermutedBlock = ApplyPermutation(currentDataBlock,IP_TABLE,64,64);
        uint64_t rightDataHalf_R = initialPermutedBlock & 0x00FFFFFFFFULL;
        uint64_t leftDataHalf_L = (initialPermutedBlock& 0xFFFFFFFF00000000ULL)>>32;

        //***************************************************************

        for(int i=0;i<16;i++){


            uint64_t fiestalOutput= ApplyPermutation(rightDataHalf_R,EP_BOX_TABLE,32,48) ^ keys[15-i];
            uint32_t sboxResult = ApplySBoxSubstitution(fiestalOutput);
            //apply S-box substitution
            fiestalOutput= ApplyPermutation(sboxResult,P_TABLE,32,32) ^ leftDataHalf_L;

            leftDataHalf_L = rightDataHalf_R;
            rightDataHalf_R = fiestalOutput;
        }

        uint64_t preOutputBlock = rightDataHalf_R<<32 | leftDataHalf_L;
        preOutputBlock = ApplyPermutation(preOutputBlock,INVERSE_IP_TABLE,64,64);

        preOutputBlock = SwapByteEndiannes(preOutputBlock);
        fwrite(&preOutputBlock,0x01,sizeof(preOutputBlock),outFile);
        currentDataBlock =0;
        items_read = fread(&currentDataBlock, 0x01,sizeof(currentDataBlock),inFile);
        currentDataBlock = SwapByteEndiannes(currentDataBlock);
    }
    }
    fclose(inFile);
    fclose(outFile);
    return 0;

}



/*
const char* plainTextPath ="D:\\_Senior2_Fall2026\\Security\\DES-Project\\plainText.txt";
const char* keyPath = "D:\\_Senior2_Fall2026\Security\\DES-Project\\key.txt";
const char* cipherTextPath = "D:\\_Senior2_Fall2026\\Security\\DES-Project\\cipherText.txt";


uint64_t ChangeBitLocation(int newIndex,int index, uint64_t data){
    data = data>>63-index;
    data = data&0x01;
    data = data<<63-(newIndex-1);
    return data;
}



uint64_t ApplyIP_TABLE(uint64_t data){
    uint64_t result = 0x00000000;
    for(int i=0;i<64;i++){
            int newIndex = IP_TABLE[i];
            uint64_t temp = data>>63-index;
            temp= temp&0x01;
            temp = temp<<63-(newIndex-1);
            result = result | temp;
    }
    return result;
}

*/

// Minimum number of bit flips to target numbers code
int minBitFlips(int start, int goal) {
    int xorValue = start ^ goal;
    int bitFlips = 0;
    while (xorValue > 0) {
        bitFlips += (xorValue & 1);
        xorValue >>= 1;
    }
    return bitFlips;
}

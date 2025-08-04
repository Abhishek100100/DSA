class Solution {
private : 
bool isBitSet(int k, uint32_t n )
{
    return (n & (1U << k)) != 0;
}
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0;
        for(int i=0;i<32;i++)
        {
            if(isBitSet(i,n)) ans = 1U<<(31-i) | ans;
        }

        return ans;
    }
};
Reverse bits of a given 32 bits unsigned integer.

Example 1:

Input: 00000010100101000001111010011100
Output: 00111001011110000010100101000000
Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, so return 964176192 which its binary representation is 00111001011110000010100101000000.

Example 2:

Input: 11111111111111111111111111111101
Output: 10111111111111111111111111111111
Explanation: The input binary string 11111111111111111111111111111101 represents the unsigned integer 4294967293, so return 3221225471 which its binary representation is 10111111111111111111111111111111.


There is some important list of the bitwise operator.
     Operator                Meaning
|   (Bitwise OR) 	        Use to Set a Bit of a Register.
&  (Bitwise AND) 	        Use to check a Bit of Register.
^  (Bitwise EX-OR) 	      Use to toggle a Bit of a Register.
~  ( Bitwise complement) 	Use for the compliment.
<< (Shift left) 	        Use to shift a sequence of Bit toward left.
>> (Shift right) 	        Use to shift a sequence of Bit toward Right

A good tutorial on reversing ways to reverse the bits https://aticleworld.com/5-way-to-reverse-bits-of-an-integer/

Solutions :

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {

        vector<int> lookup ;
        int power = 32 ;
        
        while(power > 0){
            int temp = n & 1 ; //this will get the lsb ;
            lookup.push_back(temp) ;
            n = n >> 1 ; // removing the lsb since it is already been taken care of
            power-- ;
        }
        
        uint32_t result ;
        
        for(int i = 0 ; i < lookup.size() ; i++){
            result = result << 1 ; //moving it a bit left to make space for the new bit
            result = result | lookup[i] ;
        }
                
        return result ;
    }
};

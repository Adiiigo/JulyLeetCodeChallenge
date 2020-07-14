Given two numbers, hour and minutes. Return the smaller angle (in degrees) formed between the hour and the minute hand.

Example 1:

Input: hour = 12, minutes = 30
Output: 165

Example 2:

Input: hour = 3, minutes = 30
Output: 75

Example 3:

Input: hour = 3, minutes = 15
Output: 7.5

Example 4:

Input: hour = 4, minutes = 50
Output: 155

Example 5:

Input: hour = 12, minutes = 0
Output: 0

Constraints:
  1 <= hour <= 12
  0 <= minutes <= 59
  Answers within 10^-5 of the actual value will be accepted as correct.

   Hide Hint #1  
The tricky part is determining how the minute hand affects the position of the hour hand.
   Hide Hint #2  
Calculate the angles separately then find the difference.

Reference Site: https://www.hitbullseye.com/Quant/Problems-on-Clocks.php

Solutions:
//Approach1 : explained the comments

class Solution {
public:
    double angleClock(int hour, int minutes) {
        
        /*
        * this will ensure that that 0th and 12th hour are equivalent 
        * not affecting the other hours
        */
        
        hour = hour%12 ; 
        
        /*
        * distance covered till now by the hour hand from the 0th/12th hour(min hand is at 12 so that be 0 deg)
        * 12 hours ~ 360 deg => 1 hour ~ 30 deg
        * 12*60 min ~ 360 deg
        *  1 min ~ .5 deg
        */
        double hDist = hour*30;
        
        /*
        * For the minute hand
        * 60 min ~ 360 deg => 1 min ~ 6 deg
        */
        
        /*
        * Relative Speed refers to the concept that both are moving => instead of looking into their ind speeds
        * we will look into the relative speed between them   
        * RSpeed = 6 deg - 0.5 deg = 5.5 deg(minute to hour)
        */
        
        /*
        * Since both are movind in same direction and relative speed of them is also there
        * it is bound to happen that they will individually cover some distance
        * That is called relative distance and it will be after certain minutes are passed.
        */
        double relativeD = minutes * 5.5 ; 
        
        double answer = abs(hDist - relativeD) ;
        return min(answer,360-answer) ;
    }
};
Time complexity - O(1) 
Space Complexity - O(1)

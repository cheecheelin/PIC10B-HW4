/* **********************************************************************
 File: hw4.cpp
 Author: Cheechee Lin
 Date: October 12, 2015
 
 Program that uses recursion to generate a dragon curve (using boolean values as left and right)
 
 Via wikipedia: 
 
     "Tracing an iteration of the Heighway dragon curve from one end to the other, one encounters a series of 90 degree turns, some to the right and some to the left. For the first few iterations the sequence of right (R) and left (L) turns is as follows:
     
     1st iteration: R
     2nd iteration: R R L
     3rd iteration: R R L R R L L
     4th iteration: R R L R R L L R R R L L R L L.

 ********************************************************************** */
#include <vector>
#include <ostream>

void generate_dragon_sequence(std::vector<bool>& v, int times, std::ostream& out){
    int pos;
    //std::cout<<"hi";
    //out the contents of the vector (at the very end)
    if(times==0){
        for (int i=0; i<v.size(); i++)
            out<<v[i]<<std::endl;
    }

    
    else{
        // times > 0
        
    //push R to the end of the vector
    v.push_back(true);
        
    //get index of where R is positioned
    pos = (int)v.size()-1;
    
    
        //examine the elements before the appended true(R) starting at pos-i (i=1, i=2,...)
        //if true then place false(L) at pos+i
        //if false then place true(R) at pos+i
        
        if (pos>0){
            for (int i=1; i<=pos; i++){
                if(v[pos-i]==true)
                    v.push_back(false);
                if (v[pos-i]== false)
                    v.push_back(true);
            }
            
        }
        
        //recursive function but generate one less time
        generate_dragon_sequence(v,--times,out);
       
    
    }
    
}
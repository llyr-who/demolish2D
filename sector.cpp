#include"sector.h"

#include<iostream>


void demolish::world::Sector::generateLoDs()
{
    // as this function is only called when
    // the size of level of detail is one
    // we can rest assured that this will work
    for(auto&vert:_LoD[0])
    {
        vert->fillPolars();
    }
    // now we have to sort each sector
    // with respect to theta and remove 
    // smallest untill there are only 
    // so many details remaining
     
    
    // BEFORE THE FUNCTION ENDS SORT WITH RESPECT TO THETA AGAIN
    //
    //
    // THIS IS FU**ING ESSENTIAL!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

}

void demolish::world::Sector::displayContents()
{
   int LoDSz = _LoD.size();
   for(int i=0;i<LoDSz;i++)
   {
       int tempSz = _LoD[i].size();
       std::cout << "Layer " << i << " vertices" << std::endl;
       for(int j=0;j<tempSz;j++)
       {
           _LoD[i][j]->displayProperties();
       }
   }
}

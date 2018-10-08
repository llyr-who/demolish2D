#include"scenario.h"

using demolish::world::Scenario;

void Scenario::step()
{

   //   DELETE OLD COLLISION DATA
   //       + how do we store our collison data?
   //           We generate pairs of object index data
   //           which narrow down the collision.
   //       + especially since out data is multileveled?!

   //
   //   GENERATE NEW COLLISION DATA
   //       
   //       + First determine if bounding spheres collide.
   //       + Use SAT for convex hull (like impulse)
   //       + resort to penalty
   //

  
   // container of plemin collision data
   std::vector<std::pair<int,int>> pairwiseObjectCollisionIndexData;

   // 
   float ri,rj;
   std::array<float,2> locationi, locationj;
   int numberOfObjects = _objects.size();
   for(int i=0;i<numberOfObjects;i++)
   {
       ri        =  _objects[i].getBoundingRadius();
       locationi =  _objects[i].getLocation();
       for(int j=i+1;j<numberOfObjects;j++)
       {
           rj        =  _objects[j].getBoundingRadius();
           locationj =  _objects[j].getLocation();
           // If the distance between the centres is less
           // than the sum of the radi we have a POTENTIAL
           // collisioon.
           float DBLsquared = (std::get<0>(locationi)-std::get<0>(locationj))*(std::get<0>(locationi)-std::get<0>(locationj))
                        + (std::get<1>(locationi)-std::get<1>(locationj))*(std::get<1>(locationi)-std::get<1>(locationj));
           if(DBLsquared<(ri+rj)*(ri+rj))
           {
               pairwiseObjectCollisionIndexData.emplace_back(i,j);
               std::cout << "colliusion" << std::endl;
           }


       }
   }

   //
   //   INTEGRATE FORCES
   //
   //
   

   // ... 
}

void Scenario::addObjectToScenario(Polygon&                geometry,
                            std::array<float,2>               position)
{
    Object o = Object(geometry,position);
    _objects.push_back(o);
}

void Scenario::addObjectToScenario(Object&                object)
{
    _objects.push_back(object);
}

void Scenario::render()
{
    for(auto & o: _objects)
    {   
        o.draw();
    }

}

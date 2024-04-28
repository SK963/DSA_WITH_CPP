#include <iostream>
using namespace std;
#include <vector>






int hp(vector<int>path)
    {
        int ahp = 0; // my health while traversing path
        int mhp = 0; // minimum health required to reach end of the path
        int sum;

         for(auto v : path)
         {
             sum += v;
             if(v >= 0) // the next room is friendly
             {
                 ahp += v; // increase ahp
             }
             else // the next room is deadly
             {
                 if(ahp > abs(v)) // sufficient health 
                 {
                     ahp += v; //decrease the ahp
                 }
                 else // unsufficient health
                 {
                     mhp += abs(abs(v) - ahp) + 1; // minimum health requrired
                     ahp += mhp - sum;
                 }

              }

         }
         return mhp;

    }

     

    int calculateMinimumHP(vector<vector<int>>& dungeon) 
    {
        signed health = 0;
        int damage = 0;

        vector<int> path;
        

        int i = 0;
        int j = 0;
        int mhp;
        path.push_back(dungeon[i][j]);

        while(i < dungeon.size() && j< dungeon[0].size())
        {   
            if(dungeon[i+1][j]) // right available
            {
                if(dungeon[i][j+1]) // downwards available
                {
                    if(dungeon[i+1][j] > dungeon[i][j+1]) // right is greater
                        {
                            j++;
                            path.push_back(dungeon[i][j]);

                        }    
                    else //down is greater
                    {
                        i++;
                        path.push_back(dungeon[i][j]); 
                    }    

                }
                else   //  down not available
                {
                    j++;
                    path.push_back(dungeon[i][j]);
                    
                }
            }
            else // right not available 
            {
                if(dungeon[i][j+1]) // down available
                {
                    i++;
                    path.push_back(dungeon[i][j]);
                }
                else // down not available
                {
                   mhp =  hp(path);
                    
                }

            }
            
        }
        return mhp;
    }



int main()
{
    vector<vector<int>>palace;

    int m , n;
    cin>>m>>n;

    vector<int> row;
    int temp;
    for(int i = 0 ; i< m; i++)
        {
            for(int j = 0 ; j< n ; j++)
                {
                    cin>>temp;
                    row.push_back(temp);
                }
            palace.push_back(row);
            row.clear();
            
        }


    for(int i = 0 ; i< palace.size() ; i++)
        {
            for(auto x : palace[i])
                {
                    cout<<"x"<<" ";
                }
        }
}
        
#include "Ray.h"
#include <iostream>
#include <math.h>
#define PI 3.14
#define P2 PI/2
#define P3 3*PI/2 
float Ray::Get_RadianAngle(float angle) {
    return angle * (PI / 180);
}
float Ray::distance(float x1, float x2, float y1, float y2) {
    return sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
}
void Ray::CastRay(float RayAngle,float playerX, float playerY, std::vector<std::vector<int>> map, sf::RenderWindow& window, float& distances, bool& vertical) {
   
    sf::CircleShape dot(5);
    std::vector<int> rays;
    dot.setFillColor(sf::Color::Yellow);
    
    float radianAngle = Get_RadianAngle(RayAngle);
    sf::Vector2f closestRayEnd;
    float shortestRay = std::numeric_limits<float>::max();;
    float distanceX=0, distanceY=0;
    int advancments,mapX,mapY;
    
    float rayX, rayY, xOff, yOff,rayX2,rayY2;
    for (size_t i = 0; i < 1; i++)
    {
        radianAngle += 0.05;
        advancments = 0;
        float aTan = -1/tan(radianAngle);
        if (radianAngle > PI) {
            rayY = (int)playerY/64*64-0.0001;
            rayX = (playerY - rayY) * aTan + playerX;
            yOff = -64;
            xOff = -yOff * aTan;
        }
        if (radianAngle < PI) {
            rayY = (int)playerY/64 * 64 +64 ;
            rayX = (playerY - rayY) * aTan + playerX;
            yOff = 64;
            xOff = -yOff * aTan;

        }
        if (radianAngle == 0 || radianAngle == PI) {
            rayX = playerX;
            rayY = playerY;
            advancments = 8;
        }
        while (advancments < 8) {
            mapX = (int)(rayX) /64;
            mapY = (int)(rayY) /64;
            if (mapX >= 0 && mapY >= 0 && mapX <map[0].size() && mapY < map.size()) {
                if (map[mapX][mapY] == 1) {
                    advancments = 8;

                   
                    distanceX = distance(playerX, rayX, playerY, rayY);
                    if (distanceX < shortestRay) {
                        shortestRay = distanceX;
                        closestRayEnd = sf::Vector2f(rayX,rayY);
                    }
                    break;
                   
                    
                }
            }
                rayX += xOff;
                rayY += yOff;
                advancments += 1;
              
        }
        rayX2 = rayX;
        rayY2 = rayY;
        advancments = 0;
        float nTan = -tan(radianAngle);
        if (radianAngle > P2 && radianAngle < P3) {
            rayX = (int)playerX /64 * 64 - 0.0001;
            rayY = (playerX - rayX) * nTan + playerY;
            xOff = -64;
            yOff = -xOff * nTan;

        }
        if (radianAngle < P2 || radianAngle > P3) {
            rayX = (int)playerX /64 * 64 + 64;
            rayY = (playerX - rayX) * nTan + playerY;
            xOff = 64;
            yOff = -xOff * nTan;
        }
        if (radianAngle == 0 || radianAngle == PI) {
            rayX = playerX;
            rayY = playerY;
            advancments = 8;
       

        }
        while (advancments < 8) {
            mapX = (int)(rayX) / 64;
            mapY = (int)(rayY) / 64;
            if (mapX >= 0 && mapY >= 0 && mapX <= 8 && mapY <= 8) {
                if (map[mapX][mapY] == 1) {
                    distanceY = distance(playerX, rayX, playerY, rayY);
                    if (distanceY < shortestRay) {
                        shortestRay = distanceY;
                        closestRayEnd = sf::Vector2f(rayX, rayY);
                        vertical = true;
                    }
                    break;
                    
                 
                   
                   
                }
               
            }
            rayX += xOff;
            rayY += yOff;
            advancments += 1;
           
        }
      
      
    }
    sf::Vertex line2[] = {
                      sf::Vertex(sf::Vector2f(playerX,playerY),sf::Color::Red),
                      sf::Vertex(sf::Vector2f(closestRayEnd),sf::Color::Red)
    };
    

    distances = shortestRay;
  
}

    


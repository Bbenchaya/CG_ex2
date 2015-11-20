//
//  Pixel.hpp
//  CG_EX2
//
//  Created by Asaf Chelouche on 20/11/15.
//  Copyright © 2015 Bbenchaya. All rights reserved.
//

#ifndef Pixel_hpp
#define Pixel_hpp

class Pixel {
private:
    float RGB[3];
    
public:
    Pixel& operator=(const Pixel &other);
};

#endif /* Pixel_hpp */
